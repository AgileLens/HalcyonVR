// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRSetupRule.h"

/*
 * Collection of rules related to movement SDK. Can be extended as needed
 */
namespace OculusXRMovementRules
{
	class FEnableBodyTrackingRule final : public ISetupRule
	{
	public:
		FEnableBodyTrackingRule()
			: ISetupRule(
				  "Feature_EnableBodyTracking",
				  NSLOCTEXT("OculusXRMovementRules", "EnableBodyTracking_DisplayName", "Enable Body Tracking"),
				  NSLOCTEXT("OculusXRMovementRules", "EnableBodyTracking_Description", "Body tracking must be enabled when using body tracking features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableFaceTrackingRule final : public ISetupRule
	{
	public:
		FEnableFaceTrackingRule()
			: ISetupRule(
				  "Feature_EnableFaceTracking",
				  NSLOCTEXT("OculusXRMovementRules", "EnableFaceTracking_DisplayName", "Enable Face Tracking"),
				  NSLOCTEXT("OculusXRMovementRules", "EnableFaceTracking_Description", "Face tracking must be enabled when using face tracking features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableEyeTrackingRule final : public ISetupRule
	{
	public:
		FEnableEyeTrackingRule()
			: ISetupRule(
				  "Feature_EnableEyeTracking",
				  NSLOCTEXT("OculusXRMovementRules", "EnableEyeTracking_DisplayName", "Enable Eye Tracking"),
				  NSLOCTEXT("OculusXRMovementRules", "EnableEyeTracking_Description", "Eye tracking must be enabled when using eye tracking features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	inline TArray<SetupRulePtr> MovementRules_Table{
		MakeShared<FEnableBodyTrackingRule>(),
		MakeShared<FEnableFaceTrackingRule>(),
		MakeShared<FEnableEyeTrackingRule>()
	};
} // namespace OculusXRMovementRules
