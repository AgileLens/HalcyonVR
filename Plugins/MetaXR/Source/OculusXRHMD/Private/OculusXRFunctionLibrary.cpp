// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRFunctionLibrary.h"
#include "OculusXRFunctionLibraryOpenXR.h"
#include "OculusXRFunctionLibraryOVR.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMD.h"
#include "Logging/MessageLog.h"

#define LOCTEXT_NAMESPACE "OculusFunctionLibrary"

//-------------------------------------------------------------------------------------------------
// UOculusXRFunctionLibrary
//-------------------------------------------------------------------------------------------------

TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> UOculusXRFunctionLibrary::FunctionLibraryImpl = nullptr;

TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> UOculusXRFunctionLibrary::GetOculusXRFunctionImpl()
{
	if (FunctionLibraryImpl == nullptr)
	{
		const FName SystemName(TEXT("OpenXR"));
		const bool IsOpenXR = GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName);

		if (IsOpenXR)
		{
			FunctionLibraryImpl = MakeShared<OculusXRHMD::FOculusXRFunctionLibraryOpenXR>();
		}
		else
		{
			FunctionLibraryImpl = MakeShared<OculusXRHMD::FOculusXRFunctionLibraryOVR>();
		}
	}
	return FunctionLibraryImpl;
}

void UOculusXRFunctionLibrary::ShutdownXRFunctionLibrary()
{
	FunctionLibraryImpl = nullptr;
}

UOculusXRFunctionLibrary::UOculusXRFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

OculusXRHMD::FOculusXRHMD* UOculusXRFunctionLibrary::GetOculusXRHMD()
{
	return OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
}

void UOculusXRFunctionLibrary::GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition, bool bUseOrienationForPlayerCamera, bool bUsePositionForPlayerCamera, const FVector PositionScale)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetPose(DeviceRotation, DevicePosition, NeckPosition);
	}
	else
#endif
	{
		DeviceRotation = FRotator::ZeroRotator;
		DevicePosition = FVector::ZeroVector;
		NeckPosition = FVector::ZeroVector;
	}
}

void UOculusXRFunctionLibrary::SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetBaseRotationAndBaseOffsetInMeters(Rotation, BaseOffsetInMeters, Options);
	}
#endif
}

void UOculusXRFunctionLibrary::GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetBaseRotationAndBaseOffsetInMeters(OutRotation, OutBaseOffsetInMeters);
	}
#endif
}

void UOculusXRFunctionLibrary::GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds, EOculusXRTrackedDeviceType DeviceType)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetRawSensorData(AngularAcceleration, LinearAcceleration, AngularVelocity, LinearVelocity, TimeInSeconds, DeviceType);
	}
#endif
}

bool UOculusXRFunctionLibrary::IsDeviceTracked(EOculusXRTrackedDeviceType DeviceType)
{
	bool bIsDeviceTracked = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsDeviceTracked = Impl->IsDeviceTracked(DeviceType);
	}
#endif
	return bIsDeviceTracked;
}

void UOculusXRFunctionLibrary::GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetSuggestedCpuAndGpuPerformanceLevels(CpuPerfLevel, GpuPerfLevel);
	}
#endif
}

void UOculusXRFunctionLibrary::SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetSuggestedCpuAndGpuPerformanceLevels(CpuPerfLevel, GpuPerfLevel);
	}
#endif
}

void UOculusXRFunctionLibrary::SetCPUAndGPULevels(int CPULevel, int GPULevel)
{
	// Deprecated. Please use Get/SetSuggestedCpuAndGpuPerformanceLevels instead.
}

bool UOculusXRFunctionLibrary::GetUserProfile(FOculusXRHmdUserProfile& Profile)
{
	bool bGetUserProfile = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bGetUserProfile = Impl->GetUserProfile(Profile);
	}
#endif
	return bGetUserProfile;
}

void UOculusXRFunctionLibrary::SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetBaseRotationAndPositionOffset(BaseRot, PosOffset, Options);
	}
#endif
}

void UOculusXRFunctionLibrary::GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetBaseRotationAndPositionOffset(OutRot, OutPosOffset);
	}
#endif
}

void UOculusXRFunctionLibrary::AddLoadingSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters, FRotator DeltaRotation, bool bClearBeforeAdd)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->AddLoadingSplashScreen(Texture, TranslationInMeters, Rotation, SizeInMeters, DeltaRotation, bClearBeforeAdd);
	}
#endif
}

void UOculusXRFunctionLibrary::ClearLoadingSplashScreens()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->ClearLoadingSplashScreens();
	}
#endif
}

bool UOculusXRFunctionLibrary::HasInputFocus()
{
	bool bHasInputFocus = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bHasInputFocus = Impl->HasInputFocus();
	}
#endif
	return bHasInputFocus;
}

bool UOculusXRFunctionLibrary::HasSystemOverlayPresent()
{
	bool bHasSystemOverlayPresent = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bHasSystemOverlayPresent = Impl->HasSystemOverlayPresent();
	}
