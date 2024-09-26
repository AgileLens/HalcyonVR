// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRHMDTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRHMD_OculusXRHMDTypes_generated_h
#error "OculusXRHMDTypes.generated.h already included, missing '#pragma once' in OculusXRHMDTypes.h"
#endif
#define OCULUSXRHMD_OculusXRHMDTypes_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_30_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics; \
	OCULUSXRHMD_API static class UScriptStruct* StaticStruct();


template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<struct FOculusXRHmdUserProfileField>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_46_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics; \
	OCULUSXRHMD_API static class UScriptStruct* StaticStruct();


template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<struct FOculusXRHmdUserProfile>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_213_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics; \
	OCULUSXRHMD_API static class UScriptStruct* StaticStruct();


template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<struct FOculusXRGuardianTestResult>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_249_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics; \
	OCULUSXRHMD_API static class UScriptStruct* StaticStruct();


template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<struct FOculusXRSplashDesc>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_366_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics; \
	OCULUSXRHMD_API static class UScriptStruct* StaticStruct();


template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<struct FOculusXRPerformanceMetrics>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h


#define FOREACH_ENUM_EOCULUSXRTRACKEDDEVICETYPE(op) \
	op(EOculusXRTrackedDeviceType::None) \
	op(EOculusXRTrackedDeviceType::HMD) \
	op(EOculusXRTrackedDeviceType::LTouch) \
	op(EOculusXRTrackedDeviceType::RTouch) \
	op(EOculusXRTrackedDeviceType::Touch) \
	op(EOculusXRTrackedDeviceType::DeviceObjectZero) \
	op(EOculusXRTrackedDeviceType::All) 

enum class EOculusXRTrackedDeviceType : uint8;
template<> struct TIsUEnumClass<EOculusXRTrackedDeviceType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRTrackedDeviceType>();

#define FOREACH_ENUM_EOCULUSXRFOVEATEDRENDERINGMETHOD(op) \
	op(EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering) \
	op(EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering) 

enum class EOculusXRFoveatedRenderingMethod : uint8;
template<> struct TIsUEnumClass<EOculusXRFoveatedRenderingMethod> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRFoveatedRenderingMethod>();

#define FOREACH_ENUM_EOCULUSXRFOVEATEDRENDERINGLEVEL(op) \
	op(EOculusXRFoveatedRenderingLevel::Off) \
	op(EOculusXRFoveatedRenderingLevel::Low) \
	op(EOculusXRFoveatedRenderingLevel::Medium) \
	op(EOculusXRFoveatedRenderingLevel::High) \
	op(EOculusXRFoveatedRenderingLevel::HighTop) 

enum class EOculusXRFoveatedRenderingLevel : uint8;
template<> struct TIsUEnumClass<EOculusXRFoveatedRenderingLevel> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRFoveatedRenderingLevel>();

#define FOREACH_ENUM_EOCULUSXRBOUNDARYTYPE(op) \
	op(EOculusXRBoundaryType::Boundary_Outer) \
	op(EOculusXRBoundaryType::Boundary_PlayArea) 

enum class EOculusXRBoundaryType : uint8;
template<> struct TIsUEnumClass<EOculusXRBoundaryType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRBoundaryType>();

#define FOREACH_ENUM_EOCULUSXRCOLORSPACE(op) \
	op(EOculusXRColorSpace::Unknown) \
	op(EOculusXRColorSpace::Unmanaged) \
	op(EOculusXRColorSpace::Rec_2020) \
	op(EOculusXRColorSpace::Rec_709) \
	op(EOculusXRColorSpace::Rift_CV1) \
	op(EOculusXRColorSpace::Rift_S) \
	op(EOculusXRColorSpace::Quest) \
	op(EOculusXRColorSpace::P3) \
	op(EOculusXRColorSpace::Adobe_RGB) 

enum class EOculusXRColorSpace : uint8;
template<> struct TIsUEnumClass<EOculusXRColorSpace> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRColorSpace>();

