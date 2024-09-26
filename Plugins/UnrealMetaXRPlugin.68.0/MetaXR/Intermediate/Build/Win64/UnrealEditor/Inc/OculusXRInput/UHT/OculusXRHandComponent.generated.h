// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRHandComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRINPUT_OculusXRHandComponent_generated_h
#error "OculusXRHandComponent.generated.h already included, missing '#pragma once' in OculusXRHandComponent.h"
#endif
#define OCULUSXRINPUT_OculusXRHandComponent_generated_h

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_28_INCLASS \
private: \
	static void StaticRegisterNativesUOculusXRHandComponent(); \
	friend struct Z_Construct_UClass_UOculusXRHandComponent_Statics; \
public: \
	DECLARE_CLASS(UOculusXRHandComponent, UPoseableMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OculusXRInput"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRHandComponent)


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRHandComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRHandComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRHandComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRHandComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRHandComponent(UOculusXRHandComponent&&); \
	UOculusXRHandComponent(const UOculusXRHandComponent&); \
public: \
	NO_API virtual ~UOculusXRHandComponent();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_25_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_28_INCLASS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRINPUT_API UClass* StaticClass<class UOculusXRHandComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRHandComponent_h


#define FOREACH_ENUM_EOCULUSXRCONFIDENCEBEHAVIOR(op) \
	op(EOculusXRConfidenceBehavior::None) \
	op(EOculusXRConfidenceBehavior::HideActor) 

enum class EOculusXRConfidenceBehavior : uint8;
template<> struct TIsUEnumClass<EOculusXRConfidenceBehavior> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRConfidenceBehavior>();

#define FOREACH_ENUM_EOCULUSXRSYSTEMGESTUREBEHAVIOR(op) \
	op(EOculusXRSystemGestureBehavior::None) \
	op(EOculusXRSystemGestureBehavior::SwapMaterial) 

enum class EOculusXRSystemGestureBehavior : uint8;
template<> struct TIsUEnumClass<EOculusXRSystemGestureBehavior> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRSystemGestureBehavior>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
