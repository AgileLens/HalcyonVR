// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKit.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif // WITH_EDITOR

#define LOCTEXT_NAMESPACE "FMRUKModule"

DEFINE_LOG_CATEGORY(LogMRUK);

const FString FMRUKLabels::Floor("FLOOR");
const FString FMRUKLabels::WallFace("WALL_FACE");
const FString FMRUKLabels::InvisibleWallFace("INVISIBLE_WALL_FACE");
const FString FMRUKLabels::Ceiling("CEILING");
const FString FMRUKLabels::DoorFrame("DOOR_FRAME");
const FString FMRUKLabels::WindowFrame("WINDOW_FRAME");
const FString FMRUKLabels::Couch("COUCH");
const FString FMRUKLabels::Table("TABLE");
const FString FMRUKLabels::Screen("SCREEN");
const FString FMRUKLabels::Bed("BED");
const FString FMRUKLabels::Lamp("LAMP");
const FString FMRUKLabels::Plant("PLANT");
const FString FMRUKLabels::Storage("STORAGE");
const FString FMRUKLabels::WallArt("WALL_ART");
const FString FMRUKLabels::GlobalMesh("GLOBAL_MESH");
const FString FMRUKLabels::Other("OTHER");

bool FMRUKLabelFilter::PassesFilter(const TArray<FString>& Labels) const
{
	for (const auto& ExcludedLabel : ExcludedLabels)
	{
		if (Labels.Contains(ExcludedLabel))
		{
			return false;
		}
	}
	for (const auto& IncludedLabel : IncludedLabels)
	{
		if (Labels.Contains(IncludedLabel))
		{
			return true;
		}
	}
	return IncludedLabels.IsEmpty();
}

UMRUKSettings::UMRUKSettings(const FObjectInitializer& obj)
{
}

void FMRUKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified
	// in the .uplugin file per-module
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "MRUtilityKit",
			LOCTEXT("RuntimeSettingsName", "Mixed Reality Utility Kit"), LOCTEXT("RuntimeSettingsDescription", "Configure the Mixed Reality Utility plugin"),
			GetMutableDefault<UMRUKSettings>());
	}
#endif // WITH_EDITOR
	const auto Plugin = IPluginManager::Get().FindPlugin(TEXT("OculusXR"));
	const FString PluginDirectory = FPaths::ConvertRelativePathToFull(Plugin->GetBaseDir());
	const FString ShaderDirectory = FPaths::Combine(PluginDirectory, TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/OculusXR", ShaderDirectory);
}

void FMRUKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support
	// dynamic reloading, we call this function before unloading the module.
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "MRUtilityKit");
	}
#endif // WITH_EDITOR
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMRUKModule, MRUtilityKit)
