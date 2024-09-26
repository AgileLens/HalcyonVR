// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
    public class OculusXRPassthrough : ModuleRules
    {
        public OculusXRPassthrough(ReadOnlyTargetRules Target) : base(Target)
        {
            bUseUnity = true;

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "ProceduralMeshComponent",
                    "OculusXRHMD",
                    "KhronosOpenXRHeaders",
                    "OVRPluginXR",
                    "RHI",
                    "HeadMountedDisplay",
                    "XRBase",
                    "OpenXR",
                    "OpenXRHMD"
                });

            PublicIncludePaths.AddRange(new string[] {
                "Runtime/Engine/Classes/Components",
                "Runtime/Engine/Classes/Kismet",
            });

            PrivateIncludePaths.AddRange(new string[] {
                // Relative to Engine\Plugins\Runtime\Oculus\OculusVR\Source
                "OculusXRHMD/Private",
            });

            AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenXR");
        }
    }
}
