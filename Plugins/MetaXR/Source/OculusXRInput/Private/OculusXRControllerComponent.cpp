// Copyright (c) Meta Platforms, Inc. and affiliates.

// A class to render the currently connected controller.
// Similar to how hands are tracked.

#include "OculusXRControllerComponent.h"
#include "OculusXRInput.h"
#include "Components/StaticMeshComponent.h"
#include "OculusXRHandTracking.h"
#include <OculusXRInputModule.h>

UOculusXRControllerComponent::UOculusXRControllerComponent()
	: Super(),
	// These position and rotation offsets are needed to correctly position the controller
	// when using natural or controller based hand positioning.
	// Why do these need to be hardcoded and not come from the skeleton etc?
	// It seems like the offset comes from somewhere in unreal in the first place,
	// not from a bone position, so there's not a place to load the correct orientation from.
	PositionOffsets{
		{
			FVector(0, 0, 0), // Side:  None, Controller Mapping: None
			FVector(0, 0, 0), // Side:  None, Controller Mapping: Natural
			FVector(0, 0, 0), // Side:  None, Controller Mapping: Controller
		},
		{
			FVector(0, 0, 0),			  // Side:  Left, Controller Mapping: None
			FVector(4.278, 9.969, 4.638), // Side:  Left, Controller Mapping: Natural
			FVector(4.278, 9.969, 4.638), // Side:  Left, Controller Mapping: Controller
		},
		{
			FVector(0, 0, 0),				 // Side: Right, Controller Mapping: None
			FVector(-4.104, -9.993, -4.244), // Side: Right, Controller Mapping: Natural
			FVector(-4.104, -9.993, -4.244), // Side: Right, Controller Mapping: Controller
		},
	}
	, RotationOffsets{
		{
			FVector(0, 0, 0), // Side:  None, Controller Mapping: None
			FVector(0, 0, 0), // Side:  None, Controller Mapping: Natural
			FVector(0, 0, 0), // Side:  None, Controller Mapping: Controller
		},
		{
			FVector(0, 0, 0),			   // Side:  Left, Controller Mapping: None
			FVector(90, 166.229, 263.738), // Side:  Left, Controller Mapping: Natural
			FVector(90, 168.515, 259.149), // Side:  Left, Controller Mapping: Controller
		},
		{
			FVector(0, 0, 0),			  // Side: Right, Controller Mapping: None
			FVector(90, 194.995, 83.863), // Side: Right, Controller Mapping: Natural
			FVector(90, 191.485, 79.149), // Side: Right, Controller Mapping: Controller
		},
	}
{
	_meshLoadingState = MeshLoadingState::None;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOculusXRControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UOculusXRControllerComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If we're in a capsense mode, we need to offset the controller position so that it's correct / consistent with the hand position.
	if (_cachedControllerHandType != OculusXRInput::FOculusHandTracking::ControllerDrivenHandType)
	{
		_cachedControllerHandType = OculusXRInput::FOculusHandTracking::ControllerDrivenHandType;

		const FVector positionOffset = PositionOffsets[static_cast<int>(SkeletonType)][static_cast<int>(_cachedControllerHandType)];
		const FVector rotationOffset = RotationOffsets[static_cast<int>(SkeletonType)][static_cast<int>(_cachedControllerHandType)];

		SetRelativeLocation(positionOffset);
		SetRelativeRotation(FQuat::MakeFromEuler(rotationOffset));
	}

	bool isHandTrackingEnabled = UOculusXRInputFunctionLibrary::IsHandTrackingEnabled();
	bool shouldHide = isHandTrackingEnabled && !(RenderWhenUsingControllerDrivenHands && OculusXRInput::FOculusHandTracking::ControllerDrivenHandType == EOculusXRControllerDrivenHandPoseTypes::Controller);
	if (shouldHide && !bHiddenInGame)
	{
		SetHiddenInGame(true, false);
	}
	if (!shouldHide && bHiddenInGame)
	{
		SetHiddenInGame(false, false);
	}

	if (_meshLoadingState == MeshLoadingState::None || _controllerType != GetControllerType())
	{
		InitializeMesh();
	}
}

EOculusXRControllerType UOculusXRControllerComponent::GetControllerType()
{
	EControllerHand controllerHand = EControllerHand::AnyHand;
	if (SkeletonType == EOculusXRSide::Left)
	{
		controllerHand = EControllerHand::Left;
	}
	else if (SkeletonType == EOculusXRSide::Right)
	{
		controllerHand = EControllerHand::Right;
	}
	return UOculusXRFunctionLibrary::GetControllerType(controllerHand);
}

void UOculusXRControllerComponent::InitializeMesh()
{
	if (_runtimeMesh != nullptr)
	{
		SetStaticMesh(nullptr);
		_streamableManager.Unload(_runtimeMeshPath);
		_runtimeMesh = nullptr;
	}

	auto left_controller_path = TEXT("none");
	auto right_controller_path = TEXT("none");

	_controllerType = GetControllerType();
	switch (_controllerType)
	{
		case EOculusXRControllerType::MetaQuestTouch:
			left_controller_path = TEXT("/Script/Engine.StaticMesh'/OculusXR/Meshes/LeftTouchForQuest2.LeftTouchForQuest2'");
			right_controller_path = TEXT("/Script/Engine.StaticMesh'/OculusXR/Meshes/RightTouchForQuest2.RightTouchForQuest2'");
			break;
		case EOculusXRControllerType::MetaQuestTouchPlus:
			// We don't currently have a model for the touch plus controller, default to the touch pro.
		case EOculusXRControllerType::MetaQuestTouchPro:
			left_controller_path = TEXT("/Script/Engine.StaticMesh'/OculusXR/Meshes/LeftMetaQuestTouchPro.LeftMetaQuestTouchPro'");
			right_controller_path = TEXT("/Script/Engine.StaticMesh'/OculusXR/Meshes/RightMetaQuestTouchPro.RightMetaQuestTouchPro'");
			break;
		case EOculusXRControllerType::None:
		case EOculusXRControllerType::Unknown:
		default:
			return;
	}

	auto controllerPath = left_controller_path;
	if (SkeletonType == EOculusXRSide::Right)
	{
		controllerPath = right_controller_path;
	}
	_runtimeMeshPath = FSoftObjectPath(controllerPath);

	_loadAssetHandle = _streamableManager.RequestAsyncLoad(
		_runtimeMeshPath,
		FStreamableDelegate::CreateUObject(this, &UOculusXRControllerComponent::MeshLoaded));
}

void UOculusXRControllerComponent::MeshLoaded()
{
	if (_loadAssetHandle.IsValid() && _loadAssetHandle.Get()->HasLoadCompleted())
	{
		_runtimeMesh = reinterpret_cast<UStaticMesh*>(_loadAssetHandle.Get()->GetLoadedAsset());
		_meshLoadingState = MeshLoadingState::Loaded;
		SetStaticMesh(_runtimeMesh);
	}
}
