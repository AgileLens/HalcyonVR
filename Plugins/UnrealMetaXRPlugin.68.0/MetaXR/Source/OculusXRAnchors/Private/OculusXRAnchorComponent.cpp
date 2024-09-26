// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRAnchorComponent.h"
#include "OculusXRAnchors.h"
#include "OculusXRAnchorsModule.h"
#include "OculusXRHMD.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRAnchorsPrivate.h"
#include "GameFramework/PlayerController.h"

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
static TAutoConsoleVariable<int32> CVarOculusXRVerboseAnchorDebugXR(
	TEXT("ovr.OculusXRVerboseAnchorDebug"),
	0,
	TEXT("Enables or disables verbose logging for Oculus anchors.\n")
		TEXT("<=0: disabled (no printing)\n")
			TEXT("  1: enabled  (verbose logging)\n"));
#endif

UOculusXRAnchorComponent::UOculusXRAnchorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bUpdateHeadSpaceTransform(true)
	, AnchorHandle(0)
	, StorageLocations(0)
{
	AnchorHandle = 0;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork;
}

void UOculusXRAnchorComponent::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (IsValid(World))
	{
		APlayerController* PlayerController = World->GetFirstPlayerController();
		if (IsValid(PlayerController))
		{
			PlayerCameraManager = PlayerController->PlayerCameraManager;
		}
	}
}

void UOculusXRAnchorComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateAnchorTransform();
}

void UOculusXRAnchorComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (HasValidHandle())
	{
		EOculusXRAnchorResult::Type AnchorResult;
		OculusXRAnchors::FOculusXRAnchors::DestroyAnchor(AnchorHandle.GetValue(), AnchorResult);
	}
}

FOculusXRUInt64 UOculusXRAnchorComponent::GetHandle() const
{
	return AnchorHandle;
}

void UOculusXRAnchorComponent::SetHandle(FOculusXRUInt64 Handle)
{
	AnchorHandle = Handle;
}

bool UOculusXRAnchorComponent::HasValidHandle() const
{
	return AnchorHandle != FOculusXRUInt64(0);
}

FOculusXRUUID UOculusXRAnchorComponent::GetUUID() const
{
	return AnchorUUID;
}

void UOculusXRAnchorComponent::SetUUID(FOculusXRUUID NewUUID)
{
	if (AnchorUUID.IsValidUUID())
	{
		UE_LOG(LogOculusXRAnchors, Warning, TEXT("Anchor component already has valid UUID, cannot re-assign a new UUID. Component: %s  --  Space: %llu  --  UUID: %s"),
			*GetName(), AnchorHandle.GetValue(), *AnchorUUID.ToString());
		return;
	}

	if (!NewUUID.IsValidUUID())
	{
		UE_LOG(LogOculusXRAnchors, Warning, TEXT("New UUID provided to component is invalid, cannot assign. Component: %s  --  Space: %llu"), *GetName(), AnchorHandle.GetValue());
		return;
	}

	UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Assigned new Oculus UUID: %s"), *NewUUID.ToString());

	AnchorUUID = NewUUID;
}

bool UOculusXRAnchorComponent::IsStoredAtLocation(EOculusXRSpaceStorageLocation Location) const
{
	UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Anchor UUID: %s  -  Saved Local: %d  -  Saved Cloud: %d"),
		*GetUUID().ToString(),
		StorageLocations & static_cast<int32>(EOculusXRSpaceStorageLocation::Local),
		StorageLocations & static_cast<int32>(EOculusXRSpaceStorageLocation::Cloud));

	return (StorageLocations & static_cast<int32>(Location)) > 0;
}

void UOculusXRAnchorComponent::SetStoredLocation(EOculusXRSpaceStorageLocation Location, bool Stored)
{
	if (Stored)
	{
		StorageLocations |= static_cast<int32>(Location);
	}
	else
	{
		StorageLocations = StorageLocations & ~static_cast<int32>(Location);
	}

	UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Anchor UUID: %s  -  Saved Local: %d  -  Saved Cloud: %d"),
		*GetUUID().ToString(),
		StorageLocations & static_cast<int32>(EOculusXRSpaceStorageLocation::Local),
		StorageLocations & static_cast<int32>(EOculusXRSpaceStorageLocation::Cloud));
}

bool UOculusXRAnchorComponent::IsSaved() const
{
	return StorageLocations > 0;
}

void UOculusXRAnchorComponent::UpdateAnchorTransform() const
{
	if (GetWorld() == nullptr)
	{
		UE_LOG(LogOculusXRAnchors, Warning, TEXT("Unable to retrieve World Context"));
		return;
	}

	AActor* Parent = GetOwner();
	if (Parent)
	{
		if (AnchorHandle.Value)
		{
			FTransform OutTransform;
			if (UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(AnchorHandle, OutTransform))
			{
#if WITH_EDITOR
				// Link only head-space transform update
				if (bUpdateHeadSpaceTransform && PlayerCameraManager != nullptr)
				{
					FTransform MainCameraTransform;
					MainCameraTransform.SetLocation(PlayerCameraManager->GetCameraLocation());
					MainCameraTransform.SetRotation(FQuat(PlayerCameraManager->GetCameraRotation()));

					if (!ToWorldSpacePose(MainCameraTransform, OutTransform))
					{
						UE_LOG(LogOculusXRAnchors, Display, TEXT("Was not able to transform anchor to world space pose"));
					}
				}
#endif

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
				if (CVarOculusXRVerboseAnchorDebugXR.GetValueOnGameThread() > 0)
				{
					UE_LOG(LogOculusXRAnchors, Display, TEXT("UpdateAnchor Pos %s"), *OutTransform.GetLocation().ToString());
					UE_LOG(LogOculusXRAnchors, Display, TEXT("UpdateAnchor Rot %s"), *OutTransform.GetRotation().ToString());
				}
#endif
				Parent->SetActorLocationAndRotation(OutTransform.GetLocation(), OutTransform.GetRotation(), false, 0, ETeleportType::ResetPhysics);
			}
		}
	}
}

bool UOculusXRAnchorComponent::ToWorldSpacePose(FTransform CameraTransform, FTransform& OutTrackingSpaceTransform) const
{
	OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (!OculusXRHMD)
	{
		UE_LOG(LogOculusXRAnchors, Warning, TEXT("Unable to retrieve OculusXRHMD, cannot calculate anchor world space pose."));
		return false;
	}

	OculusXRHMD::FPose MainCameraPose(CameraTransform.GetRotation(), CameraTransform.GetLocation());
	OculusXRHMD::FPose TrackingSpacePose(OutTrackingSpaceTransform.GetRotation(), OutTrackingSpaceTransform.GetLocation());

	FVector OutHeadPosition;
	FQuat OutHeadOrientation;
	const bool bGetPose = OculusXRHMD->GetCurrentPose(OculusXRHMD->HMDDeviceId, OutHeadOrientation, OutHeadPosition);
	if (!bGetPose)
		return false;

	OculusXRHMD::FPose HeadPose(OutHeadOrientation, OutHeadPosition);

	OculusXRHMD::FPose poseInHeadSpace = HeadPose.Inverse() * TrackingSpacePose;

	// To world space pose
	const OculusXRHMD::FPose WorldTrackingSpacePose = MainCameraPose * poseInHeadSpace;

	OutTrackingSpaceTransform.SetLocation(WorldTrackingSpacePose.Position);
	OutTrackingSpaceTransform.SetRotation(WorldTrackingSpacePose.Orientation);

	return true;
}
