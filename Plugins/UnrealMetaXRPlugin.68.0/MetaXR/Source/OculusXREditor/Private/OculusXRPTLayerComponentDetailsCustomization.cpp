// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPTLayerComponentDetailsCustomization.h"
#include "OculusXRPassthroughLayerComponent.h"
#include "Components/StereoLayerComponent.h"
#include "DetailWidgetRow.h"
#include "PropertyRestriction.h"
#include "DetailLayoutBuilder.h"
#include "UObject/Field.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "OculusXREditor"

//////////////////////////////////////////////////////////////////////////
// FOculusXRPTLayerComponentDetailsCustomization

TSharedRef<IDetailCustomization> FOculusXRPTLayerComponentDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FOculusXRPTLayerComponentDetailsCustomization);
}

void FOculusXRPTLayerComponentDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	TArray<FName> Categories;
	DetailBuilder.GetCategoryNames(Categories);
	for (FName CategoryName : Categories)
	{
		IDetailCategoryBuilder& CategoryBuilder = DetailBuilder.EditCategory(CategoryName, FText::GetEmpty(), ECategoryPriority::Important);

		TArray<TSharedRef<IPropertyHandle>> DefaultProperties;
		CategoryBuilder.GetDefaultProperties(DefaultProperties);

		for (TSharedRef<IPropertyHandle> PropertyHandle : DefaultProperties)
		{
			if (PropertyHandle->GetProperty()->GetName() == FName("Shape"))
			{
				ShapePropertyHandle = PropertyHandle;

				static const FName WarningColorStyle("Colors.AccentYellow");
				/* clang-format off */
				CategoryBuilder.AddCustomRow(LOCTEXT("OculusXRPTComponentShapeWarning", "Warning for UOculusXRPassthroughLayerComponent::Shape property"))
					.Visibility(TAttribute<EVisibility>(this, &FOculusXRPTLayerComponentDetailsCustomization::GetShapeWarningVisibility))
					[
						SNew(SVerticalBox)
							+ SVerticalBox::Slot().FillHeight(1.f).VAlign(EVerticalAlignment::VAlign_Center)
							[
								SNew(STextBlock)
									.Font(IDetailLayoutBuilder::GetDetailFont())
									.AutoWrapText(true)
									.Justification(ETextJustify::Center)
									.Text(TAttribute<FText>(this, &FOculusXRPTLayerComponentDetailsCustomization::GetShapeWarningText))
									.ColorAndOpacity(FAppStyle::Get().GetSlateColor(WarningColorStyle))
							]
					];
				/* clang-format on */
			}

			IDetailPropertyRow& Property = CategoryBuilder.AddProperty(PropertyHandle);
			Property.Visibility(TAttribute<EVisibility>::CreateLambda([PropertyHandle]() -> EVisibility {
				return PropertyHandle->IsEditConst() ? EVisibility::Hidden : EVisibility::Visible;
			}));
		}
	}
}

EVisibility FOculusXRPTLayerComponentDetailsCustomization::GetShapeWarningVisibility() const
{
	UObject* Shape;
	ShapePropertyHandle->GetValue(Shape);

	if (Shape == nullptr || Shape->IsA<UOculusXRStereoLayerShapeUserDefined>())
		return EVisibility::Collapsed;
	else
		return EVisibility::Visible;
}

FText FOculusXRPTLayerComponentDetailsCustomization::GetShapeWarningText() const
{
	UObject* Shape;
	ShapePropertyHandle->GetValue(Shape);

	if (Shape == nullptr || Shape->IsA<UOculusXRStereoLayerShapeUserDefined>())
		return FText::GetEmpty();
	else if (Shape->IsA<UOculusXRStereoLayerShapeReconstructed>())
		return LOCTEXT("OculusXRPTComponentShapeWarningText_Reconstructed",
			"If you wish to use the Reconstructed Passthrough Layer shape, the recommended method is to use the passthrough subsystem.\nFrom blueprint, call the \"Passthrough Subsytem->Initialize Persistent Passthrough\" node on startup instead of using this component.");
	else
		return FText::Format(LOCTEXT("OculusXRPTComponentShapeWarningText", "Please use a Shape class supporting passthrough with this component.\nIf you wish to continue using {0}, consider a Stereo Layer component instead"), FText::FromString(Shape->GetClass()->GetName()));
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
