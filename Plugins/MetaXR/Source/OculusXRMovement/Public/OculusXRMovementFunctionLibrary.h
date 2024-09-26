// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRMovementTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OculusXRMovementFunctionLibrary.generated.h"

UCLASS()
class OCULUSXRMOVEMENT_API UOculusXRMovementFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool TryGetBodyState(FOculusXRBodyState& outBodyState, float WorldToMeters = 100.0f);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool IsBodyTrackingEnabled();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool IsBodyTrackingSupported();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool RequestBodyTrackingFidelity(EOculusXRBodyTrackingFidelity fidelity);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool ResetBodyTrackingCalibration();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool SuggestBodyTrackingCalibrationOverride(float height);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool StartBodyTrackingByJointSet(EOculusXRBodyJointSet jointSet);

	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "StartBodyTracking is deprecated, use StartBodyTrackingByJointSet."), Category = "OculusXR|Body")
	static bool StartBodyTracking();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Body")
	static bool StopBodyTracking();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Face")
	static bool TryGetFaceState(FOculusXRFaceState& outFaceState);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Face")
	static bool IsFaceTrackingEnabled();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Face")
	static bool IsFaceTrackingSupported();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Face")
	static bool StartFaceTracking();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Face")
	static bool StopFaceTracking();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Eyes")
	static bool TryGetEyeGazesState(FOculusXREyeGazesState& outEyeGazesState, float WorldToMeters = 100.0f);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Eyes")
	static bool IsEyeTrackingEnabled();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Eyes")
	static bool IsEyeTrackingSupported();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Eyes")
	static bool StartEyeTracking();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Eyes")
	static bool StopEyeTracking();
};
