// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitDistanceMapGenerator.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKit.h"
#include "MRUtilityKitRoom.h"
#include "MRUtilityKitAnchor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/CanvasRenderTarget2D.h"
#include "Engine/Canvas.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Materials/MaterialInterface.h"
#include "UObject/ConstructorHelpers.h"

AMRUKDistanceMapGenerator::AMRUKDistanceMapGenerator()
{
	// Create components

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SceneCapture2D = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture2D"));

	RootComponent = Root;

	// Setup components

	SceneCapture2D->SetupAttachment(Root);
	SceneCapture2D->ProjectionType = ECameraProjectionMode::Orthographic;
	SceneCapture2D->OrthoWidth = 512.0f;
	SceneCapture2D->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
	SceneCapture2D->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
	SceneCapture2D->bCaptureEveryFrame = false;
	SceneCapture2D->bCaptureOnMovement = false;

	const ConstructorHelpers::FObjectFinder<UCanvasRenderTarget2D> RT1Finder(TEXT("/OculusXR/Textures/CRT_JumpFlood1"));
	if (RT1Finder.Succeeded())
	{
		RenderTarget1 = RT1Finder.Object;
	}
	const ConstructorHelpers::FObjectFinder<UCanvasRenderTarget2D> RT2Finder(TEXT("/OculusXR/Textures/CRT_JumpFlood2"));
	if (RT2Finder.Succeeded())
	{
		RenderTarget2 = RT2Finder.Object;
	}
	const ConstructorHelpers::FObjectFinder<UCanvasRenderTarget2D> RTMaskFinder(TEXT("/OculusXR/Textures/CRT_Mask"));
	if (RTMaskFinder.Succeeded())
	{
		SceneCapture2D->TextureTarget = RTMaskFinder.Object;
	}
	const ConstructorHelpers::FObjectFinder<UCanvasRenderTarget2D> RTDistanceMapFinder(TEXT("/OculusXR/Textures/CRT_DistanceMap"));
	if (RTDistanceMapFinder.Succeeded())
	{
		DistanceMapRenderTarget = RTDistanceMapFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> MaskMaterialFinder(TEXT("/OculusXR/Materials/M_CreateMask"));
	if (MaskMaterialFinder.Succeeded())
	{
		MaskMaterial = MaskMaterialFinder.Object;
	}
	const ConstructorHelpers::FObjectFinder<UMaterialInterface> JFPassMaterialFinder(TEXT("/OculusXR/Materials/M_JFAPass"));
	if (JFPassMaterialFinder.Succeeded())
	{
		JFPassMaterial = JFPassMaterialFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> SceneObjectMaskMaterialFinder(TEXT("/OculusXR/Materials/M_SceneObjectMask"));
	if (SceneObjectMaskMaterialFinder.Succeeded())
	{
		SceneObjectMaskMaterial = SceneObjectMaskMaterialFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> FloorMaskMaterialFinder(TEXT("/OculusXR/Materials/M_FloorMask"));
	if (FloorMaskMaterialFinder.Succeeded())
	{
		FloorMaskMaterial = FloorMaskMaterialFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> DistanceMapFreeSpaceMaterialFinder(TEXT("/OculusXR/Materials/M_DistanceMapFree"));
	if (DistanceMapFreeSpaceMaterialFinder.Succeeded())
	{
		DistanceMapFreeSpaceMaterial = DistanceMapFreeSpaceMaterialFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> DistanceMapOccupiedSpaceMaterialFinder(TEXT("/OculusXR/Materials/M_DistanceMapOccupied"));
	if (DistanceMapOccupiedSpaceMaterialFinder.Succeeded())
	{
		DistanceMapOccupiedSpaceMaterial = DistanceMapOccupiedSpaceMaterialFinder.Object;
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInterface> DistanceMapAllSpaceMaterialFinder(TEXT("/OculusXR/Materials/M_DistanceMapAll"));
	if (DistanceMapAllSpaceMaterialFinder.Succeeded())
	{
		DistanceMapAllSpaceMaterial = DistanceMapAllSpaceMaterialFinder.Object;
	}
}

void AMRUKDistanceMapGenerator::BeginPlay()
{
	Super::BeginPlay();

	SceneObjectMaskMaterial->EnsureIsComplete();
	FloorMaskMaterial->EnsureIsComplete();

	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		if (AMRUKRoom* CurrentRoom = Subsystem->GetCurrentRoom())
		{
			CreateMaskMeshesForRoom(CurrentRoom);
		}
		else
		{
			Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKDistanceMapGenerator::OnRoomCreated);
		}
	}
	else if (SpawnMode == EMRUKSpawnMode::AllRooms)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		for (auto& Room : Subsystem->Rooms)
		{
			CreateMaskMeshesForRoom(Room);
		}

		Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKDistanceMapGenerator::OnRoomCreated);
	}
}

UTexture* AMRUKDistanceMapGenerator::CaptureDistanceMap()
{
	CaptureInitialSceneMask();
	RenderDistanceMap();
	return GetDistanceMap();
}

void AMRUKDistanceMapGenerator::CaptureInitialSceneMask()
{
	if (!JFPassMaterialInstance)
	{
		JFPassMaterialInstance = UMaterialInstanceDynamic::Create(JFPassMaterial, this);
	}
	if (DistanceMapFreeSpaceMaterial && !DistanceMapFreeSpaceMaterialInstance)
	{
		DistanceMapFreeSpaceMaterialInstance = UMaterialInstanceDynamic::Create(DistanceMapFreeSpaceMaterial, this);
	}
	if (DistanceMapOccupiedSpaceMaterial && !DistanceMapOccupiedSpaceMaterialInstance)
	{
		DistanceMapOccupiedSpaceMaterialInstance = UMaterialInstanceDynamic::Create(DistanceMapOccupiedSpaceMaterial, this);
	}
	if (DistanceMapAllSpaceMaterial && !DistanceMapAllSpaceMaterialInstance)
	{
		DistanceMapAllSpaceMaterialInstance = UMaterialInstanceDynamic::Create(DistanceMapAllSpaceMaterial, this);
	}

	check(SceneCapture2D->TextureTarget->SizeX == SceneCapture2D->TextureTarget->SizeY);

	SceneCapture2D->CaptureScene();

	// Renders the texture that was captured by the scene capture component into a mask that can then be used further down

	UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), RenderTarget1, FLinearColor::Black);

	UCanvas* Canvas{};
	FVector2D Size{};
	FDrawToRenderTargetContext RenderTargetContext{};
	UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(GetWorld(), RenderTarget1, Canvas, Size, RenderTargetContext);

	Canvas->K2_DrawMaterial(MaskMaterial, FVector2D::ZeroVector, Size, FVector2D::ZeroVector);

	UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(GetWorld(), RenderTargetContext);
}

