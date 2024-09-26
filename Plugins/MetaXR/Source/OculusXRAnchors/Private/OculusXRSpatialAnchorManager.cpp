// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSpatialAnchorManager.h"
#include "OculusXRAnchorBPFunctionLibrary.h"

namespace OculusXRAnchors
{
	bool FOculusXRSpatialAnchorManager::CreateSpatialAnchor(const FTransform& InTransform, uint64& OutRequestId)
	{
		EOculusXRAnchorResult::Type Result = CreateAnchor(InTransform, OutRequestId, FTransform::Identity);
		return UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(Result);
	}
} // namespace OculusXRAnchors
