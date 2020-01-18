// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef COINCOLLECTOR_BaseCoin_generated_h
#error "BaseCoin.generated.h already included, missing '#pragma once' in BaseCoin.h"
#endif
#define COINCOLLECTOR_BaseCoin_generated_h

#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_RPC_WRAPPERS \
	virtual void OnOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor); \
 \
	DECLARE_FUNCTION(execOnOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlap_Implementation(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayCustomDeath) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlayCustomDeath(); \
		P_NATIVE_END; \
	}


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnOverlap_Implementation(AActor* OverlappedActor, AActor* OtherActor); \
 \
	DECLARE_FUNCTION(execOnOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnOverlap_Implementation(Z_Param_OverlappedActor,Z_Param_OtherActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayCustomDeath) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PlayCustomDeath(); \
		P_NATIVE_END; \
	}


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_EVENT_PARMS \
	struct BaseCoin_eventOnOverlap_Parms \
	{ \
		AActor* OverlappedActor; \
		AActor* OtherActor; \
	};


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_CALLBACK_WRAPPERS
#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABaseCoin(); \
	friend COINCOLLECTOR_API class UClass* Z_Construct_UClass_ABaseCoin(); \
public: \
	DECLARE_CLASS(ABaseCoin, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CoinCollector"), NO_API) \
	DECLARE_SERIALIZER(ABaseCoin) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_INCLASS \
private: \
	static void StaticRegisterNativesABaseCoin(); \
	friend COINCOLLECTOR_API class UClass* Z_Construct_UClass_ABaseCoin(); \
public: \
	DECLARE_CLASS(ABaseCoin, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CoinCollector"), NO_API) \
	DECLARE_SERIALIZER(ABaseCoin) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseCoin(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseCoin) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCoin); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCoin); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCoin(ABaseCoin&&); \
	NO_API ABaseCoin(const ABaseCoin&); \
public:


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABaseCoin(ABaseCoin&&); \
	NO_API ABaseCoin(const ABaseCoin&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCoin); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCoin); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseCoin)


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_PRIVATE_PROPERTY_OFFSET
#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_10_PROLOG \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_EVENT_PARMS


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_PRIVATE_PROPERTY_OFFSET \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_RPC_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_CALLBACK_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_INCLASS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_PRIVATE_PROPERTY_OFFSET \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_CALLBACK_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_INCLASS_NO_PURE_DECLS \
	CoinCollectorStarter_Source_CoinCollector_BaseCoin_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CoinCollectorStarter_Source_CoinCollector_BaseCoin_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