void AMRUKDistanceMapGenerator::RenderDistanceMap()
{
	UCanvasRenderTarget2D* RTs[2] = { RenderTarget1, RenderTarget2 };

	int32 RTIndex = 0;

	const double TextureSize = SceneCapture2D->TextureTarget->SizeX;

	check(TextureSize == RenderTarget1->SizeX);
	check(TextureSize == RenderTarget1->SizeY);
	check(TextureSize == RenderTarget2->SizeX);
	check(TextureSize == RenderTarget2->SizeY);

	const int32 LastIndex = static_cast<int32>(FMath::Log2(TextureSize / 2.0));

	// Play buffer ping pong and execute the jump flood algorithm on each step

	for (int32 I = 1; I <= LastIndex; ++I)
	{
		// Read from the render target that we have written before
		JFPassMaterialInstance->SetTextureParameterValue(FName("RT"), RTs[RTIndex]);
		const double Step = 1.0 / FMath::Pow(2.0, static_cast<double>(I));
		JFPassMaterialInstance->SetScalarParameterValue(FName("Step"), Step);

		// Make sure to render to the other render target
		RTIndex = (RTIndex + 1) % 2;
		UCanvasRenderTarget2D* RT = RTs[RTIndex];

		UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), RT, FLinearColor::Black);

		UCanvas* Canvas{};
		FVector2D Size{};
		FDrawToRenderTargetContext RenderTargetContext{};
		UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(GetWorld(), RT, Canvas, Size, RenderTargetContext);

		Canvas->K2_DrawMaterial(JFPassMaterialInstance, FVector2D::ZeroVector, Size, FVector2D::ZeroVector);

		UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(GetWorld(), RenderTargetContext);
	}

	DistanceMapRT = RTIndex;

	if (DistanceMapGenerationMode != EMRUKDistanceMapGenerationMode::None)
	{
		UMaterialInstanceDynamic* RenderMaterial = nullptr;

		UKismetRenderingLibrary::ClearRenderTarget2D(GetWorld(), DistanceMapRenderTarget);
		UCanvas* Canvas{};
		FVector2D Size{};
		FDrawToRenderTargetContext RenderTargetContext{};
		UKismetRenderingLibrary::BeginDrawCanvasToRenderTarget(GetWorld(), DistanceMapRenderTarget, Canvas, Size, RenderTargetContext);
		switch (DistanceMapGenerationMode)
		{
			case EMRUKDistanceMapGenerationMode::FreeSpace:
				RenderMaterial = DistanceMapFreeSpaceMaterialInstance;
				break;
			case EMRUKDistanceMapGenerationMode::OccupiedSpace:
				RenderMaterial = DistanceMapOccupiedSpaceMaterialInstance;
				break;
			case EMRUKDistanceMapGenerationMode::AllSpace:
				RenderMaterial = DistanceMapAllSpaceMaterialInstance;
				break;
			case EMRUKDistanceMapGenerationMode::None:
				RenderMaterial = nullptr;
				break;
		}
		if (RenderMaterial)
		{
			RenderMaterial->SetTextureParameterValue(FName("RT"), GetDistanceMapRenderTarget());
			Canvas->K2_DrawMaterial(RenderMaterial, FVector2D::ZeroVector, Size, FVector2D::ZeroVector);
		}
		UKismetRenderingLibrary::EndDrawCanvasToRenderTarget(GetWorld(), RenderTargetContext);
	}
}

