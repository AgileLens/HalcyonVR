// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRAnchorComponent.h"
#include "OculusXRHMDPrivate.h"

namespace OculusXRAnchors
{
	struct FOculusXRRoomLayoutManager
	{
		static bool RequestSceneCapture(uint64& OutRequestID);
		static bool GetSpaceRoomLayout(const uint64 Space, const uint32 MaxWallsCapacity,
			FOculusXRUUID& OutCeilingUuid, FOculusXRUUID& OutFloorUuid, TArray<FOculusXRUUID>& OutWallsUuid);

		static bool GetSpaceTriangleMesh(uint64 Space, TArray<FVector>& Vertices, TArray<int32>& Triangles);

		static void OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult);
	};
} // namespace OculusXRAnchors
