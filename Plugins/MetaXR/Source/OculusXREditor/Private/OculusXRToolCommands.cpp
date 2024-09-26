// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRToolCommands.h"

#include "../../OculusXRProjectSetupTool/Private/OculusXRProjectSetupToolModule.h"
#include "Framework/Docking/TabManager.h"

#define LOCTEXT_NAMESPACE "FOculusXREditorModule"

void FOculusToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenProjectSetupTool, "Meta XR Project Setup Tool", "Show Meta XR Project Setup Tool", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ToggleDeploySo, "Deploy compiled .so directly to device", "Faster deploy when we only have code changes by deploying compiled .so directly to device", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(ToggleIterativeCookOnTheFly, "Enable Iterative Cook on the Fly", "Faster deploy for asset changes by keeping previously cooked contents on the device (Uses Cook on the Fly)", EUserInterfaceActionType::ToggleButton, FInputChord());
	UI_COMMAND(OpenPlatWindow, "Meta XR Platform Window", "Show Meta XR Platform Window", EUserInterfaceActionType::Button, FInputChord());

	UI_COMMAND(ToggleMetaXRSim, "Meta XR Simulator", "Activate/Deactivate Meta XR Simulator", EUserInterfaceActionType::ToggleButton, FInputChord());

	UI_COMMAND(LaunchGameRoom, "Launch Game Room", "Launch Game Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LaunchLivingRoom, "Launch Living Room", "Launch Living Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LaunchBedroom, "Launch Bedroom", "Launch Bedroom", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(Corridor, "Launch Corridor", "Launch Corridor", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(FurnitureFilledRoom, "Launch Furniture-filled Room", "Launch Furniture-filled Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(HighCeilingRoom, "Launch High-ceiling Room", "Launch High-ceiling Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LivingRoomWithMultipleSpaces, "Launch Living Room with Multiple Spaces", "Launch Living Room with Multiple Spaces", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LShapeRoom, "Launch L-shape Room", "Launch L-shape Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(Office, "Launch Office", "Launch Office", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(RoomWithStaircase, "Launch Room with Staircase", "Launch Room with Staircase", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(TrapezoidalRoom, "Launch Trapezoidal Room", "Launch Trapezoidal Room", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(StopServer, "Stop Server", "Stop Server", EUserInterfaceActionType::Button, FInputChord());
}

void FOculusToolCommands::ShowOculusTool()
{
	IOculusXRProjectSetupToolModule::Get().ShowProjectSetupTool("Console");
}

#undef LOCTEXT_NAMESPACE
