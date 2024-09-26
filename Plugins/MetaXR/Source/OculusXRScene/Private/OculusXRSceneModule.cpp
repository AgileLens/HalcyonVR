// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRSceneModule.h"

#if OCULUS_SCENE_SUPPORTED_PLATFORMS
#include "OculusXRHMDModule.h"

#include "OculusXRHMD.h"
#include "OculusXRSceneEventHandling.h"

DEFINE_LOG_CATEGORY(LogOculusXRScene);

#define LOCTEXT_NAMESPACE "OculusXRScene"

//-------------------------------------------------------------------------------------------------
// FOculusXRSceneModule
//-------------------------------------------------------------------------------------------------
void FOculusXRSceneModule::StartupModule()
{
	if (IsRunningCommandlet())
	{
		return;
	}

	if (!GEngine)
	{
		return;
	}

	OculusXRHMD::FOculusXRHMD* HMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (!HMD)
	{
		UE_LOG(LogOculusXRScene, Warning, TEXT("Unable to retrieve OculusXRHMD, cannot add event polling delegates."));
		return;
	}

	HMD->AddEventPollingDelegate(OculusXRHMD::FOculusXRHMDEventPollingDelegate::CreateStatic(&OculusXRScene::FOculusXRSceneEventHandling::OnPollEvent));
}

void FOculusXRSceneModule::ShutdownModule()
{
}

#endif // OCULUS_SCENE_SUPPORTED_PLATFORMS

IMPLEMENT_MODULE(FOculusXRSceneModule, OculusXRScene)

#undef LOCTEXT_NAMESPACE
