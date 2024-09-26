// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include <Subsystems/EngineSubsystem.h>
#include "OculusXRSceneTypes.h"
#include "OculusXRAnchorTypes.h"
#include "OculusXRSceneEventDelegates.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOculusXRScene_BoundaryVisibilityChanged, EOculusXRBoundaryVisibility, BoundaryVisibility);

UCLASS()
class OCULUSXRSCENE_API UOculusXRSceneEventDelegates : public UEngineSubsystem
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FOculusXRScene_BoundaryVisibilityChanged OnBoundaryVisibilityChanged;
};
