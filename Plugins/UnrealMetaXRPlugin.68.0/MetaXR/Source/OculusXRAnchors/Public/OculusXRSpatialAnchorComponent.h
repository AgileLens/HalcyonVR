// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRAnchorComponent.h"
#include "OculusXRAnchors.h"
#include "OculusXRSpatialAnchorComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusSpatialAnchor, Log, All);

UCLASS(meta = (DisplayName = "Oculus Spatial Anchor Component", BlueprintSpawnableComponent))
class OCULUSXRANCHORS_API UOculusXRSpatialAnchorComponent : public UOculusXRAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRSpatialAnchorComponent(const FObjectInitializer& ObjectInitializer);

	static bool Create(const FTransform& NewAnchorTransform, AActor* OwningActor, const FOculusXRSpatialAnchorCreateDelegate& Callback);

	bool Erase(const FOculusXRAnchorEraseDelegate& Callback);
	bool Save(EOculusXRSpaceStorageLocation Location, const FOculusXRAnchorSaveDelegate& Callback);

private:
};
