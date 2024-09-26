// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
#include "OculusXRMRModule.h"

#include "Engine/Engine.h"
#include "ISpectatorScreenController.h"
#include "IXRTrackingSystem.h"
#include "StereoRendering.h"
#include "StereoRenderTargetManager.h"
#include "SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "EngineUtils.h"
#include "PostProcess/SceneRenderTargets.h"
#include "Kismet/GameplayStatics.h"
#include "OculusXRHMDModule.h"
#include "OculusXRHMD.h"
#include "OculusXRMRFunctionLibrary.h"
#include "OculusXRMRPrivate.h"
#include "OculusXRMR_Settings.h"
#include "OculusXRMR_State.h"
#include "OculusXRMR_CastingCameraActor.h"
#include "AudioDevice.h"
#if PLATFORM_ANDROID
#include "IVulkanDynamicRHI.h"
#endif

#if WITH_EDITOR
#include "Editor.h" // for FEditorDelegates::PostPIEStarted
#endif

#define LOCTEXT_NAMESPACE "OculusXRMR"

FOculusXRMRModule::FOculusXRMRModule()
	: bInitialized(false)
	, MRSettings(nullptr)
	, MRState(nullptr)
	, MRActor(nullptr)
	, CurrentWorld(nullptr)
	, WorldAddedEventBinding()
	, WorldDestroyedEventBinding()
	, WorldLoadEventBinding()
#if PLATFORM_ANDROID
	, bActivated(false)
	, InitialWorldAddedEventBinding()
	, InitialWorldLoadEventBinding()
	, PreWorldTickEventBinding()
#endif
#if WITH_EDITOR
	, PieBeginEventBinding()
	, PieStartedEventBinding()
	, PieEndedEventBinding()
#endif
{
}

FOculusXRMRModule::~FOculusXRMRModule()
{
}

void FOculusXRMRModule::StartupModule()
{
#if OCULUS_MR_SUPPORTED_PLATFORMS
#if PLATFORM_WINDOWS
	const TCHAR* CmdLine = FCommandLine::Get();
	const bool bAutoOpenFromParams = FParse::Param(CmdLine, TEXT("mixedreality"));

	if (bAutoOpenFromParams && FOculusXRHMDModule::Get().PreInit())
	{
		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().InitializeMixedReality()))
			{
				InitMixedRealityCapture();
			}
			else
			{
				UE_LOG(LogMR, Error, TEXT("ovrp_InitializeMixedReality() failed"));
			}
		}
		else
		{
			UE_LOG(LogMR, Error, TEXT("OVRPlugin has not been initialized"));
		}
	}
#elif PLATFORM_ANDROID
	// On Android, FOculusXRHMDModule::GetPluginWrapper().Media_Initialize() needs OVRPlugin to be initialized first, so we should handle that when the world is created
	if (GEngine)
	{
		InitialWorldAddedEventBinding = GEngine->OnWorldAdded().AddRaw(this, &FOculusXRMRModule::OnInitialWorldCreated);
	}
	InitialWorldLoadEventBinding = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FOculusXRMRModule::OnInitialWorldCreated);
#endif // PLATFORM_WINDOWS || PLATFORM_ANDROID
#endif // OCULUS_MR_SUPPORTED_PLATFORMS
}

void FOculusXRMRModule::ShutdownModule()
{
#if OCULUS_MR_SUPPORTED_PLATFORMS
	if (bInitialized)
	{
		if (GEngine)
		{
			GEngine->OnWorldAdded().Remove(WorldAddedEventBinding);
			GEngine->OnWorldDestroyed().Remove(WorldDestroyedEventBinding);
			FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(WorldLoadEventBinding);
#if WITH_EDITOR
			FEditorDelegates::PostPIEStarted.Remove(PieStartedEventBinding);
			FEditorDelegates::PrePIEEnded.Remove(PieEndedEventBinding);
#else
			// Stop casting and close camera with module if it's the game
			MRSettings->SetIsCasting(false);
#endif
		}
#if PLATFORM_ANDROID
		ovrpBool mediaInit = false;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_GetInitialized(&mediaInit)) && mediaInit == ovrpBool_True)
		{
			FOculusXRHMDModule::GetPluginWrapper().Media_Shutdown();
		}
