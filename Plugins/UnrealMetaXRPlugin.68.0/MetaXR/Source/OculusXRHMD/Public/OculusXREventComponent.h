// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
// OculusEventComponent.h: Component to handle receiving events from Oculus HMDs

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Components/ActorComponent.h"
#include "OculusXREventComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent), ClassGroup = OculusXRHMD)
class OCULUSXRHMD_API UOculusXREventComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOculusDisplayRefreshRateChangedEventDelegate, float, fromRefreshRate, float, toRefreshRate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOculusEyeTrackingStateChangedEventDelegate, bool, bEyeTrackingOn);

	UPROPERTY(BlueprintAssignable)
	FOculusDisplayRefreshRateChangedEventDelegate OculusDisplayRefreshRateChanged;

	UPROPERTY(BlueprintAssignable)
	FOculusEyeTrackingStateChangedEventDelegate OculusEyeTrackingStateChanged;

	void OnRegister() override;
	void OnUnregister() override;

private:
	/** Native handlers that get registered with the actual FCoreDelegates, and then proceed to broadcast to the delegates above */
	void OculusDisplayRefreshRateChanged_Handler(float fromRefresh, float toRefresh) { OculusDisplayRefreshRateChanged.Broadcast(fromRefresh, toRefresh); }
	void OculusEyeTrackingStateChanged_Handler(bool bEyeTrackingOn) { OculusEyeTrackingStateChanged.Broadcast(bEyeTrackingOn); }
};
