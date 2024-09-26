// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSetupRule.h"

#include "OculusXRPSTEvents.h"
#include "OculusXRPSTSettings.h"
#include "OculusXRPSTUtils.h"

ISetupRule::ISetupRule(
	const FName& InId,
	const FText& InDisplayName,
	const FText& InDescription,
	const ESetupRuleCategory InCategory,
	const ESetupRuleSeverity InSeverity,
	const ESetupRulePlatform InPlatform)
	: Id(InId), DisplayName(InDisplayName), Description(InDescription), Category(InCategory), Severity(InSeverity), Platform(InPlatform)
{
}

void ISetupRule::Apply(bool& ShouldRestartEditor)
{
	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolFix> FixedEvent;
	const auto& Annotated = FixedEvent
								.AddAnnotation(OculusXRTelemetry::Annotations::Uid, TCHAR_TO_ANSI(*Id.ToString()))
								.AddAnnotation(OculusXRTelemetry::Annotations::Level, OculusXRPSTUtils::ToString(Severity))
								.AddAnnotation(OculusXRTelemetry::Annotations::Group, OculusXRPSTUtils::ToString(Category))
								.AddAnnotation(OculusXRTelemetry::Annotations::BuildTargetGroup, OculusXRPSTUtils::ToString(static_cast<ESetupRulePlatform>(Platform)))
								.AddAnnotation(OculusXRTelemetry::Annotations::Value, "true");
	ApplyImpl(ShouldRestartEditor);
}

bool ISetupRule::IsValid()
{
	return true;
}

bool ISetupRule::IsIgnored() const
{
	return bIsIgnored;
}

void ISetupRule::SetIgnoreRule(bool bIgnore, bool bSendMetrics)
{
	if (bSendMetrics)
	{
		const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolIgnore> IgnoreEvent;
		const auto& Annotated = IgnoreEvent
									.AddAnnotation(OculusXRTelemetry::Annotations::Uid, TCHAR_TO_ANSI(*Id.ToString()))
									.AddAnnotation(OculusXRTelemetry::Annotations::Level, OculusXRPSTUtils::ToString(Severity))
									.AddAnnotation(OculusXRTelemetry::Annotations::Group, OculusXRPSTUtils::ToString(Category))
									.AddAnnotation(OculusXRTelemetry::Annotations::BuildTargetGroup, OculusXRPSTUtils::ToString(static_cast<ESetupRulePlatform>(Platform)))
									.AddAnnotation(OculusXRTelemetry::Annotations::Value, bIgnore ? "true" : "false");
	}

	if (bIsIgnored == bIgnore)
	{
		return;
	}
	bIsIgnored = bIgnore;

	if (bIgnore)
	{
		GetMutableDefault<UOculusXRPSTSettings>()->IgnoredRules.Add(Id);
	}
	else
	{
		GetMutableDefault<UOculusXRPSTSettings>()->IgnoredRules.Remove(Id);
	}
	GetMutableDefault<UOculusXRPSTSettings>()->SaveConfig();
}

const FName& ISetupRule::GetId() const
{
	return Id;
}
FText ISetupRule::GetDisplayName() const
{
	return DisplayName;
}
FText ISetupRule::GetDescription() const
{
	return Description;
}
ESetupRuleCategory ISetupRule::GetCategory() const
{
	return Category;
}
ESetupRuleSeverity ISetupRule::GetSeverity() const
{
	return Severity;
}

ESetupRulePlatform ISetupRule::GetPlatform() const
{
	return Platform;
}