#endif
		FOculusXRHMDModule::GetPluginWrapper().ShutdownMixedReality();

		if (MRSettings->IsRooted())
		{
			MRSettings->RemoveFromRoot();
		}
		if (MRState->IsRooted())
		{
			MRState->RemoveFromRoot();
		}
	}
#if PLATFORM_ANDROID
	if (InitialWorldAddedEventBinding.IsValid() && GEngine)
	{
		GEngine->OnWorldAdded().Remove(InitialWorldAddedEventBinding);
		InitialWorldAddedEventBinding.Reset();
	}
	if (InitialWorldLoadEventBinding.IsValid())
	{
		FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(InitialWorldLoadEventBinding);
		InitialWorldLoadEventBinding.Reset();
	}
#endif
#endif // OCULUS_MR_SUPPORTED_PLATFORMS
}

bool FOculusXRMRModule::IsActive()
{
	bool bReturn = bInitialized && MRSettings && MRSettings->GetIsCasting();
#if PLATFORM_ANDROID
	bReturn = bReturn && bActivated;
#endif
	return bReturn;
}

UOculusXRMR_Settings* FOculusXRMRModule::GetMRSettings()
{
	return MRSettings;
}

UOculusXRMR_State* FOculusXRMRModule::GetMRState()
{
	return MRState;
}

void FOculusXRMRModule::OnWorldCreated(UWorld* NewWorld)
{
#if PLATFORM_WINDOWS
#if WITH_EDITORONLY_DATA
	const bool bIsGameInst = !IsRunningCommandlet() && NewWorld->IsGameWorld();
	if (bIsGameInst)
#endif
	{
		CurrentWorld = NewWorld;
		SetupInGameCapture();
	}
#endif
#if PLATFORM_ANDROID
	CurrentWorld = NewWorld;
	// Check MRC activation state initially when loading world
	ChangeCaptureState();
	// Poll MRC activation state for future changes
	PreWorldTickEventBinding = FWorldDelegates::OnWorldPreActorTick.AddRaw(this, &FOculusXRMRModule::OnWorldTick);
#endif
}

void FOculusXRMRModule::OnWorldDestroyed(UWorld* NewWorld)
{
	CurrentWorld = nullptr;
#if PLATFORM_ANDROID
	if (PreWorldTickEventBinding.IsValid())
	{
		FWorldDelegates::OnWorldPreActorTick.Remove(PreWorldTickEventBinding);
		PreWorldTickEventBinding.Reset();
	}
#endif // PLATFORM_ANDROID
}

void FOculusXRMRModule::InitMixedRealityCapture()
{
	bInitialized = true;

	MRSettings = NewObject<UOculusXRMR_Settings>((UObject*)GetTransientPackage(), FName("OculusXRMR_Settings"), RF_MarkAsRootSet);
	MRState = NewObject<UOculusXRMR_State>((UObject*)GetTransientPackage(), FName("OculusXRMR_State"), RF_MarkAsRootSet);

	// Always bind the event handlers in case devs call them without MRC on
	MRSettings->TrackedCameraIndexChangeDelegate.BindRaw(this, &FOculusXRMRModule::OnTrackedCameraIndexChanged);
	MRSettings->CompositionMethodChangeDelegate.BindRaw(this, &FOculusXRMRModule::OnCompositionMethodChanged);
	MRSettings->IsCastingChangeDelegate.BindRaw(this, &FOculusXRMRModule::OnIsCastingChanged);

	ResetSettingsAndState();

	WorldAddedEventBinding = GEngine->OnWorldAdded().AddRaw(this, &FOculusXRMRModule::OnWorldCreated);
	WorldDestroyedEventBinding = GEngine->OnWorldDestroyed().AddRaw(this, &FOculusXRMRModule::OnWorldDestroyed);
	WorldLoadEventBinding = FCoreUObjectDelegates::PostLoadMapWithWorld.AddRaw(this, &FOculusXRMRModule::OnWorldCreated);

#if WITH_EDITOR
	// Bind events on PIE start/end to open/close camera
	PieBeginEventBinding = FEditorDelegates::BeginPIE.AddRaw(this, &FOculusXRMRModule::OnPieBegin);
	PieStartedEventBinding = FEditorDelegates::PostPIEStarted.AddRaw(this, &FOculusXRMRModule::OnPieStarted);
	PieEndedEventBinding = FEditorDelegates::PrePIEEnded.AddRaw(this, &FOculusXRMRModule::OnPieEnded);
#else  // WITH_EDITOR
	// Start casting and open camera with the module if it's the game
	MRSettings->SetIsCasting(true);
#endif // WITH_EDITOR
}

