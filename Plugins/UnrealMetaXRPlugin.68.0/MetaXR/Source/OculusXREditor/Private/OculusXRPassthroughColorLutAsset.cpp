// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughColorLutAsset.h"
#include "AssetTypeCategories.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "OculusXRPassthroughColorLut.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"

FText FAssetTypeActions_OculusXRPassthroughColorLut::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_PassthroughColorLUT", "PassthroughColorLUT");
}

FColor FAssetTypeActions_OculusXRPassthroughColorLut::GetTypeColor() const
{
	return FColor(100, 100, 100);
}

const TArray<FText>& FAssetTypeActions_OculusXRPassthroughColorLut::GetSubMenus() const
{
	static const TArray<FText> SubMenus{
		LOCTEXT("AssetOculusXRPassthroughColorLutSubMenu", "OculusXR")
	};

	return SubMenus;
}

UClass* FAssetTypeActions_OculusXRPassthroughColorLut::GetSupportedClass() const
{
	return UOculusXRPassthroughColorLut::StaticClass();
}

uint32 FAssetTypeActions_OculusXRPassthroughColorLut::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

UOculusXRPassthroughColorLutFactory::UOculusXRPassthroughColorLutFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UOculusXRPassthroughColorLut::StaticClass();

	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UOculusXRPassthroughColorLutFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context,
	FFeedbackContext* Warn)
{
	return NewObject<UOculusXRPassthroughColorLut>(InParent, Name, Flags);
}

uint32 UOculusXRPassthroughColorLutFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Misc;
}
#undef LOCTEXT_NAMESPACE
