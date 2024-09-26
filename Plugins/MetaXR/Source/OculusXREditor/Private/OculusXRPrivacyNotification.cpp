// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPrivacyNotification.h"

#include "GeneralProjectSettings.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

#include "OculusXRHMDModule.h"
#include "OculusXRToolStyle.h"
#include "OculusXRTelemetryEvents.h"
#include "OculusXRTelemetryPrivacySettings.h"

#define LOCTEXT_NAMESPACE "OculusXRTelemetryPrivacySettings"

void OculusXRTelemetry::SpawnNotification()
{
	const auto EditorPrivacySettings = GetDefault<UOculusXRTelemetryPrivacySettings>();
	if ((!EditorPrivacySettings) || (EditorPrivacySettings->bHasNotified))
	{
		return;
	}

	FNotificationInfo Info(LOCTEXT("PrivacyTelemetrySettingsName", "MetaXR Usage Data"));
	Info.Image = FOculusToolStyle::Get().GetBrush("OculusTool.MenuButton");
	Info.ExpireDuration = 10.0f;
	Info.bFireAndForget = false;
	Info.Hyperlink = FSimpleDelegate::CreateLambda([EditorPrivacySettings]() {
		const FString DocsURL = EditorPrivacySettings->GetAdditionalInfoUrl();
		FPlatformProcess::LaunchURL(*DocsURL, nullptr, nullptr);
	});
	Info.HyperlinkText = EditorPrivacySettings->GetAdditionalInfoUrlLabel();
	Info.SubText = EditorPrivacySettings->GetTrueStateDescription();
	Info.bUseLargeFont = true;
	TPromise<TSharedPtr<SNotificationItem>> BtnNotificationPromise;
	const auto Clicked = [NotificationFuture = BtnNotificationPromise.GetFuture().Share()](bool bConsent) {
		const TSharedPtr<SNotificationItem> Notification = NotificationFuture.Get();
		Notification->SetCompletionState(bConsent ? SNotificationItem::CS_Success : SNotificationItem::CS_Fail);
		Notification->Fadeout();

		const auto EditorPrivacySettings = GetMutableDefault<UOculusXRTelemetryPrivacySettings>();
		EditorPrivacySettings->Modify();
		EditorPrivacySettings->bIsEnabled = bConsent;
		EditorPrivacySettings->bHasNotified = true;
		EditorPrivacySettings->SaveConfig();
		if (FOculusXRHMDModule::Get().IsOVRPluginAvailable() && FOculusXRHMDModule::GetPluginWrapper().IsInitialized())
		{
			Events::FEditorConsent().End(bConsent ? EAction::Success : EAction::Fail);
			OculusXRTelemetry::PropagateTelemetryConsent();
		}
	};
	Info.ButtonDetails.Add(
		FNotificationButtonInfo(
			EditorPrivacySettings->GetFalseStateLabel(),
			EditorPrivacySettings->GetFalseStateTooltip(),
			FSimpleDelegate::CreateLambda(Clicked, false),
			SNotificationItem::CS_Pending));
	Info.ButtonDetails.Add(
		FNotificationButtonInfo(
			EditorPrivacySettings->GetTrueStateLabel(),
			EditorPrivacySettings->GetTrueStateTooltip(),
			FSimpleDelegate::CreateLambda(Clicked, true),
			SNotificationItem::CS_Pending));

	const TSharedPtr<SNotificationItem> PrivacyNotification = FSlateNotificationManager::Get().AddNotification(Info);
	if (PrivacyNotification.IsValid())
	{
		PrivacyNotification->SetCompletionState(SNotificationItem::CS_Pending);
		BtnNotificationPromise.SetValue(PrivacyNotification);
	}

	if (FOculusXRHMDModule::Get().IsOVRPluginAvailable() && FOculusXRHMDModule::GetPluginWrapper().IsInitialized())
	{
		NotEnd = Events::FEditorConsent().Start() //
					 .AddAnnotation(Events::ConsentOriginKey, "Notification");
	}
}

#undef LOCTEXT_NAMESPACE
