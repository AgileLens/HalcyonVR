// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"

class FOculusAssetDirectory
{
public:
#if WITH_EDITORONLY_DATA
	OCULUSXRHMD_API static void LoadForCook();
	OCULUSXRHMD_API static void ReleaseAll();
#endif

	static FSoftObjectPath AssetListing[];
};
