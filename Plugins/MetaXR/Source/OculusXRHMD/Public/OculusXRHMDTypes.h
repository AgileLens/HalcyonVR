// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "RHI.h"
#include "RHIResources.h"
#include "Engine/Texture2D.h"
#include "UObject/SoftObjectPath.h"
#include "OculusXRHMDTypes.generated.h"

/* Tracked device types corresponding to ovrTrackedDeviceType enum*/
UENUM(BlueprintType)
enum class EOculusXRTrackedDeviceType : uint8
{
	None UMETA(DisplayName = "No Devices"),
	HMD UMETA(DisplayName = "HMD"),
	LTouch UMETA(DisplayName = "Left Hand"),
	RTouch UMETA(DisplayName = "Right Hand"),
	Touch UMETA(DisplayName = "All Hands"),
	DeviceObjectZero UMETA(DisplayName = "DeviceObject Zero"),
	All UMETA(DisplayName = "All Devices")
};

USTRUCT(BlueprintType, meta = (DisplayName = "HMD User Profile Data Field"))
struct FOculusXRHmdUserProfileField
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	FString FieldName;

	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	FString FieldValue;

	FOculusXRHmdUserProfileField() {}
	FOculusXRHmdUserProfileField(const FString& Name, const FString& Value)
		: FieldName(Name), FieldValue(Value) {}
};

USTRUCT(BlueprintType, meta = (DisplayName = "HMD User Profile Data"))
struct FOculusXRHmdUserProfile
{
	GENERATED_USTRUCT_BODY()

	/** Name of the user's profile. */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	FString Name;

	/** Gender of the user ("male", "female", etc). */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	FString Gender;

	/** Height of the player, in meters */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	float PlayerHeight;

	/** Height of the player, in meters */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	float EyeHeight;

	/** Interpupillary distance of the player, in meters */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	float IPD;

	/** Neck-to-eye distance, in meters. X - horizontal, Y - vertical. */
	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	FVector2D NeckToEyeDistance;

	UPROPERTY(BlueprintReadWrite, Category = "Input|HeadMountedDisplay")
	TArray<FOculusXRHmdUserProfileField> ExtraFields;

	FOculusXRHmdUserProfile()
		: PlayerHeight(0.f), EyeHeight(0.f), IPD(0.f), NeckToEyeDistance(FVector2D::ZeroVector) {}
};

UENUM(BlueprintType)
enum class EOculusXRFoveatedRenderingMethod : uint8
{
	FixedFoveatedRendering = 0,
	EyeTrackedFoveatedRendering = 1,
};

UENUM(BlueprintType)
enum class EOculusXRFoveatedRenderingLevel : uint8
{
	Off = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	// High foveation setting with more detail toward the bottom of the view and more foveation near the top
	HighTop = 4
};

/* Guardian boundary types*/
UENUM(BlueprintType)
enum class EOculusXRBoundaryType : uint8
{
	Boundary_Outer UMETA(DisplayName = "Outer Boundary"),
	Boundary_PlayArea UMETA(DisplayName = "Play Area"),
};

UENUM(BlueprintType)
enum class EOculusXRColorSpace : uint8
{
	/// The default value from GetHmdColorSpace until SetClientColorDesc is called. Only valid on PC, and will be remapped to Quest on Mobile
	Unknown = 0,
	/// No color correction, not recommended for production use. See documentation for more info
	Unmanaged = 1,
	/// Color space for standardized color across all Oculus HMDs with D65 white point
	Rec_2020 = 2,
	/// Rec. 709 is used on Oculus Go and shares the same primary color coordinates as sRGB
	Rec_709 = 3,
	/// Oculus Rift CV1 uses a unique color space, see documentation for more info
	Rift_CV1 = 4 UMETA(DisplayName = "Rift CV1"),
	/// Oculus Rift S uses a unique color space, see documentation for more info
	Rift_S = 5,
	/// Oculus Quest's native color space is slightly different than Rift CV1
	Quest = 6 UMETA(DisplayName = "Quest 1"),
	/// DCI-P3 color space. See documentation for more details
	P3 = 7 UMETA(DisplayName = "P3 (Recommended)"),
	/// Similar to sRGB but with deeper greens using D65 white point
	Adobe_RGB = 8,
};

/*
 * Hand tracking settings. Please check https://developer.oculus.com/documentation/unreal/unreal-hand-tracking/
 * for detailed information.
 */
UENUM(BlueprintType)
enum class EOculusXRHandTrackingSupport : uint8
{
	ControllersOnly,
	ControllersAndHands,
	HandsOnly,
};

UENUM(BlueprintType)
enum class EOculusXRHandTrackingFrequency : uint8
{
	LOW,
	HIGH,
	MAX,
};

UENUM(BlueprintType)
enum class EOculusXRHandTrackingVersion : uint8
{
	Default,
	V1,
	V2,
};

