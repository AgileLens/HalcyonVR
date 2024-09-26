// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRInputFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHapticFeedbackEffect_Buffer;
class UHapticFeedbackEffect_Curve;
class UHapticFeedbackEffect_SoundWave;
class USkeletalMesh;
class USkinnedMeshComponent;
enum class EControllerHand : uint8;
enum class EOculusXRBone : uint8;
enum class EOculusXRControllerDrivenHandPoseTypes : uint8;
enum class EOculusXRFinger : uint8;
enum class EOculusXRHandHapticsLocation : uint8;
enum class EOculusXRHandType : uint8;
enum class EOculusXRTrackingConfidence : uint8;
struct FOculusXRCapsuleCollider;
#ifdef OCULUSXRINPUT_OculusXRInputFunctionLibrary_generated_h
#error "OculusXRInputFunctionLibrary.generated.h already included, missing '#pragma once' in OculusXRInputFunctionLibrary.h"
#endif
#define OCULUSXRINPUT_OculusXRInputFunctionLibrary_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_135_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRINPUT_API UScriptStruct* StaticStruct<struct FOculusXRCapsuleCollider>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_RPC_WRAPPERS \
	DECLARE_FUNCTION(execGetControllerDrivenHandPoses); \
	DECLARE_FUNCTION(execSetControllerDrivenHandPoses); \
	DECLARE_FUNCTION(execGetMaxHapticDuration); \
	DECLARE_FUNCTION(execGetControllerSampleRateHz); \
	DECLARE_FUNCTION(execSetHapticsByValue); \
	DECLARE_FUNCTION(execStopHapticEffect); \
	DECLARE_FUNCTION(execPlaySoundWaveHapticEffect); \
	DECLARE_FUNCTION(execPlayAmplitudeEnvelopeHapticEffect); \
	DECLARE_FUNCTION(execPlayBufferHapticEffect); \
	DECLARE_FUNCTION(execPlayCurveHapticEffect); \
	DECLARE_FUNCTION(execGetBoneName); \
	DECLARE_FUNCTION(execIsHandPositionValid); \
	DECLARE_FUNCTION(execIsHandTrackingEnabled); \
	DECLARE_FUNCTION(execGetDominantHand); \
	DECLARE_FUNCTION(execGetHandScale); \
	DECLARE_FUNCTION(execGetFingerTrackingConfidence); \
	DECLARE_FUNCTION(execGetTrackingConfidence); \
	DECLARE_FUNCTION(execIsPointerPoseValid); \
	DECLARE_FUNCTION(execGetPointerPose); \
	DECLARE_FUNCTION(execGetBoneRotation); \
	DECLARE_FUNCTION(execInitializeHandPhysics); \
	DECLARE_FUNCTION(execGetHandSkeletalMesh); \
	DECLARE_FUNCTION(execConvertBoneToFinger);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_INCLASS \
private: \
	static void StaticRegisterNativesUOculusXRInputFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOculusXRInputFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRInput"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRInputFunctionLibrary)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRInputFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRInputFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRInputFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRInputFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRInputFunctionLibrary(UOculusXRInputFunctionLibrary&&); \
	UOculusXRInputFunctionLibrary(const UOculusXRInputFunctionLibrary&); \
public: \
	NO_API virtual ~UOculusXRInputFunctionLibrary();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_145_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_RPC_WRAPPERS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_INCLASS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_148_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRINPUT_API UClass* StaticClass<class UOculusXRInputFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h


#define FOREACH_ENUM_EOCULUSXRHANDTYPE(op) \
	op(EOculusXRHandType::None) \
	op(EOculusXRHandType::HandLeft) \
	op(EOculusXRHandType::HandRight) 

enum class EOculusXRHandType : uint8;
template<> struct TIsUEnumClass<EOculusXRHandType> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRHandType>();

#define FOREACH_ENUM_EOCULUSXRSIDE(op) \
	op(EOculusXRSide::None) \
	op(EOculusXRSide::Left) \
	op(EOculusXRSide::Right) 