#define FOREACH_ENUM_EOCULUSXRHANDTRACKINGSUPPORT(op) \
	op(EOculusXRHandTrackingSupport::ControllersOnly) \
	op(EOculusXRHandTrackingSupport::ControllersAndHands) \
	op(EOculusXRHandTrackingSupport::HandsOnly) 

enum class EOculusXRHandTrackingSupport : uint8;
template<> struct TIsUEnumClass<EOculusXRHandTrackingSupport> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingSupport>();

#define FOREACH_ENUM_EOCULUSXRHANDTRACKINGFREQUENCY(op) \
	op(EOculusXRHandTrackingFrequency::LOW) \
	op(EOculusXRHandTrackingFrequency::HIGH) 

enum class EOculusXRHandTrackingFrequency : uint8;
template<> struct TIsUEnumClass<EOculusXRHandTrackingFrequency> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingFrequency>();

#define FOREACH_ENUM_EOCULUSXRHANDTRACKINGVERSION(op) \
	op(EOculusXRHandTrackingVersion::Default) \
	op(EOculusXRHandTrackingVersion::V1) \
	op(EOculusXRHandTrackingVersion::V2) 

enum class EOculusXRHandTrackingVersion : uint8;
template<> struct TIsUEnumClass<EOculusXRHandTrackingVersion> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingVersion>();

#define FOREACH_ENUM_EOCULUSXRPROCESSORPERFORMANCELEVEL(op) \
	op(EOculusXRProcessorPerformanceLevel::PowerSavings) \
	op(EOculusXRProcessorPerformanceLevel::SustainedLow) \
	op(EOculusXRProcessorPerformanceLevel::SustainedHigh) \
	op(EOculusXRProcessorPerformanceLevel::Boost) 

enum class EOculusXRProcessorPerformanceLevel : uint8;
template<> struct TIsUEnumClass<EOculusXRProcessorPerformanceLevel> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRProcessorPerformanceLevel>();

#define FOREACH_ENUM_EOCULUSXRDEVICETYPE(op) \
	op(EOculusXRDeviceType::OculusMobile_Deprecated0) \
	op(EOculusXRDeviceType::OculusQuest_Deprecated) \
	op(EOculusXRDeviceType::OculusQuest2) \
	op(EOculusXRDeviceType::MetaQuestPro) \
	op(EOculusXRDeviceType::MetaQuest3) \
	op(EOculusXRDeviceType::Rift) \
	op(EOculusXRDeviceType::Rift_S) \
	op(EOculusXRDeviceType::Quest_Link_Deprecated) \
	op(EOculusXRDeviceType::Quest2_Link) \
	op(EOculusXRDeviceType::MetaQuestProLink) \
	op(EOculusXRDeviceType::MetaQuest3Link) \
	op(EOculusXRDeviceType::OculusUnknown) 

enum class EOculusXRDeviceType : uint8;
template<> struct TIsUEnumClass<EOculusXRDeviceType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRDeviceType>();

#define FOREACH_ENUM_EOCULUSXRCONTROLLERTYPE(op) \
	op(EOculusXRControllerType::None) \
	op(EOculusXRControllerType::MetaQuestTouch) \
	op(EOculusXRControllerType::MetaQuestTouchPro) \
	op(EOculusXRControllerType::MetaQuestTouchPlus) \
	op(EOculusXRControllerType::Unknown) 

enum class EOculusXRControllerType : uint8;
template<> struct TIsUEnumClass<EOculusXRControllerType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRControllerType>();

#define FOREACH_ENUM_EOCULUSXRXRAPI(op) \
	op(EOculusXRXrApi::OVRPluginOpenXR) \
	op(EOculusXRXrApi::NativeOpenXR) 

enum class EOculusXRXrApi : uint8;
template<> struct TIsUEnumClass<EOculusXRXrApi> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRXrApi>();

#define FOREACH_ENUM_EOCULUSXRCONTROLLERPOSEALIGNMENT(op) \
	op(EOculusXRControllerPoseAlignment::Default) \
	op(EOculusXRControllerPoseAlignment::Grip) \
	op(EOculusXRControllerPoseAlignment::Aim) 

