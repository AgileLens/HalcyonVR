// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKit.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MRUTILITYKIT_MRUtilityKit_generated_h
#error "MRUtilityKit.generated.h already included, missing '#pragma once' in MRUtilityKit.h"
#endif
#define MRUTILITYKIT_MRUtilityKit_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_117_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKHit_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKHit>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_141_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKLabelFilter>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_168_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKPlaneUV>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_186_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKTexCoordModes>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_204_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKSpawnActor>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_260_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics; \
	static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKSpawnGroup>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_290_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMRUKSettings(); \
	friend struct Z_Construct_UClass_UMRUKSettings_Statics; \
public: \
	DECLARE_CLASS(UMRUKSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(UMRUKSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_290_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMRUKSettings(UMRUKSettings&&); \
	UMRUKSettings(const UMRUKSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMRUKSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMRUKSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMRUKSettings) \
	NO_API virtual ~UMRUKSettings();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_287_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_290_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_290_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h_290_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class UMRUKSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKit_h


#define FOREACH_ENUM_EMRUKINITSTATUS(op) \
	op(EMRUKInitStatus::None) \
	op(EMRUKInitStatus::Busy) \
	op(EMRUKInitStatus::Complete) \
	op(EMRUKInitStatus::Failed) 

enum class EMRUKInitStatus : uint8;
template<> struct TIsUEnumClass<EMRUKInitStatus> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKInitStatus>();

#define FOREACH_ENUM_EMRUKCOORDMODEU(op) \
	op(EMRUKCoordModeU::Metric) \
	op(EMRUKCoordModeU::MetricSeamless) \
	op(EMRUKCoordModeU::MaintainAspectRatio) \
	op(EMRUKCoordModeU::MaintainAspectRatioSeamless) \
	op(EMRUKCoordModeU::Stretch) 

enum class EMRUKCoordModeU : uint8;
template<> struct TIsUEnumClass<EMRUKCoordModeU> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKCoordModeU>();

#define FOREACH_ENUM_EMRUKCOORDMODEV(op) \
	op(EMRUKCoordModeV::Metric) \
	op(EMRUKCoordModeV::MaintainAspectRatio) \
	op(EMRUKCoordModeV::Stretch) 

enum class EMRUKCoordModeV : uint8;
template<> struct TIsUEnumClass<EMRUKCoordModeV> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKCoordModeV>();

#define FOREACH_ENUM_EMRUKSPAWNERSELECTIONMODE(op) \
	op(EMRUKSpawnerSelectionMode::Random) \
	op(EMRUKSpawnerSelectionMode::ClosestSize) \
	op(EMRUKSpawnerSelectionMode::Custom) 

enum class EMRUKSpawnerSelectionMode : uint8;
template<> struct TIsUEnumClass<EMRUKSpawnerSelectionMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnerSelectionMode>();

#define FOREACH_ENUM_EMRUKSPAWNERSCALINGMODE(op) \
	op(EMRUKSpawnerScalingMode::Stretch) \
	op(EMRUKSpawnerScalingMode::UniformScaling) \
	op(EMRUKSpawnerScalingMode::UniformXYScale) \
	op(EMRUKSpawnerScalingMode::NoScaling) \
	op(EMRUKSpawnerScalingMode::Custom) 

enum class EMRUKSpawnerScalingMode : uint8;
template<> struct TIsUEnumClass<EMRUKSpawnerScalingMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnerScalingMode>();

#define FOREACH_ENUM_EMRUKALIGNMODE(op) \
	op(EMRUKAlignMode::None) \
	op(EMRUKAlignMode::Default) \
	op(EMRUKAlignMode::CenterOnCenter) \
	op(EMRUKAlignMode::BottomOnBottom) \
	op(EMRUKAlignMode::TopOnTop) \
	op(EMRUKAlignMode::LeftOnLeft) \
	op(EMRUKAlignMode::RightOnRight) \
	op(EMRUKAlignMode::FrontOnFront) \
	op(EMRUKAlignMode::BackOnBack) \
	op(EMRUKAlignMode::BottomOnTop) \
	op(EMRUKAlignMode::TopOnBottom) \
	op(EMRUKAlignMode::LeftOnRight) \
	op(EMRUKAlignMode::RightOnLeft) \
	op(EMRUKAlignMode::FrontOnBack) \
	op(EMRUKAlignMode::BackOnFront) \
	op(EMRUKAlignMode::Custom) 

enum class EMRUKAlignMode : uint8;
template<> struct TIsUEnumClass<EMRUKAlignMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKAlignMode>();

#define FOREACH_ENUM_EMRUKFALLBACKTOPROCEDURALOVERWRITE(op) \
	op(EMRUKFallbackToProceduralOverwrite::Default) \
	op(EMRUKFallbackToProceduralOverwrite::Fallback) \
	op(EMRUKFallbackToProceduralOverwrite::NoFallback) 

enum class EMRUKFallbackToProceduralOverwrite : uint8;
template<> struct TIsUEnumClass<EMRUKFallbackToProceduralOverwrite> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKFallbackToProceduralOverwrite>();

#define FOREACH_ENUM_EMRUKSPAWNMODE(op) \
	op(EMRUKSpawnMode::None) \
	op(EMRUKSpawnMode::CurrentRoomOnly) \
	op(EMRUKSpawnMode::AllRooms) 

enum class EMRUKSpawnMode : uint8;
template<> struct TIsUEnumClass<EMRUKSpawnMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
