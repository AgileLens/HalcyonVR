// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#if PLATFORM_WINDOWS
DEFINE_LOG_CATEGORY_STATIC(LogMetaXRSES, Log, All);

struct FProcHandle;

/**  */
class FMetaXRSES
{
public:
	static void LaunchEnvironment(FString EnvironmentName);
	static void LaunchMoreRoomsEnvironment(FString EnvironmentName);
	static void LaunchEnvironment(FString EnvironmentName, FString SESPath);
	static void StopServer();

private:
	static void LaunchLocalSharingServer();
	static bool LaunchProcess(FString BinaryPath, FString Arguments, FString LogContext, FProcHandle& OutProcHandle);
	static void StopProcess(FProcHandle& ProcHandle, FString LogContext);

	static FString GetMetaXRSimPackagePath();
	static FString GetSynthEnvServerPath();
	static FString GetSynthEnvServerMoreRoomsPath();
	static FString GetLocalSharingServerPath();

	static FProcHandle EnvProcHandle;
	static FProcHandle LSSProcHandle;
};
#endif
