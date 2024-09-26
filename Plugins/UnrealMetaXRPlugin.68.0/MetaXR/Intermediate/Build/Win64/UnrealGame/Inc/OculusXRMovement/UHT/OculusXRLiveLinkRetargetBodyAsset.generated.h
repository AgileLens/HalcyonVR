// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRLiveLinkRetargetBodyAsset.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRMOVEMENT_OculusXRLiveLinkRetargetBodyAsset_generated_h
#error "OculusXRLiveLinkRetargetBodyAsset.generated.h already included, missing '#pragma once' in OculusXRLiveLinkRetargetBodyAsset.h"
#endif
#define OCULUSXRMOVEMENT_OculusXRLiveLinkRetargetBodyAsset_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_37_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBoneCorrection>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_58_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBoneCorrectionSet>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_78_INCLASS \
private: \
	static void StaticRegisterNativesUOculusXRLiveLinkRetargetBodyAsset(); \
	friend struct Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics; \
public: \
	DECLARE_CLASS(UOculusXRLiveLinkRetargetBodyAsset, ULiveLinkRetargetAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRMovement"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRLiveLinkRetargetBodyAsset)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_78_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRLiveLinkRetargetBodyAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRLiveLinkRetargetBodyAsset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRLiveLinkRetargetBodyAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRLiveLinkRetargetBodyAsset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRLiveLinkRetargetBodyAsset(UOculusXRLiveLinkRetargetBodyAsset&&); \
	UOculusXRLiveLinkRetargetBodyAsset(const UOculusXRLiveLinkRetargetBodyAsset&); \
public: \
	NO_API virtual ~UOculusXRLiveLinkRetargetBodyAsset();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_75_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_78_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_78_INCLASS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_78_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRMOVEMENT_API UClass* StaticClass<class UOculusXRLiveLinkRetargetBodyAsset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h


#define FOREACH_ENUM_EOCULUSXRAXIS(op) \
	op(EOculusXRAxis::X) \
	op(EOculusXRAxis::Y) \
	op(EOculusXRAxis::Z) \
	op(EOculusXRAxis::NegativeX) \
	op(EOculusXRAxis::NegativeY) \
	op(EOculusXRAxis::NegativeZ) 

enum class EOculusXRAxis : uint8;
template<> struct TIsUEnumClass<EOculusXRAxis> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRAxis>();

#define FOREACH_ENUM_EOCULUSXRRETARGETINGMODE(op) \
	op(EOculusXRRetargetingMode::Full) \
	op(EOculusXRRetargetingMode::Rotations) \
	op(EOculusXRRetargetingMode::RotationsPlusRoot) \
	op(EOculusXRRetargetingMode::RotationsPlusHips) \
	op(EOculusXRRetargetingMode::None) 

enum class EOculusXRRetargetingMode : uint8;
template<> struct TIsUEnumClass<EOculusXRRetargetingMode> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRRetargetingMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
