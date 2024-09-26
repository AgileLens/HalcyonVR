// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRRuleProcessorSubsystem.h"

#include "LightComponentBase.h"
#include "OculusXRProjectSetupToolModule.h"
#include "OculusXRPSTEvents.h"
#include "OculusXRPSTSettings.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRTelemetry.h"
#include "Developer/LauncherServices/Public/ILauncherServicesModule.h"
#include "Rules/OculusXRAnchorsRules.h"
#include "Rules/OculusXRCompatibilityRules.h"
#include "Rules/OculusXRMovementRules.h"
#include "Rules/OculusXRPassthroughRules.h"
#include "Rules/OculusXRRenderingRules.h"
#include "Rules/OculusXRPluginRules.h"

/**
 * Initialize the subsystem. USubsystem override
 */
void UOculusXRRuleProcessorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	PopulateDynamicLights();

	// Register rules
	RegisterRules(OculusXRRenderingRules::RenderingRules_Table);
	RegisterRules(OculusXRPluginRules::PluginRules_Table);
	RegisterRules(OculusXRCompatibilityRules::CompatibilityRules_Table);
	RegisterRules(OculusXRPassthroughRules::PassthroughRules_Table);
	RegisterRules(OculusXRMovementRules::MovementRules_Table);
	RegisterRules(OculusXRAnchorsRules::AnchorRules_Table);

	// Register on Launcher Callback
	ILauncherServicesModule& ProjectLauncherServicesModule = FModuleManager::LoadModuleChecked<ILauncherServicesModule>(
		"LauncherServices");
	LauncherCallbackHandle = ProjectLauncherServicesModule.OnCreateLauncherDelegate.AddUObject(
		this, &UOculusXRRuleProcessorSubsystem::OnLauncherCreated);
	// Show errors after play in editor is over.
	FEditorDelegates::PrePIEEnded.AddUObject(this, &UOculusXRRuleProcessorSubsystem::OnPIEEnded);

	// Update if rules are ignored. Note: At time of the rules construction it is early to fetch settings
	const auto& IgnoredRules = GetMutableDefault<UOculusXRPSTSettings>()->IgnoredRules;
	for (const auto& Rule : Rules)
	{
		Rule->SetIgnoreRule(IgnoredRules.Contains(Rule->GetId()), false);
	}

	SendSummaryEvent();
}

/**
 * De-initializes the subsystem. USubsystem override
 */
void UOculusXRRuleProcessorSubsystem::Deinitialize()
{
	SendSummaryEvent();
	Super::Deinitialize();
	if (LauncherCallbackHandle.IsValid())
	{
		ILauncherServicesModule& ProjectLauncherServicesModule = FModuleManager::LoadModuleChecked<
			ILauncherServicesModule>(
			"LauncherServices");
		ProjectLauncherServicesModule.OnCreateLauncherDelegate.Remove(LauncherCallbackHandle);
		LauncherCallbackHandle.Reset();
	}
}

/**
 * Register a rule
 */
bool UOculusXRRuleProcessorSubsystem::RegisterRule(const SetupRulePtr& Rule)
{
	if (Rule == nullptr)
	{
		UE_LOG(LogProjectSetupTool, Error, TEXT("RegisterRule: Cannot register nullptr"));
		return false;
	}
	bool bIsAlreadyRegistred = false;
	Rules.Add(Rule, &bIsAlreadyRegistred);
	if (bIsAlreadyRegistred)
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("RegisterRule: rule with id <%s> has already been registered"),
			*(Rule->GetId().ToString()));
		return false;
	}

	UE_LOG(LogProjectSetupTool, Display, TEXT("RegisterRule: added rule with id <%s>"), *(Rule->GetId().ToString()));

	return true;
}

/**
 * Unregister a rule
 */
bool UOculusXRRuleProcessorSubsystem::UnregisterRule(const SetupRulePtr& Rule)
{
	if (Rule == nullptr)
	{
		UE_LOG(LogProjectSetupTool, Error, TEXT("RegisterRule: Cannot deregister nullptr"));
		return false;
	}
	const auto Id = Rule->GetId();
	if (!Rules.Contains(Id))
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("UnregisterRule: rule with id <%s> has not been registered"),
			*Id.ToString());
		return false;
	}

	UE_LOG(LogProjectSetupTool, Display, TEXT("UnregisterRule: removed rule with id <%s>"), *Id.ToString());

	Rules.Remove(Id);
	return true;
}

/**
 * Unregister all rules
 */
void UOculusXRRuleProcessorSubsystem::UnregisterAllRules()
{
	UE_LOG(LogProjectSetupTool, Display, TEXT("UnregisterRule: removed all rules"));

	Rules.Empty();
}

/**
 * Fetch all rules
 */
const TSet<SetupRulePtr, FSetupRuleKeyFunc>& UOculusXRRuleProcessorSubsystem::GetRules() const
{
	return Rules;
}

/**
 *  Fetch rule with given `Id`
 */
SetupRulePtr UOculusXRRuleProcessorSubsystem::GetRule(const FName& Id) const
{
	const auto Found = Rules.Find(Id);
	if (Found == nullptr)
	{
		return nullptr;
	}

	return *Found;
}

bool UOculusXRRuleProcessorSubsystem::DynamicLightsExistInProject() const
{
	return DynamicLights.Num() > 0;
}

void UOculusXRRuleProcessorSubsystem::SendSummaryEvent()
{
	SendSummaryEvent(ESetupRulePlatform::MetaLink);
	SendSummaryEvent(ESetupRulePlatform::MetaQuest_2);
	SendSummaryEvent(ESetupRulePlatform::MetaQuest_3);
	SendSummaryEvent(ESetupRulePlatform::MetaQuest_Pro);
}

