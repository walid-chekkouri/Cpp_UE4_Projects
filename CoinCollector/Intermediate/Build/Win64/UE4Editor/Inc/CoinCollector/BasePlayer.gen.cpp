// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BasePlayer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasePlayer() {}
// Cross Module References
	COINCOLLECTOR_API UClass* Z_Construct_UClass_ABasePlayer_NoRegister();
	COINCOLLECTOR_API UClass* Z_Construct_UClass_ABasePlayer();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_CoinCollector();
	COINCOLLECTOR_API UFunction* Z_Construct_UFunction_ABasePlayer_Jump();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	static FName NAME_ABasePlayer_Jump = FName(TEXT("Jump"));
	void ABasePlayer::Jump()
	{
		ProcessEvent(FindFunctionChecked(NAME_ABasePlayer_Jump),NULL);
	}
	void ABasePlayer::StaticRegisterNativesABasePlayer()
	{
	}
	UFunction* Z_Construct_UFunction_ABasePlayer_Jump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "BasePlayer.h" },
				{ "ToolTip", "BlueprintImplementableEvent will allow Blueprints to implement Jump().\nIf there is no implementation, any calls to Jump() will do nothing.\nNB:If you want to provide a default implementation in C++, use BlueprintNativeEvent instead !!\nNB:An override will be an event if there is no return type. If there is a return type, it will be a function" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasePlayer, "Jump", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABasePlayer_NoRegister()
	{
		return ABasePlayer::StaticClass();
	}
	UClass* Z_Construct_UClass_ABasePlayer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APawn,
				(UObject* (*)())Z_Construct_UPackage__Script_CoinCollector,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ABasePlayer_Jump, "Jump" }, // 3651069429
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "BasePlayer.h" },
				{ "ModuleRelativePath", "BasePlayer.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpImpulse_MetaData[] = {
				{ "Category", "BasePlayer" },
				{ "ModuleRelativePath", "BasePlayer.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpImpulse = { UE4CodeGen_Private::EPropertyClass::Float, "JumpImpulse", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABasePlayer, JumpImpulse), METADATA_PARAMS(NewProp_JumpImpulse_MetaData, ARRAY_COUNT(NewProp_JumpImpulse_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementForce_MetaData[] = {
				{ "Category", "BasePlayer" },
				{ "ModuleRelativePath", "BasePlayer.h" },
				{ "ToolTip", "BlueprintReadWrite will allow you to set and read MovementForce using Blueprint nodes." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementForce = { UE4CodeGen_Private::EPropertyClass::Float, "MovementForce", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABasePlayer, MovementForce), METADATA_PARAMS(NewProp_MovementForce_MetaData, ARRAY_COUNT(NewProp_MovementForce_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
				{ "Category", "BasePlayer" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "BasePlayer.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Camera = { UE4CodeGen_Private::EPropertyClass::Object, "Camera", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ABasePlayer, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_Camera_MetaData, ARRAY_COUNT(NewProp_Camera_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
				{ "Category", "BasePlayer" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "BasePlayer.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm = { UE4CodeGen_Private::EPropertyClass::Object, "SpringArm", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ABasePlayer, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_SpringArm_MetaData, ARRAY_COUNT(NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
				{ "Category", "BasePlayer" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "BasePlayer.h" },
				{ "ToolTip", "-VisibleAnywhere will allow each component to be visible within the editor (including Blueprints).\n       -BlueprintReadOnly will allow you to get a reference to the component using Blueprint nodes.However,\n       it will not allow you to set the component.It is important for components to be read - only because their variables are pointers.\n       You do not want to allow users to set this otherwise they could point to a random location in memory.\n       Note that BlueprintReadOnly will still allow you to set variables inside of the component, which is the desired behavior.//-NOTE:Note: For non - pointer variables(int, float, boolean etc.), use EditAnywhereand BlueprintReadWrite instead." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ABasePlayer, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_Mesh_MetaData, ARRAY_COUNT(NewProp_Mesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_JumpImpulse,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MovementForce,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Camera,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpringArm,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Mesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ABasePlayer>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ABasePlayer::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABasePlayer, 1015332475);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasePlayer(Z_Construct_UClass_ABasePlayer, &ABasePlayer::StaticClass, TEXT("/Script/CoinCollector"), TEXT("ABasePlayer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasePlayer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
