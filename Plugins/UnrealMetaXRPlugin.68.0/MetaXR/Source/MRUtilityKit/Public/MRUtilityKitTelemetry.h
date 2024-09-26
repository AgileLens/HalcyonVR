// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRTelemetry.h"

namespace MRUKTelemetry
{
	using FLoadPluginMarker = OculusXRTelemetry::TMarker<257245155>;
	using FLoadGuardianMarker = OculusXRTelemetry::TMarker<257237531>;
	using FLoadBlobShadowMarker = OculusXRTelemetry::TMarker<257244458>;
	using FLoadLightDispatcherMarker = OculusXRTelemetry::TMarker<257234454>;
	using FLoadDebugComponentMarker = OculusXRTelemetry::TMarker<257232584>;
	using FLoadAnchorActorSpawnerMarker = OculusXRTelemetry::TMarker<257232670>;
	using FLoadSceneFromDeviceMarker = OculusXRTelemetry::TMarker<257235234>;
	using FLoadSceneFromJsonMarker = OculusXRTelemetry::TMarker<257237876>;
	using FLoadGridSliceResizerMarker = OculusXRTelemetry::TMarker<257238248>;
} // namespace MRUKTelemetry