enum class EOculusXRSide : uint8;
template<> struct TIsUEnumClass<EOculusXRSide> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRSide>();

#define FOREACH_ENUM_EOCULUSXRTRACKINGCONFIDENCE(op) \
	op(EOculusXRTrackingConfidence::Low) \
	op(EOculusXRTrackingConfidence::High) 

enum class EOculusXRTrackingConfidence : uint8;
template<> struct TIsUEnumClass<EOculusXRTrackingConfidence> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRTrackingConfidence>();

#define FOREACH_ENUM_EOCULUSXRFINGER(op) \
	op(EOculusXRFinger::Thumb) \
	op(EOculusXRFinger::Index) \
	op(EOculusXRFinger::Middle) \
	op(EOculusXRFinger::Ring) \
	op(EOculusXRFinger::Pinky) \
	op(EOculusXRFinger::Invalid) 

enum class EOculusXRFinger : uint8;
template<> struct TIsUEnumClass<EOculusXRFinger> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRFinger>();

#define FOREACH_ENUM_EOCULUSXRBONE(op) \
	op(EOculusXRBone::Wrist_Root) \
	op(EOculusXRBone::Hand_Start) \
	op(EOculusXRBone::Forearm_Stub) \
	op(EOculusXRBone::Thumb_0) \
	op(EOculusXRBone::Thumb_1) \
	op(EOculusXRBone::Thumb_2) \
	op(EOculusXRBone::Thumb_3) \
	op(EOculusXRBone::Index_1) \
	op(EOculusXRBone::Index_2) \
	op(EOculusXRBone::Index_3) \
	op(EOculusXRBone::Middle_1) \
	op(EOculusXRBone::Middle_2) \
	op(EOculusXRBone::Middle_3) \
	op(EOculusXRBone::Ring_1) \
	op(EOculusXRBone::Ring_2) \
	op(EOculusXRBone::Ring_3) \
	op(EOculusXRBone::Pinky_0) \
	op(EOculusXRBone::Pinky_1) \
	op(EOculusXRBone::Pinky_2) \
	op(EOculusXRBone::Pinky_3) \
	op(EOculusXRBone::Thumb_Tip) \
	op(EOculusXRBone::Max_Skinnable) \
	op(EOculusXRBone::Index_Tip) \
	op(EOculusXRBone::Middle_Tip) \
	op(EOculusXRBone::Ring_Tip) \
	op(EOculusXRBone::Pinky_Tip) \
	op(EOculusXRBone::Hand_End) \
	op(EOculusXRBone::Bone_Max) \
	op(EOculusXRBone::Invalid) 

enum class EOculusXRBone : uint8;
template<> struct TIsUEnumClass<EOculusXRBone> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRBone>();

#define FOREACH_ENUM_EOCULUSXRHANDHAPTICSLOCATION(op) \
	op(EOculusXRHandHapticsLocation::Hand) \
	op(EOculusXRHandHapticsLocation::Thumb) \
	op(EOculusXRHandHapticsLocation::Index) \
	op(EOculusXRHandHapticsLocation::HandHapticsLocation_Count) 

enum class EOculusXRHandHapticsLocation : uint8;
template<> struct TIsUEnumClass<EOculusXRHandHapticsLocation> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRHandHapticsLocation>();

#define FOREACH_ENUM_EOCULUSXRCONTROLLERDRIVENHANDPOSETYPES(op) \
	op(EOculusXRControllerDrivenHandPoseTypes::None) \
	op(EOculusXRControllerDrivenHandPoseTypes::Natural) \
	op(EOculusXRControllerDrivenHandPoseTypes::Controller) 

enum class EOculusXRControllerDrivenHandPoseTypes : uint8;
template<> struct TIsUEnumClass<EOculusXRControllerDrivenHandPoseTypes> { enum { Value = true }; };
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRControllerDrivenHandPoseTypes>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
