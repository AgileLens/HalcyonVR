// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRHMDRuntimeSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRHMD_OculusXRHMDRuntimeSettings_generated_h
#error "OculusXRHMDRuntimeSettings.generated.h already included, missing '#pragma once' in OculusXRHMDRuntimeSettings.h"
#endif
#define OCULUSXRHMD_OculusXRHMDRuntimeSettings_generated_h

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_27_INCLASS \
private: \
	static void StaticRegisterNativesUOculusXRHMDRuntimeSettings(); \
	friend struct Z_Construct_UClass_UOculusXRHMDRuntimeSettings_Statics; \
public: \
	DECLARE_CLASS(UOculusXRHMDRuntimeSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/OculusXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRHMDRuntimeSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRHMDRuntimeSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRHMDRuntimeSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRHMDRuntimeSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRHMDRuntimeSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRHMDRuntimeSettings(UOculusXRHMDRuntimeSettings&&); \
	UOculusXRHMDRuntimeSettings(const UOculusXRHMDRuntimeSettings&); \
public: \
	NO_API virtual ~UOculusXRHMDRuntimeSettings();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_24_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_27_INCLASS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRHMD_API UClass* StaticClass<class UOculusXRHMDRuntimeSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDRuntimeSettings_h


#define FOREACH_ENUM_EOCULUSXRSUPPORTEDDEVICES(op) \
	op(EOculusXRSupportedDevices::Quest2) \
	op(EOculusXRSupportedDevices::QuestPro) \
	op(EOculusXRSupportedDevices::Quest3) 

enum class EOculusXRSupportedDevices : uint8;
template<> struct TIsUEnumClass<EOculusXRSupportedDevices> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRSupportedDevices>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
