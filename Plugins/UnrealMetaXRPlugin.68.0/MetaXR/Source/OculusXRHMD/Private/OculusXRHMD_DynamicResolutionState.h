// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_Settings.h"
#include "DynamicResolutionState.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FDynamicResolutionState
	//-------------------------------------------------------------------------------------------------

	class FDynamicResolutionState : public IDynamicResolutionState
	{
	public:
		FDynamicResolutionState(const OculusXRHMD::FSettingsPtr InSettings);

		// ISceneViewFamilyScreenPercentage
		virtual void ResetHistory() override;
		virtual bool IsSupported() const override;
		virtual void SetupMainViewFamily(class FSceneViewFamily& ViewFamily) override;
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
		virtual void SetTemporalUpscaler(const UE::Renderer::Private::ITemporalUpscaler* InTemporalUpscaler) override;
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

	protected:
		virtual DynamicRenderScaling::TMap<float> GetResolutionFractionsApproximation() const override;
		virtual DynamicRenderScaling::TMap<float> GetResolutionFractionsUpperBound() const override;
		virtual void SetEnabled(bool bEnable) override;
		virtual bool IsEnabled() const override;
		virtual void ProcessEvent(EDynamicResolutionStateEvent Event) override;

	private:
		const OculusXRHMD::FSettingsPtr Settings;
		float ResolutionFraction;
		float ResolutionFractionUpperBound;
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
