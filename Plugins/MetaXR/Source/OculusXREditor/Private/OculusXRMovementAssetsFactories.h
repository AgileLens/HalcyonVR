// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Factories/BlueprintFactory.h"

#include "OculusXRMovementAssetsFactories.generated.h"

UCLASS(Abstract, hidecategories = Object, MinimalAPI)
class UOculusXRMetahumanRetargetAssetFactory : public UBlueprintFactory
{
	GENERATED_BODY()
public:
	UOculusXRMetahumanRetargetAssetFactory(const FObjectInitializer& ObjectInitializer);

	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual uint32 GetMenuCategories() const override;

protected:
	virtual void SetDefaults(const TSubclassOf<UObject> GeneratedClass) const PURE_VIRTUAL(UOculusXRMetahumanRetargetAssetFactory::SetDefaults, );
};

UCLASS(hidecategories = Object, MinimalAPI)
class UOculusXRMetahumanFaceRetargetAssetFactory : public UOculusXRMetahumanRetargetAssetFactory
{
	GENERATED_BODY()
public:
	UOculusXRMetahumanFaceRetargetAssetFactory(const FObjectInitializer& ObjectInitializer);

	virtual FText GetDisplayName() const override;

protected:
	virtual void SetDefaults(const TSubclassOf<UObject> GeneratedClass) const override;
};

UCLASS(hidecategories = Object, MinimalAPI)
class UOculusXRMetahumanBodyRetargetAssetFactory : public UOculusXRMetahumanRetargetAssetFactory
{
	GENERATED_BODY()
public:
	UOculusXRMetahumanBodyRetargetAssetFactory(const FObjectInitializer& ObjectInitializer);

	virtual FText GetDisplayName() const override;

protected:
	virtual void SetDefaults(const TSubclassOf<UObject> GeneratedClass) const override;
};
