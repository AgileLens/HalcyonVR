// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OculusXREditor : ModuleRules
{
    public OculusXREditor(ReadOnlyTargetRules Target) : base(Target)
    {
        bUseUnity = true;

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Projects",
                "InputCore",
                "UnrealEd",
                "LevelEditor",
                "PropertyEditor",
                "CoreUObject",
                "Engine",
                "EngineSettings",
                "AndroidRuntimeSettings",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "Core",
                "OculusXRHMD",
                "OculusXRMovement",
                "OculusXRPassthrough",
                "OVRPluginXR",
                "OculusXRProjectSetupTool",
                "HTTP",
                "DesktopPlatform",
                "LauncherServices",
                "GameProjectGeneration",
                "SharedSettingsWidgets",
                "RHI",
                "SourceControl",
            }
        );

        PrivateIncludePaths.AddRange(
                new string[] {
					// Relative to Engine\Plugins\Runtime\Oculus\OculusVR\Source
					"OculusXREditor/Private",
                    "OculusXRHMD/Private"
                });

        PrivateIncludePathModuleNames.AddRange(
            new string[] {
                "Settings",
                "OculusXRProjectSetupTool"
            }
            );
    }
}
