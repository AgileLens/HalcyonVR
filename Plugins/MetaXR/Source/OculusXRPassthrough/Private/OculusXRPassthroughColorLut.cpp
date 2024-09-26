// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughColorLut.h"
#include "OculusXRPassthroughLayerComponent.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMDModule.h"
#include "Math/UnrealMathUtility.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "UObject/ObjectSaveContext.h"
#include "OculusXRHMD.h"
#include "TextureResource.h"

namespace
{
	ovrpPassthroughColorLutChannels ToOVRPColorLutChannels(EColorLutChannels InColorLutChannels)
	{
		switch (InColorLutChannels)
		{
			case ColorLutChannels_RGB:
				return ovrpPassthroughColorLutChannels_Rgb;
			case ColorLutChannels_RGBA:
				return ovrpPassthroughColorLutChannels_Rgba;
			default:
				return ovrpPassthroughColorLutChannels_Invalid;
		}
	}

	TArray<uint8> ColorArrayToColorData(const TArray<FColor>& InColorArray, bool IgnoreAlphaChannel)
	{
		TArray<uint8> Data;
		const size_t ElementSize = IgnoreAlphaChannel ? 3 : 4;
		Data.SetNum(InColorArray.Num() * ElementSize);
		uint8* Dest = Data.GetData();
		for (size_t i = 0; i < InColorArray.Num(); i++)
		{
			Data[i * ElementSize + 0] = InColorArray[i].R;
			Data[i * ElementSize + 1] = InColorArray[i].G;
			Data[i * ElementSize + 2] = InColorArray[i].B;

			if (!IgnoreAlphaChannel)
			{
				Data[i * ElementSize + 3] = InColorArray[i].A;
			}
		}

		return Data;
	}

	bool IsTextureDataValid(const FLutTextureData& Data)
	{
		return Data.Data.Num() > 0 && Data.Resolution > 0;
	}
} // namespace

void UOculusXRPassthroughColorLut::SetLutFromArray(const TArray<FColor>& InColorArray, bool InIgnoreAlphaChannel)
{
	const int32 Size = InColorArray.Num();
	const int32 Resolution = FPlatformMath::RoundToInt(FPlatformMath::Pow(Size, 1.0 / 3));
	if (Resolution > GetMaxResolution())
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Setting array ignored: Resoluton is exceeding maximum resoluton of %d."), GetMaxResolution());
		return;
	}
	if (Resolution * Resolution * Resolution != Size)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Setting array ignored: Provided array size is not cube."));
		return;
	}

	/* Check if size if power of 2 */
	if ((Size & (Size - 1)) != 0)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Setting array ignored: Provided array does not result in a resolution that is a power of two."));
		return;
	}

	ColorLutType = EColorLutType::Array;

	const TArray<uint8>& Data = ColorArrayToColorData(InColorArray, InIgnoreAlphaChannel);

	if (LutHandle == 0)
	{
		LutHandle = CreateLutObject(Data, Resolution);
		return;
	}

	if (InIgnoreAlphaChannel == IgnoreAlphaChannel && Resolution == ColorArrayResolution)
	{
		UpdateLutObject(LutHandle, Data);
		return;
	}

	DestroyLutObject(LutHandle);
	LutHandle = CreateLutObject(Data, Resolution);

	IgnoreAlphaChannel = InIgnoreAlphaChannel;
	ColorArrayResolution = Resolution;
}

uint64 UOculusXRPassthroughColorLut::GetHandle(UOculusXRPassthroughLayerBase* LayerRef)
{
	if (LutHandle == 0 && ColorLutType == EColorLutType::TextureLUT && IsTextureDataValid(StoredTextureData))
	{
		LutHandle = CreateLutObject(StoredTextureData.Data, StoredTextureData.Resolution);
	}

	// Add layer to reference list
	LayerRefs.AddUnique(LayerRef->GetUniqueID());

	return LutHandle;
}

void UOculusXRPassthroughColorLut::PreSave(FObjectPreSaveContext ObjectSaveContext)
{
	Super::PreSave(ObjectSaveContext);
#if WITH_EDITOR
	StoredTextureData = TextureToColorData(LutTexture);
#endif
}

void UOculusXRPassthroughColorLut::RemoveReference(UOculusXRPassthroughLayerBase* LayerRef)
{
	LayerRefs.Remove(LayerRef->GetUniqueID());

	if (LayerRefs.Num() == 0)
	{
		DestroyLutObject(LutHandle);
		LutHandle = 0;
	}
}

