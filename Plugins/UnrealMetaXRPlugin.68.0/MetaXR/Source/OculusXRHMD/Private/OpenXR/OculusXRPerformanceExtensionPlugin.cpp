// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRPerformanceExtensionPlugin.h"
#include "OculusXRXRFunctions.h"
#include "OculusXROpenXRUtilities.h"
#include "OculusXRHMDRuntimeSettings.h"

DEFINE_LOG_CATEGORY(LogOculusPerformanceExtensionPlugin);

namespace OculusXR
{

	namespace // anonymous
	{
		XrPerfSettingsLevelEXT ToXrPerfSettingsLevel(EOculusXRProcessorPerformanceLevel PerformanceLevel)
		{
			switch (PerformanceLevel)
			{
				case EOculusXRProcessorPerformanceLevel::PowerSavings:
					return XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT;
				case EOculusXRProcessorPerformanceLevel::SustainedLow:
					return XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT;
				case EOculusXRProcessorPerformanceLevel::SustainedHigh:
					return XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT;
				case EOculusXRProcessorPerformanceLevel::Boost:
					return XR_PERF_SETTINGS_LEVEL_BOOST_EXT;
				default:
					check(false);
			}
			return XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT;
		}
	} // namespace

	bool FOculusXRPerformanceExtensionPlugin::GetRequiredExtensions(TArray<const ANSICHAR*>& OutExtensions)
	{
		return true;
	}

	bool FOculusXRPerformanceExtensionPlugin::GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions)
	{
		OutExtensions.Add(XR_EXT_PERFORMANCE_SETTINGS_EXTENSION_NAME);
		return true;
	}

	void FOculusXRPerformanceExtensionPlugin::PostCreateSession(XrSession InSession)
	{
		const UOculusXRHMDRuntimeSettings* HMDSettings = GetDefault<UOculusXRHMDRuntimeSettings>();
		LoadFromSettings();
	}

	void* FOculusXRPerformanceExtensionPlugin::OnWaitFrame(XrSession InSession, void* InNext)
	{
		if (bPerfLevelsChanged && xrPerfSettingsSetPerformanceLevelEXT.IsSet() && xrPerfSettingsSetPerformanceLevelEXT.GetValue() != nullptr)
		{
			UE_LOG(LogOculusPerformanceExtensionPlugin, Log, TEXT("Oculus OpenXR SetPerformanceLevel CPU=%d, GPU=%d"), CpuPerfLevel, GpuPerfLevel);
			ENSURE_XRCMD(xrPerfSettingsSetPerformanceLevelEXT.GetValue()(InSession, XR_PERF_SETTINGS_DOMAIN_CPU_EXT, ToXrPerfSettingsLevel(CpuPerfLevel)));
			ENSURE_XRCMD(xrPerfSettingsSetPerformanceLevelEXT.GetValue()(InSession, XR_PERF_SETTINGS_DOMAIN_GPU_EXT, ToXrPerfSettingsLevel(GpuPerfLevel)));
			bPerfLevelsChanged = false;
		}
		return InNext;
	}

	void FOculusXRPerformanceExtensionPlugin::GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuLevel, EOculusXRProcessorPerformanceLevel& GpuLevel)
	{
		if (!bPerfSettingsInitialized)
		{
			LoadFromSettings();
		}
		CpuLevel = CpuPerfLevel;
		GpuLevel = GpuPerfLevel;
	}

	void FOculusXRPerformanceExtensionPlugin::SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuLevel, EOculusXRProcessorPerformanceLevel GpuLevel)
	{
		if (CpuPerfLevel != CpuLevel || GpuPerfLevel != GpuLevel)
		{
			CpuPerfLevel = CpuLevel;
			GpuPerfLevel = GpuLevel;
			bPerfLevelsChanged = true;
		}
		bPerfSettingsInitialized = true;
	}

	void FOculusXRPerformanceExtensionPlugin::LoadFromSettings()
	{
		const UOculusXRHMDRuntimeSettings* HMDSettings = GetDefault<UOculusXRHMDRuntimeSettings>();
		SetSuggestedCpuAndGpuPerformanceLevels(HMDSettings->SuggestedCpuPerfLevel, HMDSettings->SuggestedGpuPerfLevel);
	}

} // namespace OculusXR
