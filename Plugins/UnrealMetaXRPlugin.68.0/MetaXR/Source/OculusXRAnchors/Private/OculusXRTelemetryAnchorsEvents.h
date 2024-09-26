// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRTelemetry.h"

namespace OculusXRTelemetry::Events
{
	using FAnchorsCreate = TMarker<191967648>;
	using FAnchorsCreateRequest = TScopedMarker<FAnchorsCreate, EScopeMode::Start>;
	using FAnchorsCreateResponse = TScopedMarker<FAnchorsCreate, EScopeMode::End>;
	using FAnchorsSetComponentStatus = TMarker<191962330>;
	using FAnchorsSetComponentStatusRequest = TScopedMarker<FAnchorsSetComponentStatus, EScopeMode::Start>;
	using FAnchorsSetComponentStatusResponse = TScopedMarker<FAnchorsSetComponentStatus, EScopeMode::End>;
	using FAnchorsSave = TMarker<191961984>;
	using FAnchorsSaveRequest = TScopedMarker<FAnchorsSave, EScopeMode::Start>;
	using FAnchorsSaveResponse = TScopedMarker<FAnchorsSave, EScopeMode::End>;
	using FAnchorsQuery = TMarker<191959258>;
	using FAnchorsQueryRequest = TScopedMarker<FAnchorsQuery, EScopeMode::Start>;
	using FAnchorsQueryResponse = TScopedMarker<FAnchorsQuery, EScopeMode::End>;
	using FAnchorsErase = TMarker<191960591>;
	using FAnchorsEraseRequest = TScopedMarker<FAnchorsErase, EScopeMode::Start>;
	using FAnchorsEraseResponse = TScopedMarker<FAnchorsErase, EScopeMode::End>;
} // namespace OculusXRTelemetry::Events
