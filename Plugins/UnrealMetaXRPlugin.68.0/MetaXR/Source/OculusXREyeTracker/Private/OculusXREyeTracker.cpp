// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "IEyeTrackerModule.h"
#include "EyeTrackerTypes.h"
#include "IEyeTracker.h"
#include "Modules/ModuleManager.h"

#include "GameFramework/WorldSettings.h"
#include "Engine/World.h"
#include "IXRTrackingSystem.h"
#include "Engine/Engine.h"

#include "OculusXRHMDModule.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRTelemetryEyeTrackerEvents.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS

namespace OculusXRHMD
{
	class FOculusXREyeTracker : public IEyeTracker
	{
	public:
		FOculusXREyeTracker()
		{
			GetUnitScaleFactorFromSettings(GWorld, WorldToMeters);
			if (GEngine != nullptr)
			{
				OculusXRHMD = GEngine->XRSystem.Get();
			}
			OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FMovementSDKEyeTrackerCreated>();
		}

		virtual ~FOculusXREyeTracker()
		{
			if (bIsTrackerStarted)
			{
				ensureMsgf(OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StopEyeTracking()), TEXT("Cannot stop eye tracker."));
			}
		}

	private:
		// IEyeTracker
		virtual void SetEyeTrackedPlayer(APlayerController*) override
		{
			unimplemented();
		}

		virtual bool GetEyeTrackerGazeData(FEyeTrackerGazeData& OutGazeData) const override
		{
			return ReactOnEyeTrackerState([this, &OutGazeData](const ovrpEyeGazesState& OVREyeGazesState, const FTransform& TrackingToWorld) {
				OutGazeData.FixationPoint = GetFixationPoint(OVREyeGazesState);
				OutGazeData.ConfidenceValue = MergeConfidence(OVREyeGazesState);

				OutGazeData.GazeDirection = TrackingToWorld.TransformVector(MergeOrientation(OVREyeGazesState).GetForwardVector());
				OutGazeData.GazeOrigin = TrackingToWorld.TransformPosition(MergePosition(OVREyeGazesState) * WorldToMeters);
			});
		}

		virtual bool GetEyeTrackerStereoGazeData(FEyeTrackerStereoGazeData& OutGazeData) const override
		{
			return ReactOnEyeTrackerState([this, &OutGazeData](const ovrpEyeGazesState& OVREyeGazesState, const FTransform& TrackingToWorld) {
				OutGazeData.FixationPoint = GetFixationPoint(OVREyeGazesState);
				OutGazeData.ConfidenceValue = MergeConfidence(OVREyeGazesState);

				const auto& LeftEyePose = OVREyeGazesState.EyeGazes[ovrpEye_Left].Pose;
				const auto& RightEyePose = OVREyeGazesState.EyeGazes[ovrpEye_Right].Pose;
				OutGazeData.LeftEyeDirection = TrackingToWorld.TransformVector(OculusXRHMD::ToFQuat(LeftEyePose.Orientation).GetForwardVector());
				OutGazeData.RightEyeDirection = TrackingToWorld.TransformVector(OculusXRHMD::ToFQuat(RightEyePose.Orientation).GetForwardVector());
				OutGazeData.LeftEyeOrigin = TrackingToWorld.TransformPosition(OculusXRHMD::ToFVector(LeftEyePose.Position) * WorldToMeters);
				OutGazeData.RightEyeOrigin = TrackingToWorld.TransformPosition(OculusXRHMD::ToFVector(RightEyePose.Position) * WorldToMeters);
			});
		}

		virtual EEyeTrackerStatus GetEyeTrackerStatus() const override
		{
			ovrpBool IsSupported = ovrpBool_False;
			ovrpBool IsEnabled = ovrpBool_False;
			const ovrpResult TrackingSupportedResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&IsSupported);
			const ovrpResult TrackingEnabledResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeTrackingEnabled(&IsEnabled);
			if (OVRP_SUCCESS(TrackingSupportedResult) && OVRP_SUCCESS(TrackingEnabledResult))
			{
				if ((IsSupported == ovrpBool_True) && (IsEnabled == ovrpBool_True))
				{
					return EEyeTrackerStatus::Tracking;
				}
				if (IsSupported == ovrpBool_True)
				{
					return EEyeTrackerStatus::NotTracking;
				}
			}

