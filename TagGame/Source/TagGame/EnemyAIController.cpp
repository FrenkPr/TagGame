// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "TagGameGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	GoToPlayer = MakeShared<FAivState>
	(
		[](AAIController* AIController)
		{
			AIController->MoveToActor(AIController->GetWorld()->GetFirstPlayerController()->GetPawn(), 50, false);
		},

		nullptr,

		[this](AAIController* AIController, const float DeltaTime) -> TSharedPtr<FAivState>
		{
			EPathFollowingStatus::Type State = AIController->GetMoveStatus();

			/*UKismetSystemLibrary::PrintString(GetWorld(), UEnum::GetDisplayValueAsText(State).ToString());
			UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(FVector::Distance(AIController->GetPawn()->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation())));*/

			switch (State)
			{
				case EPathFollowingStatus::Idle:
					//to don't let the enemy stop chasing player
					//while the player is in air
					if (FVector::Distance(AIController->GetPawn()->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) > 200)
					{
						CurrentState->CallEnter(AIController);  //GoToPlayer call enter state
						return GoToPlayer;
					}
					break;

				case EPathFollowingStatus::Moving:
					float ZDistFromPlayer = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z - AIController->GetPawn()->GetActorLocation().Z;
					ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

					//if the player is up on one of the blue cubes
					if (FVector::Distance(AIController->GetPawn()->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation()) <= 200 &&
						ZDistFromPlayer > 0.1f &&
						!Player->GetCharacterMovement()->IsFalling())
					{
						AIController->MoveToActor(nullptr);
						break;
					}
					
					return GoToPlayer;
					
			}

			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			if (BestBall)
			{
				ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

				BestBall->AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("ik_hand_r"));
				BestBall->SetActorRelativeLocation(FVector(0, 0, 0));
				BestBall = nullptr;

				Blackboard->SetValueAsObject(TEXT("BestBall"), BestBall);

				/*double Dist = FVector::Distance(AIController->GetPawn()->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
				UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(Dist));*/
			}
			return SearchForBall;
		}
	);

	SearchForBall = MakeShared<FAivState>
	(
		[this](AAIController* AIController)
		{
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			AGameModeBase* GameMode = AIController->GetWorld()->GetAuthGameMode();
			ATagGameGameMode* AIGameMode = Cast<ATagGameGameMode>(GameMode);
			const TArray<ABall*>& BallsList = AIGameMode->GetBalls();

			if (UKismetMathLibrary::RandomBoolWithWeight(Blackboard->GetValueAsFloat(TEXT("BestBallChoiceWeight"))))
			{
				ABall* NearestBall = nullptr;

				for (int32 i = 0; i < BallsList.Num(); i++)
				{
					//searches for the nearest and targetable ball
					if (!BallsList[i]->GetAttachParentActor() &&
						!BallsList[i]->bHasBeenTargetedByEnemy &&
						(!NearestBall ||
							FVector::Distance(AIController->GetPawn()->GetActorLocation(), BallsList[i]->GetActorLocation()) <
							FVector::Distance(AIController->GetPawn()->GetActorLocation(), NearestBall->GetActorLocation())))
					{
						NearestBall = BallsList[i];
					}
				}

				BestBall = NearestBall;

				//UKismetSystemLibrary::PrintString(GetWorld(), "Nearest ball");
			}

			else
			{
				ABall* FurthestBall = nullptr;

				for (int32 i = 0; i < BallsList.Num(); i++)
				{
					//searches for the nearest and targetable ball
					if (!BallsList[i]->GetAttachParentActor() &&
						!BallsList[i]->bHasBeenTargetedByEnemy &&
						(!FurthestBall ||
							FVector::Distance(AIController->GetPawn()->GetActorLocation(), BallsList[i]->GetActorLocation()) >
							FVector::Distance(AIController->GetPawn()->GetActorLocation(), FurthestBall->GetActorLocation())))
					{
						FurthestBall = BallsList[i];
					}
				}

				BestBall = FurthestBall;

				//UKismetSystemLibrary::PrintString(GetWorld(), "Furthest ball");
			}

			if (BestBall)
			{
				BestBall->bHasBeenTargetedByEnemy = true;
			}

			Blackboard->SetValueAsObject(TEXT("BestBall"), BestBall);
		},

		nullptr,

		[this](AAIController* AIController, const float DeltaTime) -> TSharedPtr<FAivState>
		{
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			if (BestBall)
			{
				return GoToBall;
			}

			else
			{
				CurrentState->CallEnter(AIController);  //SearchForBall call enter state
				return SearchForBall;
			}
		}
	);

	GoToBall = MakeShared<FAivState>
	(
		[this](AAIController* AIController)
		{
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));
			AIController->MoveToActor(BestBall, 100);
		},

		nullptr,

		[this](AAIController* AIController, const float DeltaTime) -> TSharedPtr<FAivState>
		{
			EPathFollowingStatus::Type State = AIController->GetMoveStatus();
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			if (State == EPathFollowingStatus::Moving &&
				FVector::Distance(AIController->GetPawn()->GetActorLocation(), BestBall->GetActorLocation()) > 100)
			{
				return nullptr;
			}

			return GrabBall;
		}
	);

	GrabBall = MakeShared<FAivState>
	(
		[this](AAIController* AIController)
		{
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			if (BestBall->GetAttachParentActor())
			{
				BestBall = nullptr;
				Blackboard->SetValueAsObject(TEXT("BestBall"), BestBall);
			}
		},

		nullptr,

		[this](AAIController* AIController, const float DeltaTime) -> TSharedPtr<FAivState>
		{
			ABall* BestBall = Cast<ABall>(Blackboard->GetValueAsObject(TEXT("BestBall")));

			if (!BestBall)
			{
				return SearchForBall;
			}

			BestBall->AttachToComponent(AIController->GetCharacter()->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("ik_hand_r"));
			BestBall->SetActorRelativeLocation(FVector(0, 0, 0));
			Blackboard->SetValueAsObject(TEXT("BestBall"), BestBall);

			return GoToPlayer;
		}
	);

	CurrentState = SearchForBall;
	CurrentState->CallEnter(this);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentState)
	{
		CurrentState = CurrentState->CallTick(this, DeltaTime);
	}
}

AEnemyAIController::AEnemyAIController(FObjectInitializer const& ObjectInitializer)
{
	Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BB_Enemy"));
	ConstructorHelpers::FObjectFinder<UBlackboardData> BB_Enemy(TEXT("/Game/Blueprints/BB_Enemy"));

	if (Blackboard && BB_Enemy.Object)
	{
		Blackboard->InitializeBlackboard(*BB_Enemy.Object);
	}

	Blackboard->SetValueAsFloat(TEXT("BestBallChoiceWeight"), 0.6f);
}