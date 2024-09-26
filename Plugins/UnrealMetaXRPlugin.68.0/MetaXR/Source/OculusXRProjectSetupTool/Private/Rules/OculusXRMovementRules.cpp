// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovementRules.h"
#include "CoreMinimal.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRBodyTrackingComponent.h"
#include "OculusXREyeTrackingComponent.h"
#include "OculusXRFaceTrackingComponent.h"
#include "OculusXRProjectSetupToolModule.h"
#include "OculusXRRuleProcessorSubsystem.h"

namespace OculusXRMovementRules
{
	bool FEnableBodyTrackingRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
		return Settings->bBodyTrackingEnabled;
	}

	void FEnableBodyTrackingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bBodyTrackingEnabled, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableBodyTrackingRule::IsValid()
	{
		return OculusXRPSTUtils::IsComponentOfTypeInWorld<UOculusXRBodyTrackingComponent>();
	}

	bool FEnableFaceTrackingRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bFaceTrackingEnabled;
	}

	void FEnableFaceTrackingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bFaceTrackingEnabled, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableFaceTrackingRule::IsValid()
	{
		return OculusXRPSTUtils::IsComponentOfTypeInWorld<UOculusXRFaceTrackingComponent>();
	}

	bool FEnableEyeTrackingRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bEyeTrackingEnabled;
	}

	void FEnableEyeTrackingRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bEyeTrackingEnabled, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableEyeTrackingRule::IsValid()
	{
		return OculusXRPSTUtils::IsComponentOfTypeInWorld<UOculusXREyeTrackingComponent>();
	}
} // namespace OculusXRMovementRules

#undef LOCTEXT_NAMESPACE
