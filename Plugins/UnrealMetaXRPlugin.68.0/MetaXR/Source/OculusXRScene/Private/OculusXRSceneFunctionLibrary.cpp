// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSceneFunctionLibrary.h"

#include "Engine/GameInstance.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRScene.h"
#include "OculusXRSceneSubsystem.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMD.h"


bool UOculusXRSceneFunctionLibrary::GetBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility& OutVisibility)
{
	OutVisibility = EOculusXRBoundaryVisibility::NotSuppressed;

	check(WorldContext);
	check(WorldContext->GetWorld());

	UOculusXRSceneSubsystem* subsystem = WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOculusXRSceneSubsystem>();
	if (subsystem == nullptr)
	{
		return false;
	}

	OutVisibility = subsystem->GetBoundaryVisibility();
	return true;
}

bool UOculusXRSceneFunctionLibrary::GetRequestedBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility& OutVisibility)
{
	OutVisibility = EOculusXRBoundaryVisibility::NotSuppressed;

	check(WorldContext);
	check(WorldContext->GetWorld());

	UOculusXRSceneSubsystem* subsystem = WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOculusXRSceneSubsystem>();
	if (subsystem == nullptr)
	{
		return false;
	}

	OutVisibility = subsystem->GetRequestedBoundaryVisibility();
	return true;
}

bool UOculusXRSceneFunctionLibrary::RequestBoundaryVisibility(const UObject* WorldContext, EOculusXRBoundaryVisibility Visibility)
{
	check(WorldContext);
	check(WorldContext->GetWorld());

	UOculusXRSceneSubsystem* subsystem = WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UOculusXRSceneSubsystem>();
	if (subsystem == nullptr)
	{
		return false;
	}

	subsystem->SetRequestedBoundaryVisibility(Visibility);

	return true;
}
