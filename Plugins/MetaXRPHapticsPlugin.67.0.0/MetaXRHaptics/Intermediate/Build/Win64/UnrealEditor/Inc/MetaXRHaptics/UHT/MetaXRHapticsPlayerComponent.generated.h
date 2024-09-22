// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MetaXRHapticsPlayerComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMetaXRHapticClip;
enum class EMetaXRHapticController : uint8;
#ifdef METAXRHAPTICS_MetaXRHapticsPlayerComponent_generated_h
#error "MetaXRHapticsPlayerComponent.generated.h already included, missing '#pragma once' in MetaXRHapticsPlayerComponent.h"
#endif
#define METAXRHAPTICS_MetaXRHapticsPlayerComponent_generated_h

#define FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetClipDuration); \
	DECLARE_FUNCTION(execGetLooping); \
	DECLARE_FUNCTION(execSetLooping); \
	DECLARE_FUNCTION(execGetFrequencyShift); \
	DECLARE_FUNCTION(execSetFrequencyShift); \
	DECLARE_FUNCTION(execGetAmplitude); \
	DECLARE_FUNCTION(execSetAmplitude); \
	DECLARE_FUNCTION(execGetPriority); \
	DECLARE_FUNCTION(execSetPriority); \
	DECLARE_FUNCTION(execSetController); \
	DECLARE_FUNCTION(execGetController); \
	DECLARE_FUNCTION(execSetHapticClip); \
	DECLARE_FUNCTION(execGetHapticClip); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execPlayWithInputs); \
	DECLARE_FUNCTION(execPlayOnController); \
	DECLARE_FUNCTION(execPlay);


#define FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMetaXRHapticsPlayerComponent(); \
	friend struct Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics; \
public: \
	DECLARE_CLASS(UMetaXRHapticsPlayerComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MetaXRHaptics"), NO_API) \
	DECLARE_SERIALIZER(UMetaXRHapticsPlayerComponent)


#define FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMetaXRHapticsPlayerComponent(UMetaXRHapticsPlayerComponent&&); \
	UMetaXRHapticsPlayerComponent(const UMetaXRHapticsPlayerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMetaXRHapticsPlayerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMetaXRHapticsPlayerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMetaXRHapticsPlayerComponent) \
	NO_API virtual ~UMetaXRHapticsPlayerComponent();


#define FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_47_PROLOG
#define FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_INCLASS_NO_PURE_DECLS \
	FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> METAXRHAPTICS_API UClass* StaticClass<class UMetaXRHapticsPlayerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h


#define FOREACH_ENUM_EMETAXRHAPTICCONTROLLER(op) \
	op(EMetaXRHapticController::Left) \
	op(EMetaXRHapticController::Right) \
	op(EMetaXRHapticController::Both) 

enum class EMetaXRHapticController : uint8;
template<> struct TIsUEnumClass<EMetaXRHapticController> { enum { Value = true }; };
template<> METAXRHAPTICS_API UEnum* StaticEnum<EMetaXRHapticController>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
