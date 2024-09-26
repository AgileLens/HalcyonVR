// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRExtensionPluginManager.h"

namespace OculusXR
{

	void FOculusXRExtensionPluginManager::StartupOpenXRPlugins()
	{
		OculusXRCoreExtensionPlugin.RegisterOpenXRExtensionPlugin();
		OculusXRPerformanceExtensionPlugin.RegisterOpenXRExtensionPlugin();
	}

	FOculusXRPerformanceExtensionPlugin& FOculusXRExtensionPluginManager::GetPerformanceExtensionPlugin()
	{
		return OculusXRPerformanceExtensionPlugin;
	}

} // namespace OculusXR