			return EEyeTrackerStatus::NotConnected;
		}

		virtual bool IsStereoGazeDataAvailable() const override
		{
			return true;
		}

	private:
		// FOculusXREyeTracker
		template <typename ReactOnState>
		bool ReactOnEyeTrackerState(ReactOnState&& React) const
		{
			if (!bIsTrackerStarted)
			{
				bIsTrackerStarted = OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartEyeTracking());
			}

			if (bIsTrackerStarted)
			{
				ovrpEyeGazesState OVREyeGazesState;
				const ovrpResult OVREyeGazesStateResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeGazesState(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, &OVREyeGazesState);
				checkf(OVREyeGazesStateResult != ovrpFailure_NotYetImplemented, TEXT("Eye tracking is not implemented on this platform."));

				if (OVRP_SUCCESS(OVREyeGazesStateResult) && IsStateValidForBothEyes(OVREyeGazesState))
				{
					FTransform TrackingToWorld = OculusXRHMD ? OculusXRHMD->GetTrackingToWorldTransform() : FTransform::Identity;
					React(OVREyeGazesState, TrackingToWorld);

					return true;
				}
			}

			return false;
		}

		static float IsStateValidForBothEyes(const ovrpEyeGazesState& OVREyeGazesState)
		{
			return OVREyeGazesState.EyeGazes[ovrpEye_Left].IsValid && OVREyeGazesState.EyeGazes[ovrpEye_Right].IsValid;
		}

		static float MergeConfidence(const ovrpEyeGazesState& OVREyeGazesState)
		{
			const auto& LeftEyeConfidence = OVREyeGazesState.EyeGazes[ovrpEye_Left].Confidence;
			const auto& RightEyeConfidence = OVREyeGazesState.EyeGazes[ovrpEye_Right].Confidence;
			return FGenericPlatformMath::Min(LeftEyeConfidence, RightEyeConfidence);
		}

		/// Warn: The result of MergedOrientation is not normalized.
		static FQuat MergeOrientation(const ovrpEyeGazesState& OVREyeGazesState)
		{
			const auto& LeftEyeOrientation = OculusXRHMD::ToFQuat(OVREyeGazesState.EyeGazes[ovrpEye_Left].Pose.Orientation);
			const auto& RightEyeOrientation = OculusXRHMD::ToFQuat(OVREyeGazesState.EyeGazes[ovrpEye_Right].Pose.Orientation);
			return FQuat::FastLerp(LeftEyeOrientation, RightEyeOrientation, 0.5f);
		}

		static FVector MergePosition(const ovrpEyeGazesState& OVREyeGazesState)
		{
			const auto& LeftEyePosition = OculusXRHMD::ToFVector(OVREyeGazesState.EyeGazes[ovrpEye_Left].Pose.Position);
			const auto& RightEyePosition = OculusXRHMD::ToFVector(OVREyeGazesState.EyeGazes[ovrpEye_Right].Pose.Position);
			return (LeftEyePosition + RightEyePosition) / 2.f;
		}

		static FVector GetFixationPoint(const ovrpEyeGazesState& OVREyeGazesState)
		{
			return FVector::ZeroVector; // Not supported
		}

		float WorldToMeters = 100.f;
		IXRTrackingSystem* OculusXRHMD = nullptr;
		mutable bool bIsTrackerStarted = false;
	};
} // namespace OculusXRHMD
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

class FOculusXREyeTrackerModule : public IEyeTrackerModule
{
public:
	static inline FOculusXREyeTrackerModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FOculusXREyeTrackerModule>("OculusXREyeTracker");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("OculusXREyeTracker");
	}

	virtual FString GetModuleKeyName() const override
	{
		return TEXT("OculusXREyeTracker");
	}

	virtual bool IsEyeTrackerConnected() const override
	{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
		if (FOculusXRHMDModule::Get().IsOVRPluginAvailable() && FOculusXRHMDModule::GetPluginWrapper().IsInitialized())
		{
			ovrpBool IsSupported = ovrpBool_False;
			const ovrpResult trackingSupportedResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&IsSupported);
			if (OVRP_SUCCESS(trackingSupportedResult))
			{
				return (IsSupported == ovrpBool_True);
			}
		}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
		return false;
	}

	virtual TSharedPtr<class IEyeTracker, ESPMode::ThreadSafe> CreateEyeTracker() override
	{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
		if (FOculusXRHMDModule::Get().IsOVRPluginAvailable() && FOculusXRHMDModule::GetPluginWrapper().IsInitialized())
		{
			return MakeShared<OculusXRHMD::FOculusXREyeTracker>();
		}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
		return TSharedPtr<class IEyeTracker, ESPMode::ThreadSafe>();
	}
};

IMPLEMENT_MODULE(FOculusXREyeTrackerModule, OculusXREyeTracker)
