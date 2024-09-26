// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OVRPluginXR : ModuleRules
{
	public OVRPluginXR(ReadOnlyTargetRules Target) : base(Target)
	{


		Type = ModuleType.External;

		string SourceDirectory = "$(PluginDir)/Source/ThirdParty/OVRPlugin/OVRPlugin/";

		PublicIncludePaths.Add(SourceDirectory + "Include");

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			RuntimeDependencies.Add(SourceDirectory + "Lib/arm64-v8a/OpenXR/libOVRPlugin.so");
		}
	}
}
