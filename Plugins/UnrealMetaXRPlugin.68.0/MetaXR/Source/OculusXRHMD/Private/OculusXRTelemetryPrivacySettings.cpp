// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRTelemetryPrivacySettings.h"

#include "OculusXRHMDModule.h"
#include "OculusXRTelemetry.h"
#include "OculusXRTelemetryEvents.h"

#define LOCTEXT_NAMESPACE "OculusXRTelemetryPrivacySettings"

UOculusXRTelemetryPrivacySettings::UOculusXRTelemetryPrivacySettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOculusXRTelemetryPrivacySettings::GetToggleCategoryAndPropertyNames(FName& OutCategory, FName& OutProperty) const
{
	OutCategory = FName("Options");
	OutProperty = FName("bIsEnabled");
};

FText UOculusXRTelemetryPrivacySettings::GetFalseStateLabel() const
{
	return LOCTEXT("FalseStateLabel", "Don't Send");
};

FText UOculusXRTelemetryPrivacySettings::GetFalseStateTooltip() const
{
	return LOCTEXT("FalseStateTooltip", "Don't send MetaXR plugin usage data to Meta.");
};

FText UOculusXRTelemetryPrivacySettings::GetFalseStateDescription() const
{
	return LOCTEXT("FalseStateDescription", "By opting out you don't allow Meta to collect usage data on its SDKs, such as package name, class names and plugin configuration in your projects using Meta SDKs on this machine. This data helps improve the Meta SDKs and is collected in accordance with Meta's Privacy Policy.");
};

FText UOculusXRTelemetryPrivacySettings::GetTrueStateLabel() const
{
	return LOCTEXT("TrueStateLabel", "Send Usage Data");
};

FText UOculusXRTelemetryPrivacySettings::GetTrueStateTooltip() const
{
	return LOCTEXT("TrueStateTooltip", "Send MetaXR plugin usage data to Meta.");
};

FText UOculusXRTelemetryPrivacySettings::GetTrueStateDescription() const
{
	return LOCTEXT("TrueStateDescription", "By opting in you allow Meta to collect usage data on its SDKs, such as package name, class names and plugin configuration in your projects using Meta SDKs on this machine. This data helps improve the Meta SDKs and is collected in accordance with Meta's Privacy Policy.");
};

FString UOculusXRTelemetryPrivacySettings::GetAdditionalInfoUrl() const
{
	return FString(TEXT("https://www.meta.com/legal/quest/privacy-policy/"));
};

FText UOculusXRTelemetryPrivacySettings::GetAdditionalInfoUrlLabel() const
{
	return LOCTEXT("HyperlinkLabel", "Meta Platforms Technologies Privacy Policy");
};

#if WITH_EDITOR
void UOculusXRTelemetryPrivacySettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRTelemetryPrivacySettings, bIsEnabled))
	{
		using namespace OculusXRTelemetry;
		if (FOculusXRHMDModule::Get().IsOVRPluginAvailable() && FOculusXRHMDModule::GetPluginWrapper().IsInitialized())
		{
			PropagateTelemetryConsent();
			Events::FEditorConsent().Start()						 //
				.AddAnnotation(Events::ConsentOriginKey, "Settings") //
				.End(bIsEnabled ? EAction::Success : EAction::Fail);
		}
	}
}
#endif

#undef LOCTEXT_NAMESPACE
