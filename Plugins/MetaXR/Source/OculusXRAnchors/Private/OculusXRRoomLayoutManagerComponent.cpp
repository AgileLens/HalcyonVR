// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRRoomLayoutManagerComponent.h"
#include "OculusXRHMD.h"
#include "OculusXRRoomLayoutManager.h"
#include "OculusXRAnchorDelegates.h"
#include "OculusXRAnchorManager.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "ProceduralMeshComponent.h"
#include "OculusXRAnchorsModule.h"

UOculusXRRoomLayoutManagerComponent::UOculusXRRoomLayoutManagerComponent(const FObjectInitializer& ObjectInitializer)
{
	bWantsInitializeComponent = true; // so that InitializeComponent() gets called
}

void UOculusXRRoomLayoutManagerComponent::OnRegister()
{
	Super::OnRegister();

	FOculusXRAnchorEventDelegates::OculusSceneCaptureComplete.AddUObject(this, &UOculusXRRoomLayoutManagerComponent::OculusRoomLayoutSceneCaptureComplete_Handler);
}

void UOculusXRRoomLayoutManagerComponent::OnUnregister()
{
	Super::OnUnregister();

	FOculusXRAnchorEventDelegates::OculusSceneCaptureComplete.RemoveAll(this);
}

void UOculusXRRoomLayoutManagerComponent::InitializeComponent()
{
	Super::InitializeComponent();
}

void UOculusXRRoomLayoutManagerComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

bool UOculusXRRoomLayoutManagerComponent::LaunchCaptureFlow()
{
	UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Launch capture flow -- UOculusXRRoomLayoutManagerComponent"));

	uint64 OutRequest = 0;
	const bool bSuccess = OculusXRAnchors::FOculusXRRoomLayoutManager::RequestSceneCapture(OutRequest);
	if (bSuccess)
	{
		EntityRequestList.Add(OutRequest);
	}

	UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Launch capture flow -- RequestSceneCapture -- %d"), bSuccess);

	return bSuccess;
}

bool UOculusXRRoomLayoutManagerComponent::GetRoomLayout(FOculusXRUInt64 Space, FOculusXRRoomLayout& RoomLayoutOut, int32 MaxWallsCapacity)
{
	return UOculusXRAnchorBPFunctionLibrary::GetRoomLayout(Space, RoomLayoutOut, MaxWallsCapacity);
}

bool UOculusXRRoomLayoutManagerComponent::LoadTriangleMesh(FOculusXRUInt64 Space, UProceduralMeshComponent* Mesh, bool CreateCollision) const
{
	ensure(Mesh);
	TArray<FVector> Vertices;
	TArray<int32> Triangles;

	bool Success = OculusXRAnchors::FOculusXRRoomLayoutManager::GetSpaceTriangleMesh(Space, Vertices, Triangles);
	if (!Success)
	{
		return false;
	}

	// Mesh->bUseAsyncCooking = true;
	TArray<FVector> EmptyNormals;
	TArray<FVector2D> EmptyUV;
	TArray<FColor> EmptyVertexColors;
	TArray<FProcMeshTangent> EmptyTangents;
	Mesh->CreateMeshSection(0, Vertices, Triangles, EmptyNormals, EmptyUV, EmptyVertexColors, EmptyTangents, CreateCollision);

	return true;
}
