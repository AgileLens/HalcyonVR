// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMultiPlayerTestingSubsystem.h"

#include "IHeadMountedDisplay.h"
#include "IXRTrackingSystem.h"
#include "Widgets/SViewport.h"
#include "Slate/SceneViewport.h"

#include "IOculusXRHMDModule.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRHMD.h"

#if WITH_EDITOR
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#include "Settings/LevelEditorPlaySettings.h"
#endif

#if PLATFORM_WINDOWS
#include "Windows/WindowsPlatformProcess.h"
#include <TlHelp32.h>
#endif

/**
 * Initialize the subsystem. USubsystem override
 */
void UOculusXRMultiPlayerTestingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

/**
 * De-initializes the subsystem. USubsystem override
 */
void UOculusXRMultiPlayerTestingSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

ETickableTickType UOculusXRMultiPlayerTestingSubsystem::GetTickableTickType() const
{
	return IsMultiPlayerTestingSupported() ? ETickableTickType::Always : ETickableTickType::Never;
}

bool UOculusXRMultiPlayerTestingSubsystem::IsAllowedToTick() const
{
	return IsMultiPlayerTestingSupported();
}

void UOculusXRMultiPlayerTestingSubsystem::Tick(float)
{
#if PLATFORM_WINDOWS && WITH_EDITOR
	bool bSingleProcessMode = true;
	if (!IsMultiPlayerTestingEnabled(bSingleProcessMode))
	{
		return;
	}

	if (GEngine)
	{
		const ULevelEditorPlaySettings* PlayInSettings = GetDefault<ULevelEditorPlaySettings>();
		bool RunUnderOneProcess = true;
		PlayInSettings->GetRunUnderOneProcess(RunUnderOneProcess);
		if (GetMutableDefault<UOculusXRHMDRuntimeSettings>()->bSetActivePIEToPrimary && RunUnderOneProcess)
		{
			SwitchPrimaryPIE_SingleProcess();
		}
	}
#endif
}

bool UOculusXRMultiPlayerTestingSubsystem::IsMultiPlayerTestingSupported() const
{
#if PLATFORM_WINDOWS && WITH_EDITOR
	return true;
#else
	return false;
#endif
}

#if PLATFORM_WINDOWS
bool UOculusXRMultiPlayerTestingSubsystem::IsMultiPlayerTestingEnabled(bool& bSingleProcessMode)
{
	bSingleProcessMode = false;
	NumClients = 1;
	// ULevelEditorPlaySettings of 2nd+ player of MultipleProcess mode does NOT have correct GetRunUnderOneProcess() data.
	//  Let's use InInstanceNum to figure out how many clients are enabled already.
	int InInstanceNum = 0;
	FParse::Value(FCommandLine::Get(), TEXT("InInstanceNum="), InInstanceNum);
	if (InInstanceNum)
	{
		bSingleProcessMode = false;
		NumClients = InInstanceNum + 1;
	}
#if WITH_EDITOR
	else
	{
		// SingleProcess mode OR 1st player of MultipleProcess mode are kicked off from editor
		const ULevelEditorPlaySettings* PlayInSettings = GetDefault<ULevelEditorPlaySettings>();
		if (PlayInSettings)
		{
			PlayInSettings->GetPlayNumberOfClients(NumClients);
			PlayInSettings->GetRunUnderOneProcess(bSingleProcessMode);
		}
	}
#endif // WITH_EDITOR

	return (NumClients > 1 && OculusXRHMD::FOculusXRHMD::GetOculusXRHMD() && OculusXRHMD::FOculusXRHMD::GetOculusXRHMD()->IsStereoEnabled());
}

