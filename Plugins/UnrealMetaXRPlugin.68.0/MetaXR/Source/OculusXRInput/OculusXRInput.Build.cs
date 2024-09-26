// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
    public class OculusXRInput : ModuleRules
    {
        public OculusXRInput(ReadOnlyTargetRules Target) : base(Target)
        {
            bUseUnity = true;

            PrivateIncludePathModuleNames.AddRange(
                new string[]
                {
                    "InputDevice",			// For IInputDevice.h
					"HeadMountedDisplay",	// For IMotionController.h
					"ImageWrapper"
                });

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "ApplicationCore",
                    "Engine",
                    "InputCore",
                    "HeadMountedDisplay",
                    "OculusXRHMD",
                    "OculusXRMR",
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
					// Relative to Engine\Plugins\Runtime\Oculus\OculusVR\Source
					"OculusXRHMD/Private",
                });

            PublicIncludePaths.AddRange(
                new string[] {
                    "Runtime/Renderer/Private",
                    "Runtime/Engine/Classes/Components",
                });

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/OVRPlugin/OVRPlugin/Lib/" + Target.Platform.ToString() + "/OpenXR/OVRPlugin.dll");
            }
        }
    }
}
