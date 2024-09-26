// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRPlatformToolSettings.h"

UOculusXRPlatformToolSettings::UOculusXRPlatformToolSettings()
	: OculusTargetPlatform(EOculusXRPlatformTarget::Rift)
{
	uint8 NumPlatforms = (uint8)EOculusXRPlatformTarget::Length;
	OculusApplicationID.Init("", NumPlatforms);
	OculusApplicationToken.Init("", NumPlatforms);
	OculusReleaseChannel.Init("Alpha", NumPlatforms);
	OculusReleaseNote.Init("", NumPlatforms);
	OculusLaunchFilePath.Init("", NumPlatforms);
	OculusSymbolDirPath.Init("", NumPlatforms);
	OculusLanguagePacksPath.Init("", NumPlatforms);
	OculusExpansionFilesPath.Init("", NumPlatforms);
	OculusAssetConfigs.Init(FOculusXRAssetConfigArray(), NumPlatforms);
	UploadDebugSymbols = true;

	for (int i = 0; i < NumPlatforms; i++)
	{
		OculusAssetConfigs[i].ConfigArray = TArray<FOculusXRAssetConfig>();
	}
}
