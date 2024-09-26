// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "GameFramework/Actor.h"
#include "MeshActor.generated.h"

UCLASS()
class AMeshActor : public AActor
{
	GENERATED_BODY()

public:
	UStaticMeshComponent* Mesh;

public:
	AMeshActor();
};
