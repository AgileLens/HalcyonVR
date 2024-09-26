// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 struct FMRUKSpawnGroup;
class AActor;
class AMRUKAnchor;
class AMRUKRoom;
class UMaterialInterface;
enum class EMRUKPositioningMethod : uint8;
struct FMRUKHit;
struct FMRUKLabelFilter;
struct FOculusXRUInt64;
struct FRandomStream;
#ifdef MRUTILITYKIT_MRUtilityKitSubsystem_generated_h
#error "MRUtilityKitSubsystem.generated.h already included, missing '#pragma once' in MRUtilityKitSubsystem.h"
#endif
#define MRUTILITYKIT_MRUtilityKitSubsystem_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_43_DELEGATE \
static void FOnLoaded_DelegateWrapper(const FMulticastScriptDelegate& OnLoaded, bool Success);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_44_DELEGATE \
static void FOnCaptureComplete_DelegateWrapper(const FMulticastScriptDelegate& OnCaptureComplete, bool Success);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_45_DELEGATE \
static void FOnRoomCreated_DelegateWrapper(const FMulticastScriptDelegate& OnRoomCreated, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_46_DELEGATE \
static void FOnRoomUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnRoomUpdated, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_47_DELEGATE \
static void FOnRoomRemoved_DelegateWrapper(const FMulticastScriptDelegate& OnRoomRemoved, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_48_DELEGATE \
static void FOnRoomEntered_DelegateWrapper(const FMulticastScriptDelegate& OnRoomEntered, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_49_DELEGATE \
static void FOnRoomExited_DelegateWrapper(const FMulticastScriptDelegate& OnRoomExited, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSceneCaptureComplete); \
	DECLARE_FUNCTION(execUpdatedSceneDataLoadedComplete); \
	DECLARE_FUNCTION(execSceneDataLoadedComplete); \
	DECLARE_FUNCTION(execLaunchSceneCapture); \
	DECLARE_FUNCTION(execSpawnInteriorFromStream); \
	DECLARE_FUNCTION(execSpawnInterior); \
	DECLARE_FUNCTION(execIsPositionInSceneVolume); \
	DECLARE_FUNCTION(execGetLargestSurface); \
	DECLARE_FUNCTION(execGetKeyWall); \
	DECLARE_FUNCTION(execGetBestPoseFromRaycast); \
	DECLARE_FUNCTION(execTryGetClosestSeatPose); \
	DECLARE_FUNCTION(execTryGetClosestSurfacePosition); \
	DECLARE_FUNCTION(execClearScene); \
	DECLARE_FUNCTION(execLoadSceneFromDevice); \
	DECLARE_FUNCTION(execLoadSceneFromJsonString); \
	DECLARE_FUNCTION(execSaveSceneToJsonString); \
	DECLARE_FUNCTION(execGetCurrentRoom); \
	DECLARE_FUNCTION(execRaycastAll); \
	DECLARE_FUNCTION(execRaycast);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMRUKSubsystem(); \
	friend struct Z_Construct_UClass_UMRUKSubsystem_Statics; \
public: \
	DECLARE_CLASS(UMRUKSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(UMRUKSubsystem)


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMRUKSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMRUKSubsystem(UMRUKSubsystem&&); \
	UMRUKSubsystem(const UMRUKSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMRUKSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMRUKSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMRUKSubsystem) \
	NO_API virtual ~UMRUKSubsystem();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_37_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h_40_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class UMRUKSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
