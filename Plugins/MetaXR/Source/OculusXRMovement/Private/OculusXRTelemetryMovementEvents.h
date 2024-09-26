// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRTelemetry.h"

namespace OculusXRTelemetry::Events
{
	using FMovementSDKLiveLinkCreated = TMarker<191961034>;
	using FMovementSDKLiveLinkInit = TMarker<191970472>;
	using FMovementSDKBodyStart = TMarker<191958900>;
	using FMovementSDKFaceStart = TMarker<191966310>;
	using FMovementSDKEyeStart = TMarker<191969182>;
} // namespace OculusXRTelemetry::Events
