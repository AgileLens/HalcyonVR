// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPluginRules.h"
#include "CoreMinimal.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPSTUtils.h"
#include "Editor/GameProjectGeneration/Public/GameProjectGenerationModule.h"
#include "Interfaces/IPluginManager.h"
#include "Interfaces/IProjectManager.h"

namespace OculusXRPluginRules
{
	namespace
	{
		bool IsPluginEnabled(const FString& PluginName)
		{
			const auto Plugin = IPluginManager::Get().FindPlugin(PluginName);
			if (!Plugin)
			{
				return false;
			}

			return Plugin->IsEnabled();
		}

		bool DisablePlugin(const FString& PluginName)
		{
			FText FailMessage;
			bool bSuccess = IProjectManager::Get().SetPluginEnabled(
				PluginName, false, FailMessage);
			const bool bIsProjectDirty = IProjectManager::Get().IsCurrentProjectDirty();
			if (bSuccess && bIsProjectDirty)
			{
				FGameProjectGenerationModule::Get().TryMakeProjectFileWriteable(FPaths::GetProjectFilePath());
				bSuccess = IProjectManager::Get().SaveCurrentProjectToDisk(FailMessage);
			}
			if (!bSuccess)
			{
				FMessageDialog::Open(EAppMsgType::Ok, FailMessage);
			}

			return bSuccess && !bIsProjectDirty;
		}
	} // namespace
	bool FUseRecommendedXRAPIRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
		return Settings->XrApi == EOculusXRXrApi::OVRPluginOpenXR;
	}

	void FUseRecommendedXRAPIRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UOculusXRHMDRuntimeSettings, XrApi, EOculusXRXrApi::OVRPluginOpenXR);
		OutShouldRestartEditor = false;
	}

	bool FDisableOculusVRRule::IsApplied() const
	{
		return bApplied || !IsPluginEnabled(PluginName);
	}

	void FDisableOculusVRRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OutShouldRestartEditor = DisablePlugin(PluginName);
		bApplied = OutShouldRestartEditor;
	}

	bool FDisableSteamVRRule::IsApplied() const
	{
		return bApplied || !IsPluginEnabled(PluginName);
	}

	void FDisableSteamVRRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OutShouldRestartEditor = DisablePlugin(PluginName);
		bApplied = OutShouldRestartEditor;
	}
} // namespace OculusXRPluginRules

#undef LOCTEXT_NAMESPACE
