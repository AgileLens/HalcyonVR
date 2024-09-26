// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRMR_Settings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EOculusXRMR_CameraDeviceEnum : uint8;
enum class EOculusXRMR_CompositionMethod : uint8;
#ifdef OCULUSXRMR_OculusXRMR_Settings_generated_h
#error "OculusXRMR_Settings.generated.h already included, missing '#pragma once' in OculusXRMR_Settings.h"
#endif
#define OCULUSXRMR_OculusXRMR_Settings_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSaveToIni); \
	DECLARE_FUNCTION(execLoadFromIni); \
	DECLARE_FUNCTION(execGetBindToTrackedCameraIndex); \
	DECLARE_FUNCTION(execBindToTrackedCameraIndexIfAvailable); \
	DECLARE_FUNCTION(execSetIsCasting); \
	DECLARE_FUNCTION(execGetIsCasting); \
	DECLARE_FUNCTION(execSetCapturingCamera); \
	DECLARE_FUNCTION(execGetCapturingCamera); \
	DECLARE_FUNCTION(execSetCompositionMethod); \
	DECLARE_FUNCTION(execGetCompositionMethod);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRMR_Settings(); \
	friend struct Z_Construct_UClass_UOculusXRMR_Settings_Statics; \
public: \
	DECLARE_CLASS(UOculusXRMR_Settings, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRMR"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRMR_Settings)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRMR_Settings(UOculusXRMR_Settings&&); \
	UOculusXRMR_Settings(const UOculusXRMR_Settings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRMR_Settings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRMR_Settings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRMR_Settings) \
	NO_API virtual ~UOculusXRMR_Settings();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_40_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_43_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRMR_API UClass* StaticClass<class UOculusXRMR_Settings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h


#define FOREACH_ENUM_EOCULUSXRMR_CAMERADEVICEENUM(op) \
	op(EOculusXRMR_CameraDeviceEnum::CD_None_DEPRECATED) \
	op(EOculusXRMR_CameraDeviceEnum::CD_WebCamera0_DEPRECATED) \
	op(EOculusXRMR_CameraDeviceEnum::CD_WebCamera1_DEPRECATED) 

enum class EOculusXRMR_CameraDeviceEnum : uint8;
template<> struct TIsUEnumClass<EOculusXRMR_CameraDeviceEnum> { enum { Value = true }; };
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_CameraDeviceEnum>();

#define FOREACH_ENUM_EOCULUSXRMR_CLIPPINGREFERENCE(op) \
	op(EOculusXRMR_ClippingReference::CR_TrackingReference) \
	op(EOculusXRMR_ClippingReference::CR_Head) 

enum class EOculusXRMR_ClippingReference : uint8;
template<> struct TIsUEnumClass<EOculusXRMR_ClippingReference> { enum { Value = true }; };
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_ClippingReference>();

#define FOREACH_ENUM_EOCULUSXRMR_POSTPROCESSEFFECTS(op) \
	op(EOculusXRMR_PostProcessEffects::PPE_Off) \
	op(EOculusXRMR_PostProcessEffects::PPE_On) 

enum class EOculusXRMR_PostProcessEffects : uint8;
template<> struct TIsUEnumClass<EOculusXRMR_PostProcessEffects> { enum { Value = true }; };
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_PostProcessEffects>();

#define FOREACH_ENUM_EOCULUSXRMR_COMPOSITIONMETHOD(op) \
	op(EOculusXRMR_CompositionMethod::ExternalComposition) \
	op(EOculusXRMR_CompositionMethod::DirectComposition_DEPRECATED) 

enum class EOculusXRMR_CompositionMethod : uint8;
template<> struct TIsUEnumClass<EOculusXRMR_CompositionMethod> { enum { Value = true }; };
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_CompositionMethod>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