void FOculusXRMRModule::SetupExternalCamera()
{
	using namespace OculusXRHMD;

	if (!MRSettings->GetIsCasting())
	{
		return;
	}

	// Always request the MRC actor to handle a camera state change on its end
	MRState->ChangeCameraStateRequested = true;
}

void FOculusXRMRModule::SetupInGameCapture()
{
	// Don't do anything if we don't have a UWorld or if we are not casting
	if (CurrentWorld == nullptr || !MRSettings->GetIsCasting())
	{
		return;
	}

	// Set the bind camera request to true
	MRState->BindToTrackedCameraIndexRequested = true;

	// Don't add another actor if there's already a MRC camera actor
	for (TActorIterator<AOculusXRMR_CastingCameraActor> ActorIt(CurrentWorld); ActorIt; ++ActorIt)
	{
		if (IsValidChecked(*ActorIt) && !ActorIt->IsUnreachable() && ActorIt->IsValidLowLevel())
		{
			MRActor = *ActorIt;
			return;
		}
	}

	// Spawn an MRC camera actor if one wasn't already there
	MRActor = CurrentWorld->SpawnActorDeferred<AOculusXRMR_CastingCameraActor>(AOculusXRMR_CastingCameraActor::StaticClass(), FTransform::Identity);
	MRActor->InitializeStates(MRSettings, MRState);
	UGameplayStatics::FinishSpawningActor(MRActor, FTransform::Identity);
}

void FOculusXRMRModule::CloseInGameCapture()
{
	// Destory actor and close the camera when we turn MRC off
	if (MRActor != nullptr && MRActor->GetWorld() != nullptr)
	{
		MRActor->Destroy();
		MRActor = nullptr;
	}
}

void FOculusXRMRModule::ResetSettingsAndState()
{
	// Reset MR State
	MRState->TrackedCamera = FOculusXRTrackedCamera();
	MRState->TrackingReferenceComponent = nullptr;
	MRState->ChangeCameraStateRequested = false;
	MRState->BindToTrackedCameraIndexRequested = false;

	// Reset MR Settings
	const bool bAutoOpenInExternalComposition = FParse::Param(FCommandLine::Get(), TEXT("externalcomposition"));
	MRSettings->BindToTrackedCameraIndexIfAvailable(0);
	MRSettings->LoadFromIni();

	// Save right after load to write defaults to the config if they weren't already there
	MRSettings->SaveToIni();

	if (bAutoOpenInExternalComposition)
	{
		MRSettings->CompositionMethod = EOculusXRMR_CompositionMethod::ExternalComposition;
	}
}

