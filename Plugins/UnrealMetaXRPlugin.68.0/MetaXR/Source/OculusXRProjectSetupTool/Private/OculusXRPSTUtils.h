// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "CoreMinimal.h"
#include "OculusXRProjectSetupToolModule.h"

#define OCULUSXR_UPDATE_SETTINGS(SettingsClass, PropertyName, PropertyValue) \
	{                                                                        \
		SettingsClass* Settings = GetMutableDefault<SettingsClass>();        \
		Settings->PropertyName = PropertyValue;                              \
		Settings->UpdateSinglePropertyInConfigFile(                          \
			Settings->GetClass()->FindPropertyByName(                        \
				GET_MEMBER_NAME_CHECKED(SettingsClass, PropertyName)),       \
			Settings->GetDefaultConfigFilename());                           \
	}

namespace OculusXRPSTUtils
{
	/**
	 * Return if there is a component of a given type in the world.
	 */
	template <typename T>
	bool IsComponentOfTypeInWorld()
	{
		for (TObjectIterator<T> Iterator; Iterator;)
		{
			return true;
		}

		return false;
	}

	/**
	 * Return if there is a component of a given type in the world that matches the condition.
	 *
	 * Usage :
	 *	IsComponentOfTypeInWorld<T>([](T* Component){ return Component->SomeProperty == DesiredValue; })
	 */
	template <typename T>
	bool IsComponentOfTypeInWorld(TFunction<bool(T*)> Condition)
	{
		for (TObjectIterator<T> Iterator; Iterator; ++Iterator)
		{
			if (Condition(*Iterator))
				return true;
		}

		return false;
	}

	inline const char* ToString(ESetupRuleSeverity Severity)
	{
		switch (Severity)
		{
			case ESetupRuleSeverity::Critical:
				return "critical";
			case ESetupRuleSeverity::Performance:
				return "performance";
			case ESetupRuleSeverity::Warning:
				return "warning";
			default:
				UE_LOG(LogTemp, Error, TEXT("Not covered Severity enum. %d"), Severity);
				check(false);
		}
		return "";
	}

	inline const char* ToString(ESetupRuleCategory Category)
	{
		switch (Category)
		{
			case ESetupRuleCategory::Compatibility:
				return "Compatibility";
			case ESetupRuleCategory::Rendering:
				return "Rendering";
			case ESetupRuleCategory::Quality:
				return "Quality";
			case ESetupRuleCategory::Physics:
				return "Physics";
			case ESetupRuleCategory::Plugins:
				return "Plugins";
			case ESetupRuleCategory::Features:
				return "Features";
			case ESetupRuleCategory::Miscellaneous:
				return "Miscellaneous";
			default:
				UE_LOG(LogTemp, Error, TEXT("Not covered Category enum. %d"), Category);
				check(false);
		}
		return "";
	}

	inline const char* ToString(ESetupRulePlatform Platform)
	{
		FString Result = "";
		if ((Platform & ESetupRulePlatform::MetaLink) == ESetupRulePlatform::MetaLink)
			Result += " PC Link";
		if ((Platform & ESetupRulePlatform::MetaQuest_2) == ESetupRulePlatform::MetaQuest_2)
			Result += " Quest 2";
		if ((Platform & ESetupRulePlatform::MetaQuest_3) == ESetupRulePlatform::MetaQuest_3)
			Result += " Quest 3";
		if ((Platform & ESetupRulePlatform::MetaQuest_Pro) == ESetupRulePlatform::MetaQuest_Pro)
			Result += " Quest Pro";
		return TCHAR_TO_ANSI(*Result);
	}

	inline const char* GetDisplayName(ESetupRulePlatform Platform)
	{
		if ((Platform & MetaQuest_All) == MetaQuest_All)
			return "All Quest";
		if ((Platform & ESetupRulePlatform::MetaLink) == ESetupRulePlatform::MetaLink)
			return "PC Link";
		if ((Platform & ESetupRulePlatform::MetaQuest_2) == ESetupRulePlatform::MetaQuest_2)
			return "Quest 2";
		if ((Platform & ESetupRulePlatform::MetaQuest_3) == ESetupRulePlatform::MetaQuest_3)
			return "Quest 3";
		if ((Platform & ESetupRulePlatform::MetaQuest_Pro) == ESetupRulePlatform::MetaQuest_Pro)
			return "Quest Pro";
		return "";
	}

	inline void SetBrushStyle(const TSharedPtr<FSlateStyleSet>& Style, const ESetupRulePlatform Platform)
	{
		FString RelativePath = "PlatformQuest3"; // Quest3 and All Quest
		FVector2d Size{ 32.f, 32.f };
		if (Platform == ESetupRulePlatform::MetaLink)
		{
			RelativePath = "PlatformDesktop";
			Size = { 16.f, 16.f };
		}

		if (Platform == ESetupRulePlatform::MetaQuest_Pro || Platform == ESetupRulePlatform::MetaQuest_2)
		{
			RelativePath = "PlatformQuest2";
		}

		Style->Set(GetDisplayName(Platform),
			new FSlateVectorImageBrush(Style->RootToContentDir(RelativePath, TEXT(".svg")),
				Size));
	}
	inline bool ShouldRuleBeSkipped(const SetupRulePtr& Rule, ESetupRulePlatform Platform, const TSet<ESetupRuleSeverity>& Severities)
	{
		return !Rule->IsValid() || Rule->IsIgnored() || !Severities.Contains(Rule->GetSeverity()) || (Rule->GetPlatform() & Platform) != Platform;
	}

	inline void LogErrorForUnAppliedRules(const TArray<SetupRulePtr>& UnAppliedRules)
	{
		if (!UnAppliedRules.IsEmpty())
		{
			UE_LOG(LogProjectSetupTool, Error, TEXT("Following critical rules are not applied:\n%s"),
				*FString::JoinBy(
					UnAppliedRules,
					TEXT("\n"),
					[](const SetupRulePtr Rule) { return Rule->GetDisplayName().ToString(); }));
			UE_LOG(LogProjectSetupTool, Error, TEXT("To fix them open `Tools > Meta XR Project Setup Tool`"));
		}
	}
} // namespace OculusXRPSTUtils
