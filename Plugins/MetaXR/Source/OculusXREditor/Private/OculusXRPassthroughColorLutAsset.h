// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "AssetTypeActions_Base.h"

#include "OculusXRPassthroughColorLutAsset.generated.h"

class FAssetTypeActions_OculusXRPassthroughColorLut : public FAssetTypeActions_Base
{
public:
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual const TArray<FText>& GetSubMenus() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
};

UCLASS(hidecategories = Object, MinimalAPI)
class UOculusXRPassthroughColorLutFactory : public UFactory
{
	GENERATED_BODY()

public:
	UOculusXRPassthroughColorLutFactory(const FObjectInitializer& ObjectInitializer);

	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context,
		FFeedbackContext* Warn) override;

	virtual uint32 GetMenuCategories() const override;
};
