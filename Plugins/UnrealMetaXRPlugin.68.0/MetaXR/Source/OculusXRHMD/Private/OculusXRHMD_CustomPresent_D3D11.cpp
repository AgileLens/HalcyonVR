// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_CustomPresent.h"
#include "OculusXRHMDPrivateRHI.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11
#include "OculusXRHMD.h"

#ifndef WINDOWS_PLATFORM_TYPES_GUARD
#include "Windows/AllowWindowsPlatformTypes.h"
#endif

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FD3D11CustomPresent
	//-------------------------------------------------------------------------------------------------

	class FD3D11CustomPresent : public FCustomPresent
	{
	public:
		FD3D11CustomPresent(FOculusXRHMD* InOculusXRHMD);

		// Implementation of FCustomPresent, called by Plugin itself
		virtual bool IsUsingCorrectDisplayAdapter() const override;
		virtual void* GetOvrpDevice() const override;
		virtual FTextureRHIRef CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags) override;
	};

	FD3D11CustomPresent::FD3D11CustomPresent(FOculusXRHMD* InOculusXRHMD)
		: FCustomPresent(InOculusXRHMD, ovrpRenderAPI_D3D11, PF_B8G8R8A8, true)
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

	bool FD3D11CustomPresent::IsUsingCorrectDisplayAdapter() const
	{
		const void* luid;

		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetDisplayAdapterId2(&luid)) && luid)
		{
			TRefCountPtr<ID3D11Device> D3D11Device;

			ExecuteOnRenderThread([&D3D11Device]() {
				D3D11Device = (ID3D11Device*)RHIGetNativeDevice();
			});

			if (D3D11Device)
			{
				TRefCountPtr<IDXGIDevice> DXGIDevice;
				TRefCountPtr<IDXGIAdapter> DXGIAdapter;
				DXGI_ADAPTER_DESC DXGIAdapterDesc;

				if (SUCCEEDED(D3D11Device->QueryInterface(__uuidof(IDXGIDevice), (void**)DXGIDevice.GetInitReference())) && SUCCEEDED(DXGIDevice->GetAdapter(DXGIAdapter.GetInitReference())) && SUCCEEDED(DXGIAdapter->GetDesc(&DXGIAdapterDesc)))
				{
					return !FMemory::Memcmp(luid, &DXGIAdapterDesc.AdapterLuid, sizeof(LUID));
				}
			}
		}

		// Not enough information.  Assume that we are using the correct adapter.
		return true;
	}

	void* FD3D11CustomPresent::GetOvrpDevice() const
	{
		return GetID3D11DynamicRHI()->RHIGetDevice();
	}

	FTextureRHIRef FD3D11CustomPresent::CreateTexture_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, ovrpTextureHandle InTexture, ETextureCreateFlags InTexCreateFlags)
	{
		CheckInRenderThread();

		switch (InResourceType)
		{
			case RRT_Texture2D:
				return GetID3D11DynamicRHI()->RHICreateTexture2DFromResource(InFormat, InTexCreateFlags, InBinding, (ID3D11Texture2D*)InTexture).GetReference();

			case RRT_Texture2DArray:
				return GetID3D11DynamicRHI()->RHICreateTexture2DArrayFromResource(InFormat, InTexCreateFlags, InBinding, (ID3D11Texture2D*)InTexture).GetReference();

			case RRT_TextureCube:
				return GetID3D11DynamicRHI()->RHICreateTextureCubeFromResource(InFormat, InTexCreateFlags | TexCreate_TargetArraySlicesIndependently, InBinding, (ID3D11Texture2D*)InTexture).GetReference();

			default:
				return nullptr;
		}
	}

	//-------------------------------------------------------------------------------------------------
	// APIs
	//-------------------------------------------------------------------------------------------------

	FCustomPresent* CreateCustomPresent_D3D11(FOculusXRHMD* InOculusXRHMD)
	{
		return new FD3D11CustomPresent(InOculusXRHMD);
	}

} // namespace OculusXRHMD

#if PLATFORM_WINDOWS
#undef WINDOWS_PLATFORM_TYPES_GUARD
#endif

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11
