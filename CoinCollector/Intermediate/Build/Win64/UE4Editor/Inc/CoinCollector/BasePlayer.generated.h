// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COINCOLLECTOR_BasePlayer_generated_h
#error "BasePlayer.generated.h already included, missing '#pragma once' in BasePlayer.h"
#endif
#define COINCOLLECTOR_BasePlayer_generated_h

#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_RPC_WRAPPERS
#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_EVENT_PARMS
#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_CALLBACK_WRAPPERS
#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABasePlayer(); \
	friend COINCOLLECTOR_API class UClass* Z_Construct_UClass_ABasePlayer(); \
public: \
	DECLARE_CLASS(ABasePlayer, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CoinCollector"), NO_API) \
	DECLARE_SERIALIZER(ABasePlayer) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_INCLASS \
private: \
	static void StaticRegisterNativesABasePlayer(); \
	friend COINCOLLECTOR_API class UClass* Z_Construct_UClass_ABasePlayer(); \
public: \
	DECLARE_CLASS(ABasePlayer, APawn, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/CoinCollector"), NO_API) \
	DECLARE_SERIALIZER(ABasePlayer) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABasePlayer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABasePlayer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePlayer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasePlayer(ABasePlayer&&); \
	NO_API ABasePlayer(const ABasePlayer&); \
public:


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasePlayer(ABasePlayer&&); \
	NO_API ABasePlayer(const ABasePlayer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasePlayer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasePlayer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasePlayer)


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_PRIVATE_PROPERTY_OFFSET
#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_12_PROLOG \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_EVENT_PARMS


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_RPC_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_CALLBACK_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_INCLASS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_PRIVATE_PROPERTY_OFFSET \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_CALLBACK_WRAPPERS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_INCLASS_NO_PURE_DECLS \
	CoinCollectorStarter_Source_CoinCollector_BasePlayer_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CoinCollectorStarter_Source_CoinCollector_BasePlayer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
