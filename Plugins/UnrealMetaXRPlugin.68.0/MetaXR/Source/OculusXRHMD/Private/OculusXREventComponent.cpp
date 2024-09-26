// @lint-ignore-every LICENSELINT
// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.
#include "OculusXREventComponent.h"
#include "OculusXRHMD.h"
#include "OculusXRDelegates.h"

void UOculusXREventComponent::OnRegister()
{
	Super::OnRegister();

	FOculusEventDelegates::OculusDisplayRefreshRateChanged.AddUObject(this, &UOculusXREventComponent::OculusDisplayRefreshRateChanged_Handler);
	FOculusEventDelegates::OculusEyeTrackingStateChanged.AddUObject(this, &UOculusXREventComponent::OculusEyeTrackingStateChanged_Handler);
}

void UOculusXREventComponent::OnUnregister()
{
	Super::OnUnregister();

	FOculusEventDelegates::OculusDisplayRefreshRateChanged.RemoveAll(this);
	FOculusEventDelegates::OculusEyeTrackingStateChanged.RemoveAll(this);
}
