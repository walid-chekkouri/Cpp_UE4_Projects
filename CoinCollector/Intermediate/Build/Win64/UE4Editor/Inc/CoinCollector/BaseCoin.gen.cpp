// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BaseCoin.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseCoin() {}
// Cross Module References
	COINCOLLECTOR_API UClass* Z_Construct_UClass_ABaseCoin_NoRegister();
	COINCOLLECTOR_API UClass* Z_Construct_UClass_ABaseCoin();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_CoinCollector();
	COINCOLLECTOR_API UFunction* Z_Construct_UFunction_ABaseCoin_OnOverlap();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COINCOLLECTOR_API UFunction* Z_Construct_UFunction_ABaseCoin_PlayCustomDeath();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	static FName NAME_ABaseCoin_OnOverlap = FName(TEXT("OnOverlap"));
	void ABaseCoin::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
	{
		BaseCoin_eventOnOverlap_Parms Parms;
		Parms.OverlappedActor=OverlappedActor;
		Parms.OtherActor=OtherActor;
		ProcessEvent(FindFunctionChecked(NAME_ABaseCoin_OnOverlap),&Parms);
	}
	void ABaseCoin::StaticRegisterNativesABaseCoin()
	{
		UClass* Class = ABaseCoin::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlap", (Native)&ABaseCoin::execOnOverlap },
			{ "PlayCustomDeath", (Native)&ABaseCoin::execPlayCustomDeath },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ABaseCoin_OnOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BaseCoin_eventOnOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor = { UE4CodeGen_Private::EPropertyClass::Object, "OverlappedActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BaseCoin_eventOnOverlap_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OverlappedActor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "BaseCoin.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCoin, "OnOverlap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, sizeof(BaseCoin_eventOnOverlap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABaseCoin_PlayCustomDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "BaseCoin.h" },
				{ "ToolTip", "To call a C++ function from Blueprints" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABaseCoin, "PlayCustomDeath", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABaseCoin_NoRegister()
	{
		return ABaseCoin::StaticClass();
	}
	UClass* Z_Construct_UClass_ABaseCoin()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_CoinCollector,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ABaseCoin_OnOverlap, "OnOverlap" }, // 1848815916
				{ &Z_Construct_UFunction_ABaseCoin_PlayCustomDeath, "PlayCustomDeath" }, // 2160559842
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "BaseCoin.h" },
				{ "ModuleRelativePath", "BaseCoin.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RotationRate_MetaData[] = {
				{ "Category", "BaseCoin" },
				{ "ModuleRelativePath", "BaseCoin.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RotationRate = { UE4CodeGen_Private::EPropertyClass::Float, "RotationRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ABaseCoin, RotationRate), METADATA_PARAMS(NewProp_RotationRate_MetaData, ARRAY_COUNT(NewProp_RotationRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CoinMesh_MetaData[] = {
				{ "Category", "BaseCoin" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "BaseCoin.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CoinMesh = { UE4CodeGen_Private::EPropertyClass::Object, "CoinMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ABaseCoin, CoinMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_CoinMesh_MetaData, ARRAY_COUNT(NewProp_CoinMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
				{ "Category", "BaseCoin" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "BaseCoin.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Root = { UE4CodeGen_Private::EPropertyClass::Object, "Root", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ABaseCoin, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(NewProp_Root_MetaData, ARRAY_COUNT(NewProp_Root_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RotationRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CoinMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Root,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ABaseCoin>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ABaseCoin::StaticClass,
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
	IMPLEMENT_CLASS(ABaseCoin, 1902896923);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABaseCoin(Z_Construct_UClass_ABaseCoin, &ABaseCoin::StaticClass, TEXT("/Script/CoinCollector"), TEXT("ABaseCoin"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABaseCoin);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