void AMRUKDistanceMapGenerator::OnRoomCreated(AMRUKRoom* Room)
{
	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly && SpawnedMaskMeshes.Num() > 0 && !SpawnedMaskMeshes.Find(Room))
	{
		// We already spawned a room
		return;
	}

	CreateMaskMeshesForRoom(Room);
}

void AMRUKDistanceMapGenerator::CreateMaskMeshesForRoom(AMRUKRoom* Room)
{
	if (!Room)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not create masked meshes for room that is a nullptr"));
		return;
	}

	if (TArray<AActor*>* Actors = SpawnedMaskMeshes.Find(Room))
	{
		for (AActor* Actor : *Actors)
		{
			Actor->Destroy();
		}
		Actors->Empty();
		SpawnedMaskMeshes.Remove(Room);
	}

	// Create for each anchor a mesh with a material to use as a mask
	// to initialize the jump flood algorithm.

	TArray<AActor*> SpawnedActors;

	for (auto& Anchor : Room->AllAnchors)
	{
		if (!Anchor->VolumeBounds.IsValid)
		{
			continue;
		}

		SpawnedActors.Push(CreateMaskMeshOfAnchor(Anchor));
	}
	if (Room->FloorAnchor)
	{
		SpawnedActors.Push(CreateMaskMeshOfAnchor(Room->FloorAnchor));
	}

	SpawnedMaskMeshes.Add(Room, SpawnedActors);

	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	Subsystem->OnRoomRemoved.AddUniqueDynamic(this, &AMRUKDistanceMapGenerator::RemoveMaskMeshesFromRoom);
	Subsystem->OnRoomUpdated.AddUniqueDynamic(this, &AMRUKDistanceMapGenerator::OnRoomCreated);

	OnReady.Broadcast();
}

