// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MeshActor.h"
#include "UObject/ConstructorHelpers.h"

AMeshActor::AMeshActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeFinder(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	if (CubeFinder.Succeeded())
	{
		Mesh->SetStaticMesh(CubeFinder.Object);
	}
	SetRootComponent(Mesh);
}
