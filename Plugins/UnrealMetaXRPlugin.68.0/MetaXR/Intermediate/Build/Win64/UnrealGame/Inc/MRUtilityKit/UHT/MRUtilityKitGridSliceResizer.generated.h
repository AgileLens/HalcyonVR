// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitGridSliceResizer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MRUTILITYKIT_MRUtilityKitGridSliceResizer_generated_h
#error "MRUtilityKitGridSliceResizer.generated.h already included, missing '#pragma once' in MRUtilityKitGridSliceResizer.h"
#endif
#define MRUTILITYKIT_MRUtilityKitGridSliceResizer_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSliceMesh);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMRUKGridSliceResizerComponent(); \
	friend struct Z_Construct_UClass_UMRUKGridSliceResizerComponent_Statics; \
public: \
	DECLARE_CLASS(UMRUKGridSliceResizerComponent, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(UMRUKGridSliceResizerComponent)


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMRUKGridSliceResizerComponent(UMRUKGridSliceResizerComponent&&); \
	UMRUKGridSliceResizerComponent(const UMRUKGridSliceResizerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMRUKGridSliceResizerComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMRUKGridSliceResizerComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMRUKGridSliceResizerComponent) \
	NO_API virtual ~UMRUKGridSliceResizerComponent();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_63_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h_66_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class UMRUKGridSliceResizerComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGridSliceResizer_h


#define FOREACH_ENUM_EMRUKSCALECENTERMODE(op) \
	op(EMRUKScaleCenterMode::None) \
	op(EMRUKScaleCenterMode::XAxis) \
	op(EMRUKScaleCenterMode::YAxis) \
	op(EMRUKScaleCenterMode::ZAxis) 

enum class EMRUKScaleCenterMode : uint8;
template<> struct TIsUEnumClass<EMRUKScaleCenterMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKScaleCenterMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
