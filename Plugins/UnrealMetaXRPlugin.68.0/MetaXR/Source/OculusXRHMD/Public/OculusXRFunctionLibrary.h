// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "OculusXRHMDTypes.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IOculusXRHMDModule.h"
#include "OculusXRFunctionLibrary.generated.h"

namespace OculusXRHMD
{
	class FOculusXRHMD;
	class IOculusXRFunctionLibrary
	{
	public:
		virtual void GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition) = 0;
		virtual void SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options) = 0;
		virtual void GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters) = 0;
		virtual void GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds, EOculusXRTrackedDeviceType DeviceType) = 0;
		virtual bool IsDeviceTracked(EOculusXRTrackedDeviceType DeviceType) = 0;
		virtual void GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel) = 0;
		virtual void SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel) = 0;
		virtual void SetCPUAndGPULevels(int CPULevel, int GPULevel) = 0;
		virtual bool GetUserProfile(FOculusXRHmdUserProfile& Profile) = 0;
		virtual void SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options) = 0;
		virtual void GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset) = 0;
		virtual void AddLoadingSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters, FRotator DeltaRotation, bool bClearBeforeAdd) = 0;
		virtual void ClearLoadingSplashScreens() = 0;
		virtual bool HasInputFocus() = 0;
		virtual bool HasSystemOverlayPresent() = 0;
		virtual void GetGPUUtilization(bool& IsGPUAvailable, float& GPUUtilization) = 0;
		virtual float GetGPUFrameTime() = 0;
		virtual void GetPerformanceMetrics(FOculusXRPerformanceMetrics& PerformanceMetrics) = 0;


		virtual EOculusXRFoveatedRenderingMethod GetFoveatedRenderingMethod() = 0;
		virtual void SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod Method) = 0;
		virtual void SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel level, bool isDynamic) = 0;
		virtual EOculusXRFoveatedRenderingLevel GetFoveatedRenderingLevel() = 0;
		virtual bool GetEyeTrackedFoveatedRenderingSupported() = 0;
		virtual FString GetDeviceName() = 0;
		virtual EOculusXRDeviceType GetDeviceType() = 0;
		virtual EOculusXRControllerType GetControllerType(EControllerHand deviceHand) = 0;
		virtual TArray<float> GetAvailableDisplayFrequencies() = 0;
		virtual float GetCurrentDisplayFrequency() = 0;
		virtual void SetDisplayFrequency(float RequestedFrequency) = 0;
		virtual void EnablePositionTracking(bool bPositionTracking) = 0;
		virtual void EnableOrientationTracking(bool bOrientationTracking) = 0;
		virtual void SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers) = 0;
		virtual class IStereoLayers* GetStereoLayers() = 0;
		virtual bool IsGuardianConfigured() = 0;
		virtual bool IsGuardianDisplayed() = 0;
		virtual TArray<FVector> GetGuardianPoints(EOculusXRBoundaryType BoundaryType, bool UsePawnSpace /* = false */) = 0;
		virtual FVector GetGuardianDimensions(EOculusXRBoundaryType BoundaryType) = 0;
		virtual FTransform GetPlayAreaTransform() = 0;
		virtual FOculusXRGuardianTestResult GetPointGuardianIntersection(const FVector Point, EOculusXRBoundaryType BoundaryType) = 0;
		virtual FOculusXRGuardianTestResult GetNodeGuardianIntersection(EOculusXRTrackedDeviceType DeviceType, EOculusXRBoundaryType BoundaryType) = 0;
		virtual void SetGuardianVisibility(bool GuardianVisible) = 0;
		virtual bool GetSystemHmd3DofModeEnabled() = 0;
		virtual EOculusXRColorSpace GetHmdColorDesc() = 0;
		virtual void SetClientColorDesc(EOculusXRColorSpace ColorSpace) = 0;
		virtual void SetLocalDimmingOn(bool LocalDimmingOn) = 0;
		virtual bool IsPassthroughSupported() = 0;
		virtual bool IsColorPassthroughSupported() = 0;
		virtual void StartEnvironmentDepth() = 0;
		virtual void StopEnvironmentDepth() = 0;
		virtual bool IsEnvironmentDepthStarted() = 0;
		virtual void SetEnvironmentDepthHandRemoval(bool RemoveHands) = 0;
		virtual void SetXROcclusionsMode(UObject* WorldContextObject, EOculusXROcclusionsMode Mode) = 0;
		virtual void SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType EyeBufferSharpenType) = 0;
		virtual bool IsPassthroughRecommended() = 0;
	};
} // namespace OculusXRHMD

