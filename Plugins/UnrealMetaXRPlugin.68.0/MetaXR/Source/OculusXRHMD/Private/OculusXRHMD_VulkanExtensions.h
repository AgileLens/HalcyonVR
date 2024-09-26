// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"
#include "IHeadMountedDisplayVulkanExtensions.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FVulkanExtensions
	//-------------------------------------------------------------------------------------------------

	class FVulkanExtensions : public IHeadMountedDisplayVulkanExtensions, public TSharedFromThis<FVulkanExtensions, ESPMode::ThreadSafe>
	{
	public:
		FVulkanExtensions() {}
		virtual ~FVulkanExtensions() {}

		// IHeadMountedDisplayVulkanExtensions
		virtual bool GetVulkanInstanceExtensionsRequired(TArray<const ANSICHAR*>& Out) override;
		virtual bool GetVulkanDeviceExtensionsRequired(struct VkPhysicalDevice_T* pPhysicalDevice, TArray<const ANSICHAR*>& Out) override;
	};

#if WITH_EDITOR
	class FEditorVulkanExtensions : public IHeadMountedDisplayVulkanExtensions, public TSharedFromThis<FEditorVulkanExtensions, ESPMode::ThreadSafe>
	{
	public:
		FEditorVulkanExtensions() {}
		virtual ~FEditorVulkanExtensions() {}

		// IHeadMountedDisplayVulkanExtensions
		virtual bool GetVulkanInstanceExtensionsRequired(TArray<const ANSICHAR*>& Out) override;
		virtual bool GetVulkanDeviceExtensionsRequired(struct VkPhysicalDevice_T* pPhysicalDevice, TArray<const ANSICHAR*>& Out) override;
	};
#endif

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
