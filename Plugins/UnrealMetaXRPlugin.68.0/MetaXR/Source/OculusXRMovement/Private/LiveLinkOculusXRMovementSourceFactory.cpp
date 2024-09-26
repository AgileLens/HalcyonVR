// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "LiveLinkOculusXRMovementSourceFactory.h"
#include "IOculusXRMovementModule.h"

#include "Features/IModularFeatures.h"
#include "ILiveLinkClient.h"

#define LOCTEXT_NAMESPACE "OculusXRMovement"

FText ULiveLinkOculusXRMovementSourceFactory::GetSourceDisplayName() const
{
	return LOCTEXT("OculusXRMovementLiveLinkSourceName", "Meta MovementSDK Live Link");
}

FText ULiveLinkOculusXRMovementSourceFactory::GetSourceTooltip() const
{
	return LOCTEXT("OculusXRMovementLiveLinkSourceTooltip", "Meta MovementSDK Live Link Source");
}

ULiveLinkOculusXRMovementSourceFactory::EMenuType ULiveLinkOculusXRMovementSourceFactory::GetMenuType() const
{
	if (IModularFeatures::Get().IsModularFeatureAvailable(ILiveLinkClient::ModularFeatureName))
	{
		const ILiveLinkClient& LiveLinkClient = IModularFeatures::Get().GetModularFeature<ILiveLinkClient>(ILiveLinkClient::ModularFeatureName);

		if (!IOculusXRMovementModule::Get().IsLiveLinkSourceValid() || !LiveLinkClient.HasSourceBeenAdded(IOculusXRMovementModule::Get().GetLiveLinkSource()))
		{
			return EMenuType::MenuEntry;
		}
	}
	return EMenuType::Disabled;
}

TSharedPtr<ILiveLinkSource> ULiveLinkOculusXRMovementSourceFactory::CreateSource(const FString& ConnectionString) const
{
	return IOculusXRMovementModule::Get().GetLiveLinkSource();
}

#undef LOCTEXT_NAMESPACE
