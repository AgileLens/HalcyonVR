// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRStereoLayersFlagsSupplier.h"
#include "IStereoLayers.h"
#include "OVR_Plugin_Types.h"

TSharedPtr<FOculusXRStereoLayersFlagsSupplier> FOculusXRStereoLayersFlagsSupplier::Instance = NULL;

TSharedPtr<FOculusXRStereoLayersFlagsSupplier> FOculusXRStereoLayersFlagsSupplier::Get()
{
	if (!Instance.IsValid())
	{
		Instance = MakeShared<FOculusXRStereoLayersFlagsSupplier>();
	}

	return Instance;
}

FOculusXRStereoLayersFlagsSupplier::FOculusXRStereoLayersFlagsSupplier()
{
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	uint32 Value = IStereoLayers::ELayerFlags::LAYER_FLAG_MAX_VALUE << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerFlag_BicubicFiltering);
	SupportedFilters.Add(FName("Bicubic Filtering"));

	Value = Value << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerSubmitFlag_AutoLayerFilter);
	SupportedFilters.Add(FName("Auto Filtering"));

	Value = Value << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerSubmitFlag_EfficientSuperSample);
	SupportedFilters.Add(FName("Normal SuperSampling"));

	Value = Value << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerSubmitFlag_ExpensiveSuperSample);
	SupportedFilters.Add(FName("Quality SuperSampling"));

	Value = Value << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerSubmitFlag_EfficientSharpen);
	SupportedFilters.Add(FName("Normal Sharpening"));

	Value = Value << 1;
	UnrealFlagValOvrpFlagValMap.Add(Value, ovrpLayerSubmitFlag_QualitySharpen);
	SupportedFilters.Add(FName("Quality Sharpening"));
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)
}

int FOculusXRStereoLayersFlagsSupplier::GetOvrpFlag(uint32 DescFlags, bool bMQSR)
{
	int LayerSubmitFlags = 0;
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	for (auto& FlagPair : UnrealFlagValOvrpFlagValMap)
	{
		if (bMQSR && FlagPair.Value == ovrpLayerFlag_BicubicFiltering)
		{
			continue;
		}
		else if (!bMQSR && FlagPair.Value != ovrpLayerFlag_BicubicFiltering)
		{
			continue;
		}

		if (DescFlags & FlagPair.Key)
		{
			LayerSubmitFlags |= FlagPair.Value;
		}
	}

	if (bMQSR)
	{ // validate if autofilter conflicts with supersampling and sharpening
		bool bAutoFiltering = LayerSubmitFlags & ovrpLayerSubmitFlag_AutoLayerFilter;
		bool bSuperSamplingType = ((LayerSubmitFlags & ovrpLayerSubmitFlag_EfficientSuperSample) || (LayerSubmitFlags & ovrpLayerSubmitFlag_ExpensiveSuperSample));
		bool bSSharpenType = ((LayerSubmitFlags & ovrpLayerSubmitFlag_EfficientSharpen) || (LayerSubmitFlags & ovrpLayerSubmitFlag_QualitySharpen));

		if (!bAutoFiltering && bSuperSamplingType && bSSharpenType)
		{
			UE_LOG(LogTemp, Error, TEXT("XR sharpening and supersampling cannot be enabled simultaneously.\n Either enable autofiltering or disable one of the options."));
			return 0;
		}
	}
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

	return LayerSubmitFlags;
}
