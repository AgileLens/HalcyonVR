// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRAnchorManager.h"

namespace OculusXRAnchors
{
	struct FOculusXRSpatialAnchorManager : FOculusXRAnchorManager
	{
		FOculusXRSpatialAnchorManager()
			: FOculusXRAnchorManager()
		{
		}

		static bool CreateSpatialAnchor(const FTransform& InTransform, uint64& OutRequestId);
	};
} // namespace OculusXRAnchors
