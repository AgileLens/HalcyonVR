// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughModule.h"

#include "OculusXRHMD.h"
#include "OculusXRPassthroughEventHandling.h"
#include "Misc/CoreDelegates.h"

DEFINE_LOG_CATEGORY(LogOculusXRPassthrough);

#define LOCTEXT_NAMESPACE "OculusXRPassthrough"

//-------------------------------------------------------------------------------------------------
// FOculusXRPassthroughModule
//-------------------------------------------------------------------------------------------------

FOculusXRPassthroughModule::FOculusXRPassthroughModule()
{
}

void FOculusXRPassthroughModule::StartupModule()
{
	PassthroughXR = MakeShareable(new XRPassthrough::FPassthroughXR());
	PassthroughXR->RegisterAsOpenXRExtension();

	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FOculusXRPassthroughModule::OnPostEngineInit);
}

void FOculusXRPassthroughModule::ShutdownModule()
{
}

void FOculusXRPassthroughModule::OnPostEngineInit()
{
	if (IsRunningCommandlet())
	{
		return;
	}

	if (!GEngine)
	{
		UE_LOG(LogOculusXRPassthrough, Warning, TEXT("No GEngine, cannot add event polling delegate."));
		return;
	}

	OculusXRHMD::FOculusXRHMD* HMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (!HMD)
	{
		FName XRSystemName = GEngine->XRSystem ? GEngine->XRSystem->GetSystemName() : "None";
		UE_LOG(LogOculusXRPassthrough, Warning, TEXT("Unable to retrieve OculusXRHMD, cannot add event polling delegate. (current xrsystem : %s)"), *XRSystemName.ToString());
		return;
	}

	HMD->AddEventPollingDelegate(OculusXRHMD::FOculusXRHMDEventPollingDelegate::CreateStatic(&OculusXRPassthrough::FOculusXRPassthroughEventHandling::OnPollEvent));
}

IMPLEMENT_MODULE(FOculusXRPassthroughModule, OculusXRPassthrough)

#undef LOCTEXT_NAMESPACE
