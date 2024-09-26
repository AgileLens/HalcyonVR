// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRPersistentPassthroughInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOculusXRStereoLayerShapeReconstructed;
#ifdef OCULUSXRPASSTHROUGH_OculusXRPersistentPassthroughInstance_generated_h
#error "OculusXRPersistentPassthroughInstance.generated.h already included, missing '#pragma once' in OculusXRPersistentPassthroughInstance.h"
#endif
#define OCULUSXRPASSTHROUGH_OculusXRPersistentPassthroughInstance_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_15_DELEGATE \
OCULUSXRPASSTHROUGH_API void FOculusXRPassthrough_LayerResumed_Single_DelegateWrapper(const FScriptDelegate& OculusXRPassthrough_LayerResumed_Single);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRPASSTHROUGH_API UScriptStruct* StaticStruct<struct FOculusXRPersistentPassthroughParameters>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAnyLayerResumedEvent); \
	DECLARE_FUNCTION(execGetShape); \
	DECLARE_FUNCTION(execGetPriority); \
	DECLARE_FUNCTION(execSetPriority); \
	DECLARE_FUNCTION(execIsVisible); \
	DECLARE_FUNCTION(execSetVisible);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRPersistentPassthroughInstance(); \
	friend struct Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics; \
public: \
	DECLARE_CLASS(UOculusXRPersistentPassthroughInstance, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRPassthrough"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRPersistentPassthroughInstance)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRPersistentPassthroughInstance(UOculusXRPersistentPassthroughInstance&&); \
	UOculusXRPersistentPassthroughInstance(const UOculusXRPersistentPassthroughInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRPersistentPassthroughInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRPersistentPassthroughInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRPersistentPassthroughInstance) \
	NO_API virtual ~UOculusXRPersistentPassthroughInstance();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_99_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_102_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRPASSTHROUGH_API UClass* StaticClass<class UOculusXRPersistentPassthroughInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
