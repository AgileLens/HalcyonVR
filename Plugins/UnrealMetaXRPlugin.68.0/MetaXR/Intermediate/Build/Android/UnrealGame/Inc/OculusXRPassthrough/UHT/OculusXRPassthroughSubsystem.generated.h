// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRPassthroughSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOculusXRPersistentPassthroughInstance;
struct FOculusXRPersistentPassthroughParameters;
#ifdef OCULUSXRPASSTHROUGH_OculusXRPassthroughSubsystem_generated_h
#error "OculusXRPassthroughSubsystem.generated.h already included, missing '#pragma once' in OculusXRPassthroughSubsystem.h"
#endif
#define OCULUSXRPASSTHROUGH_OculusXRPassthroughSubsystem_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_11_DELEGATE \
OCULUSXRPASSTHROUGH_API void FOculusXRPassthrough_AnyLayerResumed_DelegateWrapper(const FMulticastScriptDelegate& OculusXRPassthrough_AnyLayerResumed, int32 LayerID);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPersistentPassthrough); \
	DECLARE_FUNCTION(execDestroyPersistentPassthrough); \
	DECLARE_FUNCTION(execInitializePersistentPassthrough);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRPassthroughSubsystem(); \
	friend struct Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics; \
public: \
	DECLARE_CLASS(UOculusXRPassthroughSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRPassthrough"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRPassthroughSubsystem)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRPassthroughSubsystem(UOculusXRPassthroughSubsystem&&); \
	UOculusXRPassthroughSubsystem(const UOculusXRPassthroughSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRPassthroughSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRPassthroughSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOculusXRPassthroughSubsystem) \
	NO_API virtual ~UOculusXRPassthroughSubsystem();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_13_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRPASSTHROUGH_API UClass* StaticClass<class UOculusXRPassthroughSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