UCLASS()
class OCULUSXRHMD_API UOculusXRFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	 * Grabs the current orientation and position for the HMD.  If positional tracking is not available, DevicePosition will be a zero vector
	 *
	 * @param DeviceRotation	(out) The device's current rotation
	 * @param DevicePosition	(out) The device's current position, in its own tracking space
	 * @param NeckPosition		(out) The estimated neck position, calculated using NeckToEye vector from User Profile. Same coordinate space as DevicePosition.
	 * @param bUseOrienationForPlayerCamera	(in) Should be set to 'true' if the orientation is going to be used to update orientation of the camera manually.
	 * @param bUsePositionForPlayerCamera	(in) Should be set to 'true' if the position is going to be used to update position of the camera manually.
	 * @param PositionScale		(in) The 3D scale that will be applied to position.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static void GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition, bool bUseOrienationForPlayerCamera = false, bool bUsePositionForPlayerCamera = false, const FVector PositionScale = FVector::ZeroVector);

	/**
	 * Reports raw sensor data. If HMD doesn't support any of the parameters then it will be set to zero.
	 *
	 * @param AngularAcceleration	(out) Angular acceleration in radians per second per second.
	 * @param LinearAcceleration		(out) Acceleration in meters per second per second.
	 * @param AngularVelocity		(out) Angular velocity in radians per second.
	 * @param LinearVelocity			(out) Velocity in meters per second.
	 * @param TimeInSeconds			(out) Time when the reported IMU reading took place, in seconds.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static void GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds, EOculusXRTrackedDeviceType DeviceType = EOculusXRTrackedDeviceType::HMD);

	/**
	 * Returns if the device is currently tracked by the runtime or not.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool IsDeviceTracked(EOculusXRTrackedDeviceType DeviceType);

	/**
	 * Set the CPU and GPU levels as hints to the Oculus device (Deprecated).
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecatedMessage = "Deprecated. Please use Get/SetSuggestedCpuAndGpuPerformanceLevels instead"))
	static void SetCPUAndGPULevels(int CPULevel, int GPULevel);

	/**
	 * Get the suggested CPU and GPU levels to the Oculus device.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel);

	/**
	 * Set the suggested CPU and GPU levels to the Oculus device.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel);

	/**
	 * Returns current user profile.
	 *
	 * @param Profile		(out) Structure to hold current user profile.
	 * @return (boolean)	True, if user profile was acquired.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool GetUserProfile(FOculusXRHmdUserProfile& Profile);

	/**
	 * Sets 'base rotation' - the rotation that will be subtracted from
	 * the actual HMD orientation.
	 * Sets base position offset (in meters). The base position offset is the distance from the physical (0, 0, 0) position
	 * to current HMD position (bringing the (0, 0, 0) point to the current HMD position)
	 * Note, this vector is set by ResetPosition call; use this method with care.
	 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.
	 *
	 * @param Rotation			(in) Rotator object with base rotation
	 * @param BaseOffsetInMeters (in) the vector to be set as base offset, in meters.
	 * @param Options			(in) specifies either position, orientation or both should be set.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options);

	/**
	 * Returns current base rotation and base offset.
	 * The base offset is currently used base position offset, previously set by the
	 * ResetPosition or SetBasePositionOffset calls. It represents a vector that translates the HMD's position
	 * into (0,0,0) point, in meters.
	 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.
	 *
	 * @param OutRotation			(out) Rotator object with base rotation
	 * @param OutBaseOffsetInMeters	(out) base position offset, vector, in meters.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static void GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters);

	/**
	 * Scales the HMD position that gets added to the virtual camera position.
	 *
	 * @param PosScale3D	(in) the scale to apply to the HMD position.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "This feature is no longer supported."))
	static void SetPositionScale3D(FVector PosScale3D) {}

	/**
	 * Sets 'base rotation' - the rotation that will be subtracted from
	 * the actual HMD orientation.
	 * The position offset might be added to current HMD position,
	 * effectively moving the virtual camera by the specified offset. The addition
	 * occurs after the HMD orientation and position are applied.
	 *
	 * @param BaseRot			(in) Rotator object with base rotation
	 * @param PosOffset			(in) the vector to be added to HMD position.
	 * @param Options			(in) specifies either position, orientation or both should be set.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "A hack, proper camera positioning should be used"))
	static void SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options);

	/**
	 * Returns current base rotation and position offset.
	 *
	 * @param OutRot			(out) Rotator object with base rotation
	 * @param OutPosOffset		(out) the vector with previously set position offset.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "A hack, proper camera positioning should be used"))
	static void GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset);

	/**
	 * Adds loading splash screen with parameters
	 *
	 * @param Texture			(in) A texture asset to be used for the splash.
	 * @param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).
	 * @param Rotation			(in) Initial rotation of the splash screen, with the origin at the center of the splash screen.
	 * @param SizeInMeters		(in) Size, in meters, of the quad with the splash screen.
	 * @param DeltaRotation		(in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.
	 * @param bClearBeforeAdd	(in) If true, clears splashes before adding a new one.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "Use Add Loading Screen Splash from the Head Mounted Display Loading Screen functions instead."))
	static void AddLoadingSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters = FVector2D(1.0f, 1.0f), FRotator DeltaRotation = FRotator::ZeroRotator, bool bClearBeforeAdd = false);

	/**
	 * Removes all the splash screens.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "Use Clear Loading Screen Splashes from the Head Mounted Display Loading Screen functions instead."))
	static void ClearLoadingSplashScreens();

	/**
	 * Returns true, if the app has input focus.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool HasInputFocus();

	/**
	 * Returns true, if the system overlay is present.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool HasSystemOverlayPresent();

	/**
	 * Returns the GPU utilization availability and value
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static void GetGPUUtilization(bool& IsGPUAvailable, float& GPUUtilization);

	/**
	 * Returns the GPU frame time on supported mobile platforms (Go for now)
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static float GetGPUFrameTime();

	/**
	 * Returns the performance metrics
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static void GetPerformanceMetrics(FOculusXRPerformanceMetrics& PerformanceMetrics);

	/**
	 * Returns the foveated rendering method currently being used
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static EOculusXRFoveatedRenderingMethod GetFoveatedRenderingMethod();

	/**
	 * Set the requested foveated rendering method
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod Method);

	/**
	 * Returns the current multiresolution level
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static EOculusXRFoveatedRenderingLevel GetFoveatedRenderingLevel();

	/**
	 * Set the requested foveated rendering level for the next frame, and whether FFR's level is now dynamic or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel level, bool isDynamic);

	/**
	 * Returns whether eye-tracked foveated rendering is supported or not
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static bool GetEyeTrackedFoveatedRenderingSupported();

	/**
	 * Returns the current device's name
	 */
	UE_DEPRECATED(4.22, "UOculusXRFunctionLibrary::GetDeviceName has been deprecated and no longer functions as before. Please use the enum-based GetDeviceType instead.")
	UFUNCTION(BlueprintPure, Category = "OculusLibrary", meta = (DeprecatedFunction, DeprecationMessage = "UOculusXRFunctionLibrary::GetDeviceName has been deprecated and no longer functions as before. Please use the enum-based GetDeviceType instead."))
	static FString GetDeviceName();

	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static EOculusXRDeviceType GetDeviceType();

	/**
	 * Returns the current controller's type
	 * @param deviceHand				(in) The hand to get the position from
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static EOculusXRControllerType GetControllerType(EControllerHand deviceHand);

	/**
	 * Returns the current available frequencies
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static TArray<float> GetAvailableDisplayFrequencies();

	/**
	 * Returns the current display frequency
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static float GetCurrentDisplayFrequency();

	/**
	 * Sets the requested display frequency
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetDisplayFrequency(float RequestedFrequency);

	/**
	 * Enables/disables positional tracking on devices that support it.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void EnablePositionTracking(bool bPositionTracking);

	/**
	 * Enables/disables orientation tracking on devices that support it.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void EnableOrientationTracking(bool bOrientationTracking);

	/**
	 * Set the Color Scale/Offset
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers = false);

	/**
	 * Returns true if system headset is in 3dof mode
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool GetSystemHmd3DofModeEnabled();

	/**
	 * Returns the color space of the target HMD
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static EOculusXRColorSpace GetHmdColorDesc();

	/**
	 * Sets the target HMD to do color space correction to a specific color space
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetClientColorDesc(EOculusXRColorSpace ColorSpace);

	/**
	 * Turns on or off local dimming
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetLocalDimmingOn(bool LocalDimmingOn);

	/**
	 * Checks if passthrough is supported
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static bool IsPassthroughSupported();

	/**
	 * Checks if color passthrough is supported
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static bool IsColorPassthroughSupported();

	/**
	 * Create the environment depth texture swap chain and start receiving
	 * depth texture every frame until stopped.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void StartEnvironmentDepth();

	/**
	 * Destroy the environment depth texture swap chain and stop receiving
	 * new depth textures every frame. Call this when environment depth is
	 * no longer needed to free up resources.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void StopEnvironmentDepth();

	/**
	 * Returns true if StartEnvironmentDepth() has been called and is currently running.
	 * If called right after calling StartEnvironmentDepth() it'll return false as it needs some time for EnvironmentDepth to start
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary")
	static bool IsEnvironmentDepthStarted();

	/**
	 * When hands removal is enabled and hand tracking is active, the region
	 * of the depth texture which contains the hands will be replaced with
	 * the best estimate for depth behind the hands.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetEnvironmentDepthHandRemoval(bool RemoveHands);

	/**
	 * Sets the occlusions mode using environment depth. When occlusions are enabled
	 * virtual objects that are behind physical objects will be occluded so that
	 * the sense of immersion is preserved.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary", meta = (WorldContext = "WorldContextObject"))
	static void SetXROcclusionsMode(UObject* WorldContextObject, EOculusXROcclusionsMode Mode);

	/**
	 * Sets the eyebuffer sharpen type. This amplifies contrast and fine details.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static void SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType EyeBufferSharpenType);

	/**
	 * Get a system recommendation on whether Passthrough should be active.
	 * When set, it is recommended for apps which optionally support an MR experience
	 * with Passthrough to default to that mode.
	 * Currently, this is determined based on whether the user has Passthrough active in the home environment.
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary")
	static bool IsPassthroughRecommended();

	/**
	 * Returns IStereoLayers interface to work with overlays.
	 */
	static class IStereoLayers* GetStereoLayers();


	/* GUARDIAN API */
	/**
	 * Returns true if the Guardian Outer Boundary is being displayed
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary|Guardian")
	static bool IsGuardianDisplayed();

	/* GUARDIAN API */
	/**
	 * Returns true if the Guardian has been set up by the user, false if the user is in "seated" mode and has not set up a play space.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary|Guardian")
	static bool IsGuardianConfigured();

	/**
	 * Returns the list of points in UE world space of the requested Boundary Type
	 * @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)
	 * @param UsePawnSpace			(in) Boolean indicating to return the points in world space or pawn space
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary|Guardian")
	static TArray<FVector> GetGuardianPoints(EOculusXRBoundaryType BoundaryType, bool UsePawnSpace = false);

	/**
	 * Returns the dimensions in UE world space of the requested Boundary Type
	 * @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary|Guardian")
	static FVector GetGuardianDimensions(EOculusXRBoundaryType BoundaryType);

	/**
	 * Returns the transform of the play area rectangle, defining its position, rotation and scale to apply to a unit cube to match it with the play area.
	 */
	UFUNCTION(BlueprintPure, Category = "OculusLibrary|Guardian")
	static FTransform GetPlayAreaTransform();

	/**
	 * Get the intersection result between a UE4 coordinate and a guardian boundary
	 * @param Point					(in) Point in UE space to test against guardian boundaries
	 * @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|Guardian")
	static FOculusXRGuardianTestResult GetPointGuardianIntersection(const FVector Point, EOculusXRBoundaryType BoundaryType);

	/**
	 * Get the intersection result between a tracked device (HMD or controllers) and a guardian boundary
	 * @param DeviceType             (in) Tracked Device type to test against guardian boundaries
	 * @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|Guardian")
	static FOculusXRGuardianTestResult GetNodeGuardianIntersection(EOculusXRTrackedDeviceType DeviceType, EOculusXRBoundaryType BoundaryType);

	/**
	 * Forces the runtime to render guardian at all times or not
	 * @param GuardianVisible			(in) True will display guardian, False will hide it
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|Guardian")
	static void SetGuardianVisibility(bool GuardianVisible);

	/** When player triggers the Guardian boundary */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOculusGuardianTriggeredEvent, FOculusXRGuardianTestResult);

	/** When player returns within outer bounds */
	DECLARE_MULTICAST_DELEGATE(FOculusGuardianReturnedEvent);

	/**
	 * For outer boundary only. Devs can bind delegates via something like: BoundaryComponent->OnOuterBoundaryTriggered.AddDynamic(this, &UCameraActor::PauseGameForBoundarySystem) where
	 * PauseGameForBoundarySystem() takes a TArray<FBoundaryTestResult> parameter.
	 */
	// UPROPERTY(BlueprintAssignable, Category = "Input|OculusLibrary|Guardian")
	// static FOculusGuardianTriggeredEvent OnGuardianTriggered;

	/** For outer boundary only. Devs can bind delegates via something like: BoundaryComponent->OnOuterBoundaryReturned.AddDynamic(this, &UCameraActor::ResumeGameForBoundarySystem) */
	// UPROPERTY(BlueprintAssignable, Category = "OculusLibrary|Guardian")
	// FOculusGuardianReturnedEvent OnGuardianReturned;

	static void ShutdownXRFunctionLibrary();

protected:
	static class OculusXRHMD::FOculusXRHMD* GetOculusXRHMD();
	static TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> GetOculusXRFunctionImpl();
	static TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> FunctionLibraryImpl;
};
