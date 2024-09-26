
// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class IPropertyHandle;

class OCULUSXREDITOR_API FOculusXRSettingsToggle : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance();

	// IDetailCustomization interface
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;
	// End of IDetailCustomization interface
private:
	bool IsToggleValue(bool bValue) const;
	void OnToggledTo(bool bSetTo);
	void OnNavigateHyperlink(FString Url);
	FText GetDescriptionText() const;

	TSharedPtr<IPropertyHandle> TogglePropertyHandle;
	TWeakObjectPtr<UObject> ToggleSettingObject;
};
