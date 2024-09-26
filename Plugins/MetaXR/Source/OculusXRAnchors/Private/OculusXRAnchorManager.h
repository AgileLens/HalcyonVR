// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRAnchorComponent.h"
#include "OculusXRHMDPrivate.h"
#include "OVR_Plugin_Types.h"

namespace OculusXRAnchors
{
	struct OCULUSXRANCHORS_API FOculusXRAnchorManager
	{
		static EOculusXRAnchorResult::Type CreateAnchor(const FTransform& InTransform, uint64& OutRequestId, const FTransform& CameraTransform);
		static EOculusXRAnchorResult::Type DestroySpace(uint64 Space);
		static EOculusXRAnchorResult::Type SetSpaceComponentStatus(uint64 Space, EOculusXRSpaceComponentType SpaceComponentType, bool Enable, float Timeout, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type GetSpaceComponentStatus(uint64 Space, EOculusXRSpaceComponentType SpaceComponentType, bool& OutEnabled, bool& OutChangePending);
		static EOculusXRAnchorResult::Type GetSupportedAnchorComponents(uint64 Handle, TArray<EOculusXRSpaceComponentType>& OutSupportedTypes);
		static EOculusXRAnchorResult::Type SaveAnchor(uint64 Space, EOculusXRSpaceStorageLocation StorageLocation, EOculusXRSpaceStoragePersistenceMode StoragePersistenceMode, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type SaveAnchorList(const TArray<uint64>& Spaces, EOculusXRSpaceStorageLocation StorageLocation, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type EraseAnchor(uint64 AnchorHandle, EOculusXRSpaceStorageLocation StorageLocation, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type QuerySpaces(const FOculusXRSpaceQueryInfo& QueryInfo, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type ShareSpaces(const TArray<uint64>& Spaces, const TArray<uint64>& UserIds, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type GetSpaceContainerUUIDs(uint64 Space, TArray<FOculusXRUUID>& OutUUIDs);
		static EOculusXRAnchorResult::Type GetSpaceScenePlane(uint64 Space, FVector& OutPos, FVector& OutSize);
		static EOculusXRAnchorResult::Type GetSpaceSceneVolume(uint64 Space, FVector& OutPos, FVector& OutSize);
		static EOculusXRAnchorResult::Type GetSpaceSemanticClassification(uint64 Space, TArray<FString>& OutSemanticClassification);
		static EOculusXRAnchorResult::Type GetSpaceContainer(uint64 Space, TArray<FOculusXRUUID>& OutContainerUuids);
		static EOculusXRAnchorResult::Type GetSpaceBoundary2D(uint64 Space, TArray<FVector2f>& OutVertices);
		static EOculusXRAnchorResult::Type DiscoverSpaces(const FOculusXRSpaceDiscoveryInfo& DiscoveryInfo, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type SaveSpaces(const TArray<uint64>& Spaces, uint64& OutRequestId);
		static EOculusXRAnchorResult::Type EraseSpaces(const TArray<FOculusXRUInt64>& Handles, const TArray<FOculusXRUUID>& UUIDs, uint64& OutRequestId);


		static void OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult);
	};
} // namespace OculusXRAnchors
