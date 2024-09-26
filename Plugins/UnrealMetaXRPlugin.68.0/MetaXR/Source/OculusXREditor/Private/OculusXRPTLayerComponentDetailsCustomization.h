// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "PropertyHandle.h"
#include "IDetailCustomization.h"

class IDetailLayoutBuilder;

class FOculusXRPTLayerComponentDetailsCustomization : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	// IDetailCustomization interface
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
	// End of IDetailCustomization interface

	EVisibility GetShapeWarningVisibility() const;
	FText GetShapeWarningText() const;

private:
	TSharedPtr<IPropertyHandle> ShapePropertyHandle;
};
