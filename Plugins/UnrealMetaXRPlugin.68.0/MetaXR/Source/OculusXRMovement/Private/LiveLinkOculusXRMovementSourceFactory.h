// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "LiveLinkSourceFactory.h"
#include "LiveLinkOculusXRMovementSourceFactory.generated.h"

UCLASS()
class ULiveLinkOculusXRMovementSourceFactory : public ULiveLinkSourceFactory
{
public:
	GENERATED_BODY()

	virtual FText GetSourceDisplayName() const override;
	virtual FText GetSourceTooltip() const override;

	virtual EMenuType GetMenuType() const override;
	virtual TSharedPtr<ILiveLinkSource> CreateSource(const FString& ConnectionString) const override;

	TSharedPtr<class SLiveLinkOculusXRMovementSourceEditor> ActiveSourceEditor;
};
