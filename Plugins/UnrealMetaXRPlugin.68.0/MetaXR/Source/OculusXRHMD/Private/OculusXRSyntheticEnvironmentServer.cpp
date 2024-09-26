// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRSyntheticEnvironmentServer.h"
#if PLATFORM_WINDOWS
#include "HAL/FileManager.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRTelemetryEvents.h"
#include "Misc/MessageDialog.h"

#include "Windows/WindowsPlatformMisc.h"

const FString SynthEnvServer = "Synthetic Environment Server";
const FString LocalSharingServer = "Local Sharing Server";

FProcHandle FMetaXRSES::EnvProcHandle;
FProcHandle FMetaXRSES::LSSProcHandle;

void FMetaXRSES::StopServer()
{
	StopProcess(EnvProcHandle, SynthEnvServer);
	StopProcess(LSSProcHandle, LocalSharingServer);
}

void FMetaXRSES::LaunchEnvironment(FString EnvironmentName)
{
	FString SESPath = GetSynthEnvServerPath();
	LaunchEnvironment(EnvironmentName, SESPath);
}

void FMetaXRSES::LaunchMoreRoomsEnvironment(FString EnvironmentName)
{
	FString SESPath = GetSynthEnvServerPath();
	LaunchEnvironment(EnvironmentName, FMetaXRSES::GetSynthEnvServerMoreRoomsPath());
}

void FMetaXRSES::LaunchEnvironment(FString EnvironmentName, FString SESPath)
{
	if (GetMetaXRSimPackagePath().IsEmpty())
	{
		return;
	}
	StopServer();

	OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FSimulator> Event;
	const bool bLaunched = LaunchProcess(SESPath, EnvironmentName, LocalSharingServer, EnvProcHandle);
	const auto& _ = Event.SetResult(bLaunched ? OculusXRTelemetry::EAction::Success : OculusXRTelemetry::EAction::Fail).AddAnnotation("launch", StringCast<ANSICHAR>(*EnvironmentName).Get());

	LaunchLocalSharingServer();
}

void FMetaXRSES::LaunchLocalSharingServer()
{
	OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FSimulator> Event;
	FString LSSPath = GetLocalSharingServerPath();
	const bool bLaunched = LaunchProcess(LSSPath, "", LocalSharingServer, LSSProcHandle);
	const auto& _ = Event.SetResult(bLaunched ? OculusXRTelemetry::EAction::Success : OculusXRTelemetry::EAction::Fail).AddAnnotation("launch", "localsharingserver");
}

bool FMetaXRSES::LaunchProcess(FString BinaryPath, FString Arguments, FString LogContext, FProcHandle& OutProcHandle)
{
	if (!IFileManager::Get().FileExists(*BinaryPath))
	{
		UE_LOG(LogMetaXRSES, Error, TEXT("Failed to find %s."), *BinaryPath);
		return false;
	}
	UE_LOG(LogMetaXRSES, Log, TEXT("Launching %s."), *BinaryPath);

	uint32 OutProcessId = 0;
	OutProcHandle = FPlatformProcess::CreateProc(*BinaryPath, *Arguments, false, false, false, &OutProcessId, 0, NULL, NULL);
	if (!OutProcHandle.IsValid())
	{
		UE_LOG(LogMetaXRSES, Error, TEXT("Failed to launch %s."), *BinaryPath);
		FPlatformProcess::CloseProc(OutProcHandle);
		return false;
	}

	UE_LOG(LogMetaXRSES, Log, TEXT("Launched %s."), *BinaryPath);
	return true;
}

void FMetaXRSES::StopProcess(FProcHandle& ProcHandle, FString LogContext)
{
	if (ProcHandle.IsValid())
	{
		if (FPlatformProcess::IsProcRunning(ProcHandle))
		{
			UE_LOG(LogMetaXRSES, Log, TEXT("Stopping %s."), *LogContext);
			FPlatformProcess::TerminateProc(ProcHandle);
		}
		FPlatformProcess::CloseProc(ProcHandle);
	}
	else
	{
		UE_LOG(LogMetaXRSES, Warning, TEXT("Failed to stop process %s because it is not active anymore."), *LogContext);
	}
}

FString FMetaXRSES::GetMetaXRSimPackagePath()
{
	FString JsonPath = GetMutableDefault<UOculusXRHMDRuntimeSettings>()->MetaXRJsonPath.FilePath;
	if (JsonPath.IsEmpty() || !IFileManager::Get().FileExists(*JsonPath))
	{
		FString Message("Meta XR Simulator Not Found.\nPlease set its path in Project Settings/Meta XR Plugin/PC.");
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(Message));
		UE_LOG(LogMetaXRSES, Error, TEXT("%s"), *Message);
	}
	return FPaths::GetPath(JsonPath);
}

FString FMetaXRSES::GetSynthEnvServerPath()
{
	return GetMetaXRSimPackagePath() + "/.synth_env_server/synth_env_server.exe";
}

FString FMetaXRSES::GetSynthEnvServerMoreRoomsPath()
{
	return GetMetaXRSimPackagePath() + "/ses_rooms~/synth_env_server_extra_rooms.exe";
}

FString FMetaXRSES::GetLocalSharingServerPath()
{
	return GetMetaXRSimPackagePath() + "/.local_sharing_server/local_sharing_server.exe";
}
#endif
