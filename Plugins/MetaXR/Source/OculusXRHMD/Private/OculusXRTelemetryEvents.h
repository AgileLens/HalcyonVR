// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRTelemetry.h"

namespace OculusXRTelemetry::Events
{
	using FEditorConsent = TMarker<191965622>;
	using FSimulator = TMarker<191963436>;
	constexpr const char* ConsentOriginKey = "Origin";
} // namespace OculusXRTelemetry::Events
