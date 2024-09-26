// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "HAL/IConsoleManager.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FConsoleCommands
	//-------------------------------------------------------------------------------------------------

	class FConsoleCommands : private FSelfRegisteringExec
	{
	public:
		FConsoleCommands(class FOculusXRHMD* InHMDPtr);

		// FSelfRegisteringExec interface
		virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	private:
		FAutoConsoleCommand UpdateOnRenderThreadCommand;
		FAutoConsoleCommand PixelDensityMinCommand;
		FAutoConsoleCommand PixelDensityMaxCommand;
		FAutoConsoleCommand HQBufferCommand;
		FAutoConsoleCommand HQDistortionCommand;
		FAutoConsoleCommand ShowGlobalMenuCommand;
		FAutoConsoleCommand ShowQuitMenuCommand;

#if !UE_BUILD_SHIPPING
		// Debug console commands
		FAutoConsoleCommand StatsCommand;
		FAutoConsoleCommand CubemapCommand;
		FAutoConsoleCommand ShowSettingsCommand;
		FAutoConsoleCommand IPDCommand;
#endif // !UE_BUILD_SHIPPING
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
