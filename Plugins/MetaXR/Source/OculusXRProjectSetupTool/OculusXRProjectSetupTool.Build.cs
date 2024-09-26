// Copyright (c) Meta Platforms, Inc. and affiliates.

using UnrealBuildTool;

public class OculusXRProjectSetupTool : ModuleRules
{
    public OculusXRProjectSetupTool(ReadOnlyTargetRules Target) : base(Target)
    {

        bUseUnity = true;

        PrivateIncludePaths.AddRange(
            new string[] {
                "OculusXRHMD/Private",
                "OculusXRUncookedOnly/Private",
            });

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Projects",
                "UnrealEd",
                "LevelEditor",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "EngineSettings",
                "OculusXRHMD",
                "OculusXRMovement",
                "OculusXRPassthrough",
                "OculusXRAnchors",
                "OculusXRScene",
                "OculusXRUncookedOnly",
				"AndroidRuntimeSettings",
                "LauncherServices",
                "ToolWidgets",
                "WorkspaceMenuStructure",
                "PluginBrowser",
                "ToolMenus",
                "RHI",
				"BlueprintGraph",
			}
        );
    }
}
