// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "IOculusXRAnchorsModule.h"
#include "OculusXRAnchors.h"

#define LOCTEXT_NAMESPACE "OculusAnchors"

//-------------------------------------------------------------------------------------------------
// FOculusXRAnchorsModule
//-------------------------------------------------------------------------------------------------

#if OCULUS_ANCHORS_SUPPORTED_PLATFORMS

DECLARE_LOG_CATEGORY_EXTERN(LogOculusXRAnchors, Log, All);

class FOculusXRAnchorsModule : public IOculusXRAnchorsModule
{
public:
	virtual ~FOculusXRAnchorsModule() = default;

	// IModuleInterface interface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static OculusXRAnchors::FOculusXRAnchors* GetOculusAnchors();

private:
	OculusXRAnchors::FOculusXRAnchors Anchors;
};

#else // OCULUS_ANCHORS_SUPPORTED_PLATFORMS

class FOculusXRAnchorsModule : public FDefaultModuleImpl
{
};

#endif // OCULUS_ANCHORS_SUPPORTED_PLATFORMS

#undef LOCTEXT_NAMESPACE
