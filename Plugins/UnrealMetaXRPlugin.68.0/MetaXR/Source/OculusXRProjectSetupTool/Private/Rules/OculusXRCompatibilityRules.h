// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRSetupRule.h"

// Collection of rules related to compatibility. Can be extended as needed
namespace OculusXRCompatibilityRules
{

	class FUseAndroidSDKMinimumRule final : public ISetupRule
	{
	public:
		FUseAndroidSDKMinimumRule();
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FUseAndroidSDKTargetRule final : public ISetupRule
	{
	public:
		FUseAndroidSDKTargetRule();
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FUseArm64CPURule final : public ISetupRule
	{
	public:
		FUseArm64CPURule()
			: ISetupRule(
				  "Compatibility_UseArm64CPU",
				  NSLOCTEXT("OculusXRCompatibilityRules", "UseArm64CPU_DisplayName", "Use Arm64 CPU Architecture"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "UseArm64CPU_Description", "Meta Quest store requires 64-bit applications"),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnablePackageForMetaQuestRule final : public ISetupRule
	{
	public:
		FEnablePackageForMetaQuestRule()
			: ISetupRule(
				  "Compatibility_UsePackageForMetaQuest",
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_DisplayName", "Enable Package for Meta Quest devices"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_Description", "\"Package for Meta Quest devices\" must be enabled."),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FQuest2SupportedDeviceRule final : public ISetupRule
	{
	public:
		FQuest2SupportedDeviceRule()
			: ISetupRule(
				  "Compatibility_UsePackageForQuest2",
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_DisplayName", "Use Package for Quest2"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_Description", "Meta Quest2 must be added to \"Supported Meta Quest Devices\"."),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical,
				  ESetupRulePlatform::MetaQuest_2) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FQuestProSupportedDeviceRule final : public ISetupRule
	{
	public:
		FQuestProSupportedDeviceRule()
			: ISetupRule(
				  "Compatibility_UsePackageForQuestPro",
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_DisplayName", "Use Package for QuestPro"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_Description", "Meta QuestPro must be added to \"Supported Meta Quest Devices\"."),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical,
				  ESetupRulePlatform::MetaQuest_Pro) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FQuest3SupportedDeviceRule final : public ISetupRule
	{
	public:
		FQuest3SupportedDeviceRule()
			: ISetupRule(
				  "Compatibility_UsePackageForQuest3",
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_DisplayName", "Use Package for Quest3"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "UsePackageForQuest_Description", "Meta Quest3 must be added to \"Supported Meta Quest Devices\"."),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical,
				  ESetupRulePlatform::MetaQuest_3) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableFullscreenRule final : public ISetupRule
	{
	public:
		FEnableFullscreenRule()
			: ISetupRule(
				  "Compatibility_EnableFullscreen",
				  NSLOCTEXT("OculusXRCompatibilityRules", "EnableFullscreen_DisplayName", "Enable Fullscreen"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "EnableFullscreen_Description", "Android fullscreen must be enabled for VR"),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Warning,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableStartInVRRule final : public ISetupRule
	{
	public:
		FEnableStartInVRRule()
			: ISetupRule(
				  "Compatibility_EnableStartInVR",
				  NSLOCTEXT("OculusXRCompatibilityRules", "EnableStartInVR_DisplayName", "Enable Start in VR"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "EnableStartInVR_Description", "Enable the \"Start in VR\" setting to ensure your app starts in VR. (You can also ignore this and pass -vr at the command line"),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Warning) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableTouchInterfaceRule final : public ISetupRule
	{
	public:
		FDisableTouchInterfaceRule()
			: ISetupRule(
				  "Compatibility_DisableTouchInterface",
				  NSLOCTEXT("OculusXRCompatibilityRules", "DisableTouchInterface_DisplayName", "Disable Touch Interface"),
				  NSLOCTEXT("OculusXRCompatibilityRules", "DisableTouchInterface_Description", "Touch interface will interfere with correct VR input behavior"),
				  ESetupRuleCategory::Compatibility,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	inline TArray<SetupRulePtr> CompatibilityRules_Table{
		MakeShared<FUseAndroidSDKMinimumRule>(),
		MakeShared<FUseAndroidSDKTargetRule>(),
		MakeShared<FUseArm64CPURule>(),
		MakeShared<FEnablePackageForMetaQuestRule>(),
		MakeShared<FQuest2SupportedDeviceRule>(),
		MakeShared<FQuestProSupportedDeviceRule>(),
		MakeShared<FQuest3SupportedDeviceRule>(),
		MakeShared<FEnableFullscreenRule>(),
		MakeShared<FEnableStartInVRRule>(),
		MakeShared<FDisableTouchInterfaceRule>()
	};
} // namespace OculusXRCompatibilityRules
