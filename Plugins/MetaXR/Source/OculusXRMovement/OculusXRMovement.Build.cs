// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
    public class OculusXRMovement : ModuleRules
    {
        public OculusXRMovement(ReadOnlyTargetRules Target) : base(Target)
        {
            bUseUnity = true;

            PublicDependencyModuleNames.AddRange(
                new string[] {
                    "LiveLinkInterface",
                    "LiveLinkAnimationCore",
                });

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "ApplicationCore",
                    "Engine",
                    "InputCore",
                    "LiveLink",
                    "HeadMountedDisplay",
                    "OVRPluginXR",
                    "OculusXRHMD",
                });

            PrivateIncludePaths.AddRange(
                new string[] {
                    "OculusXRHMD/Private",
                });
        }
    }
}