AActor* AMRUKDistanceMapGenerator::CreateMaskMeshOfAnchor(AMRUKAnchor* Anchor)
{
	check(Anchor);

	FActorSpawnParameters ActorSpawnParams{};
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ActorSpawnParams.Owner = Anchor;
	AActor* Actor = GetWorld()->SpawnActor<AActor>(ActorSpawnParams);

	Actor->Tags.Push(GMRUK_DISTANCE_MAP_ACTOR_TAG);

	const auto R = NewObject<USceneComponent>(Actor, TEXT("Root"));
	Actor->SetRootComponent(R);
	R->RegisterComponent();
	Actor->AddInstanceComponent(R);

	Actor->AttachToActor(Anchor, FAttachmentTransformRules::KeepRelativeTransform);

	const auto ProceduralMesh = NewObject<UProceduralMeshComponent>(Actor, TEXT("DistanceMapMesh"));
	Anchor->GenerateProceduralAnchorMesh(ProceduralMesh, {}, {}, true, false);

	// Set a material depending if the anchor is the floor or a scene object.
	// The different materials have different colors. These colors will be used to create different
	// initialization masks for the jump flood algorithm.

	if (Anchor == Anchor->Room->FloorAnchor)
	{
		ProceduralMesh->SetMaterial(0, FloorMaskMaterial);
	}
	else
	{
		ProceduralMesh->SetMaterial(0, SceneObjectMaskMaterial);
	}

	ProceduralMesh->SetupAttachment(Actor->GetRootComponent());
	ProceduralMesh->RegisterComponent();
	Actor->AddInstanceComponent(ProceduralMesh);

	// The created meshes will be only used to create a mask for jump flood.
	// Therefore we don't want them to show up in the normal camera.
	// This unfortunate means that the meshes will show up in other scene captures the user may place as well.

	ProceduralMesh->SetVisibleInSceneCaptureOnly(true);
	SceneCapture2D->ShowOnlyActors.Push(Actor);

	return Actor;
}

AActor* AMRUKDistanceMapGenerator::UpdateMaskMeshOfAnchor(AMRUKAnchor* Anchor)
{
	TArray<AActor*> ChildActors;
	Anchor->GetAllChildActors(ChildActors);

	for (auto Child : ChildActors)
	{
		if (Child->ActorHasTag(GMRUK_DISTANCE_MAP_ACTOR_TAG))
		{
			// Remove existing distance map actor
			SceneCapture2D->ShowOnlyActors.Remove(Child);
			Child->Destroy();
		}
	}

	return CreateMaskMeshOfAnchor(Anchor);
}

UTexture* AMRUKDistanceMapGenerator::GetDistanceMap() const
{
	return GetDistanceMapRenderTarget();
}

UCanvasRenderTarget2D* AMRUKDistanceMapGenerator::GetDistanceMapRenderTarget() const
{
	if (DistanceMapRT == -1)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Make sure to first render the distance map by calling CaptureDistanceMap()"));
		return nullptr;
	}
	check(DistanceMapRT >= 0);

	UCanvasRenderTarget2D* RTs[2] = { RenderTarget1, RenderTarget2 };
	return RTs[DistanceMapRT];
}

FMinimalViewInfo AMRUKDistanceMapGenerator::GetSceneCaptureView() const
{
	FMinimalViewInfo Info = {};
	SceneCapture2D->GetCameraView(1.0f, Info);
	return Info;
}

void AMRUKDistanceMapGenerator::RemoveMaskMeshesFromRoom(AMRUKRoom* Room)
{
	if (!Room)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not remove masked meshes for room that is a nullptr"));
		return;
	}

	if (TArray<AActor*>* Actors = SpawnedMaskMeshes.Find(Room))
	{
		for (AActor* Actor : *Actors)
		{
			Actor->Destroy();
		}
		Actors->Empty();
		SpawnedMaskMeshes.Remove(Room);
	}
}
