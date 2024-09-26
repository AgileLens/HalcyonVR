// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "OculusXRToolStyle.h"
#include "OculusXREditorModule.h"
#include "HAL/IConsoleManager.h"

class FOculusToolCommands : public TCommands<FOculusToolCommands>
{
public:
	FOculusToolCommands()
		: TCommands<FOculusToolCommands>(
			  TEXT("OculusTool"), NSLOCTEXT("Contexts", "OculusXREditor", "OculusXREditor Plugin"), NAME_None,
			  FOculusToolStyle::GetStyleSetName())
		, ShowOculusToolCommand(
			  TEXT("vr.oculus.ShowToolWindow"),
			  *NSLOCTEXT("OculusRift", "CCommandText_ShowToolWindow",
				  "Show the Oculus Editor Tool window (editor only).")
				   .ToString(),
			  FConsoleCommandDelegate::CreateRaw(this, &FOculusToolCommands::ShowOculusTool))
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> OpenProjectSetupTool;
	TSharedPtr<FUICommandInfo> ToggleDeploySo;
	TSharedPtr<FUICommandInfo> ToggleIterativeCookOnTheFly;
	TSharedPtr<FUICommandInfo> OpenPlatWindow;
	TSharedPtr<FUICommandInfo> ToggleMetaXRSim;
	TSharedPtr<FUICommandInfo> LaunchGameRoom;
	TSharedPtr<FUICommandInfo> LaunchLivingRoom;
	TSharedPtr<FUICommandInfo> LaunchBedroom;
	TSharedPtr<FUICommandInfo> Corridor;
	TSharedPtr<FUICommandInfo> FurnitureFilledRoom;
	TSharedPtr<FUICommandInfo> HighCeilingRoom;
	TSharedPtr<FUICommandInfo> LivingRoomWithMultipleSpaces;
	TSharedPtr<FUICommandInfo> LShapeRoom;
	TSharedPtr<FUICommandInfo> Office;
	TSharedPtr<FUICommandInfo> RoomWithStaircase;
	TSharedPtr<FUICommandInfo> TrapezoidalRoom;
	TSharedPtr<FUICommandInfo> StopServer;

private:
	void ShowOculusTool();

	FAutoConsoleCommand ShowOculusToolCommand;
};