#endif
	return bHasSystemOverlayPresent;
}

void UOculusXRFunctionLibrary::GetGPUUtilization(bool& IsGPUAvailable, float& GPUUtilization)
{
	GPUUtilization = 0.0f;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetGPUUtilization(IsGPUAvailable, GPUUtilization);
	}
#endif
}

float UOculusXRFunctionLibrary::GetGPUFrameTime()
{
	float FrameTime = 0;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		FrameTime = Impl->GetGPUFrameTime();
	}
#endif
	return FrameTime;
}

void UOculusXRFunctionLibrary::GetPerformanceMetrics(FOculusXRPerformanceMetrics& PerformanceMetrics)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->GetPerformanceMetrics(PerformanceMetrics);
	}
#endif
}


EOculusXRFoveatedRenderingMethod UOculusXRFunctionLibrary::GetFoveatedRenderingMethod()
{
	EOculusXRFoveatedRenderingMethod FoveatedRenderingMethod = EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		FoveatedRenderingMethod = Impl->GetFoveatedRenderingMethod();
	}
#endif
	return FoveatedRenderingMethod;
}

void UOculusXRFunctionLibrary::SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod Method)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetFoveatedRenderingMethod(Method);
	}
#endif
}

void UOculusXRFunctionLibrary::SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel level, bool isDynamic)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetFoveatedRenderingLevel(level, isDynamic);
	}
#endif
}

EOculusXRFoveatedRenderingLevel UOculusXRFunctionLibrary::GetFoveatedRenderingLevel()
{
	EOculusXRFoveatedRenderingLevel FoveatedRenderingLevel = EOculusXRFoveatedRenderingLevel::Off;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		FoveatedRenderingLevel = Impl->GetFoveatedRenderingLevel();
	}
#endif
	return FoveatedRenderingLevel;
}

bool UOculusXRFunctionLibrary::GetEyeTrackedFoveatedRenderingSupported()
{
	bool bEyeTrackedFoveatedRenderingSupported = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bEyeTrackedFoveatedRenderingSupported = Impl->GetEyeTrackedFoveatedRenderingSupported();
	}
#endif
	return bEyeTrackedFoveatedRenderingSupported;
}

FString UOculusXRFunctionLibrary::GetDeviceName()
{
	FString DeviceName;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		DeviceName = Impl->GetDeviceName();
	}
#endif
	return DeviceName;
}

EOculusXRDeviceType UOculusXRFunctionLibrary::GetDeviceType()
{
	EOculusXRDeviceType DeviceType = EOculusXRDeviceType::OculusUnknown;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		DeviceType = Impl->GetDeviceType();
	}
#endif
	return DeviceType;
}

EOculusXRControllerType UOculusXRFunctionLibrary::GetControllerType(EControllerHand deviceHand)
{
	EOculusXRControllerType ControllerType = EOculusXRControllerType::Unknown;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		ControllerType = Impl->GetControllerType(deviceHand);
	}
#endif
	return ControllerType;
}

TArray<float> UOculusXRFunctionLibrary::GetAvailableDisplayFrequencies()
{
	TArray<float> FreqArray;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		FreqArray = Impl->GetAvailableDisplayFrequencies();
	}
#endif
	return FreqArray;
}

float UOculusXRFunctionLibrary::GetCurrentDisplayFrequency()
{
	float Frequency = 0.0f;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Frequency = Impl->GetCurrentDisplayFrequency();
	}
#endif
	return Frequency;
}

void UOculusXRFunctionLibrary::SetDisplayFrequency(float RequestedFrequency)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetDisplayFrequency(RequestedFrequency);
	}
#endif
}

void UOculusXRFunctionLibrary::EnablePositionTracking(bool bPositionTracking)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->EnablePositionTracking(bPositionTracking);
	}
#endif
}

void UOculusXRFunctionLibrary::EnableOrientationTracking(bool bOrientationTracking)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->EnableOrientationTracking(bOrientationTracking);
	}
#endif
}

void UOculusXRFunctionLibrary::SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetColorScaleAndOffset(ColorScale, ColorOffset, bApplyToAllLayers);
	}
#endif
}

class IStereoLayers* UOculusXRFunctionLibrary::GetStereoLayers()
{
	IStereoLayers* Layers = nullptr;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Layers = Impl->GetStereoLayers();
	}
#endif
	return Layers;
}

bool UOculusXRFunctionLibrary::IsGuardianConfigured()
{
	bool bIsGuardianConfigured = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsGuardianConfigured = Impl->IsGuardianConfigured();
	}
#endif
	return bIsGuardianConfigured;
}

bool UOculusXRFunctionLibrary::IsGuardianDisplayed()
{
	bool bIsGuardianDisplayed = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsGuardianDisplayed = Impl->IsGuardianDisplayed();
	}
#endif
	return bIsGuardianDisplayed;
}

TArray<FVector> UOculusXRFunctionLibrary::GetGuardianPoints(EOculusXRBoundaryType BoundaryType, bool UsePawnSpace /* = false */)
{
	TArray<FVector> BoundaryPointList;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		BoundaryPointList = Impl->GetGuardianPoints(BoundaryType, UsePawnSpace);
	}
