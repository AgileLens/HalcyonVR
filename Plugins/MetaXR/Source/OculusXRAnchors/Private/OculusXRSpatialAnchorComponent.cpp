// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSpatialAnchorComponent.h"

DEFINE_LOG_CATEGORY(LogOculusSpatialAnchor);

UOculusXRSpatialAnchorComponent::UOculusXRSpatialAnchorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UOculusXRSpatialAnchorComponent::Create(const FTransform& NewAnchorTransform, AActor* OwningActor, const FOculusXRSpatialAnchorCreateDelegate& Callback)
{
	EOculusXRAnchorResult::Type AnchorResult;
	return OculusXRAnchors::FOculusXRAnchors::CreateSpatialAnchor(NewAnchorTransform, OwningActor, Callback, AnchorResult);
}

bool UOculusXRSpatialAnchorComponent::Erase(const FOculusXRAnchorEraseDelegate& Callback)
{
	EOculusXRAnchorResult::Type AnchorResult;
	return OculusXRAnchors::FOculusXRAnchors::EraseAnchor(this, Callback, AnchorResult);
}

bool UOculusXRSpatialAnchorComponent::Save(EOculusXRSpaceStorageLocation Location, const FOculusXRAnchorSaveDelegate& Callback)
{
	EOculusXRAnchorResult::Type AnchorResult;
	return OculusXRAnchors::FOculusXRAnchors::SaveAnchor(this, Location, Callback, AnchorResult);
}
