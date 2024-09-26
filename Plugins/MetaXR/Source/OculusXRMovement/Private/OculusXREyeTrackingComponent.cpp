// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXREyeTrackingComponent.h"

#include "GameFramework/WorldSettings.h"
#include "GameFramework/PlayerController.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRPluginWrapper.h"
#include "OculusXRMovementFunctionLibrary.h"
#include "OculusXRMovementHelpers.h"
#include "OculusXRMovementLog.h"
#include "OculusXRTelemetryMovementEvents.h"

int UOculusXREyeTrackingComponent::TrackingInstanceCount = 0;

UOculusXREyeTrackingComponent::UOculusXREyeTrackingComponent()
	: TargetMeshComponentName(NAME_None)
	, bUpdatePosition(true)
	, bUpdateRotation(true)
	, ConfidenceThreshold(0.f)
	, bAcceptInvalid(false)
	, WorldToMeters(100.f)
	, TargetPoseableMeshComponent(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	EyeToBone.Add(EOculusXREye::Left, "LeftEye");
	EyeToBone.Add(EOculusXREye::Right, "RightEye");
	OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FMovementSDKEyeStart>(static_cast<int>(GetTypeHash(this)));
}

void UOculusXREyeTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!UOculusXRMovementFunctionLibrary::IsEyeTrackingSupported())
	{
		// Early exit if eye tracking isn't supported
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Eye tracking is not supported. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	// Try & check initializing the eye data
	if (!InitializeEyes())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to initialize eye tracking data. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
	}

	if (!UOculusXRMovementFunctionLibrary::StartEyeTracking())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to start eye tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	++TrackingInstanceCount;
}

void UOculusXREyeTrackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsComponentTickEnabled())
	{
		if (--TrackingInstanceCount == 0)
		{
			if (!UOculusXRMovementFunctionLibrary::StopEyeTracking())
			{
				UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to stop eye tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
			}
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UOculusXREyeTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(TargetPoseableMeshComponent))
	{
		UE_LOG(LogOculusXRMovement, VeryVerbose, TEXT("No target mesh specified. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	FOculusXREyeGazesState EyeGazesState;

	if (UOculusXRMovementFunctionLibrary::TryGetEyeGazesState(EyeGazesState, WorldToMeters))
	{
		for (uint8 i = 0u; i < static_cast<uint8>(EOculusXREye::COUNT); ++i)
		{
			if (PerEyeData[i].EyeIsMapped)
			{
				const auto& Bone = PerEyeData[i].MappedBoneName;
				const auto& EyeGaze = EyeGazesState.EyeGazes[i];
				if ((bAcceptInvalid || EyeGaze.bIsValid) && (EyeGaze.Confidence >= ConfidenceThreshold))
				{
					int32 BoneIndex = TargetPoseableMeshComponent->GetBoneIndex(Bone);
					FTransform CurrentTransform = TargetPoseableMeshComponent->GetBoneTransformByName(Bone, EBoneSpaces::ComponentSpace);

					if (bUpdatePosition)
					{
						CurrentTransform.SetLocation(EyeGaze.Position);
					}

					if (bUpdateRotation)
					{
						CurrentTransform.SetRotation(EyeGaze.Orientation.Quaternion() * PerEyeData[i].InitialRotation);
					}

					TargetPoseableMeshComponent->SetBoneTransformByName(Bone, CurrentTransform, EBoneSpaces::ComponentSpace);
				}
			}
		}
	}
	else
	{
		UE_LOG(LogOculusXRMovement, VeryVerbose, TEXT("Failed to get Eye state from EyeTrackingComponent. (%s:%s)"), *GetOwner()->GetName(), *GetName());
	}
}

void UOculusXREyeTrackingComponent::ClearRotationValues()
{
	if (!IsValid(TargetPoseableMeshComponent))
	{
		UE_LOG(LogOculusXRMovement, VeryVerbose, TEXT("No target mesh specified. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		return;
	}

	for (uint8 i = 0u; i < static_cast<uint8>(EOculusXREye::COUNT); ++i)
	{
		if (PerEyeData[i].EyeIsMapped)
		{
			const auto& Bone = PerEyeData[i].MappedBoneName;

			int32 BoneIndex = TargetPoseableMeshComponent->GetBoneIndex(Bone);
			FTransform CurrentTransform = TargetPoseableMeshComponent->GetBoneTransformByName(Bone, EBoneSpaces::ComponentSpace);

			CurrentTransform.SetRotation(PerEyeData[i].InitialRotation);

			TargetPoseableMeshComponent->SetBoneTransformByName(Bone, CurrentTransform, EBoneSpaces::ComponentSpace);
		}
	}
}

bool UOculusXREyeTrackingComponent::InitializeEyes()
{
	bool bIsAnythingMapped = false;

	TargetPoseableMeshComponent = OculusXRUtility::FindComponentByName<UPoseableMeshComponent>(GetOwner(), TargetMeshComponentName);

	if (!IsValid(TargetPoseableMeshComponent))
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Could not find mesh with name (%s) for component. (%s:%s)"), *TargetMeshComponentName.ToString(), *GetOwner()->GetName(), *GetName());
		return false;
	}

	for (uint8 i = 0u; i < static_cast<uint8>(EOculusXREye::COUNT); ++i)
	{
		const EOculusXREye Eye = static_cast<EOculusXREye>(i);
		const FName* BoneNameForThisEye = EyeToBone.Find(Eye);
		PerEyeData[i].EyeIsMapped = (nullptr != BoneNameForThisEye);

		if (PerEyeData[i].EyeIsMapped)
		{
			int32 BoneIndex = TargetPoseableMeshComponent->GetBoneIndex(*BoneNameForThisEye);
			if (BoneIndex == INDEX_NONE)
			{
				PerEyeData[i].EyeIsMapped = false; // Eye is explicitly mapped to a bone. But the bone name doesn't exist.
				UE_LOG(LogOculusXRMovement, Warning, TEXT("Could not find bone by name (%s) in mesh %s. (%s:%s)"), *BoneNameForThisEye->ToString(), *TargetPoseableMeshComponent->GetName(), *GetOwner()->GetName(), *GetName());
			}
			else
			{
				PerEyeData[i].MappedBoneName = *BoneNameForThisEye;
				PerEyeData[i].InitialRotation = TargetPoseableMeshComponent->GetBoneTransformByName(*BoneNameForThisEye, EBoneSpaces::ComponentSpace).GetRotation();
				bIsAnythingMapped = true;
			}
		}
		else
		{
			UE_LOG(LogOculusXRMovement, Display, TEXT("Eye (%s) is not mapped to any bone on mesh (%s)"), *StaticEnum<EOculusXREye>()->GetValueAsString(Eye), *TargetPoseableMeshComponent->GetName());
		}
	}

	if (!bIsAnythingMapped)
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Component name -- %s:%s, doesn't have a valid configuration."), *GetOwner()->GetName(), *GetName());
	}

	if (!OculusXRHMD::GetUnitScaleFactorFromSettings(GetWorld(), WorldToMeters))
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot get world settings. (%s:%s)"), *GetOwner()->GetName(), *GetName());
	}

	return bIsAnythingMapped;
}
