// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRAnchorsModule.h"

#if OCULUS_ANCHORS_SUPPORTED_PLATFORMS
#include "OculusXRHMDModule.h"
#include "OculusXRHMD.h"
#include "OculusXRAnchors.h"
#include "OculusXRAnchorManager.h"
#include "OculusXRRoomLayoutManager.h"

DEFINE_LOG_CATEGORY(LogOculusXRAnchors);

#define LOCTEXT_NAMESPACE "OculusXRAnchors"

//-------------------------------------------------------------------------------------------------
// FOculusXRAnchorsModule
//-------------------------------------------------------------------------------------------------
void FOculusXRAnchorsModule::StartupModule()
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
		UE_LOG(LogOculusXRAnchors, Warning, TEXT("Unable to retrieve OculusXRHMD, cannot add event polling delegates."));
		return;
	}

	HMD->AddEventPollingDelegate(OculusXRHMD::FOculusXRHMDEventPollingDelegate::CreateStatic(&OculusXRAnchors::FOculusXRAnchorManager::OnPollEvent));
	HMD->AddEventPollingDelegate(OculusXRHMD::FOculusXRHMDEventPollingDelegate::CreateStatic(&OculusXRAnchors::FOculusXRRoomLayoutManager::OnPollEvent));

	Anchors.Initialize();
}

void FOculusXRAnchorsModule::ShutdownModule()
{
	Anchors.Teardown();
}

OculusXRAnchors::FOculusXRAnchors* FOculusXRAnchorsModule::GetOculusAnchors()
{
	FOculusXRAnchorsModule& Module = FModuleManager::LoadModuleChecked<FOculusXRAnchorsModule>(TEXT("OculusXRAnchors"));
	return &Module.Anchors;
}

#endif // OCULUS_ANCHORS_SUPPORTED_PLATFORMS

IMPLEMENT_MODULE(FOculusXRAnchorsModule, OculusXRAnchors)

#undef LOCTEXT_NAMESPACE
