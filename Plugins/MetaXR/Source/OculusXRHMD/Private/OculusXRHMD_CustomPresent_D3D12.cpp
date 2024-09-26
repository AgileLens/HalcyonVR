// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_CustomPresent.h"
#include "OculusXRHMDPrivateRHI.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
#include "OculusXRHMD.h"

#ifndef WINDOWS_PLATFORM_TYPES_GUARD
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FCustomPresentD3D12
	//-------------------------------------------------------------------------------------------------

	class FD3D12CustomPresent : public FCustomPresent
	{
	public:
		FD3D12CustomPresent(FOculusXRHMD* InOculusXRHMD);

		// Implementation of FCustomPresent, called by Plugin itself
		virtual bool IsUsingCorrectDisplayAdapter() const override;
		virtual void* GetOvrpDevice() const override;
		virtual FTextureRHIRef CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags) override;
	};

	FD3D12CustomPresent::FD3D12CustomPresent(FOculusXRHMD* InOculusXRHMD)
		: FCustomPresent(InOculusXRHMD, ovrpRenderAPI_D3D12, PF_B8G8R8A8, true)
	{
		switch (GPixelFormats[PF_DepthStencil].PlatformFormat)
		{
			case DXGI_FORMAT_R24G8_TYPELESS:
				DefaultDepthOvrpTextureFormat = ovrpTextureFormat_D24_S8;
				break;
			case DXGI_FORMAT_R32G8X24_TYPELESS:
				DefaultDepthOvrpTextureFormat = ovrpTextureFormat_D32_FP_S8;
				break;
			default:
				UE_LOG(LogHMD, Error, TEXT("Unrecognized depth buffer format"));
				break;
		}
	}

	bool FD3D12CustomPresent::IsUsingCorrectDisplayAdapter() const
	{
		const void* luid;

		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetDisplayAdapterId2(&luid)) && luid)
		{
			TRefCountPtr<ID3D12Device> D3DDevice;

			ExecuteOnRenderThread([&D3DDevice]() {
				D3DDevice = (ID3D12Device*)RHIGetNativeDevice();
			});

			if (D3DDevice)
			{
				LUID AdapterLuid = D3DDevice->GetAdapterLuid();
				return !FMemory::Memcmp(luid, &AdapterLuid, sizeof(LUID));
			}
		}

		// Not enough information.  Assume that we are using the correct adapter.
		return true;
	}

	void* FD3D12CustomPresent::GetOvrpDevice() const
	{
		return GetID3D12DynamicRHI()->RHIGetCommandQueue();
	}

	FTextureRHIRef FD3D12CustomPresent::CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags)
	{
		CheckInRenderThread();

		ID3D12DynamicRHI* DynamicRHI = GetID3D12DynamicRHI();

		switch (InResourceType)
		{
			case RRT_Texture2D:
				return DynamicRHI->RHICreateTexture2DFromResource(InFormat, InTexCreateFlags, InBinding, (ID3D12Resource*)InTexture).GetReference();

			case RRT_Texture2DArray:
				return DynamicRHI->RHICreateTexture2DArrayFromResource(InFormat, InTexCreateFlags, InBinding, (ID3D12Resource*)InTexture).GetReference();

			case RRT_TextureCube:
				return DynamicRHI->RHICreateTextureCubeFromResource(InFormat, InTexCreateFlags, InBinding, (ID3D12Resource*)InTexture).GetReference();

			default:
				return nullptr;
		}
	}

	//-------------------------------------------------------------------------------------------------
	// APIs
	//-------------------------------------------------------------------------------------------------

	FCustomPresent* CreateCustomPresent_D3D12(FOculusXRHMD* InOculusXRHMD)
	{
		return new FD3D12CustomPresent(InOculusXRHMD);
	}

} // namespace OculusXRHMD

#if PLATFORM_WINDOWS
#undef WINDOWS_PLATFORM_TYPES_GUARD
#endif

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