static void SwitchPrimaryPIE(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
{
	if (!GEngine || !GEngine->XRSystem.IsValid())
	{
		Ar.Logf(TEXT("XRSystem must be valid to switch PrimaryPIE!"));
		return;
	}

	if (!GetMutableDefault<UOculusXRHMDRuntimeSettings>()->bSetCVarPIEToPrimary)
	{
		Ar.Logf(TEXT("Please enable \"Set CVar PIE To Primary\" in MetaXRPlugin settings!"));
		return;
	}

	if (Args.Num())
	{
		if (UOculusXRMultiPlayerTestingSubsystem* MPTSSubsystem = GEngine ? GEngine->GetEngineSubsystem<UOculusXRMultiPlayerTestingSubsystem>() : nullptr)
		{
			MPTSSubsystem->SwitchPrimaryPIE(nullptr, FCString::Atoi(*Args[0]));
		}
	}
	else
	{
		Ar.Logf(TEXT("Invalid PrimaryPIEIndex!"));
	}
}

const int DefaultNextProcIndex = -1;
static FAutoConsoleCommand CSwitchHMDCmd(
	TEXT("vr.PrimaryPIEIndex"),
	TEXT("Set primary PIE index on the fly. Setting it to -1 is to set the index to next PIE window. If RunUnderOneProcess is enabled, this index can be set to any PIE index."),
	FConsoleCommandWithWorldArgsAndOutputDeviceDelegate::CreateStatic(SwitchPrimaryPIE));

void UOculusXRMultiPlayerTestingSubsystem::SwitchPrimaryPIE(UGameViewportClient* InViewport, TOptional<int> PrimaryPIEIndex)
{
	bool bSingleProcessMode = true;
	if (!IsMultiPlayerTestingEnabled(bSingleProcessMode))
	{
		return;
	}

	if (!bSingleProcessMode)
	{
		check(PrimaryPIEIndex.IsSet());
		SwitchPrimaryPIE_MultiProcess(PrimaryPIEIndex.GetValue());
	}
#if WITH_EDITOR
	else
	{
		SwitchPrimaryPIE_SingleProcess(InViewport, PrimaryPIEIndex);
	}
#endif
}

void UOculusXRMultiPlayerTestingSubsystem::GetUnrealEditorProcs(TArray<int32>& ProcIds)
{
	FString ProcNameWithExtension = "UnrealEditor.exe";
	HANDLE SnapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (SnapShot != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 Entry;
		Entry.dwSize = sizeof(PROCESSENTRY32);

		const int ProjectNameMaxLength = 512;
		if (::Process32First(SnapShot, &Entry))
		{
			do
			{
				// find unreal editor processes
				if (FCString::Stricmp(*ProcNameWithExtension, Entry.szExeFile) == 0)
				{
					int32 ProcID = Entry.th32ProcessID;
					HWND HWnd = FWindowsPlatformMisc::GetTopLevelWindowHandle(ProcID);
					if (HWnd)
					{
						const TCHAR* ProjectName = FApp::GetProjectName();
						WCHAR Buffer[ProjectNameMaxLength];
						GetWindowText(HWnd, Buffer, ProjectNameMaxLength);
						size_t ProjectNameLen = _tcslen(ProjectName);
						if (_tcsnccmp(ProjectName, Buffer, ProjectNameLen) == 0)
						{
							ProcIds.Add(ProcID);
						}
					}
				}
			}
			while (::Process32Next(SnapShot, &Entry));
		}
		::CloseHandle(SnapShot);
	}
	ProcIds.Sort(TLess<int32>());
}

// Activate PIE window across processes.
void UOculusXRMultiPlayerTestingSubsystem::SwitchPrimaryPIE_MultiProcess(int PrimaryPIEIndex)
{
	uint32 CurProcId = FPlatformProcess::GetCurrentProcessId();
	uint32 DestProcId = -1;
	TArray<int32> ProcIds;
	GetUnrealEditorProcs(ProcIds);
	// For now, PrimaryPIEIndex must be -1 which means we always switch to next player.
	// The reason is users don't know each process' index and cannot easily set it via vr.PrimaryPIEIndex even if we sort processIDs first.
	if (PrimaryPIEIndex == DefaultNextProcIndex)
	{ // find next process's Id
		int32 CurProcIdx = ProcIds.Find(CurProcId);
		check(CurProcIdx != INDEX_NONE);
		int32 NextProcIdx = (CurProcIdx + 1) % ProcIds.Num();
		DestProcId = ProcIds[NextProcIdx];
	}
	else
	{
		UE_LOG(LogHMD, Warning, TEXT("vr.PrimaryPIEIndex must be -1 if RunUnderOneProcess is not set."));
		return;
	}

	if (DestProcId == -1)
	{
		UE_LOG(LogHMD, Warning, TEXT("Cannot find vr.PrimaryPIEIndex: %d"), PrimaryPIEIndex);
		return;
	}
	else
	{
		UE_LOG(LogHMD, Log, TEXT("SwitchPrimaryPIE from ProcID: %d to: %d"), CurProcId, DestProcId);
		HWND MainWindowHandle = FWindowsPlatformMisc::GetTopLevelWindowHandle(DestProcId);
		::SwitchToThisWindow(MainWindowHandle, true);
	}
}

#if WITH_EDITOR
void UOculusXRMultiPlayerTestingSubsystem::SwitchPrimaryPIE_SingleProcess(UGameViewportClient* InViewport, TOptional<int> PrimaryPIEIndex)
{
	if (InViewport && PrimaryPIEIndex.IsSet())
	{
		UE_LOG(LogHMD, Warning, TEXT("InViewport and PrimaryPIEIndex should not be set at the same time."));
		return;
	}

	if (!GEditor)
	{
		UE_LOG(LogHMD, Warning, TEXT("SwitchPrimaryPIE_SingleProcess is only supported in editor."));
		return;
	}

	if (PrimaryPIEIndex == DefaultNextProcIndex)
	{ // Activate the world next to the current primary one
		for (const FWorldContext& WorldContext : GEditor->GetWorldContexts())
		{
			if (WorldContext.bIsPrimaryPIEInstance)
			{
				PrimaryPIEIndex = (WorldContext.PIEInstance + 1) % NumClients;
			}
		}
	}

	FWorldContext* OldPrimaryWorld = nullptr;
	FWorldContext* NewPrimaryWorld = nullptr;
	for (const FWorldContext& WorldContext : GEditor->GetWorldContexts())
	{
		if (WorldContext.bIsPrimaryPIEInstance)
		{
			OldPrimaryWorld = GEditor->GetWorldContextFromWorld(WorldContext.World());
		}
		else if (WorldContext.GameViewport == InViewport || (PrimaryPIEIndex.IsSet() && WorldContext.PIEInstance == PrimaryPIEIndex.GetValue()))
		{
			NewPrimaryWorld = GEditor->GetWorldContextFromWorld(WorldContext.World());
		}
	}

	if (OldPrimaryWorld && NewPrimaryWorld)
	{
		SwitchPrimaryPIE(OldPrimaryWorld, NewPrimaryWorld);
	}
	else
	{
		UE_LOG(LogHMD, Warning, TEXT("Failed to switch primary PIE."));
	}
}

void UOculusXRMultiPlayerTestingSubsystem::SwitchPrimaryPIE_SingleProcess()
{
	NumClients = 0;
	const ULevelEditorPlaySettings* PlayInSettings = GetDefault<ULevelEditorPlaySettings>();
	if (PlayInSettings)
	{
		PlayInSettings->GetPlayNumberOfClients(NumClients);
	}

	if (!(GEditor && GEditor->GetPlayInEditorSessionInfo().IsSet() && GEditor->GetPlayInEditorSessionInfo()->NumClientInstancesCreated == NumClients))
	{
		return;
	}

	FWorldContext* OldPrimaryWorld = nullptr;
	FWorldContext* NewPrimaryWorld = nullptr;
	for (const FWorldContext& WorldContext : GEditor->GetWorldContexts())
	{
		if (!WorldContext.GameViewport || !WorldContext.GameViewport->GetGameViewport())
		{
			UE_LOG(LogHMD, Warning, TEXT("No GameViewport or SceneViewPort for the current world %d."), WorldContext.PIEInstance);
			continue;
		}
		const FSceneViewport* SceneViewPort = WorldContext.GameViewport->GetGameViewport();
		if (WorldContext.bIsPrimaryPIEInstance && !SceneViewPort->HasFocus())
		{
			OldPrimaryWorld = GEditor->GetWorldContextFromWorld(WorldContext.World());
		}
		else if (!WorldContext.bIsPrimaryPIEInstance && SceneViewPort->HasFocus())
		{
			NewPrimaryWorld = GEditor->GetWorldContextFromWorld(WorldContext.World());
		}
	}

	if (OldPrimaryWorld && NewPrimaryWorld)
	{
		UE_LOG(LogHMD, Log, TEXT("SwitchPrimaryPIE from %d to %d."), OldPrimaryWorld->PIEInstance, NewPrimaryWorld->PIEInstance);
		SwitchPrimaryPIE(OldPrimaryWorld, NewPrimaryWorld);
	}
}

void UOculusXRMultiPlayerTestingSubsystem::SwitchPrimaryPIE(FWorldContext* OldPrimaryWorld, FWorldContext* NewPrimaryWorld)
{
	auto TogglePrimaryWorld = [](FWorldContext* PrimaryWorld, bool bEnable) {
		check(PrimaryWorld != nullptr);

		FSceneViewport* SceneViewPort = PrimaryWorld->GameViewport->GetGameViewport();

		PrimaryWorld->bIsPrimaryPIEInstance = bEnable;
		SceneViewPort->GetViewportWidget().Pin()->EnableStereoRendering(bEnable);
		SceneViewPort->GetViewportWidget().Pin()->SetRenderDirectlyToWindow(bEnable);
		SceneViewPort->SetPlayInEditorGetsMouseControl(bEnable);
		SceneViewPort->SetViewportSize(SceneViewPort->GetSizeXY().X, SceneViewPort->GetSizeXY().Y);
		if (bEnable)
		{
			SceneViewPort->FindWindow()->GetNativeWindow()->SetWindowFocus();
		}
		else
		{
			SceneViewPort->FindWindow()->SetViewportSizeDrivenByWindow(true);
		}
	};

	if (NewPrimaryWorld->GameViewport && NewPrimaryWorld->GameViewport->GetGameViewport() && OldPrimaryWorld->GameViewport && OldPrimaryWorld->GameViewport->GetGameViewport())
	{
		TogglePrimaryWorld(NewPrimaryWorld, true);
		TogglePrimaryWorld(OldPrimaryWorld, false);

		if (OculusXRHMD::FOculusXRHMD::GetOculusXRHMD())
		{
			OculusXRHMD::FOculusXRHMD::GetOculusXRHMD()->SwitchPrimaryPIE(NewPrimaryWorld->PIEInstance);
		}
	}
}
#endif // WITH_EDITOR
#endif // PLATFORM_WINDOWS
