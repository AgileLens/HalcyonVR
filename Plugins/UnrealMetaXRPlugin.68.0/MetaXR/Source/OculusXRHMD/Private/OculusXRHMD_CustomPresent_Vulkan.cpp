// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_CustomPresent.h"
#include "OculusXRHMDPrivateRHI.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN
#include "OculusXRHMD.h"
#include "IVulkanDynamicRHI.h"

#if PLATFORM_WINDOWS
#ifndef WINDOWS_PLATFORM_TYPES_GUARD
#include "Windows/AllowWindowsPlatformTypes.h"
#endif
#endif

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FCustomPresentVulkan
	//-------------------------------------------------------------------------------------------------

	class FVulkanCustomPresent : public FCustomPresent
	{
	public:
		FVulkanCustomPresent(FOculusXRHMD* InOculusXRHMD);

		// Implementation of FCustomPresent, called by Plugin itself
		virtual bool IsUsingCorrectDisplayAdapter() const override;
		virtual void* GetOvrpInstance() const override;
		virtual void* GetOvrpPhysicalDevice() const override;
		virtual void* GetOvrpDevice() const override;
		virtual void* GetOvrpCommandQueue() const override;
		virtual FTextureRHIRef CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags) override;
		// This is a hack to turn force FSR off when we allocate our FDM to avoid a crash on Quest 3
		// TODO: Remove this for UE 5.3 after there's an engine-side fix
		virtual void UseFragmentDensityMapOverShadingRate_RHIThread() override;
#ifdef WITH_OCULUS_BRANCH
		virtual void UpdateFoveationOffsets_RHIThread(bool bUseTileOffsets, FIntPoint TileOffsets[2]) override;
#endif // WITH_OCULUS_BRANCH
	};

	FVulkanCustomPresent::FVulkanCustomPresent(FOculusXRHMD* InOculusXRHMD)
		: FCustomPresent(InOculusXRHMD, ovrpRenderAPI_Vulkan, PF_R8G8B8A8, true)
	{
#if PLATFORM_ANDROID
		if (GRHISupportsRHIThread && GIsThreadedRendering && GUseRHIThread_InternalUseOnly)
		{
			SetRHIThreadEnabled(false, false);
		}
#endif

		switch (GPixelFormats[PF_DepthStencil].PlatformFormat)
		{
			case VK_FORMAT_D24_UNORM_S8_UINT:
				DefaultDepthOvrpTextureFormat = ovrpTextureFormat_D24_S8;
				break;
			case VK_FORMAT_D32_SFLOAT_S8_UINT:
				DefaultDepthOvrpTextureFormat = ovrpTextureFormat_D32_FP_S8;
				break;
			default:
				UE_LOG(LogHMD, Error, TEXT("Unrecognized depth buffer format"));
				break;
		}
		bSupportsSubsampled = GetIVulkanDynamicRHI()->RHISupportsEXTFragmentDensityMap2();
	}

	bool FVulkanCustomPresent::IsUsingCorrectDisplayAdapter() const
	{
#if PLATFORM_WINDOWS
		const void* AdapterId = nullptr;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetDisplayAdapterId2(&AdapterId)) && AdapterId)
		{
			return GetIVulkanDynamicRHI()->RHIDoesAdapterMatchDevice(AdapterId);
		}
#endif

		// Not enough information.  Assume that we are using the correct adapter.
		return true;
	}

	void* FVulkanCustomPresent::GetOvrpInstance() const
	{
		return GetIVulkanDynamicRHI()->RHIGetVkInstance();
	}

	void* FVulkanCustomPresent::GetOvrpPhysicalDevice() const
	{
		return GetIVulkanDynamicRHI()->RHIGetVkPhysicalDevice();
	}

	void* FVulkanCustomPresent::GetOvrpDevice() const
	{
		return GetIVulkanDynamicRHI()->RHIGetVkDevice();
	}

	void* FVulkanCustomPresent::GetOvrpCommandQueue() const
	{
		return GetIVulkanDynamicRHI()->RHIGetGraphicsVkQueue();
	}

	FTextureRHIRef FVulkanCustomPresent::CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags)
	{
		CheckInRenderThread();

		IVulkanDynamicRHI* VulkanRHI = GetIVulkanDynamicRHI();
		const VkImageSubresourceRange SubresourceRangeAll = { VK_IMAGE_ASPECT_COLOR_BIT, 0, VK_REMAINING_MIP_LEVELS, 0, VK_REMAINING_ARRAY_LAYERS };

		if (EnumHasAnyFlags(InTexCreateFlags, TexCreate_RenderTargetable))
		{
			VulkanRHI->RHISetImageLayout((VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, SubresourceRangeAll);
		}
		else if (EnumHasAnyFlags(InTexCreateFlags, TexCreate_Foveation))
		{
			VulkanRHI->RHISetImageLayout((VkImage)InTexture, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT, SubresourceRangeAll);
		}

		switch (InResourceType)
		{
			case RRT_Texture2D:
				return VulkanRHI->RHICreateTexture2DFromResource(InFormat, InSizeX, InSizeY, InNumMips, InNumSamples, (VkImage)InTexture, InTexCreateFlags, InBinding).GetReference();

			case RRT_Texture2DArray:
				return VulkanRHI->RHICreateTexture2DArrayFromResource(InFormat, InSizeX, InSizeY, 2, InNumMips, InNumSamples, (VkImage)InTexture, InTexCreateFlags, InBinding).GetReference();

			case RRT_TextureCube:
				return VulkanRHI->RHICreateTextureCubeFromResource(InFormat, InSizeX, false, 1, InNumMips, (VkImage)InTexture, InTexCreateFlags, InBinding).GetReference();

			default:
				return nullptr;
		}
	}

	// This is a hack to turn force FSR off when we allocate our FDM to avoid a crash on Quest 3
	// TODO: Remove this for UE 5.3 after there's an engine-side fix
	void FVulkanCustomPresent::UseFragmentDensityMapOverShadingRate_RHIThread()
	{
		CheckInRHIThread();
		SCOPED_NAMED_EVENT(UseFragmentDensityMapOverShadingRate_RHIThread, FColor::Red);

		GRHIVariableRateShadingImageDataType = VRSImage_Fractional;
		GRHIVariableRateShadingImageFormat = PF_R8G8;
	}

#ifdef WITH_OCULUS_BRANCH
	void FVulkanCustomPresent::UpdateFoveationOffsets_RHIThread(bool bUseOffsets, FIntPoint Offsets[2])
	{
		CheckInRHIThread();

		SCOPED_NAMED_EVENT(UpdateFoveationOffsets_RHIThread, FColor::Red);
		GetIVulkanDynamicRHI()->RHISetQcomFragmentDensityMapOffsets(bUseOffsets, Offsets);
	}
#endif // WITH_OCULUS_BRANCH

	//-------------------------------------------------------------------------------------------------
	// APIs
	//-------------------------------------------------------------------------------------------------

	FCustomPresent* CreateCustomPresent_Vulkan(FOculusXRHMD* InOculusXRHMD)
	{
		return new FVulkanCustomPresent(InOculusXRHMD);
	}

} // namespace OculusXRHMD

#if PLATFORM_WINDOWS
#undef WINDOWS_PLATFORM_TYPES_GUARD
#endif

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN
