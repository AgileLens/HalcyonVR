// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "OculusXRHMDTypes.h"
#include "OpenXR/IOculusXRExtensionPlugin.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPerformanceExtensionPlugin, Log, All);

namespace OculusXR
{

	class FOculusXRPerformanceExtensionPlugin : public IOculusXRExtensionPlugin
	{
	private:
		bool bPerfSettingsInitialized;
		bool bPerfLevelsChanged;
		EOculusXRProcessorPerformanceLevel CpuPerfLevel;
		EOculusXRProcessorPerformanceLevel GpuPerfLevel;

	public:
		// IOpenXRExtensionPlugin
		virtual bool GetRequiredExtensions(TArray<const ANSICHAR*>& OutExtensions) override;
		virtual bool GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions) override;
		virtual void PostCreateSession(XrSession InSession) override;
		virtual void* OnWaitFrame(XrSession InSession, void* InNext) override;

		void GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel);
		void SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel);
		void LoadFromSettings();
	};

} // namespace OculusXR
