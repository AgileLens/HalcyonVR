// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
    public class OculusXRMR : ModuleRules
    {
        public OculusXRMR(ReadOnlyTargetRules Target) : base(Target)
        {
            bUseUnity = true;

            PrivateIncludePathModuleNames.AddRange(
                new string[]
                {
                    "InputDevice",			// For IInputDevice.h
					"HeadMountedDisplay",	// For IMotionController.h
					"ImageWrapper",
                    "Engine"
                });

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "InputCore",
                    "Slate",
                    "SlateCore",
                    "RHI",
                    "VulkanRHI",
                    "RenderCore",
                    "MediaAssets",
                    "HeadMountedDisplay",
                    "OculusXRHMD",
                    "OVRPluginXR",
                });

            if (Target.Version.MajorVersion > 5 || (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion >= 3))
            {
                PrivateDependencyModuleNames.AddRange(
                    new string[]
                    {
                        "XRBase",
                    });
            }

            PrivateIncludePaths.AddRange(
                new string[] {
                    "OculusXRHMD/Private",
                    "OculusXRInput/Private",
                });

            PublicIncludePaths.AddRange(
                new string[] {
                "Runtime/Renderer/Private",
                "Runtime/Engine/Classes/Components",
                "Runtime/MediaAssets/Private",
            });

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                PublicDelayLoadDLLs.Add("OVRPluginXR.dll");
            }

            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
            }

            if (Target.bBuildEditor == true)
            {
                PrivateDependencyModuleNames.Add("UnrealEd");
            }
        }
    }
}
