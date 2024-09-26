// Copyright (c) Meta Platforms, Inc. and affiliates.

using UnrealBuildTool;

public class MRUtilityKit : ModuleRules
{
    public MRUtilityKit(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bUseUnity = true;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "RenderCore",
                "Projects"
            });


        if (Target.Version.MajorVersion > 5 || (Target.Version.MajorVersion == 5 && Target.Version.MinorVersion >= 3))
        {
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "XRBase",
                });
        }


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "OculusXRHMD",
                "OculusXRAnchors",
                "OculusXRScene",
                "Json",
                "ProceduralMeshComponent",
                "HeadMountedDisplay",
                "MRUtilityKitShared"
            });
    }
}