enum class EOculusXRControllerPoseAlignment : uint8;
template<> struct TIsUEnumClass<EOculusXRControllerPoseAlignment> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRControllerPoseAlignment>();

#define FOREACH_ENUM_EOCULUSXROCCLUSIONSMODE(op) \
	op(EOculusXROcclusionsMode::Disabled) \
	op(EOculusXROcclusionsMode::HardOcclusions) \
	op(EOculusXROcclusionsMode::SoftOcclusions) 

enum class EOculusXROcclusionsMode : uint8;
template<> struct TIsUEnumClass<EOculusXROcclusionsMode> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXROcclusionsMode>();

#define FOREACH_ENUM_EOCULUSXREYEBUFFERSHARPENTYPE(op) \
	op(EOculusXREyeBufferSharpenType::SLST_None) \
	op(EOculusXREyeBufferSharpenType::SLST_Normal) \
	op(EOculusXREyeBufferSharpenType::SLST_Quality) \
	op(EOculusXREyeBufferSharpenType::SLST_Auto) 

enum class EOculusXREyeBufferSharpenType : uint8;
template<> struct TIsUEnumClass<EOculusXREyeBufferSharpenType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXREyeBufferSharpenType>();

#define FOREACH_ENUM_EPROCESSORFAVOR(op) \
	op(EProcessorFavor::FavorEqually) \
	op(EProcessorFavor::FavorCPU) \
	op(EProcessorFavor::FavorGPU) 

enum class EProcessorFavor : int8;
template<> struct TIsUEnumClass<EProcessorFavor> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EProcessorFavor>();

#define FOREACH_ENUM_EOCULUSXRHMDBODYTRACKINGFIDELITY(op) \
	op(EOculusXRHMDBodyTrackingFidelity::Unset) \
	op(EOculusXRHMDBodyTrackingFidelity::Low) \
	op(EOculusXRHMDBodyTrackingFidelity::High) 

enum class EOculusXRHMDBodyTrackingFidelity : uint8;
template<> struct TIsUEnumClass<EOculusXRHMDBodyTrackingFidelity> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHMDBodyTrackingFidelity>();

#define FOREACH_ENUM_EOCULUSXRHMDBODYJOINTSET(op) \
	op(EOculusXRHMDBodyJointSet::UpperBody) \
	op(EOculusXRHMDBodyJointSet::FullBody) 

enum class EOculusXRHMDBodyJointSet : uint8;
template<> struct TIsUEnumClass<EOculusXRHMDBodyJointSet> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHMDBodyJointSet>();

#define FOREACH_ENUM_EFACETRACKINGDATASOURCECONFIG(op) \
	op(EFaceTrackingDataSourceConfig::Visual) \
	op(EFaceTrackingDataSourceConfig::Audio) 

enum class EFaceTrackingDataSourceConfig : int8;
template<> struct TIsUEnumClass<EFaceTrackingDataSourceConfig> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EFaceTrackingDataSourceConfig>();

#define FOREACH_ENUM_ESYSTEMSPLASHBACKGROUNDTYPE(op) \
	op(ESystemSplashBackgroundType::Black) \
	op(ESystemSplashBackgroundType::Contextual) 

enum class ESystemSplashBackgroundType : int8;
template<> struct TIsUEnumClass<ESystemSplashBackgroundType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<ESystemSplashBackgroundType>();

#define FOREACH_ENUM_EOCULUSXRMPPOSERESTORETYPE(op) \
	op(EOculusXRMPPoseRestoreType::Disabled) \
	op(EOculusXRMPPoseRestoreType::PositionOnly) \
	op(EOculusXRMPPoseRestoreType::PositionAndRotation) 

enum class EOculusXRMPPoseRestoreType : uint8;
template<> struct TIsUEnumClass<EOculusXRMPPoseRestoreType> { enum { Value = true }; };
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRMPPoseRestoreType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
