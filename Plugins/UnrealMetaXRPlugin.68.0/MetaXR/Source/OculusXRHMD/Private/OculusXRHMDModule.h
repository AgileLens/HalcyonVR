// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"
#include "IHeadMountedDisplay.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRHMD_VulkanExtensions.h"
#include "OculusXRPluginWrapper.h"
#include "OpenXR/OculusXRExtensionPluginManager.h"

//-------------------------------------------------------------------------------------------------
// FOculusXRHMDModule
//-------------------------------------------------------------------------------------------------

class FOculusXRHMDModule : public IOculusXRHMDModule
{
public:
	FOculusXRHMDModule();

	static inline FOculusXRHMDModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FOculusXRHMDModule>("OculusXRHMD");
	}

	// IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// IHeadMountedDisplayModule
	virtual FString GetModuleKeyName() const override;
	virtual void GetModuleAliases(TArray<FString>& AliasesOut) const override;
	virtual bool PreInit() override;
	virtual bool IsHMDConnected() override;
	virtual uint64 GetGraphicsAdapterLuid() override;
	virtual FString GetAudioInputDevice() override;
	virtual FString GetAudioOutputDevice() override;
	virtual FString GetDeviceSystemName() override;

	virtual TSharedPtr<class IXRTrackingSystem, ESPMode::ThreadSafe> CreateTrackingSystem() override;
	virtual TSharedPtr<IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe> GetVulkanExtensions() override;
	virtual bool IsStandaloneStereoOnlyDevice() override;

	virtual OculusXR::FOculusXRExtensionPluginManager& GetExtensionPluginManager();

	// IOculusXRHMDModule
	virtual void GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition, bool bUseOrienationForPlayerCamera = false, bool bUsePositionForPlayerCamera = false, const FVector PositionScale = FVector::ZeroVector) override
	{
		UOculusXRFunctionLibrary::GetPose(DeviceRotation, DevicePosition, NeckPosition, bUseOrienationForPlayerCamera, bUsePositionForPlayerCamera, PositionScale);
	}

	virtual void GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds) override
	{
		UOculusXRFunctionLibrary::GetRawSensorData(AngularAcceleration, LinearAcceleration, AngularVelocity, LinearVelocity, TimeInSeconds, EOculusXRTrackedDeviceType::HMD);
	}

	virtual bool GetUserProfile(struct FOculusXRHmdUserProfile& Profile) override
	{
		return UOculusXRFunctionLibrary::GetUserProfile(Profile);
	}

	virtual void SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options) override
	{
		UOculusXRFunctionLibrary::SetBaseRotationAndBaseOffsetInMeters(Rotation, BaseOffsetInMeters, Options);
	}

	virtual void GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters) override
	{
		UOculusXRFunctionLibrary::GetBaseRotationAndBaseOffsetInMeters(OutRotation, OutBaseOffsetInMeters);
	}

	virtual void SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options) override
	{
		UOculusXRFunctionLibrary::SetBaseRotationAndPositionOffset(BaseRot, PosOffset, Options);
	}

	virtual void GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset) override
	{
		UOculusXRFunctionLibrary::GetBaseRotationAndPositionOffset(OutRot, OutPosOffset);
	}

	virtual class IStereoLayers* GetStereoLayers() override
	{
		return UOculusXRFunctionLibrary::GetStereoLayers();
	}

	bool IsOVRPluginAvailable() const
	{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
		return OVRPluginHandle != nullptr;
#else
		return false;
#endif
	}

	// FMetaXRSimulator
	OCULUSXRHMD_API static bool IsSimulatorActivated();
	OCULUSXRHMD_API static void ToggleOpenXRRuntime();

	// FMetaXRSES
	OCULUSXRHMD_API static void LaunchEnvironment(FString EnvironmentName);
	OCULUSXRHMD_API static void LaunchMoreRoomsEnvironment(FString EnvironmentName);
	OCULUSXRHMD_API static void StopServer();

#if OCULUS_HMD_SUPPORTED_PLATFORMS
	OCULUSXRHMD_API static void* GetOVRPluginHandle();
	OCULUSXRHMD_API static OculusPluginWrapper& GetPluginWrapper();
	virtual bool PoseToOrientationAndPosition(const FQuat& InOrientation, const FVector& InPosition, FQuat& OutOrientation, FVector& OutPosition) const override;

protected:
	void SetGraphicsAdapterLuid(uint64 InLuid);

	static OculusPluginWrapper PluginWrapper;

	bool bPreInit;
	bool bPreInitCalled;
	void* OVRPluginHandle;
	uint64 GraphicsAdapterLuid;
	TWeakPtr<IHeadMountedDisplay, ESPMode::ThreadSafe> HeadMountedDisplay;
	TSharedPtr<IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe> VulkanExtensions;
	OculusXR::FOculusXRExtensionPluginManager ExtensionPluginManager;

	friend class ::OculusXRHMD::FOculusXRHMD;

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
};
