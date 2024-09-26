// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRXRFunctions.h"
#include "OpenXRCore.h"
#include "OculusXROpenXRUtilities.h"

namespace OculusXR
{
	TOptional<PFN_xrPerfSettingsSetPerformanceLevelEXT> xrPerfSettingsSetPerformanceLevelEXT = nullptr;

	void InitOpenXRFunctions(XrInstance InInstance)
	{
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPerfSettingsSetPerformanceLevelEXT", &xrPerfSettingsSetPerformanceLevelEXT);
	}

} // namespace OculusXR
