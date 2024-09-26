// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRTelemetry.h"

namespace OculusXRTelemetry::Events
{
	using FProjectSetupToolIgnore = TMarker<191964172>;
	using FProjectSetupToolFix = TMarker<191966457>;
	using FProjectSetupToolOption = TMarker<191964194>;
	using FProjectSetupToolSummary = TMarker<191966987>;
	using FProjectSetupToolOpen = TMarker<191967598>;
	using FProjectSetupToolClose = TMarker<191957393>;
	using FProjectSetupToolNext = TMarker<191956372>;
	using FProjectSetupToolPrev = TMarker<191956161>;
	using FProjectSetupToolTutorialClose = TMarker<191962723>;
} // namespace OculusXRTelemetry::Events

namespace OculusXRTelemetry::Annotations
{
	constexpr const char* Uid = "Uid";
	constexpr const char* Level = "Level";
	constexpr const char* Type = "Type";
	constexpr const char* Value = "Value";
	constexpr const char* BuildTargetGroup = "BuildTargetGroup";
	constexpr const char* Count = "Count";
	constexpr const char* Group = "Group";
	constexpr const char* Origin = "Origin";
	constexpr const char* TutorialCompleted = "TutorialCompleted";
} // namespace OculusXRTelemetry::Annotations