UENUM(BlueprintType)
enum class EOculusXRProcessorPerformanceLevel : uint8
{
	PowerSavings = 0 UMETA(DisplayName = "PowerSavings", ToolTip = "Usually used in non-XR section (head-locked / static screen), during which power savings are to be prioritized"),
	SustainedLow = 1 UMETA(DisplayName = "SustainedLow", ToolTip = "App enters a low and stable complexity section, during which reducing power is more important than occasional late rendering frames"),
	SustainedHigh = 2 UMETA(DisplayName = "SustainedHigh", ToolTip = "Let XR Runtime to perform consistent XR compositing and frame rendering within a thermally sustainable range"),
	Boost = 3 UMETA(DisplayName = "Boost(*)", ToolTip = "Allow XR Runtime to step up beyond the thermally sustainable range for short period. (Currently equivalent to SustainedHigh and not recommended to be used on Quest)")
};

UENUM(BlueprintType)
enum class EOculusXRDeviceType : uint8
{
	// mobile HMDs
	OculusMobile_Deprecated0 = 0,
	OculusQuest_Deprecated,
	OculusQuest2,
	MetaQuestPro,
	MetaQuest3,

	// PC HMDs
	Rift = 100,
	Rift_S,
	Quest_Link_Deprecated,
	Quest2_Link,
	MetaQuestProLink,
	MetaQuest3Link,

	// default
	OculusUnknown = 200,
};

UENUM(BlueprintType)
enum class EOculusXRControllerType : uint8
{
	None = 0,
	MetaQuestTouch = 1,
	MetaQuestTouchPro = 2,
	MetaQuestTouchPlus = 3,
	Unknown = 0x7f,
};

UENUM(BlueprintType)
enum class EOculusXRXrApi : uint8
{
	OVRPluginOpenXR = 0 UMETA(DisplayName = "Oculus OVRPlugin + OpenXR backend (current recommended)", ToolTip = "Oculus plugin integration using OpenXR backend on both Mobile and PC. All new features will ship on backend for the forseeable future."),

	NativeOpenXR = 1 UMETA(DisplayName = "Epic Native OpenXR with Oculus vendor extensions", ToolTip = "Disable Legacy Oculus in favor of the native OpenXR implementation, with Oculus vendor extensions. Must enable the OpenXR plugin. This will be where Epic focuses XR development going forward. Oculus OpenXR extensions may be moved into a separate plugin (or plugins) in the future to improve modularity. The features supported by OpenXR are listed in the OpenXR specification on khronos.org, and the features supported by a given runtime can be verified with the \"OpenXR Explorer\" application on GitHub."),
};

/*
 * Information about relationships between a triggered boundary (EOculusXRBoundaryType::Boundary_Outer or
 * EOculusXRBoundaryType::Boundary_PlayArea) and a device or point in the world.
 * All dimensions, points, and vectors are returned in Unreal world coordinate space.
 */
USTRUCT(BlueprintType)
struct FOculusXRGuardianTestResult
{
	GENERATED_BODY()

	/** Is there a triggering interaction between the device/point and specified boundary? */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boundary Test Result")
	bool IsTriggering = false;

	/** Device type triggering boundary (EOculusXRTrackedDeviceType::None if BoundaryTestResult corresponds to a point rather than a device) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boundary Test Result")
	EOculusXRTrackedDeviceType DeviceType = EOculusXRTrackedDeviceType::None;

	/** Distance of device/point to surface of boundary specified by BoundaryType */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boundary Test Result")
	float ClosestDistance = 0.0f;

	/** Closest point on surface corresponding to specified boundary */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boundary Test Result")
	FVector ClosestPoint = FVector(0.0f);

	/** Normal of closest point */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Boundary Test Result")
	FVector ClosestPointNormal = FVector(0.0f, 0.0f, 1.0f);
};

UENUM()
enum class EOculusXRControllerPoseAlignment : uint8
{
	Default = 0 UMETA(ToolTip = "Default pose alignment used in all versions of the Meta XR plugin. Recommended pose for compatibility with previous assets designed for the Meta XR plugin."),

	Grip = 1 UMETA(ToolTip = "Grip pose alignment as defined by OpenXR. Use this for cross-plugin compatibility with assets designed for the native OpenXR grip pose."),

	Aim = 2 UMETA(ToolTip = "Aim pose alignment as defined by OpenXR. Use this for cross-plugin compatibility with assets designed for the native OpenXR aim pose."),
};