#endif
	return BoundaryPointList;
}

FVector UOculusXRFunctionLibrary::GetGuardianDimensions(EOculusXRBoundaryType BoundaryType)
{
	FVector Dimensions = FVector::ZeroVector;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Dimensions = Impl->GetGuardianDimensions(BoundaryType);
	}
#endif
	return Dimensions;
}

FTransform UOculusXRFunctionLibrary::GetPlayAreaTransform()
{
	FTransform Transform;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Transform = Impl->GetPlayAreaTransform();
	}
#endif
	return Transform;
}

FOculusXRGuardianTestResult UOculusXRFunctionLibrary::GetPointGuardianIntersection(const FVector Point, EOculusXRBoundaryType BoundaryType)
{
	FOculusXRGuardianTestResult InteractionInfo;
	memset(&InteractionInfo, 0, sizeof(FOculusXRGuardianTestResult));
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		InteractionInfo = Impl->GetPointGuardianIntersection(Point, BoundaryType);
	}
#endif
	return InteractionInfo;
}

FOculusXRGuardianTestResult UOculusXRFunctionLibrary::GetNodeGuardianIntersection(EOculusXRTrackedDeviceType DeviceType, EOculusXRBoundaryType BoundaryType)
{
	FOculusXRGuardianTestResult InteractionInfo;
	memset(&InteractionInfo, 0, sizeof(FOculusXRGuardianTestResult));
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		InteractionInfo = Impl->GetNodeGuardianIntersection(DeviceType, BoundaryType);
	}
#endif
	return InteractionInfo;
}

void UOculusXRFunctionLibrary::SetGuardianVisibility(bool GuardianVisible)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetGuardianVisibility(GuardianVisible);
	}
#endif
}

bool UOculusXRFunctionLibrary::GetSystemHmd3DofModeEnabled()
{
	bool bGetSystemHmd3DofModeEnabled = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bGetSystemHmd3DofModeEnabled = Impl->GetSystemHmd3DofModeEnabled();
	}
#endif
	return bGetSystemHmd3DofModeEnabled;
}

EOculusXRColorSpace UOculusXRFunctionLibrary::GetHmdColorDesc()
{
	EOculusXRColorSpace HmdColorSpace = EOculusXRColorSpace::Unknown;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		HmdColorSpace = Impl->GetHmdColorDesc();
	}
#endif
	return HmdColorSpace;
}

void UOculusXRFunctionLibrary::SetClientColorDesc(EOculusXRColorSpace ColorSpace)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetClientColorDesc(ColorSpace);
	}
#endif
}

void UOculusXRFunctionLibrary::SetLocalDimmingOn(bool LocalDimmingOn)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetLocalDimmingOn(LocalDimmingOn);
	}
#endif
}

bool UOculusXRFunctionLibrary::IsPassthroughSupported()
{
	bool bIsPassthroughSupported = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsPassthroughSupported = Impl->IsPassthroughSupported();
	}
#endif
	return bIsPassthroughSupported;
}

bool UOculusXRFunctionLibrary::IsColorPassthroughSupported()
{
	bool bIsColorPassthroughSupported = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsColorPassthroughSupported = Impl->IsColorPassthroughSupported();
	}
#endif
	return bIsColorPassthroughSupported;
}

void UOculusXRFunctionLibrary::StartEnvironmentDepth()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->StartEnvironmentDepth();
	}
#endif
}

void UOculusXRFunctionLibrary::StopEnvironmentDepth()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->StopEnvironmentDepth();
	}
#endif
}

bool UOculusXRFunctionLibrary::IsEnvironmentDepthStarted()
{
	bool bIsEnvironmentDepthStarted = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsEnvironmentDepthStarted = Impl->IsEnvironmentDepthStarted();
	}
#endif
	return bIsEnvironmentDepthStarted;
}

void UOculusXRFunctionLibrary::SetEnvironmentDepthHandRemoval(bool RemoveHands)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetEnvironmentDepthHandRemoval(RemoveHands);
	}
#endif
}

void UOculusXRFunctionLibrary::SetXROcclusionsMode(UObject* WorldContextObject, EOculusXROcclusionsMode Mode)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetXROcclusionsMode(WorldContextObject, Mode);
	}
#endif
}

void UOculusXRFunctionLibrary::SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType EyeBufferSharpenType)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		Impl->SetEyeBufferSharpenType(EyeBufferSharpenType);
	}
#endif
}

bool UOculusXRFunctionLibrary::IsPassthroughRecommended()
{
	bool bIsPassthroughRecommended = false;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	TSharedPtr<OculusXRHMD::IOculusXRFunctionLibrary> Impl = GetOculusXRFunctionImpl();
	if (Impl != nullptr)
	{
		bIsPassthroughRecommended = Impl->IsPassthroughRecommended();
	}
#endif
	return bIsPassthroughRecommended;
}
#undef LOCTEXT_NAMESPACE
