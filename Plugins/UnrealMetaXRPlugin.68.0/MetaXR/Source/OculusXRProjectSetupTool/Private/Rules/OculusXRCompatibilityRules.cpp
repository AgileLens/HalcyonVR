// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRCompatibilityRules.h"
#include "CoreMinimal.h"
#include "AndroidRuntimeSettings.h"
#include "GeneralProjectSettings.h"
#include "OculusXRRuleProcessorSubsystem.h"
#include "GameFramework/InputSettings.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPSTUtils.h"

#define LOCTEXT_NAMESPACE "OculusXRCompatibilityRules"
namespace
{
	constexpr int32 MinimumAndroidAPILevel = 32;
	constexpr int32 TargetAndroidAPILevel = 32;
} // namespace

namespace OculusXRCompatibilityRules
{

	FUseAndroidSDKMinimumRule::FUseAndroidSDKMinimumRule()
		: ISetupRule(
			  "Compatibility_UseAndroidSDKMinimum",
			  LOCTEXT("UseAndroidSDKMinimum_DisplayName", "Use Android SDK Minimum Version"),
			  FText::Format(
				  LOCTEXT("UseAndroidSDKMinimum_Description", "Minimum Android API level must be at least {0}."),
				  MinimumAndroidAPILevel),
			  ESetupRuleCategory::Compatibility,
			  ESetupRuleSeverity::Critical,
			  MetaQuest_All) {}

	bool FUseAndroidSDKMinimumRule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->MinSDKVersion >= MinimumAndroidAPILevel;
	}

	void FUseAndroidSDKMinimumRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, MinSDKVersion, MinimumAndroidAPILevel);
		OutShouldRestartEditor = false;
	}

	FUseAndroidSDKTargetRule::FUseAndroidSDKTargetRule()
		: ISetupRule(
			  "Compatibility_UseAndroidSDKTarget",
			  LOCTEXT("UseAndroidSDKTarget_DisplayName", "Use Android SDK Target Version"),
			  FText::Format(
				  LOCTEXT("UseAndroidSDKTarget_Description", "Target Android API level must be at least {0}."),
				  TargetAndroidAPILevel),
			  ESetupRuleCategory::Compatibility,
			  ESetupRuleSeverity::Critical,
			  MetaQuest_All) {}

	bool FUseAndroidSDKTargetRule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->TargetSDKVersion >= TargetAndroidAPILevel;
	}

	void FUseAndroidSDKTargetRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, TargetSDKVersion, TargetAndroidAPILevel);
		OutShouldRestartEditor = false;
	}

	bool FUseArm64CPURule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->bBuildForArm64 && !Settings->bBuildForX8664;
	}

	void FUseArm64CPURule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bBuildForArm64, true);
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bBuildForX8664, false);
		OutShouldRestartEditor = false;
	}
	bool FEnablePackageForMetaQuestRule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->bPackageForMetaQuest && !Settings->bSupportsVulkanSM5 && !Settings->bBuildForES31 && Settings->ExtraApplicationSettings.Find("com.oculus.supportedDevices") != INDEX_NONE;
	}

	void FEnablePackageForMetaQuestRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bPackageForMetaQuest, true);
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bSupportsVulkanSM5, false);
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bBuildForES31, false);

		UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();
		if (Settings->ExtraApplicationSettings.Find("com.oculus.supportedDevices") == INDEX_NONE)
		{
			const FString SupportedDevicesValue("quest|quest2|questpro");
			Settings->ExtraApplicationSettings.Append("<meta-data android:name=\"com.oculus.supportedDevices\" android:value=\"" + SupportedDevicesValue + "\" />");
			Settings->UpdateSinglePropertyInConfigFile(Settings->GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UAndroidRuntimeSettings, ExtraApplicationSettings)), Settings->GetDefaultConfigFilename());
		}

		OutShouldRestartEditor = false;
	}

	bool FQuest2SupportedDeviceRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->SupportedDevices.Contains(EOculusXRSupportedDevices::Quest2);
	}

	void FQuest2SupportedDeviceRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		Settings->SupportedDevices.Add(EOculusXRSupportedDevices::Quest2);
		// UpdateSinglePropertyInConfigFile does not support arrays
		Settings->SaveConfig(CPF_Config, *Settings->GetDefaultConfigFilename());
		OutShouldRestartEditor = false;
	}

	bool FQuestProSupportedDeviceRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->SupportedDevices.Contains(EOculusXRSupportedDevices::QuestPro);
	}

	void FQuestProSupportedDeviceRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		Settings->SupportedDevices.Add(EOculusXRSupportedDevices::QuestPro);
		// UpdateSinglePropertyInConfigFile does not support arrays
		Settings->SaveConfig(CPF_Config, *Settings->GetDefaultConfigFilename());
		OutShouldRestartEditor = false;
	}

	bool FQuest3SupportedDeviceRule::IsApplied() const
	{
		const UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		return Settings->SupportedDevices.Contains(EOculusXRSupportedDevices::Quest3);
	}

	void FQuest3SupportedDeviceRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();

		Settings->SupportedDevices.Add(EOculusXRSupportedDevices::Quest3);
		// UpdateSinglePropertyInConfigFile does not support arrays
		Settings->SaveConfig(CPF_Config, *Settings->GetDefaultConfigFilename());
		OutShouldRestartEditor = false;
	}

	bool FEnableFullscreenRule::IsApplied() const
	{
		const UAndroidRuntimeSettings* Settings = GetMutableDefault<UAndroidRuntimeSettings>();

		return Settings->bFullScreen;
	}

	void FEnableFullscreenRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UAndroidRuntimeSettings, bFullScreen, true);
		OutShouldRestartEditor = false;
	}

	bool FEnableStartInVRRule::IsApplied() const
	{
		const UGeneralProjectSettings* Settings = GetDefault<UGeneralProjectSettings>();

		return Settings->bStartInVR != 0;
	}

	void FEnableStartInVRRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UGeneralProjectSettings, bStartInVR, true);
		OutShouldRestartEditor = false;
	}

	bool FDisableTouchInterfaceRule::IsApplied() const
	{
		const UInputSettings* Settings = GetDefault<UInputSettings>();

		return Settings->DefaultTouchInterface.IsNull();
	}

	void FDisableTouchInterfaceRule::ApplyImpl(bool& OutShouldRestartEditor)
	{
		OCULUSXR_UPDATE_SETTINGS(UInputSettings, DefaultTouchInterface, nullptr);
		OutShouldRestartEditor = false;
	}
} // namespace OculusXRCompatibilityRules

#undef LOCTEXT_NAMESPACE
