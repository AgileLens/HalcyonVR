// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OculusXRPlatformToolSettings.generated.h"

UENUM()
enum class EOculusXRPlatformTarget : uint8
{
	Rift UMETA(DisplayName = "Rift"),
	Quest UMETA(DisplayName = "Quest"),
	Length UMETA(DisplayName = "Invalid")
};

UENUM()
enum class EOculusXRGamepadEmulation : uint8
{
	Off UMETA(DisplayName = "Off"),
	Twinstick UMETA(DisplayName = "Twinstick"),
	RightDPad UMETA(DisplayName = "Right D Pad"),
	LeftDPad UMETA(DisplayName = "Left D Pad"),
	Length UMETA(DisplayName = "Invalid")
};

UENUM()
enum class EOculusXRAssetType : uint8
{
	Default UMETA(DisplayName = "Default"),
	Store UMETA(DisplayName = "Store"),
	Language_Pack UMETA(DisplayName = "Language Pack"),
	Length UMETA(DisplayName = "Invlaid"),
};

USTRUCT()
struct FOculusXRRedistPackage
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool Included = false;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString Name;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString Id;
};

USTRUCT()
struct FOculusXRAssetConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	EOculusXRAssetType AssetType = EOculusXRAssetType::Default;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool Required = false;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString Name;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString Sku;
};

USTRUCT()
struct FOculusXRAssetConfigArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FOculusXRAssetConfig> ConfigArray;
};

/**
 *
 */
UCLASS(config = Editor)
class OCULUSXREDITOR_API UOculusXRPlatformToolSettings : public UObject
{
	GENERATED_BODY()

public:
	UOculusXRPlatformToolSettings();

	uint8 GetTargetPlatform()
	{
		return (uint8)OculusTargetPlatform;
	}
	void SetTargetPlatform(uint8 i)
	{
		OculusTargetPlatform = (EOculusXRPlatformTarget)i;
	}

	FString GetApplicationID()
	{
		return (uint8)OculusTargetPlatform < OculusApplicationID.Num() ? OculusApplicationID[(uint8)OculusTargetPlatform] : "";
	}
	void SetApplicationID(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusApplicationID[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetApplicationToken()
	{
		return (uint8)OculusTargetPlatform < OculusApplicationToken.Num() ? OculusApplicationToken[(uint8)OculusTargetPlatform] : "";
	}
	void SetApplicationToken(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusApplicationToken[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetReleaseChannel()
	{
		return (uint8)OculusTargetPlatform < OculusReleaseChannel.Num() ? OculusReleaseChannel[(uint8)OculusTargetPlatform] : "Alpha";
	}
	void SetReleaseChannel(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusReleaseChannel[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetReleaseNote()
	{
		return (uint8)OculusTargetPlatform < OculusReleaseNote.Num() ? OculusReleaseNote[(uint8)OculusTargetPlatform] : "";
	}
	void SetReleaseNote(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusReleaseNote[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetLaunchFilePath()
	{
		return (uint8)OculusTargetPlatform < OculusLaunchFilePath.Num() ? OculusLaunchFilePath[(uint8)OculusTargetPlatform] : "";
	}
	void SetLaunchFilePath(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusLaunchFilePath[(uint8)OculusTargetPlatform] = s;
		}
	}

	EOculusXRGamepadEmulation GetRiftGamepadEmulation()
	{
		return OculusRiftGamepadEmulation;
	}
	void SetRiftGamepadEmulation(uint8 i)
	{
		OculusRiftGamepadEmulation = (EOculusXRGamepadEmulation)i;
	}

	FString GetLanguagePacksPath()
	{
		return (uint8)OculusTargetPlatform < OculusLanguagePacksPath.Num() ? OculusLanguagePacksPath[(uint8)OculusTargetPlatform] : "";
	}
	void SetLanguagePacksPath(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusLanguagePacksPath[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetExpansionFilesPath()
	{
		return (uint8)OculusTargetPlatform < OculusExpansionFilesPath.Num() ? OculusExpansionFilesPath[(uint8)OculusTargetPlatform] : "";
	}
	void SetExpansionFilesPath(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusExpansionFilesPath[(uint8)OculusTargetPlatform] = s;
		}
	}

	FString GetSymbolDirPath()
	{
		return (uint8)OculusTargetPlatform < OculusSymbolDirPath.Num() ? OculusSymbolDirPath[(uint8)OculusTargetPlatform] : "";
	}
	void SetSymbolDirPath(FString s)
	{
		if (OculusTargetPlatform < EOculusXRPlatformTarget::Length)
		{
			OculusSymbolDirPath[(uint8)OculusTargetPlatform] = s;
		}
	}

	TArray<FOculusXRAssetConfig>* GetAssetConfigs()
	{
		return (uint8)OculusTargetPlatform < OculusAssetConfigs.Num() ? &OculusAssetConfigs[(uint8)OculusTargetPlatform].ConfigArray : nullptr;
	}

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString OculusRiftBuildDirectory;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString OculusRiftBuildVersion;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString OculusRiftLaunchParams;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool OculusRiftFireWallException;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString OculusRift2DLaunchPath;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString OculusRift2DLaunchParams;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FOculusXRRedistPackage> OculusRedistPackages;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool UploadDebugSymbols;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool DebugSymbolsOnly;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	FString BuildID;

private:
	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	EOculusXRPlatformTarget OculusTargetPlatform;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusApplicationID;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusApplicationToken;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusReleaseChannel;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusReleaseNote;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusLaunchFilePath;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	EOculusXRGamepadEmulation OculusRiftGamepadEmulation;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusLanguagePacksPath;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusExpansionFilesPath;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FString> OculusSymbolDirPath;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TArray<FOculusXRAssetConfigArray> OculusAssetConfigs;
};