#if PLATFORM_ANDROID
void FOculusXRMRModule::ChangeCaptureState()
{
	ovrpBool activated;
	// Set up or close in-game capture when activation state changes
	if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_Update()) && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_IsMrcActivated(&activated)) && activated == ovrpBool_True)
	{
		if (!bActivated)
		{
			UE_LOG(LogMR, Log, TEXT("Activating MR Capture"))
			bActivated = true;

			// UE resizes the main scene color and depth targets to the maximum dimensions of all rendertargets,
			// which causes rendering issues if it doesn't match the compositor-allocated eye textures. This is
			// a hacky fix by making sure that the scene capture rendertarget is no larger than the eye.
			int frameWidth;
			int frameHeight;
			FOculusXRHMDModule::GetPluginWrapper().Media_GetMrcFrameSize(&frameWidth, &frameHeight);
			uint32 maxWidth = frameWidth / 2;
			uint32 maxHeight = frameHeight;
			IStereoRenderTargetManager* const StereoRenderTargetManager = GEngine->StereoRenderingDevice->GetRenderTargetManager();
			if (StereoRenderTargetManager)
			{
#ifdef WITH_OCULUS_BRANCH
				StereoRenderTargetManager->CalculateRenderTargetSize(maxWidth, maxHeight);
#else  // WITH_OCULUS_BRANCH
				StereoRenderTargetManager->CalculateRenderTargetSize(*(FViewport*)GEngine->GameViewport->GetGameViewport(), maxWidth, maxHeight);
#endif // WITH_OCULUS_BRANCH
			}
			maxWidth *= 2;
			frameWidth = frameWidth > maxWidth ? maxWidth : frameWidth;
			frameHeight = frameHeight > maxHeight ? maxHeight : frameHeight;
			FOculusXRHMDModule::GetPluginWrapper().Media_SetMrcFrameSize(frameWidth, frameHeight);
			UE_LOG(LogMR, Log, TEXT("MRC Frame width: %d height %d"), frameWidth, frameHeight);

			SetupInGameCapture();
		}
	}
	else
	{
		if (bActivated)
		{
			UE_LOG(LogMR, Log, TEXT("Deactivating MR Capture"))
			bActivated = false;
			CloseInGameCapture();
		}
	}
}

void FOculusXRMRModule::OnWorldTick(UWorld* World, ELevelTick Tick, float Delta)
{
	// Poll MRC activation state
	if (CurrentWorld && World == CurrentWorld)
	{
		ChangeCaptureState();
	}
}

void FOculusXRMRModule::OnInitialWorldCreated(UWorld* NewWorld)
{
	// Remove the initial world load handlers
	if (InitialWorldAddedEventBinding.IsValid())
	{
		GEngine->OnWorldAdded().Remove(InitialWorldAddedEventBinding);
		InitialWorldAddedEventBinding.Reset();
	}
	if (InitialWorldLoadEventBinding.IsValid())
	{
		FCoreUObjectDelegates::PostLoadMapWithWorld.Remove(InitialWorldLoadEventBinding);
		InitialWorldLoadEventBinding.Reset();
	}

	// Initialize and check if MRC is enabled
	if (FOculusXRHMDModule::Get().PreInit())
	{
		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().InitializeMixedReality()))
			{
				ovrpBool mrcEnabled;

				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_Initialize()))
				{
					UE_LOG(LogMR, Log, TEXT("MRC Initialized"));

					if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_IsMrcEnabled(&mrcEnabled)) && mrcEnabled == ovrpBool_True)
					{
						UE_LOG(LogMR, Log, TEXT("MRC Enabled"));

						// Find a free queue index for vulkan
						if (RHIGetInterfaceType() == ERHIInterfaceType::Vulkan)
						{
							unsigned int queueIndex = 0;
							ExecuteOnRenderThread([&queueIndex]() {
								ExecuteOnRHIThread([&queueIndex]() {
									const uint32 GraphicsQueueIndex = GetIVulkanDynamicRHI()->RHIGetGraphicsQueueIndex();
									if (GraphicsQueueIndex == queueIndex)
									{
										++queueIndex;
									}
								});
							});
							FOculusXRHMDModule::GetPluginWrapper().Media_SetAvailableQueueIndexVulkan(queueIndex);
						}

						FOculusXRHMDModule::GetPluginWrapper().Media_SetMrcInputVideoBufferType(ovrpMediaInputVideoBufferType_TextureHandle);

						FAudioDeviceHandle AudioDevice = FAudioDevice::GetMainAudioDevice();
						if (AudioDevice.GetAudioDevice())
						{
							float SampleRate = AudioDevice->GetSampleRate();
							FOculusXRHMDModule::GetPluginWrapper().Media_SetMrcAudioSampleRate((int)SampleRate);
						}

						InitMixedRealityCapture();
						OnWorldCreated(NewWorld);
					}
					else
					{
						// Shut down if MRC not enabled or the media couldn't be enabled
						FOculusXRHMDModule::GetPluginWrapper().Media_Shutdown();
						FOculusXRHMDModule::GetPluginWrapper().ShutdownMixedReality();
					}
				}
				else
				{
					// Shut down if MRC not enabled or the media couldn't be enabled
					FOculusXRHMDModule::GetPluginWrapper().ShutdownMixedReality();
				}
			}
			else
			{
				UE_LOG(LogMR, Error, TEXT("ovrp_InitializeMixedReality() failed"));
			}
		}
		else
		{
			UE_LOG(LogMR, Error, TEXT("OVRPlugin has not been initialized"));
		}
	}
}
#endif

