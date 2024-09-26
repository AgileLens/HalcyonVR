// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRMR_Settings.h"
#include "OculusXRMRPrivate.h"
#include "OculusXRHMD.h"
#include "Engine/Engine.h"

UOculusXRMR_Settings::UOculusXRMR_Settings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ClippingReference(EOculusXRMR_ClippingReference::CR_Head)
	, bUseTrackedCameraResolution(true)
	, WidthPerView(960)
	, HeightPerView(540)
	, CastingLatency(0.0f)
	, BackdropColor(FColor::Green)
	, ExternalCompositionPostProcessEffects(EOculusXRMR_PostProcessEffects::PPE_Off)
	, bIsCasting(false)
	, CompositionMethod(EOculusXRMR_CompositionMethod::ExternalComposition)
	, BindToTrackedCameraIndex(-1)
{
}

void UOculusXRMR_Settings::SetCompositionMethod(EOculusXRMR_CompositionMethod val)
{
	if (CompositionMethod == val)
	{
		return;
	}
	auto old = CompositionMethod;
	CompositionMethod = val;
	CompositionMethodChangeDelegate.Execute(old, val);
}

void UOculusXRMR_Settings::SetCapturingCamera(EOculusXRMR_CameraDeviceEnum val)
{
	// deprecated
}

void UOculusXRMR_Settings::SetIsCasting(bool val)
{
	if (bIsCasting == val)
	{
		return;
	}
	auto old = bIsCasting;
	bIsCasting = val;
	IsCastingChangeDelegate.Execute(old, val);
}

void UOculusXRMR_Settings::BindToTrackedCameraIndexIfAvailable(int InTrackedCameraIndex)
{
	if (BindToTrackedCameraIndex == InTrackedCameraIndex)
	{
		return;
	}
	auto old = BindToTrackedCameraIndex;
	BindToTrackedCameraIndex = InTrackedCameraIndex;
	TrackedCameraIndexChangeDelegate.Execute(old, InTrackedCameraIndex);
}

void UOculusXRMR_Settings::LoadFromIni()
{
	if (!GConfig)
	{
		UE_LOG(LogMR, Warning, TEXT("GConfig is NULL"));
		return;
	}

	// Flushing the GEngineIni is necessary to get the settings reloaded at the runtime, but the manual flushing
	// could cause an assert when loading audio settings if launching through editor at the 2nd time. Disabled temporarily.
	// GConfig->Flush(true, GEngineIni);

	const TCHAR* OculusXRMRSettings = TEXT("Oculus.Settings.MixedReality");
	bool v;
	float f;
	int32 i;
	FVector vec;
	FColor color;
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("CompositionMethod"), i, GEngineIni))
	{
		SetCompositionMethod((EOculusXRMR_CompositionMethod)i);
	}
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("ClippingReference"), i, GEngineIni))
	{
		ClippingReference = (EOculusXRMR_ClippingReference)i;
	}
	if (GConfig->GetBool(OculusXRMRSettings, TEXT("bUseTrackedCameraResolution"), v, GEngineIni))
	{
		bUseTrackedCameraResolution = v;
	}
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("WidthPerView"), i, GEngineIni))
	{
		WidthPerView = i;
	}
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("HeightPerView"), i, GEngineIni))
	{
		HeightPerView = i;
	}
	if (GConfig->GetFloat(OculusXRMRSettings, TEXT("CastingLatency"), f, GEngineIni))
	{
		CastingLatency = f;
	}
	if (GConfig->GetColor(OculusXRMRSettings, TEXT("BackdropColor"), color, GEngineIni))
	{
		BackdropColor = color;
	}
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("BindToTrackedCameraIndex"), i, GEngineIni))
	{
		BindToTrackedCameraIndexIfAvailable(i);
	}
	if (GConfig->GetInt(OculusXRMRSettings, TEXT("ExternalCompositionPostProcessEffects"), i, GEngineIni))
	{
		ExternalCompositionPostProcessEffects = (EOculusXRMR_PostProcessEffects)i;
	}

	UE_LOG(LogMR, Log, TEXT("MixedReality settings loaded from Engine.ini"));
}

void UOculusXRMR_Settings::SaveToIni() const
{
	if (!GConfig)
	{
		UE_LOG(LogMR, Warning, TEXT("GConfig is NULL"));
		return;
	}

	const TCHAR* OculusXRMRSettings = TEXT("Oculus.Settings.MixedReality");
	GConfig->SetInt(OculusXRMRSettings, TEXT("CompositionMethod"), (int32)CompositionMethod, GEngineIni);
	GConfig->SetInt(OculusXRMRSettings, TEXT("ClippingReference"), (int32)ClippingReference, GEngineIni);
	GConfig->SetBool(OculusXRMRSettings, TEXT("bUseTrackedCameraResolution"), bUseTrackedCameraResolution, GEngineIni);
	GConfig->SetInt(OculusXRMRSettings, TEXT("WidthPerView"), WidthPerView, GEngineIni);
	GConfig->SetInt(OculusXRMRSettings, TEXT("HeightPerView"), HeightPerView, GEngineIni);
	GConfig->SetFloat(OculusXRMRSettings, TEXT("CastingLatency"), CastingLatency, GEngineIni);
	GConfig->SetColor(OculusXRMRSettings, TEXT("BackdropColor"), BackdropColor, GEngineIni);
	GConfig->SetInt(OculusXRMRSettings, TEXT("BindToTrackedCameraIndex"), (int32)BindToTrackedCameraIndex, GEngineIni);
	GConfig->SetInt(OculusXRMRSettings, TEXT("ExternalCompositionPostProcessEffects"), (int32)ExternalCompositionPostProcessEffects, GEngineIni);

	GConfig->Flush(false, GEngineIni);

	UE_LOG(LogMR, Log, TEXT("MixedReality settings saved to Engine.ini"));
}
