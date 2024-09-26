// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRAnchorComponent.h"
#include "OculusXRSceneAnchorComponent.generated.h"

/**
 * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead
 * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)
 */
UCLASS(meta = (DisplayName = "OculusXR Scene Anchor Component", BlueprintSpawnableComponent))
class OCULUSXRSCENE_API UOculusXRSceneAnchorComponent : public UOculusXRAnchorComponent
{
	GENERATED_BODY()

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UOculusXRSceneAnchorComponent(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Transient, BlueprintReadOnly, Category = "OculusXR|Scene Anchor Component")
	TArray<FString> SemanticClassifications;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "OculusXR|Scene Anchor Component")
	FOculusXRUInt64 RoomSpaceID = 0;
};
