// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
    public class OculusXRHMD : ModuleRules
    {
        public OculusXRHMD(ReadOnlyTargetRules Target) : base(Target)
        {
            bUseUnity = true;

            var EngineDir = Path.GetFullPath(Target.RelativeEnginePath);

            PrivateIncludePaths.AddRange(
                new string[] {
                    Path.Combine(EngineDir, "Source/Runtime/Renderer/Private"),
                    Path.Combine(EngineDir, "Source/Runtime/Renderer/Private"),
                    Path.Combine(EngineDir, "Source/Runtime/OpenGLDrv/Private"),
                    Path.Combine(EngineDir, "Source/Runtime/Engine/Classes/Components"),
                    Path.Combine(EngineDir, "Source/Runtime/Engine/Classes/Kismet"),
                });

            PublicIncludePathModuleNames.AddRange(
                new string[] {
                    "Launch",
                    "ProceduralMeshComponent",
                    "AndroidPermission",
                    "OpenXRHMD",
                });

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "EngineSettings",
                    "InputCore",
                    "RHI",
                    "RHICore",
                    "RenderCore",
                    "Renderer",
                    "Slate",
                    "SlateCore",
                    "ImageWrapper",
                    "MediaAssets",
                    "Analytics",
                    "OpenGLDrv",
                    "VulkanRHI",
                    "OVRPluginXR",
                    "OculusOpenXRLoader",
                    "ProceduralMeshComponent",
                    "Projects",
                    "KhronosOpenXRHeaders",
                    "OpenXR",
                    "OpenXRHMD",
                });

            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "HeadMountedDisplay",
                });

            PublicIncludePaths.AddRange(
                new string[] {
                    Path.Combine(EngineDir, "Plugins/Runtime/OpenXR/Source/OpenXRHMD/Private"),
                });

            if (Target.Version.MajorVersion > 5 || (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion >= 3))
            {
                PublicDependencyModuleNames.AddRange(
                    new string[]
                    {
                        "XRBase",
                    });
            }

            if (Target.bBuildEditor == true)
            {
                PrivateDependencyModuleNames.Add("UnrealEd");
            }

            AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenGL");

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                // D3D
                {
                    PrivateDependencyModuleNames.AddRange(
                        new string[]
                        {
                            "D3D11RHI",
                            "D3D12RHI",
                        });

                    PrivateIncludePaths.AddRange(
                        new string[]
                        {
                            "OculusXRMR/Public",
                        });

                    AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "DX12");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAPI");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11Audio");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "DirectSound");
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAftermath");
                }

                // Vulkan
                {
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
                }

                // OVRPlugin
                if (Target.Platform == UnrealTargetPlatform.Win64)
                {
                    RuntimeDependencies.Add("$(PluginDir)/Source/ThirdParty/OVRPlugin/OVRPlugin/Lib/" + Target.Platform.ToString() + "/OpenXR/OVRPlugin.dll");
                }
            }
            else if (Target.Platform == UnrealTargetPlatform.Android)
            {
                // We are not currently supporting Mixed Reality on Android, but we need to include IOculusXRMRModule.h for OCULUS_MR_SUPPORTED_PLATFORMS definition
                PrivateIncludePaths.AddRange(
                        new string[]
                        {
                            "OculusXRMR/Public"
                        });

                // Vulkan
                {
                    AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
                }

                // AndroidPlugin
                {
                    string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                    AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "OculusMobile_APL.xml"));
                }
            }
        }
    }
}
