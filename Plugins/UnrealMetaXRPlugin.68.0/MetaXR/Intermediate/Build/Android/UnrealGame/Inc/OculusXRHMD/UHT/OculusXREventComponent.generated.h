// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXREventComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRHMD_OculusXREventComponent_generated_h
#error "OculusXREventComponent.generated.h already included, missing '#pragma once' in OculusXREventComponent.h"
#endif
#define OCULUSXRHMD_OculusXREventComponent_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_18_DELEGATE \
static void FOculusDisplayRefreshRateChangedEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& OculusDisplayRefreshRateChangedEventDelegate, float fromRefreshRate, float toRefreshRate);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_19_DELEGATE \
static void FOculusEyeTrackingStateChangedEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& OculusEyeTrackingStateChangedEventDelegate, bool bEyeTrackingOn);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXREventComponent(); \
	friend struct Z_Construct_UClass_UOculusXREventComponent_Statics; \
public: \
	DECLARE_CLASS(UOculusXREventComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OculusXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UOculusXREventComponent)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXREventComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXREventComponent(UOculusXREventComponent&&); \
	UOculusXREventComponent(const UOculusXREventComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXREventComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXREventComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXREventComponent) \
	NO_API virtual ~UOculusXREventComponent();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_12_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRHMD_API UClass* StaticClass<class UOculusXREventComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
