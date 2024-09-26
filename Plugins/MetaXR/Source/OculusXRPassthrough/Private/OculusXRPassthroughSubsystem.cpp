// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughSubsystem.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "OculusXRPersistentPassthroughInstance.h"
#include "OculusXRHMD.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPassthroughEventHandling.h"
#include "OculusXRPassthroughModule.h"
#include "Engine/World.h"

UOculusXRPassthroughSubsystem* UOculusXRPassthroughSubsystem::GetPassthroughSubsystem(const UWorld* InWorld)
{
	if (InWorld)
	{
		return UGameInstance::GetSubsystem<UOculusXRPassthroughSubsystem>(InWorld->GetGameInstance());
	}

	return nullptr;
}

UOculusXRPassthroughSubsystem::UOculusXRPassthroughSubsystem()
{
}

bool UOculusXRPassthroughSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	// return true if "Passthrough Enabled" is checked in MetaXR plugin's settings.

	return GetDefault<UOculusXRHMDRuntimeSettings>()->bInsightPassthroughEnabled;
}

void UOculusXRPassthroughSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	DelegateHandleLayerResumed = OculusXRPassthrough::FOculusXRPassthroughEventDelegates::OculusPassthroughLayerResumed.AddLambda([this](int layerID) {
		UE_LOG(LogOculusXRPassthrough, Log, TEXT("UOculusXRPassthroughSubsystem - Received layer #%d resumed event"), layerID);
		OnAnyLayerResumed.Broadcast(layerID);
	});
}

void UOculusXRPassthroughSubsystem::Deinitialize()
{
	OculusXRPassthrough::FOculusXRPassthroughEventDelegates::OculusPassthroughLayerResumed.Remove(DelegateHandleLayerResumed);
}

UOculusXRPersistentPassthroughInstance* UOculusXRPassthroughSubsystem::InitializePersistentPassthrough(FOculusXRPersistentPassthroughParameters Parameters, const FOculusXRPassthrough_LayerResumed_Single& LayerResumed)
{
	if (IsValid(PPTInstance))
	{
		PPTInstance->AddLayerResumedSingleDelegate(LayerResumed);
		PPTInstance->UpdateParameters(Parameters);

		return PPTInstance;
	}

	PPTInstance = NewObject<UOculusXRPersistentPassthroughInstance>(this, "PersistentPassthroughInstance", RF_NoFlags);
	PPTInstance->AddLayerResumedSingleDelegate(LayerResumed);
	PPTInstance->InitLayer(Parameters);
	OnAnyLayerResumed.AddDynamic(PPTInstance, &UOculusXRPersistentPassthroughInstance::OnAnyLayerResumedEvent);

	return PPTInstance;
}

void UOculusXRPassthroughSubsystem::DestroyPersistentPassthrough()
{
	if (!IsValid(PPTInstance))
	{
		return;
	}

	OnAnyLayerResumed.RemoveDynamic(PPTInstance, &UOculusXRPersistentPassthroughInstance::OnAnyLayerResumedEvent);
	PPTInstance->ConditionalBeginDestroy();
	PPTInstance = nullptr;
}

UOculusXRPersistentPassthroughInstance* UOculusXRPassthroughSubsystem::GetPersistentPassthrough() const
{
	return PPTInstance;
}
