// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRAnchorComponents.h"

#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRAnchorManager.h"
#include "OculusXRRoomLayoutManager.h"
#include "OculusXRSpatialAnchorComponent.h"

bool UOculusXRBaseAnchorComponent::IsComponentEnabled() const
{
	bool OutEnabled;
	bool OutChangePending;

	auto OutResult = OculusXRAnchors::FOculusXRAnchorManager::GetSpaceComponentStatus(Space, Type, OutEnabled, OutChangePending);
	return UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(OutResult) && OutEnabled;
}

EOculusXRSpaceComponentType UOculusXRBaseAnchorComponent::GetType() const
{
	return Type;
}

uint64 UOculusXRBaseAnchorComponent::GetSpace() const
{
	return Space;
}

bool UOculusXRLocatableAnchorComponent::GetTransform(FTransform& outTransform) const
{
	ensure(IsComponentEnabled());

	if (!UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(Space, outTransform))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching transform failed."));
		return false;
	}
	return true;
}

bool UOculusXRPlaneAnchorComponent::GetPositionAndSize(FVector& outPosition, FVector& outSize) const
{
	ensure(IsComponentEnabled());

	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(OculusXRAnchors::FOculusXRAnchorManager::GetSpaceScenePlane(Space, outPosition, outSize)))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching scene plane failed."));
		return false;
	}

	return true;
}

bool UOculusXRVolumeAnchorComponent::GetPositionAndSize(FVector& outPosition, FVector& outSize) const
{
	ensure(IsComponentEnabled());

	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(OculusXRAnchors::FOculusXRAnchorManager::GetSpaceSceneVolume(Space, outPosition, outSize)))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching scene plane failed."));
		return false;
	}

	return true;
}

bool UOculusXRSemanticClassificationAnchorComponent::GetSemanticClassifications(TArray<FString>& outClassifications) const
{
	ensure(IsComponentEnabled());

	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(OculusXRAnchors::FOculusXRAnchorManager::GetSpaceSemanticClassification(Space, outClassifications)))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching scene volume failed."));
		return false;
	}

	return true;
}

bool UOculusXRRoomLayoutAnchorComponent::GetRoomLayout(FOculusXRUUID& outFloorUUID, FOculusXRUUID& outCeilingUUID, TArray<FOculusXRUUID>& outWallsUUIDs) const
{
	ensure(IsComponentEnabled());

	if (!OculusXRAnchors::FOculusXRRoomLayoutManager::GetSpaceRoomLayout(Space, 64, outCeilingUUID, outFloorUUID, outWallsUUIDs))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching room layout failed."));
		return false;
	}

	return true;
}

bool UOculusXRSpaceContainerAnchorComponent::GetUUIDs(TArray<FOculusXRUUID>& outUUIDs) const
{
	ensure(IsComponentEnabled());

	if (!OculusXRAnchors::FOculusXRAnchorManager::GetSpaceContainer(Space, outUUIDs))
	{
		UE_LOG(LogOculusSpatialAnchor, Warning, TEXT("Fetching container uuids failed."));
		return false;
	}

	return true;
}
