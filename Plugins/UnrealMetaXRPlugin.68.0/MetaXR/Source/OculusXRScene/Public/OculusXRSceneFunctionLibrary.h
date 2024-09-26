// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRAnchorTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OculusXRSceneFunctionLibrary.generated.h"

UCLASS()
class OCULUSXRSCENE_API UOculusXRSceneFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	// Returns the current boundary visibility
	UFUNCTION(BlueprintPure, Category = "OculusXR|Scene", meta = (WorldContext = "WorldContext"))
	static bool GetBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility& OutVisibility);

	// Returns the requested boundary visibility state
	UFUNCTION(BlueprintPure, Category = "OculusXR|Scene", meta = (WorldContext = "WorldContext"))
	static bool GetRequestedBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility& OutVisibility);

	// Requests to change the current boundary visibility
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene", meta = (WorldContext = "WorldContext"))
	static bool RequestBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility NewVisibilityRequest);
};
