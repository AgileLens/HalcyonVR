// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovementFunctionLibrary.h"

#include "IOculusXRMovementModule.h"
#include "LiveLinkOculusXRMovementSourceFactory.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRMovement.h"
#include "OculusXRHMD.h"
#include "OculusXRMovementLiveLink.h"

bool UOculusXRMovementFunctionLibrary::TryGetBodyState(FOculusXRBodyState& outBodyState, float WorldToMeters)
{
	return OculusXRMovement::GetBodyState(outBodyState, WorldToMeters);
}

bool UOculusXRMovementFunctionLibrary::IsBodyTrackingEnabled()
{
	return OculusXRMovement::IsBodyTrackingEnabled();
}

bool UOculusXRMovementFunctionLibrary::IsBodyTrackingSupported()
{
	return OculusXRMovement::IsBodyTrackingSupported();
}

bool UOculusXRMovementFunctionLibrary::RequestBodyTrackingFidelity(EOculusXRBodyTrackingFidelity fidelity)
{
	return OculusXRMovement::RequestBodyTrackingFidelity(fidelity);
}

bool UOculusXRMovementFunctionLibrary::ResetBodyTrackingCalibration()
{
	return OculusXRMovement::ResetBodyTrackingCalibration();
}

bool UOculusXRMovementFunctionLibrary::SuggestBodyTrackingCalibrationOverride(float height)
{
	return OculusXRMovement::SuggestBodyTrackingCalibrationOverride(height);
}

bool UOculusXRMovementFunctionLibrary::StartBodyTrackingByJointSet(EOculusXRBodyJointSet jointSet)
{
	return OculusXRMovement::StartBodyTrackingByJointSet(jointSet);
}

bool UOculusXRMovementFunctionLibrary::StartBodyTracking()
{
	return OculusXRMovement::StartBodyTracking();
}

bool UOculusXRMovementFunctionLibrary::StopBodyTracking()
{
	return OculusXRMovement::StopBodyTracking();
}

bool UOculusXRMovementFunctionLibrary::TryGetFaceState(FOculusXRFaceState& outFaceState)
{
	return OculusXRMovement::GetFaceState(outFaceState);
}

bool UOculusXRMovementFunctionLibrary::IsFaceTrackingEnabled()
{
	return OculusXRMovement::IsFaceTrackingEnabled();
}

bool UOculusXRMovementFunctionLibrary::IsFaceTrackingSupported()
{
	return OculusXRMovement::IsFaceTrackingSupported();
}

bool UOculusXRMovementFunctionLibrary::StartFaceTracking()
{
	return OculusXRMovement::StartFaceTracking();
}

bool UOculusXRMovementFunctionLibrary::StopFaceTracking()
{
	return OculusXRMovement::StopFaceTracking();
}

bool UOculusXRMovementFunctionLibrary::TryGetEyeGazesState(FOculusXREyeGazesState& outEyeGazesState, float WorldToMeters)
{
	return OculusXRMovement::GetEyeGazesState(outEyeGazesState, WorldToMeters);
}

bool UOculusXRMovementFunctionLibrary::IsEyeTrackingEnabled()
{
	return OculusXRMovement::IsEyeTrackingEnabled();
}

bool UOculusXRMovementFunctionLibrary::IsEyeTrackingSupported()
{
	return OculusXRMovement::IsEyeTrackingSupported();
}

bool UOculusXRMovementFunctionLibrary::StartEyeTracking()
{
	return OculusXRMovement::StartEyeTracking();
}

bool UOculusXRMovementFunctionLibrary::StopEyeTracking()
{
	return OculusXRMovement::StopEyeTracking();
}
