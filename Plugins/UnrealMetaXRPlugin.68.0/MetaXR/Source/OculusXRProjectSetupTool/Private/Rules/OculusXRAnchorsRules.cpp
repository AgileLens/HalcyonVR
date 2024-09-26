// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRAnchorsRules.h"
#include "CoreMinimal.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRAnchorComponents.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRSceneActor.h"

namespace OculusXRAnchorsRules
{
	bool FEnableAnchorSupportRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bAnchorSupportEnabled;
	}

	void FEnableAnchorSupportRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bAnchorSupportEnabled, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableAnchorSupportRule::IsValid()
	{
		return OculusXRPSTUtils::IsComponentOfTypeInWorld<UOculusXRBaseAnchorComponent>() || OculusXRPSTUtils::IsComponentOfTypeInWorld<AOculusXRSceneActor>();
	}

	bool FEnableSceneSupportRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->bSceneSupportEnabled;
	}

	void FEnableSceneSupportRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, bSceneSupportEnabled, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableSceneSupportRule::IsValid()
	{
		return OculusXRPSTUtils::IsComponentOfTypeInWorld<AOculusXRSceneActor>();
	}
} // namespace OculusXRAnchorsRules

#undef LOCTEXT_NAMESPACE
