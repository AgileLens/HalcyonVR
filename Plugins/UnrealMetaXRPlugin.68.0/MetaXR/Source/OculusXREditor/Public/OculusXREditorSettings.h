// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OculusXREditorSettings.generated.h"

UENUM()
enum class EOculusXRPlatform : uint8
{
	PC UMETA(DisplayName = "PC"),
	Mobile UMETA(DisplayName = "Mobile"),
	Length UMETA(DisplayName = "Invalid")
};

/**
 *
 */
UCLASS(config = Editor)
class OCULUSXREDITOR_API UOculusXREditorSettings : public UObject
{
	GENERATED_BODY()

public:
	UOculusXREditorSettings();

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	TMap<FName, bool> PerfToolIgnoreList;

	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	EOculusXRPlatform PerfToolTargetPlatform;

	UPROPERTY(globalconfig, EditAnywhere, Category = MetaXR)
	bool bAddMenuOption;
};
