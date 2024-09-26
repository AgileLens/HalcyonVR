// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OpenXRHeaders : ModuleRules
{
	public OpenXRHeaders(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string SourceDirectory = "$(PluginDir)/Source/ThirdParty/OpenXR/";

		PublicIncludePaths.Add(SourceDirectory + "include");
	}
}
