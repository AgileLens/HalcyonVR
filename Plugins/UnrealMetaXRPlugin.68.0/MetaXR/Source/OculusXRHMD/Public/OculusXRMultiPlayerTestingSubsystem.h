// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Tickable.h"
#include "Subsystems/EngineSubsystem.h"
#include "IOculusXRHMDModule.h"
#include "Engine/GameViewportClient.h"

#include "OculusXRMultiPlayerTestingSubsystem.generated.h"

/**
 * The rule processor handles registration and querying of rules
 */
UCLASS()
class OCULUSXRHMD_API UOculusXRMultiPlayerTestingSubsystem final : public UEngineSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	/**
	 * Initialize the subsystem. USubsystem override
	 */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	 * De-initializes the subsystem. USubsystem override
	 */
	virtual void Deinitialize() override;

	//~ Begin FTickableGameObject interface
	virtual bool IsTickableInEditor() const { return true; }
	virtual ETickableTickType GetTickableTickType() const override;
	virtual bool IsAllowedToTick() const override;
	virtual void Tick(float DeltaTime) override;
	TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UOculusXRMultiPlayerTestingSubsystem, STATGROUP_Tickables); }
	//~ End FTickableGameObject interface

#if PLATFORM_WINDOWS
	void SwitchPrimaryPIE(UGameViewportClient* InViewport, TOptional<int> PrimaryPIEIndex);
	void SwitchPrimaryPIE_MultiProcess(int PrimaryPIEIndex);
#if WITH_EDITOR
	void SwitchPrimaryPIE_SingleProcess();
	void SwitchPrimaryPIE(FWorldContext* OldPrimaryWorld, FWorldContext* NewPrimaryWorld);
	void SwitchPrimaryPIE_SingleProcess(UGameViewportClient* InViewport, TOptional<int> PrimaryPIEIndex);
#endif // WITH_EDITOR
#endif // PLATFORM_WINDOWS

private:
	bool IsMultiPlayerTestingSupported() const;
#if PLATFORM_WINDOWS
	void GetUnrealEditorProcs(TArray<int32>& ProcIds);
	bool IsMultiPlayerTestingEnabled(bool& bSingleProcessMode);
	int32 NumClients;
#endif // PLATFORM_WINDOWS
};
