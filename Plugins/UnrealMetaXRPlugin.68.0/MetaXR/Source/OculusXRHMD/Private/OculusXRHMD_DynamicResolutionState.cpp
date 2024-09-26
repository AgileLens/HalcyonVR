// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_DynamicResolutionState.h"
#include "LegacyScreenPercentageDriver.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "SceneView.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FDynamicResolutionState implementation
	//-------------------------------------------------------------------------------------------------

	FDynamicResolutionState::FDynamicResolutionState(const OculusXRHMD::FSettingsPtr InSettings)
		: Settings(InSettings)
		, ResolutionFraction(-1.0f)
		, ResolutionFractionUpperBound(-1.0f)
	{
		check(Settings.IsValid());
	}

	void FDynamicResolutionState::ResetHistory() {
		// Empty - Oculus drives resolution fraction externally
	};

	bool FDynamicResolutionState::IsSupported() const
	{
		return true;
	}

	void FDynamicResolutionState::SetupMainViewFamily(class FSceneViewFamily& ViewFamily)
	{
		check(IsInGameThread());
		check(ViewFamily.EngineShowFlags.ScreenPercentage == true);

		if (IsEnabled())
		{
			// Compute desired resolution fraction range
			float MinResolutionFraction = Settings->PixelDensityMin;
			float MaxResolutionFraction = Settings->PixelDensityMax;

			// Clamp resolution fraction to what the renderer can do.
			MinResolutionFraction = FMath::Max(MinResolutionFraction, ISceneViewFamilyScreenPercentage::kMinResolutionFraction);
			MaxResolutionFraction = FMath::Min(MaxResolutionFraction, ISceneViewFamilyScreenPercentage::kMaxResolutionFraction);

			ResolutionFraction = FMath::Clamp(Settings->PixelDensity, MinResolutionFraction, MaxResolutionFraction);
			ResolutionFractionUpperBound = MaxResolutionFraction;

			ViewFamily.SetScreenPercentageInterface(new FLegacyScreenPercentageDriver(ViewFamily, ResolutionFraction, ResolutionFractionUpperBound));
		}
	}
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	void FDynamicResolutionState::SetTemporalUpscaler(const UE::Renderer::Private::ITemporalUpscaler* InTemporalUpscaler)
	{
		// Not supported
		return;
	}
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

	DynamicRenderScaling::TMap<float> FDynamicResolutionState::GetResolutionFractionsApproximation() const
	{
		DynamicRenderScaling::TMap<float> ResolutionFractions;
		ResolutionFractions.SetAll(1.0f);
		ResolutionFractions[GDynamicPrimaryResolutionFraction] = ResolutionFraction;
		return ResolutionFractions;
	}

	DynamicRenderScaling::TMap<float> FDynamicResolutionState::GetResolutionFractionsUpperBound() const
	{
		DynamicRenderScaling::TMap<float> ResolutionFractions;
		ResolutionFractions.SetAll(1.0f);
		ResolutionFractions[GDynamicPrimaryResolutionFraction] = ResolutionFractionUpperBound;
		return ResolutionFractionUpperBound;
	}

	void FDynamicResolutionState::SetEnabled(bool bEnable)
	{
		check(IsInGameThread());
		Settings->Flags.bPixelDensityAdaptive = bEnable;
	}

	bool FDynamicResolutionState::IsEnabled() const
	{
		check(IsInGameThread());
		return Settings->Flags.bPixelDensityAdaptive;
	}

	void FDynamicResolutionState::ProcessEvent(EDynamicResolutionStateEvent Event) {
		// Empty - Oculus drives resolution fraction externally
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
