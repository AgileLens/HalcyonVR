// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRAnchorTypes.h"
#include "OculusXRSceneTypes.h"

namespace OculusXRScene
{
	struct OCULUSXRSCENE_API FOculusXRScene
	{

		// Requests to change the current boundary visibility
		static EOculusXRAnchorResult::Type RequestBoundaryVisibility(EOculusXRBoundaryVisibility NewVisibilityRequest);

		// Gets the current boundary visibility
		static EOculusXRAnchorResult::Type GetBoundaryVisibility(EOculusXRBoundaryVisibility& OutVisibility);
	};
} // namespace OculusXRScene