USTRUCT()
struct FOculusXRSplashDesc
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (AllowedClasses = "/Script/Engine.Texture", ToolTip = "Texture to display"))
	FSoftObjectPath TexturePath;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "transform of center of quad (meters)."))
	FTransform TransformInMeters;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Dimensions in meters."))
	FVector2D QuadSizeInMeters;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "A delta rotation that will be added each rendering frame (half rate of full vsync)."))
	FQuat DeltaRotation;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Texture offset amount from the top left corner."))
	FVector2D TextureOffset;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Texture scale."))
	FVector2D TextureScale;

	UPROPERTY(config, EditAnywhere, Category = Settings, meta = (ToolTip = "Whether the splash layer uses it's alpha channel."))
	bool bNoAlphaChannel;

	// Runtime data
	UTexture* LoadingTexture;
	FTextureRHIRef LoadedTexture;
	bool bIsDynamic;

	FOculusXRSplashDesc()
		: TransformInMeters(FVector(4.0f, 0.f, 0.f))
		, QuadSizeInMeters(3.f, 3.f)
		, DeltaRotation(FQuat::Identity)
		, TextureOffset(0.0f, 0.0f)
		, TextureScale(1.0f, 1.0f)
		, bNoAlphaChannel(false)
		, LoadingTexture(nullptr)
		, LoadedTexture(nullptr)
		, bIsDynamic(false)
	{
	}

	bool operator==(const FOculusXRSplashDesc& d) const
	{
		return TexturePath == d.TexturePath && TransformInMeters.Equals(d.TransformInMeters) && QuadSizeInMeters == d.QuadSizeInMeters && DeltaRotation.Equals(d.DeltaRotation) && TextureOffset == d.TextureOffset && TextureScale == d.TextureScale && bNoAlphaChannel == d.bNoAlphaChannel && LoadingTexture == d.LoadingTexture && LoadedTexture == d.LoadedTexture && bIsDynamic == d.bIsDynamic;
	}
};

UENUM(BlueprintType)
enum class EOculusXROcclusionsMode : uint8
{
	/// Environment depth occlusions disabled.
	Disabled = 0,
	/// Hard occlusions, good performance, shows hard edges between the real and virtual world.
	HardOcclusions = 1,
	/// Soft occlusions, most expensive, shows soft edges between the real and virtual world.
	SoftOcclusions = 2,
};

UENUM(BlueprintType)
enum class EOculusXREyeBufferSharpenType : uint8
{
	/// No Sharpening
	SLST_None UMETA(DisplayName = "No Sharpening"),

	/// Normal Sharpening
	SLST_Normal UMETA(DisplayName = "Normal Sharpening"),

	/// Quality Sharpening
	SLST_Quality UMETA(DisplayName = "Quality Sharpening"),

	/// Auto Filtering: Runtime automatically chooses the appropriate sharpening filter
	SLST_Auto UMETA(DisplayName = "Auto Filtering"),

	SLST_MAX,
};

UENUM()
enum class EProcessorFavor : int8
{
	FavorEqually = 0 UMETA(DisplayName = "Favor Equally"),
	FavorCPU = 1 UMETA(DisplayName = "Favor CPU"),
	FavorGPU = 2 UMETA(DisplayName = "Favor GPU"),
};

UENUM(BlueprintType)
enum class EOculusXRHMDBodyTrackingFidelity : uint8
{
	Unset = 0 UMETA(Hidden),
	Low = 1,
	High = 2,
};

UENUM(BlueprintType)
enum class EOculusXRHMDBodyJointSet : uint8
{
	UpperBody = 0,
	FullBody = 1,
};

UENUM()
enum class EFaceTrackingDataSourceConfig : int8
{
	Visual = 0 UMETA(DisplayName = "Visual"),
	Audio = 1 UMETA(DisplayName = "Audio"),
	MAX = 2 UMETA(Hidden),
};

UENUM()
enum class ESystemSplashBackgroundType : int8
{
	Black = 0 UMETA(DisplayName = "Black"),
	Contextual = 1 UMETA(DisplayName = "Passthrough (Contextual)"),
};

USTRUCT(BlueprintType, meta = (DisplayName = "Oculus Performance Metrics"))
struct FOculusXRPerformanceMetrics
{
	GENERATED_USTRUCT_BODY()

	/** App CPU Time (ms) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float AppCpuTime;

	/** App GPU Time (ms) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float AppGpuTime;

	/** Compositor CPU Time (ms) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float ComCpuTime;

	/** Compositor GPU Time (ms) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float ComGpuTime;

	/** Compositor Dropped Frames */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	int DroppedFrames;

	/** System GPU Util % */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float GpuUtil;

	/** System CPU Util Avg % */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float CpuUtilAvg;

	/** System CPU Util Worst % */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	float CpuUtilWorst;

	/** Compositor SpaceWarp Mode: 0: Disabled; 1: Enabled */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	int ComSpaceWarpMode;

	/** CPU Core Util % */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Performance Metrics")
	TArray<float> CpuCoreUtil;

	FOculusXRPerformanceMetrics()
		: AppCpuTime(0.f)
		, AppGpuTime(0.f)
		, ComCpuTime(0.f)
		, ComGpuTime(0.f)
		, DroppedFrames(0)
		, GpuUtil(0.f)
		, CpuUtilAvg(0.f)
		, CpuUtilWorst(0.f)
		, ComSpaceWarpMode(0)
	{
	}
};

UENUM(BlueprintType)
enum class EOculusXRMPPoseRestoreType : uint8
{
	/// DONOT restore head and controller poses
	Disabled = 0 UMETA(DisplayName = "Disabled"),
	/// Only restore head and controller position
	PositionOnly = 1 UMETA(DisplayName = "Restore Position Only"),
	/// Restore head and controller position and rotation
	PositionAndRotation = 2 UMETA(DisplayName = "Restore Position And Rotation"),
};
