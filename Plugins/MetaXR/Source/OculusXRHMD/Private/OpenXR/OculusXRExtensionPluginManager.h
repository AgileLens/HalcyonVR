// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "OculusXRCoreExtensionPlugin.h"
#include "OculusXRPerformanceExtensionPlugin.h"

namespace OculusXR
{

	class FOculusXRExtensionPluginManager
	{
	public:
		FOculusXRExtensionPluginManager(){};
		virtual ~FOculusXRExtensionPluginManager() {}

		void StartupOpenXRPlugins();

		FOculusXRCoreExtensionPlugin OculusXRCoreExtensionPlugin;
		FOculusXRPerformanceExtensionPlugin OculusXRPerformanceExtensionPlugin;
		virtual FOculusXRPerformanceExtensionPlugin& GetPerformanceExtensionPlugin();
	};

} // namespace OculusXR