void UOculusXRRuleProcessorSubsystem::SendSummaryEvent(ESetupRulePlatform Platform) const
{
	const auto& Status = UnAppliedRulesStatus(Platform);
	const char* Level = Status.PendingRequiredRulesCount > 0 ? "Critical" : "Recommended";
	const char* Value = TCHAR_TO_ANSI(*FString::FromInt(Status.PendingRequiredRulesCount > 0 ? Status.PendingRequiredRulesCount : Status.PendingRecommendedRulesCount));
	const char* Total = TCHAR_TO_ANSI(
		*FString::FromInt(Status.PendingRequiredRulesCount + Status.PendingRecommendedRulesCount));
	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolSummary> SummaryEvent;
	const auto& CriticalAnnotated = SummaryEvent
										.AddAnnotation(OculusXRTelemetry::Annotations::Level, Level)
										.AddAnnotation(OculusXRTelemetry::Annotations::Value, Value)
										.AddAnnotation(OculusXRTelemetry::Annotations::Count, Total)
										.AddAnnotation(OculusXRTelemetry::Annotations::BuildTargetGroup, OculusXRPSTUtils::ToString(Platform));
}

void UOculusXRRuleProcessorSubsystem::Refresh()
{
	PopulateDynamicLights();
	SendSummaryEvent();
}

UOculusXRRuleProcessorSubsystem::RuleStatus UOculusXRRuleProcessorSubsystem::UnAppliedRulesStatus(
	ESetupRulePlatform Platform) const
{
	RuleStatus Status{};
	for (const auto& Rule : Rules)
	{
		if (Rule->IsApplied())
		{
			continue;
		}
		if (OculusXRPSTUtils::ShouldRuleBeSkipped(Rule, Platform, { ESetupRuleSeverity::Critical, ESetupRuleSeverity::Performance, ESetupRuleSeverity::Warning }))
		{
			continue;
		}

		if (Rule->GetSeverity() == ESetupRuleSeverity::Critical)
		{
			++Status.PendingRequiredRulesCount;
		}
		else
		{
			++Status.PendingRecommendedRulesCount;
		}
	}
	return Status;
}

void UOculusXRRuleProcessorSubsystem::PopulateDynamicLights()
{
	DynamicLights.Empty();

	for (TObjectIterator<ULightComponentBase> LightItr; LightItr; ++LightItr)
	{
		const AActor* owner = LightItr->GetOwner();
		if (owner != nullptr && (owner->IsRootComponentStationary() || owner->IsRootComponentMovable()) && !owner->IsHiddenEd() && LightItr->IsVisible() && owner->IsEditable() && owner->IsSelectable() && LightItr->GetWorld() == GEditor->GetEditorWorldContext().World())
		{
			DynamicLights.Add(LightItr->GetFullGroupName(false), TWeakObjectPtr<ULightComponentBase>(*LightItr));
		}
	}
}

void UOculusXRRuleProcessorSubsystem::RegisterRules(const TArray<SetupRulePtr>& InRules)
{
	for (const auto& Rule : InRules)
	{
		if (!RegisterRule(Rule))
		{
			UE_LOG(LogProjectSetupTool, Error, TEXT("Cannot register rule <%s>"), *Rule->GetId().ToString());
		}
	}
}

void UOculusXRRuleProcessorSubsystem::OnLauncherCreated(ILauncherRef Launcher)
{
	// Add callback for when launcher worker is started
	Launcher->FLauncherWorkerStartedDelegate.AddUObject(
		this, &UOculusXRRuleProcessorSubsystem::OnLauncherWorkerStarted);
}

void UOculusXRRuleProcessorSubsystem::OnLauncherWorkerStarted(ILauncherWorkerPtr LauncherWorker,
	ILauncherProfileRef Profile)
{
	if (!GetMutableDefault<UOculusXRPSTSettings>()->bStopBuildOnUnAppliedCriticalItems)
	{
		return;
	}

	const TArray<FString> Platforms = Profile.Get().GetCookedPlatforms();
	ESetupRulePlatform RulePlatforms = ESetupRulePlatform::None;
	if (Platforms.Contains("Android_ASTC"))
	{
		RulePlatforms |= MetaQuest_All;
	}

	if (Platforms.Contains("Windows"))
	{
		RulePlatforms |= ESetupRulePlatform::MetaLink;
	}

	const auto& UnAppliedRules = UnAppliedRulesForPlatform(RulePlatforms, { ESetupRuleSeverity::Critical });

	OculusXRPSTUtils::LogErrorForUnAppliedRules(UnAppliedRules);
	if (!UnAppliedRules.IsEmpty())
	{
		LauncherWorker->Cancel();
	}
}

void UOculusXRRuleProcessorSubsystem::OnPIEEnded(bool bIsSimulating)
{
	const auto& UnAppliedRules = UnAppliedRulesForPlatform(ESetupRulePlatform::MetaLink, { ESetupRuleSeverity::Critical });

	OculusXRPSTUtils::LogErrorForUnAppliedRules(UnAppliedRules);
}

TArray<SetupRulePtr> UOculusXRRuleProcessorSubsystem::UnAppliedRulesForPlatform(ESetupRulePlatform Platform, const TSet<ESetupRuleSeverity>& Severities) const
{
	TArray<SetupRulePtr> UnAppliedRules = {};
	for (const auto Rule : Rules)
	{
		if (!OculusXRPSTUtils::ShouldRuleBeSkipped(Rule, Platform, Severities) && !Rule->IsApplied())
		{
			UnAppliedRules.Add(Rule);
		}
	}

	return UnAppliedRules;
}
