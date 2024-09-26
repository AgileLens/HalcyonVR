// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRFunctionLibrary.h"

namespace OculusXRHMD
{
	class FOculusXRFunctionLibraryOpenXR : public IOculusXRFunctionLibrary
	{
	public:
		virtual void GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition) override;
		virtual void SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options) override;
		virtual void GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters) override;
		virtual void GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds, EOculusXRTrackedDeviceType DeviceType) override;
		virtual bool IsDeviceTracked(EOculusXRTrackedDeviceType DeviceType) override;
		virtual void GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel) override;
		virtual void SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel) override;
		virtual void SetCPUAndGPULevels(int CPULevel, int GPULevel) override;
		virtual bool GetUserProfile(FOculusXRHmdUserProfile& Profile) override;
		virtual void SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options) override;
		virtual void GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset) override;
		virtual void AddLoadingSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters, FRotator DeltaRotation, bool bClearBeforeAdd) override;
		virtual void ClearLoadingSplashScreens() override;
		virtual bool HasInputFocus() override;
		virtual bool HasSystemOverlayPresent() override;
		virtual void GetGPUUtilization(bool& IsGPUAvailable, float& GPUUtilization) override;
		virtual float GetGPUFrameTime() override;
		virtual void GetPerformanceMetrics(FOculusXRPerformanceMetrics& PerformanceMetrics) override;


		virtual EOculusXRFoveatedRenderingMethod GetFoveatedRenderingMethod() override;
		virtual void SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod Method) override;
		virtual void SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel level, bool isDynamic) override;
		virtual EOculusXRFoveatedRenderingLevel GetFoveatedRenderingLevel() override;
		virtual bool GetEyeTrackedFoveatedRenderingSupported() override;
		virtual FString GetDeviceName() override;
		virtual EOculusXRDeviceType GetDeviceType() override;
		virtual EOculusXRControllerType GetControllerType(EControllerHand deviceHand) override;
		virtual TArray<float> GetAvailableDisplayFrequencies() override;
		virtual float GetCurrentDisplayFrequency() override;
		virtual void SetDisplayFrequency(float RequestedFrequency) override;
		virtual void EnablePositionTracking(bool bPositionTracking) override;
		virtual void EnableOrientationTracking(bool bOrientationTracking) override;
		virtual void SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers) override;
		virtual class IStereoLayers* GetStereoLayers() override;
		virtual bool IsGuardianConfigured() override;
		virtual bool IsGuardianDisplayed() override;
		virtual TArray<FVector> GetGuardianPoints(EOculusXRBoundaryType BoundaryType, bool UsePawnSpace /* = false */) override;
		virtual FVector GetGuardianDimensions(EOculusXRBoundaryType BoundaryType) override;
		virtual FTransform GetPlayAreaTransform() override;
		virtual FOculusXRGuardianTestResult GetPointGuardianIntersection(const FVector Point, EOculusXRBoundaryType BoundaryType) override;
		virtual FOculusXRGuardianTestResult GetNodeGuardianIntersection(EOculusXRTrackedDeviceType DeviceType, EOculusXRBoundaryType BoundaryType) override;
		virtual void SetGuardianVisibility(bool GuardianVisible) override;
		virtual bool GetSystemHmd3DofModeEnabled() override;
		virtual EOculusXRColorSpace GetHmdColorDesc() override;
		virtual void SetClientColorDesc(EOculusXRColorSpace ColorSpace) override;
		virtual void SetLocalDimmingOn(bool LocalDimmingOn) override;
		virtual bool IsPassthroughSupported() override;
		virtual bool IsColorPassthroughSupported() override;
		virtual void StartEnvironmentDepth() override;
		virtual void StopEnvironmentDepth() override;
		virtual bool IsEnvironmentDepthStarted() override;
		virtual void SetEnvironmentDepthHandRemoval(bool RemoveHands) override;
		virtual void SetXROcclusionsMode(UObject* WorldContextObject, EOculusXROcclusionsMode Mode) override;
		virtual void SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType EyeBufferSharpenType) override;
		virtual bool IsPassthroughRecommended() override;
	};
} // namespace OculusXRHMD
