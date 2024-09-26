// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRMovementTypes.h"

namespace XRSpaceFlags
{
	static const uint64 XR_SPACE_LOCATION_ORIENTATION_VALID_BIT = 0x00000001;
	static const uint64 XR_SPACE_LOCATION_POSITION_VALID_BIT = 0x00000002;
	static const uint64 XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT = 0x00000004;
	static const uint64 XR_SPACE_LOCATION_POSITION_TRACKED_BIT = 0x00000008;
} // namespace XRSpaceFlags

struct OCULUSXRMOVEMENT_API OculusXRMovement
{
	static bool GetBodyState(FOculusXRBodyState& outOculusXRBodyState, float WorldToMeters = 100.0f);
	static bool IsBodyTrackingEnabled();
	static bool IsBodyTrackingSupported();
	static bool StartBodyTracking();
	static bool StopBodyTracking();
	static bool StartBodyTrackingByJointSet(EOculusXRBodyJointSet jointSet);
	static bool RequestBodyTrackingFidelity(EOculusXRBodyTrackingFidelity fidelity);
	static bool ResetBodyTrackingCalibration();
	static bool SuggestBodyTrackingCalibrationOverride(float height);
	static bool GetBodySkeleton(FOculusXRBodySkeleton& outOculusXRBodyState, float WorldToMeters = 100.0f);

private:
	static bool IsFullBodyTrackingEnabled();

public:
	static bool GetFaceState(FOculusXRFaceState& outOculusXRFaceState);
	static bool IsFaceTrackingEnabled();
	static bool IsFaceTrackingSupported();
	static bool StartFaceTracking();
	static bool StopFaceTracking();

	static bool GetEyeGazesState(FOculusXREyeGazesState& outOculusXREyeGazesState, float WorldToMeters = 100.0f);
	static bool IsEyeTrackingEnabled();
	static bool IsEyeTrackingSupported();
	static bool StartEyeTracking();
	static bool StopEyeTracking();
};
