// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
#include "OculusXRMR_State.h"
#include "OculusXRMRFunctionLibrary.h"

UOculusXRMR_State::UOculusXRMR_State(const FObjectInitializer& ObjectInitializer)
	: TrackedCamera()
	, TrackingReferenceComponent(nullptr)
	, ScalingFactor(1.0f)
	, ChangeCameraStateRequested(false)
	, BindToTrackedCameraIndexRequested(false)
{
}
