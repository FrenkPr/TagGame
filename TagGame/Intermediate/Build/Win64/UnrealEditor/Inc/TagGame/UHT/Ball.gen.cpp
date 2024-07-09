// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TagGame/Ball.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBall() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	TAGGAME_API UClass* Z_Construct_UClass_ABall();
	TAGGAME_API UClass* Z_Construct_UClass_ABall_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TagGame();
// End Cross Module References
	void ABall::StaticRegisterNativesABall()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABall);
	UClass* Z_Construct_UClass_ABall_NoRegister()
	{
		return ABall::StaticClass();
	}
	struct Z_Construct_UClass_ABall_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BallMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BallMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bHasBeenTargetedByEnemy_MetaData[];
#endif
		static void NewProp_bHasBeenTargetedByEnemy_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasBeenTargetedByEnemy;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABall_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TagGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Ball.h" },
		{ "ModuleRelativePath", "Ball.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::NewProp_BallMesh_MetaData[] = {
		{ "Category", "Ball" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sets default values for this actor's properties\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Ball.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets default values for this actor's properties" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABall_Statics::NewProp_BallMesh = { "BallMesh", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABall, BallMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::NewProp_BallMesh_MetaData), Z_Construct_UClass_ABall_Statics::NewProp_BallMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy_MetaData[] = {
		{ "Category", "Ball" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// if a ball has already been targeted by an enemy\n" },
#endif
		{ "ModuleRelativePath", "Ball.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if a ball has already been targeted by an enemy" },
#endif
	};
#endif
	void Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy_SetBit(void* Obj)
	{
		((ABall*)Obj)->bHasBeenTargetedByEnemy = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy = { "bHasBeenTargetedByEnemy", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABall), &Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy_MetaData), Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABall_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABall_Statics::NewProp_BallMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABall_Statics::NewProp_bHasBeenTargetedByEnemy,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABall_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABall>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABall_Statics::ClassParams = {
		&ABall::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABall_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::Class_MetaDataParams), Z_Construct_UClass_ABall_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABall()
	{
		if (!Z_Registration_Info_UClass_ABall.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABall.OuterSingleton, Z_Construct_UClass_ABall_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABall.OuterSingleton;
	}
	template<> TAGGAME_API UClass* StaticClass<ABall>()
	{
		return ABall::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABall);
	ABall::~ABall() {}
	struct Z_CompiledInDeferFile_FID_Users_fmoch_OneDrive_Documenti_Unreal_Projects_C___TagGame_Source_TagGame_Ball_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_fmoch_OneDrive_Documenti_Unreal_Projects_C___TagGame_Source_TagGame_Ball_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABall, ABall::StaticClass, TEXT("ABall"), &Z_Registration_Info_UClass_ABall, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABall), 1162983841U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_fmoch_OneDrive_Documenti_Unreal_Projects_C___TagGame_Source_TagGame_Ball_h_1868402481(TEXT("/Script/TagGame"),
		Z_CompiledInDeferFile_FID_Users_fmoch_OneDrive_Documenti_Unreal_Projects_C___TagGame_Source_TagGame_Ball_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_fmoch_OneDrive_Documenti_Unreal_Projects_C___TagGame_Source_TagGame_Ball_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
