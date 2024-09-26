// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"
#include "Delegates/Delegate.h"

class FOculusEventDelegates
{
public:
	/** When the display refresh rate is changed */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusDisplayRefreshRateChangedEvent, float /*fromRefreshRate*/, float /*toRefreshRate*/);
	static FOculusDisplayRefreshRateChangedEvent OculusDisplayRefreshRateChanged;

	/** When the eye tracking status changes */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOculusEyeTrackingStateChangedEvent, bool /*bIsEyeTrackingOn*/);
	static FOculusEyeTrackingStateChangedEvent OculusEyeTrackingStateChanged;
};
