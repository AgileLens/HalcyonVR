// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OculusXRUncookedOnly : ModuleRules
{
    public OculusXRUncookedOnly(ReadOnlyTargetRules Target) : base(Target)
    {
        bUseUnity = true;

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "CoreUObject",
                "Engine",
                "Core",
                "OculusXRHMD",
                "BlueprintGraph",
                "OculusXRPassthrough",
                "KismetCompiler",
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
				// Relative to Engine\Plugins\Runtime\Oculus\OculusVR\Source
				"OculusXRUncookedOnly/Private",
            });

        PrivateIncludePathModuleNames.AddRange(
            new string[] {
            }
        );
    }
}
