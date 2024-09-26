// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "IOculusXRMRModule.h"
#include "Engine/EngineBaseTypes.h"

#define LOCTEXT_NAMESPACE "OculusXRMR"

enum class EOculusXRMR_CompositionMethod : uint8;
enum class EOculusXRMR_DepthQuality : uint8;

class UOculusXRMR_Settings;
class AOculusXRMR_CastingCameraActor;
class UOculusXRMR_State;

//-------------------------------------------------------------------------------------------------
// FOculusXRInputModule
//-------------------------------------------------------------------------------------------------

class FOculusXRMRModule : public IOculusXRMRModule
{
public:
	FOculusXRMRModule();
	~FOculusXRMRModule();

	static inline FOculusXRMRModule& Get()
	{
		return FModuleManager::GetModuleChecked<FOculusXRMRModule>("OculusXRMR");
	}

	// IOculusXRMRModule
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	bool IsInitialized() { return bInitialized; }

	bool IsActive();
	UOculusXRMR_Settings* GetMRSettings();
	UOculusXRMR_State* GetMRState();

private:
	bool bInitialized;
	UOculusXRMR_Settings* MRSettings;
	UOculusXRMR_State* MRState;
	AOculusXRMR_CastingCameraActor* MRActor;
	UWorld* CurrentWorld;

	FDelegateHandle WorldAddedEventBinding;
	FDelegateHandle WorldDestroyedEventBinding;
	FDelegateHandle WorldLoadEventBinding;

	void InitMixedRealityCapture();

	/** Initialize the tracked physical camera */
	void SetupExternalCamera();
	/** Set up the needed settings and actors for MRC in-game */
	void SetupInGameCapture();
	/** Destroy actors for MRC in-game */
	void CloseInGameCapture();
	/** Reset all the MRC settings and state to the config and default */
	void ResetSettingsAndState();

	/** Handle changes on specific settings */
	void OnCompositionMethodChanged(EOculusXRMR_CompositionMethod OldVal, EOculusXRMR_CompositionMethod NewVal);
	void OnIsCastingChanged(bool OldVal, bool NewVal);
	void OnUseDynamicLightingChanged(bool OldVal, bool NewVal);
	void OnDepthQualityChanged(EOculusXRMR_DepthQuality OldVal, EOculusXRMR_DepthQuality NewVal);
	void OnTrackedCameraIndexChanged(int OldVal, int NewVal);

	void OnWorldCreated(UWorld* NewWorld);
	void OnWorldDestroyed(UWorld* NewWorld);

#if PLATFORM_ANDROID
	bool bActivated;

	FDelegateHandle InitialWorldAddedEventBinding;
	FDelegateHandle InitialWorldLoadEventBinding;
	FDelegateHandle PreWorldTickEventBinding;

	void ChangeCaptureState();
	void OnWorldTick(UWorld* World, ELevelTick Tick, float Delta);
	void OnInitialWorldCreated(UWorld* NewWorld);
#endif

#if WITH_EDITOR
	FDelegateHandle PieBeginEventBinding;
	FDelegateHandle PieStartedEventBinding;
	FDelegateHandle PieEndedEventBinding;

	void OnPieBegin(bool bIsSimulating);
	void OnPieStarted(bool bIsSimulating);
	void OnPieEnded(bool bIsSimulating);
#endif
};

#undef LOCTEXT_NAMESPACE
