// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Materials/MaterialInterface.h"
#include "OculusXRResourceHolder.generated.h"

/**
 *
 */
UCLASS()
class UOculusXRResourceHolder : public UObject
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
	UMaterial* PokeAHoleMaterial;
};
