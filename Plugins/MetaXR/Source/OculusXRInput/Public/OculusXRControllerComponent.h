// Copyright (c) Meta Platforms, Inc. and affiliates.

// A class to render the currently connected controller.
// Similar to how hands are tracked.

#pragma once
#include "OculusXRInputFunctionLibrary.h"
#include "OculusXRFunctionLibrary.h"
#include "Components/StaticMeshComponent.h"
#include <Engine/StreamableManager.h>

// Must always be the last include.
#include "OculusXRControllerComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent), ClassGroup = OculusHand)
class UOculusXRControllerComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UOculusXRControllerComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** The skeleton that will be loaded */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
	EOculusXRSide SkeletonType;

	/** Should this controller be rendered when using controller driven hand poses */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
	bool RenderWhenUsingControllerDrivenHands;

private:
	enum MeshLoadingState
	{
		None,
		Loading,
		Loaded
	};

	UStaticMesh* _runtimeMesh;
	MeshLoadingState _meshLoadingState;
	TSharedPtr<FStreamableHandle> _loadAssetHandle;
	FStreamableManager _streamableManager;
	EOculusXRControllerType _controllerType;
	FSoftObjectPath _runtimeMeshPath;
	EOculusXRControllerDrivenHandPoseTypes _cachedControllerHandType;

	void InitializeMesh();
	void MeshLoaded();
	EOculusXRControllerType GetControllerType();

	const FVector PositionOffsets
		[EOculusXRSideCount]
		[EOculusXRControllerDrivenHandPoseTypesCount];
	const FVector RotationOffsets
		[EOculusXRSideCount]
		[EOculusXRControllerDrivenHandPoseTypesCount];
};
