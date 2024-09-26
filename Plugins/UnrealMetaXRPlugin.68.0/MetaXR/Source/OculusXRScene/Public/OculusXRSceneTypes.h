// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRSceneTypes.generated.h"

USTRUCT()
struct OCULUSXRSCENE_API FSceneTypesPlaceholder
{
	GENERATED_BODY()
public:
};


UENUM(BlueprintType)
enum class EOculusXRBoundaryVisibility : uint8
{
	Invalid = 0,
	NotSuppressed = 1,
	Suppressed = 2
};
