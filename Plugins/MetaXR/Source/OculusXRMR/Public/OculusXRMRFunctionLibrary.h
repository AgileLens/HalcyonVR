// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OculusXRMRFunctionLibrary.generated.h"

class USceneComponent;
class UOculusXRMR_Settings;
struct FOculusXRTrackedCamera;

namespace OculusXRHMD
{
	class FOculusXRHMD;
}

UCLASS()
class OCULUSXRMR_API UOculusXRMRFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	// Get the OculusXRMR settings object
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR", meta = (DisplayName = "Get Oculus MR Settings"))
	static UOculusXRMR_Settings* GetOculusXRMRSettings();

	// Get the component that the OculusXRMR camera is tracking. When this is null, the camera will track the player pawn.
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR")
	static USceneComponent* GetTrackingReferenceComponent();

	// Set the component for the OculusXRMR camera to track. If this is set to null, the camera will track the player pawn.
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR")
	static bool SetTrackingReferenceComponent(USceneComponent* Component);

	// Get the scaling factor for the MRC configuration. Returns 0 if not available.
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR", meta = (DisplayName = "Get MRC Scaling Factor"))
	static float GetMrcScalingFactor();

	// Set the scaling factor for the MRC configuration. This should be a positive value set to the same scaling as the VR player pawn so that the game capture and camera video are aligned.
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR", meta = (DisplayName = "Set MRC Scaling Factor"))
	static bool SetMrcScalingFactor(float ScalingFactor = 1.0f);

	// Check if MRC is enabled
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR")
	static bool IsMrcEnabled();

	// Check if MRC is enabled and actively capturing
	UFUNCTION(BlueprintCallable, Category = "OculusLibrary|MR")
	static bool IsMrcActive();

public:
	static class OculusXRHMD::FOculusXRHMD* GetOculusXRHMD();

	/** Retrieve an array of all (calibrated) tracked cameras which were calibrated through the CameraTool */
	static void GetAllTrackedCamera(TArray<FOculusXRTrackedCamera>& TrackedCameras, bool bCalibratedOnly = true);

	static bool GetTrackingReferenceLocationAndRotationInWorldSpace(USceneComponent* TrackingReferenceComponent, FVector& TRLocation, FRotator& TRRotation);
};