void FOculusXRMRModule::OnTrackedCameraIndexChanged(int OldVal, int NewVal)
{
	if (OldVal == NewVal)
	{
		return;
	}
	MRState->BindToTrackedCameraIndexRequested = true;
}

void FOculusXRMRModule::OnCompositionMethodChanged(EOculusXRMR_CompositionMethod OldVal, EOculusXRMR_CompositionMethod NewVal)
{
	if (OldVal == NewVal)
	{
		return;
	}
	SetupExternalCamera();
}

void FOculusXRMRModule::OnIsCastingChanged(bool OldVal, bool NewVal)
{
	if (OldVal == NewVal)
	{
		return;
	}
	if (NewVal == true)
	{
#if PLATFORM_ANDROID
		FOculusXRHMDModule::GetPluginWrapper().Media_SetMrcActivationMode(ovrpMediaMrcActivationMode_Automatic);
#endif
		// Initialize everything again if we turn MRC on
		SetupExternalCamera();
		SetupInGameCapture();
	}
	else
	{
#if PLATFORM_ANDROID
		FOculusXRHMDModule::GetPluginWrapper().Media_SetMrcActivationMode(ovrpMediaMrcActivationMode_Disabled);
#endif
		CloseInGameCapture();
	}
}

void FOculusXRMRModule::OnUseDynamicLightingChanged(bool OldVal, bool NewVal)
{
	if (OldVal == NewVal)
	{
		return;
	}
	SetupExternalCamera();
}

void FOculusXRMRModule::OnDepthQualityChanged(EOculusXRMR_DepthQuality OldVal, EOculusXRMR_DepthQuality NewVal)
{
	if (OldVal == NewVal)
	{
		return;
	}
	SetupExternalCamera();
}

#if WITH_EDITOR
void FOculusXRMRModule::OnPieBegin(bool bIsSimulating)
{
	// Reset all the parameters and start casting when PIE starts but before the game is initialized
	if (!bIsSimulating)
	{

		ResetSettingsAndState();

		// Always start casting with PIE (since this can only be reached if the command line param is on)
		MRSettings->SetIsCasting(true);
	}
}

void FOculusXRMRModule::OnPieStarted(bool bIsSimulating)
{
	// Handle the PIE world as a normal game world
	UWorld* PieWorld = GEditor->GetPIEWorldContext()->World();
	if (!bIsSimulating && PieWorld)
	{
		OnWorldCreated(PieWorld);
	}
}

void FOculusXRMRModule::OnPieEnded(bool bIsSimulating)
{
	UWorld* PieWorld = GEditor->GetPIEWorldContext()->World();
	if (!bIsSimulating && PieWorld)
	{
		// Stop casting when PIE ends
		MRSettings->SetIsCasting(false);
		OnWorldDestroyed(PieWorld);
	}
}
#endif // WITH_EDITOR

IMPLEMENT_MODULE(FOculusXRMRModule, OculusXRMR)

#undef LOCTEXT_NAMESPACE