FLutTextureData UOculusXRPassthroughColorLut::TextureToColorData(class UTexture2D* InLutTexture) const
{

	if (ColorLutType != EColorLutType::TextureLUT)
	{
		return FLutTextureData();
	}

	if (InLutTexture == nullptr)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Ignoring provided LUT texture. Provided texture is NULL."));
		return FLutTextureData();
	}

	if (InLutTexture->LODGroup != TextureGroup::TEXTUREGROUP_ColorLookupTable)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Ignoring provided LUT texture. Provided texture is not LUT texture."));
		return FLutTextureData();
	}

	if (InLutTexture->GetPlatformData()->Mips.Num() <= 0)
	{
		if (IsTextureDataValid(StoredTextureData))
		{
			// We do not need to save it again. Use previously saved data.
			return StoredTextureData;
		}
		return FLutTextureData();
	}

	const uint32 TextureWidth = InLutTexture->GetImportedSize().X;
	const uint32 TextureHeight = InLutTexture->GetImportedSize().Y;

	uint32 ColorMapSize;
	uint32 SlicesPerRow;

	if (TextureWidth == TextureHeight)
	{
		float EdgeLength = FPlatformMath::Pow(TextureWidth, 2.0f / 3.0f);
		ColorMapSize = FPlatformMath::RoundToInt(EdgeLength);
		if (FPlatformMath::Abs(EdgeLength - ColorMapSize) > ZERO_ANIMWEIGHT_THRESH)
		{
			UE_LOG(LogOculusPassthrough, Warning, TEXT("LUT width and height are equal but don't correspond to an 'exploded cube'"));
			return FLutTextureData();
		}

		SlicesPerRow = FPlatformMath::Sqrt(ColorMapSize * 1.0f);
	}
	else
	{
		if (TextureWidth != TextureHeight * TextureHeight)
		{
			UE_LOG(LogOculusPassthrough, Warning, TEXT("For rectangular LUTs, the width is expected to be equal to edgeLength^2"));
			return FLutTextureData();
		}
		ColorMapSize = TextureHeight;
		SlicesPerRow = TextureHeight;
	}

	FTexture2DMipMap& MipMap = InLutTexture->GetPlatformData()->Mips[0];
	FByteBulkData* BulkData = &MipMap.BulkData;
	const FColor* FormatedImageData = reinterpret_cast<const FColor*>(BulkData->Lock(LOCK_READ_ONLY));

	TArray<FColor> Colors;
	Colors.SetNum(ColorMapSize * ColorMapSize * ColorMapSize);

	for (uint32 bi = 0; bi < ColorMapSize; bi++)
	{
		uint32 bi_row = bi % SlicesPerRow;
		uint32 bi_col = bi / SlicesPerRow;
		for (uint32 gi = 0; gi < ColorMapSize; gi++)
		{
			for (uint32 ri = 0; ri < ColorMapSize; ri++)
			{
				uint32 sX = ri + bi_row * ColorMapSize;
				uint32 sY = gi + bi_col * ColorMapSize;
				Colors[bi * ColorMapSize * ColorMapSize + gi * ColorMapSize + ri] = FormatedImageData[sX + sY * TextureWidth];
			}
		}
	}
	BulkData->Unlock();
	return FLutTextureData(ColorArrayToColorData(Colors, IgnoreAlphaChannel), ColorMapSize);
}

uint64 UOculusXRPassthroughColorLut::CreateLutObject(const TArray<uint8>& InData, uint32 Resolution) const
{
	ovrpPassthroughColorLutData OVRPData;
	OVRPData.Buffer = InData.GetData();
	OVRPData.BufferSize = InData.Num();
	const EColorLutChannels Channels = IgnoreAlphaChannel ? EColorLutChannels::ColorLutChannels_RGB : EColorLutChannels::ColorLutChannels_RGBA;
	ovrpPassthroughColorLut Handle;
	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().CreatePassthroughColorLut(
			ToOVRPColorLutChannels(Channels),
			Resolution,
			OVRPData,
			&Handle)))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed creating passthrough color lut."));
		return 0;
	}
	return Handle;
}

void UOculusXRPassthroughColorLut::UpdateLutObject(uint64 Handle, const TArray<uint8>& InData) const
{
	if (Handle == 0)
	{
		return;
	}

	ovrpPassthroughColorLutData OVRPData;
	OVRPData.Buffer = InData.GetData();
	OVRPData.BufferSize = InData.Num();

	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().UpdatePassthroughColorLut(
			Handle,
			OVRPData)))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed updating passthrough color lut data."));
		return;
	}
}

void UOculusXRPassthroughColorLut::DestroyLutObject(uint64 Handle) const
{
	if (Handle == 0)
	{
		return;
	}
	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().DestroyPassthroughColorLut(Handle)))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to destroy passthrough color lut."));
	}
}

void UOculusXRPassthroughColorLut::BeginDestroy()
{
	Super::BeginDestroy();
	DestroyLutObject(LutHandle);
	LutHandle = 0;
}

int UOculusXRPassthroughColorLut::GetMaxResolution()
{
	if (MaxResolution > -1)
	{
		return MaxResolution;
	}

	ovrpInsightPassthroughCapabilities PassthroughCapabilites;
	PassthroughCapabilites.Fields =
		static_cast<ovrpInsightPassthroughCapabilityFields>(
			ovrpInsightPassthroughCapabilityFields::ovrpInsightPassthroughCapabilityFields_Flags | ovrpInsightPassthroughCapabilityFields::ovrpInsightPassthroughCapabilityFields_MaxColorLutResolution);

	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetPassthroughCapabilities(&PassthroughCapabilites)))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to fetch passthrough capabilities."));
		// Default MAX resoulution is 64.
		return 64;
	}
	MaxResolution = PassthroughCapabilites.MaxColorLutResolution;
	return MaxResolution;
}
