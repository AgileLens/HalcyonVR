// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRFunctionLibraryOVR.h"

#include "OculusXRHMD.h"

namespace OculusXRHMD
{
	void FOculusXRFunctionLibraryOVR::GetPose(FRotator& DeviceRotation, FVector& DevicePosition, FVector& NeckPosition)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD && OculusXRHMD->IsHeadTrackingAllowed())
		{
			FQuat HeadOrientation = FQuat::Identity;
			FVector HeadPosition = FVector::ZeroVector;
			OculusXRHMD->GetCurrentPose(OculusXRHMD->HMDDeviceId, HeadOrientation, HeadPosition);
			DeviceRotation = HeadOrientation.Rotator();
			DevicePosition = HeadPosition;
			NeckPosition = OculusXRHMD->GetNeckPosition(HeadOrientation, HeadPosition);
		}
		else
		{
			DeviceRotation = FRotator::ZeroRotator;
			DevicePosition = FVector::ZeroVector;
			NeckPosition = FVector::ZeroVector;
		}
	}

	void FOculusXRFunctionLibraryOVR::SetBaseRotationAndBaseOffsetInMeters(FRotator Rotation, FVector BaseOffsetInMeters, EOrientPositionSelector::Type Options)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			if ((Options == EOrientPositionSelector::Orientation) || (Options == EOrientPositionSelector::OrientationAndPosition))
			{
				OculusXRHMD->SetBaseRotation(Rotation);
			}
			if ((Options == EOrientPositionSelector::Position) || (Options == EOrientPositionSelector::OrientationAndPosition))
			{
				OculusXRHMD->SetBaseOffsetInMeters(BaseOffsetInMeters);
			}
		}
	}

	void FOculusXRFunctionLibraryOVR::GetBaseRotationAndBaseOffsetInMeters(FRotator& OutRotation, FVector& OutBaseOffsetInMeters)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OutRotation = OculusXRHMD->GetBaseRotation();
			OutBaseOffsetInMeters = OculusXRHMD->GetBaseOffsetInMeters();
		}
		else
		{
			OutRotation = FRotator::ZeroRotator;
			OutBaseOffsetInMeters = FVector::ZeroVector;
		}
	}

	void FOculusXRFunctionLibraryOVR::GetRawSensorData(FVector& AngularAcceleration, FVector& LinearAcceleration, FVector& AngularVelocity, FVector& LinearVelocity, float& TimeInSeconds, EOculusXRTrackedDeviceType DeviceType)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			ovrpPoseStatef state;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, OculusXRHMD::ToOvrpNode(DeviceType), &state)))
			{
				AngularAcceleration = OculusXRHMD::ToFVector(state.AngularAcceleration);
				LinearAcceleration = OculusXRHMD::ToFVector(state.Acceleration);
				AngularVelocity = OculusXRHMD::ToFVector(state.AngularVelocity);
				LinearVelocity = OculusXRHMD::ToFVector(state.Velocity);
				TimeInSeconds = state.Time;
			}
		}
	}

	bool FOculusXRFunctionLibraryOVR::IsDeviceTracked(EOculusXRTrackedDeviceType DeviceType)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			ovrpBool Present;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodePresent2(OculusXRHMD::ToOvrpNode(DeviceType), &Present)))
			{
				return Present != ovrpBool_False;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	void FOculusXRFunctionLibraryOVR::GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			OculusXRHMD->GetSuggestedCpuAndGpuPerformanceLevels(CpuPerfLevel, GpuPerfLevel);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			OculusXRHMD->SetSuggestedCpuAndGpuPerformanceLevels(CpuPerfLevel, GpuPerfLevel);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetCPUAndGPULevels(int CPULevel, int GPULevel)
	{
		// Deprecated. Please use Get/SetSuggestedCpuAndGpuPerformanceLevels instead.
	}

	bool FOculusXRFunctionLibraryOVR::GetUserProfile(FOculusXRHmdUserProfile& Profile)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD::FOculusXRHMD::UserProfile Data;
			if (OculusXRHMD->GetUserProfile(Data))
			{
				Profile.Name = "";
				Profile.Gender = "Unknown";
				Profile.PlayerHeight = 0.0f;
				Profile.EyeHeight = Data.EyeHeight;
				Profile.IPD = Data.IPD;
				Profile.NeckToEyeDistance = FVector2D(Data.EyeDepth, 0.0f);
				return true;
			}
		}
		return false;
	}

	void FOculusXRFunctionLibraryOVR::SetBaseRotationAndPositionOffset(FRotator BaseRot, FVector PosOffset, EOrientPositionSelector::Type Options)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			if (Options == EOrientPositionSelector::Orientation || Options == EOrientPositionSelector::OrientationAndPosition)
			{
				OculusXRHMD->SetBaseRotation(BaseRot);
			}
		}
	}

	void FOculusXRFunctionLibraryOVR::GetBaseRotationAndPositionOffset(FRotator& OutRot, FVector& OutPosOffset)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OutRot = OculusXRHMD->GetBaseRotation();
			OutPosOffset = FVector::ZeroVector;
		}
	}

	void FOculusXRFunctionLibraryOVR::AddLoadingSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters, FRotator DeltaRotation, bool bClearBeforeAdd)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD::FSplash* Splash = OculusXRHMD->GetSplash();
			if (Splash)
			{
				if (bClearBeforeAdd)
				{
					Splash->ClearSplashes();
				}

				FOculusXRSplashDesc Desc;
				Desc.LoadingTexture = Texture;
				Desc.QuadSizeInMeters = SizeInMeters;
				Desc.TransformInMeters = FTransform(Rotation, TranslationInMeters);
				Desc.DeltaRotation = FQuat(DeltaRotation);
				Splash->AddSplash(Desc);
			}
		}
	}

	void FOculusXRFunctionLibraryOVR::ClearLoadingSplashScreens()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD::FSplash* Splash = OculusXRHMD->GetSplash();
			if (Splash)
			{
				Splash->ClearSplashes();
			}
		}
	}

	bool FOculusXRFunctionLibraryOVR::HasInputFocus()
	{
		const OculusXRHMD::FOculusXRHMD* const OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			ovrpBool HasFocus;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppHasInputFocus(&HasFocus)))
			{
				return HasFocus != ovrpBool_False;
			}
		}
		return false;
	}

	bool FOculusXRFunctionLibraryOVR::HasSystemOverlayPresent()
	{
		const OculusXRHMD::FOculusXRHMD* const OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr && OculusXRHMD->IsHMDActive())
		{
			ovrpBool HasFocus;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppHasInputFocus(&HasFocus)))
			{
				return HasFocus == ovrpBool_False;
			}
		}
		return false;
	}

	void FOculusXRFunctionLibraryOVR::GetGPUUtilization(bool& IsGPUAvailable, float& GPUUtilization)
	{
		GPUUtilization = 0.0f;
		const OculusXRHMD::FOculusXRHMD* const OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool bIsSupported = ovrpBool_False;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_System_GpuUtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
			{
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_System_GpuUtilPercentage_Float, &GPUUtilization)))
				{
					IsGPUAvailable = true;
					GPUUtilization *= 100;
				}
			}
		}
	}

	float FOculusXRFunctionLibraryOVR::GetGPUFrameTime()
	{
		float FrameTime = 0;
		const OculusXRHMD::FOculusXRHMD* const OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool bIsSupported = ovrpBool_False;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_App_GpuTime_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
			{
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_App_GpuTime_Float, &FrameTime)))
				{
					return FrameTime * 1000;
				}
			}
		}
		return 0.0f;
	}

	void FOculusXRFunctionLibraryOVR::GetPerformanceMetrics(FOculusXRPerformanceMetrics& PerformanceMetrics)
	{
		const OculusXRHMD::FOculusXRHMD* const OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			PerformanceMetrics = OculusXRHMD->GetPerformanceMetrics();
		}
	}


	EOculusXRFoveatedRenderingMethod FOculusXRFunctionLibraryOVR::GetFoveatedRenderingMethod()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool enabled;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetFoveationEyeTracked(&enabled)))
			{
				return enabled == ovrpBool_True ? EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering : EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering;
			}
		}
		return EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering;
	}

	void FOculusXRFunctionLibraryOVR::SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod Method)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->SetFoveatedRenderingMethod(Method);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel level, bool isDynamic)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->SetFoveatedRenderingLevel(level, isDynamic);
		}
	}

	EOculusXRFoveatedRenderingLevel FOculusXRFunctionLibraryOVR::GetFoveatedRenderingLevel()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpTiledMultiResLevel Lvl;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetTiledMultiResLevel(&Lvl)))
			{
				return (EOculusXRFoveatedRenderingLevel)Lvl;
			}
		}
		return EOculusXRFoveatedRenderingLevel::Off;
	}

	bool FOculusXRFunctionLibraryOVR::GetEyeTrackedFoveatedRenderingSupported()
	{
		// Always return false on other engine releases, since they don't have FDM offset support
#ifdef WITH_OCULUS_BRANCH
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool Supported;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetFoveationEyeTrackedSupported(&Supported)))
			{
				return Supported == ovrpBool_True;
			}
		}
#endif // WITH_OCULUS_BRANCH
		return false;
	}

	FString FOculusXRFunctionLibraryOVR::GetDeviceName()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			const char* NameString;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetSystemProductName2(&NameString)) && NameString)
			{
				return FString(NameString);
			}
		}
		return FString();
	}

	EOculusXRDeviceType FOculusXRFunctionLibraryOVR::GetDeviceType()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			if (OculusXRHMD->GetSettings())
			{
				switch (OculusXRHMD->GetSettings()->SystemHeadset)
				{
					case ovrpSystemHeadset_Oculus_Quest:
						return EOculusXRDeviceType::OculusQuest_Deprecated;
					case ovrpSystemHeadset_Oculus_Quest_2:
						return EOculusXRDeviceType::OculusQuest2;
					case ovrpSystemHeadset_Meta_Quest_Pro:
						return EOculusXRDeviceType::MetaQuestPro;
					case ovrpSystemHeadset_Meta_Quest_3:
						return EOculusXRDeviceType::MetaQuest3;
					case ovrpSystemHeadset_Rift_CV1:
						return EOculusXRDeviceType::Rift;
					case ovrpSystemHeadset_Rift_S:
						return EOculusXRDeviceType::Rift_S;
					case ovrpSystemHeadset_Oculus_Link_Quest:
						return EOculusXRDeviceType::Quest_Link_Deprecated;
					case ovrpSystemHeadset_Oculus_Link_Quest_2:
						return EOculusXRDeviceType::Quest2_Link;
					case ovrpSystemHeadset_Meta_Link_Quest_Pro:
						return EOculusXRDeviceType::MetaQuestProLink;
					case ovrpSystemHeadset_Meta_Link_Quest_3:
						return EOculusXRDeviceType::MetaQuest3Link;
					default:
						break;
				}
			}
		}
		return EOculusXRDeviceType::OculusUnknown;
	}

	EOculusXRControllerType FOculusXRFunctionLibraryOVR::GetControllerType(EControllerHand deviceHand)
	{
		auto getOVRPHand = [](EControllerHand hand) {
			switch (hand)
			{
				case EControllerHand::Left:
					return ovrpHand::ovrpHand_Left;
				case EControllerHand::Right:
					return ovrpHand::ovrpHand_Right;
				default:
					break;
			}
			return ovrpHand::ovrpHand_None;
		};

		auto getEControllerType = [](ovrpInteractionProfile profile) {
			switch (profile)
			{
				case ovrpInteractionProfile::ovrpInteractionProfile_Touch:
					return EOculusXRControllerType::MetaQuestTouch;
				case ovrpInteractionProfile::ovrpInteractionProfile_TouchPro:
					return EOculusXRControllerType::MetaQuestTouchPro;
				case ovrpInteractionProfile::ovrpInteractionProfile_TouchPlus:
					return EOculusXRControllerType::MetaQuestTouchPlus;
				default:
					break;
			}
			return EOculusXRControllerType::None;
		};

		ovrpInteractionProfile interactionProfile = ovrpInteractionProfile::ovrpInteractionProfile_None;
		ovrpHand hand = getOVRPHand(deviceHand);
		if (hand == ovrpHand::ovrpHand_None)
			return EOculusXRControllerType::Unknown;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetCurrentInteractionProfile(hand, &interactionProfile)))
		{
			return getEControllerType(interactionProfile);
		}
		return EOculusXRControllerType::Unknown;
	}

	TArray<float> FOculusXRFunctionLibraryOVR::GetAvailableDisplayFrequencies()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			int NumberOfFrequencies;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetSystemDisplayAvailableFrequencies(nullptr, &NumberOfFrequencies)))
			{
				TArray<float> freqArray;
				freqArray.SetNum(NumberOfFrequencies);
				FOculusXRHMDModule::GetPluginWrapper().GetSystemDisplayAvailableFrequencies(freqArray.GetData(), &NumberOfFrequencies);
				return freqArray;
			}
		}
		return TArray<float>();
	}

	float FOculusXRFunctionLibraryOVR::GetCurrentDisplayFrequency()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			float Frequency;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetSystemDisplayFrequency2(&Frequency)))
			{
				return Frequency;
			}
		}
		return 0.0f;
	}

	void FOculusXRFunctionLibraryOVR::SetDisplayFrequency(float RequestedFrequency)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			FOculusXRHMDModule::GetPluginWrapper().SetSystemDisplayFrequency(RequestedFrequency);
		}
	}

	void FOculusXRFunctionLibraryOVR::EnablePositionTracking(bool bPositionTracking)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			FOculusXRHMDModule::GetPluginWrapper().SetTrackingPositionEnabled2(bPositionTracking);
		}
	}

	void FOculusXRFunctionLibraryOVR::EnableOrientationTracking(bool bOrientationTracking)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			FOculusXRHMDModule::GetPluginWrapper().SetTrackingOrientationEnabled2(bOrientationTracking);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->SetColorScaleAndOffset(ColorScale, ColorOffset, bApplyToAllLayers);
		}
	}

	class IStereoLayers* FOculusXRFunctionLibraryOVR::GetStereoLayers()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			return OculusXRHMD;
		}
		return nullptr;
	}

	static ovrpBoundaryType ToOvrpBoundaryType(EOculusXRBoundaryType Source)
	{
		switch (Source)
		{
			case EOculusXRBoundaryType::Boundary_PlayArea:
				return ovrpBoundary_PlayArea;

			case EOculusXRBoundaryType::Boundary_Outer:
			default:
				return ovrpBoundary_Outer;
		}
	}

	bool FOculusXRFunctionLibraryOVR::IsGuardianConfigured()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool boundaryConfigured;
			return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryConfigured2(&boundaryConfigured)) && boundaryConfigured;
		}
		return false;
	}

	bool FOculusXRFunctionLibraryOVR::IsGuardianDisplayed()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool boundaryVisible;
			return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryVisible2(&boundaryVisible)) && boundaryVisible;
		}
		return false;
	}

	TArray<FVector> FOculusXRFunctionLibraryOVR::GetGuardianPoints(EOculusXRBoundaryType BoundaryType, bool UsePawnSpace /* = false */)
	{
		TArray<FVector> BoundaryPointList;
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool bBoundaryConfigured = false;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryConfigured2(&bBoundaryConfigured)) && bBoundaryConfigured)
			{
				ovrpBoundaryType obt = ToOvrpBoundaryType(BoundaryType);
				int NumPoints = 0;

				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryGeometry3(obt, nullptr, &NumPoints)))
				{
					// allocate points
					const int BufferSize = NumPoints;
					ovrpVector3f* BoundaryPoints = new ovrpVector3f[BufferSize];

					if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryGeometry3(obt, BoundaryPoints, &NumPoints)))
					{
						NumPoints = FMath::Min(BufferSize, NumPoints);
						check(NumPoints <= BufferSize); // For static analyzer
						BoundaryPointList.Reserve(NumPoints);

						for (int i = 0; i < NumPoints; i++)
						{
							FVector point;
							if (UsePawnSpace)
							{
								point = OculusXRHMD->ConvertVector_M2U(BoundaryPoints[i]);
							}
							else
							{
								point = OculusXRHMD->ScaleAndMovePointWithPlayer(BoundaryPoints[i]);
							}
							BoundaryPointList.Add(point);
						}
					}

					delete[] BoundaryPoints;
				}
			}
		}
		return BoundaryPointList;
	}

	FVector FOculusXRFunctionLibraryOVR::GetGuardianDimensions(EOculusXRBoundaryType BoundaryType)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBoundaryType obt = ToOvrpBoundaryType(BoundaryType);
			ovrpVector3f Dimensions;

			if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryDimensions2(obt, &Dimensions)))
				return FVector::ZeroVector;

			Dimensions.z *= -1.0;
			return OculusXRHMD->ConvertVector_M2U(Dimensions);
		}
		return FVector::ZeroVector;
	}

	FTransform FOculusXRFunctionLibraryOVR::GetPlayAreaTransform()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool bBoundaryConfigured = false;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryConfigured2(&bBoundaryConfigured)) && bBoundaryConfigured)
			{
				int NumPoints = 4;
				ovrpVector3f BoundaryPoints[4];

				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryGeometry3(ovrpBoundary_PlayArea, BoundaryPoints, &NumPoints)))
				{
					FVector ConvertedPoints[4];

					for (int i = 0; i < NumPoints; i++)
					{
						ConvertedPoints[i] = OculusXRHMD->ScaleAndMovePointWithPlayer(BoundaryPoints[i]);
					}

					float metersScale = OculusXRHMD->GetWorldToMetersScale();

					FVector Edge = ConvertedPoints[1] - ConvertedPoints[0];
					float Angle = FMath::Acos((Edge).GetSafeNormal() | FVector::RightVector);
					FQuat Rotation(FVector::UpVector, Edge.X < 0 ? Angle : -Angle);

					FVector Position = (ConvertedPoints[0] + ConvertedPoints[1] + ConvertedPoints[2] + ConvertedPoints[3]) / 4;
					FVector Scale(FVector::Distance(ConvertedPoints[3], ConvertedPoints[0]) / metersScale, FVector::Distance(ConvertedPoints[1], ConvertedPoints[0]) / metersScale, 1.0);

					return FTransform(Rotation, Position, Scale);
				}
			}
		}
		return FTransform();
	}

	FOculusXRGuardianTestResult FOculusXRFunctionLibraryOVR::GetPointGuardianIntersection(const FVector Point, EOculusXRBoundaryType BoundaryType)
	{
		FOculusXRGuardianTestResult InteractionInfo;
		memset(&InteractionInfo, 0, sizeof(FOculusXRGuardianTestResult));

		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpVector3f OvrpPoint = OculusXRHMD->WorldLocationToOculusPoint(Point);
			ovrpBoundaryType OvrpBoundaryType = ToOvrpBoundaryType(BoundaryType);
			ovrpBoundaryTestResult InteractionResult;

			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().TestBoundaryPoint2(OvrpPoint, OvrpBoundaryType, &InteractionResult)))
			{
				InteractionInfo.IsTriggering = (InteractionResult.IsTriggering != 0);
				InteractionInfo.ClosestDistance = OculusXRHMD->ConvertFloat_M2U(InteractionResult.ClosestDistance);
				InteractionInfo.ClosestPoint = OculusXRHMD->ScaleAndMovePointWithPlayer(InteractionResult.ClosestPoint);
				InteractionInfo.ClosestPointNormal = OculusXRHMD->ConvertVector_M2U(InteractionResult.ClosestPointNormal);
				InteractionInfo.DeviceType = EOculusXRTrackedDeviceType::None;
			}
		}

		return InteractionInfo;
	}

	FOculusXRGuardianTestResult FOculusXRFunctionLibraryOVR::GetNodeGuardianIntersection(EOculusXRTrackedDeviceType DeviceType, EOculusXRBoundaryType BoundaryType)
	{
		FOculusXRGuardianTestResult InteractionInfo;
		memset(&InteractionInfo, 0, sizeof(FOculusXRGuardianTestResult));

		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpNode OvrpNode = OculusXRHMD::ToOvrpNode(DeviceType);
			ovrpBoundaryType OvrpBoundaryType = ToOvrpBoundaryType(BoundaryType);
			ovrpBoundaryTestResult TestResult;

			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().TestBoundaryNode2(OvrpNode, ovrpBoundary_PlayArea, &TestResult)) && TestResult.IsTriggering)
			{
				InteractionInfo.IsTriggering = true;
				InteractionInfo.DeviceType = OculusXRHMD::ToEOculusXRTrackedDeviceType(OvrpNode);
				InteractionInfo.ClosestDistance = OculusXRHMD->ConvertFloat_M2U(TestResult.ClosestDistance);
				InteractionInfo.ClosestPoint = OculusXRHMD->ScaleAndMovePointWithPlayer(TestResult.ClosestPoint);
				InteractionInfo.ClosestPointNormal = OculusXRHMD->ConvertVector_M2U(TestResult.ClosestPointNormal);
			}
		}

		return InteractionInfo;
	}

	void FOculusXRFunctionLibraryOVR::SetGuardianVisibility(bool GuardianVisible)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			FOculusXRHMDModule::GetPluginWrapper().SetBoundaryVisible2(GuardianVisible);
		}
	}

	bool FOculusXRFunctionLibraryOVR::GetSystemHmd3DofModeEnabled()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpBool enabled;
			return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetSystemHmd3DofModeEnabled(&enabled)) && enabled;
		}
		return false;
	}

	EOculusXRColorSpace FOculusXRFunctionLibraryOVR::GetHmdColorDesc()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpColorSpace HmdColorSpace;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetHmdColorDesc(&HmdColorSpace)))
			{
				return (EOculusXRColorSpace)HmdColorSpace;
			}
		}
		return EOculusXRColorSpace::Unknown;
	}

	void FOculusXRFunctionLibraryOVR::SetClientColorDesc(EOculusXRColorSpace ColorSpace)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpColorSpace ClientColorSpace = (ovrpColorSpace)ColorSpace;
#if PLATFORM_ANDROID
			if (ClientColorSpace == ovrpColorSpace_Unknown)
			{
				ClientColorSpace = ovrpColorSpace_Quest;
			}
#endif
			FOculusXRHMDModule::GetPluginWrapper().SetClientColorDesc(ClientColorSpace);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetLocalDimmingOn(bool LocalDimmingOn)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			UE_LOG(LogHMD, Log, TEXT("SetLocalDimmingOn %d"), LocalDimmingOn);
			FOculusXRHMDModule::GetPluginWrapper().SetLocalDimming(LocalDimmingOn);
		}
	}

	bool FOculusXRFunctionLibraryOVR::IsPassthroughSupported()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpInsightPassthroughCapabilityFlags capabilities;

			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPassthroughCapabilityFlags(&capabilities)))
			{
				return (capabilities & ovrpInsightPassthroughCapabilityFlags::ovrpInsightPassthroughCapabilityFlags_Passthrough)
					== ovrpInsightPassthroughCapabilityFlags::ovrpInsightPassthroughCapabilityFlags_Passthrough;
			}

			return false;
		}
		return false;
	}

	bool FOculusXRFunctionLibraryOVR::IsColorPassthroughSupported()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			ovrpInsightPassthroughCapabilityFlags capabilities;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPassthroughCapabilityFlags(&capabilities)))
			{
				return (capabilities & ovrpInsightPassthroughCapabilityFlags::ovrpInsightPassthroughCapabilityFlags_Color)
					== ovrpInsightPassthroughCapabilityFlags::ovrpInsightPassthroughCapabilityFlags_Color;
			}
			return false;
		}
		return false;
	}

	void FOculusXRFunctionLibraryOVR::StartEnvironmentDepth()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			int CreateFlags = 0;
			OculusXRHMD->StartEnvironmentDepth(CreateFlags);
		}
	}

	void FOculusXRFunctionLibraryOVR::StopEnvironmentDepth()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->StopEnvironmentDepth();
		}
	}

	bool FOculusXRFunctionLibraryOVR::IsEnvironmentDepthStarted()
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			return OculusXRHMD->IsEnvironmentDepthStarted();
		}
		return false;
	}

	void FOculusXRFunctionLibraryOVR::SetEnvironmentDepthHandRemoval(bool RemoveHands)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->SetEnvironmentDepthHandRemoval(RemoveHands);
		}
	}

	void FOculusXRFunctionLibraryOVR::SetXROcclusionsMode(UObject* WorldContextObject, EOculusXROcclusionsMode Mode)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			OculusXRHMD->EnableHardOcclusions(Mode == EOculusXROcclusionsMode::HardOcclusions);
			OculusXRHMD->EnableSoftOcclusions(Mode == EOculusXROcclusionsMode::SoftOcclusions);
		}
#if defined(WITH_OCULUS_BRANCH)
		WorldContextObject->GetWorld()->Scene->SetEnableXRPassthroughSoftOcclusions(Mode == EOculusXROcclusionsMode::SoftOcclusions);
#else
		ensureMsgf(Mode != EOculusXROcclusionsMode::SoftOcclusions, TEXT("Soft occlusions are only supported with the Oculus branch of the Unreal Engine"));
#endif
	}

	void FOculusXRFunctionLibraryOVR::SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType EyeBufferSharpenType)
	{
		OculusXRHMD::FOculusXRHMD* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusXRHMD != nullptr)
		{
			switch (EyeBufferSharpenType)
			{
				case EOculusXREyeBufferSharpenType::SLST_Normal:
					FOculusXRHMDModule::GetPluginWrapper().SetEyeBufferSharpenType(ovrpLayerSubmitFlag_EfficientSharpen);
					break;
				case EOculusXREyeBufferSharpenType::SLST_Quality:
					FOculusXRHMDModule::GetPluginWrapper().SetEyeBufferSharpenType(ovrpLayerSubmitFlag_QualitySharpen);
					break;
				case EOculusXREyeBufferSharpenType::SLST_Auto:
					FOculusXRHMDModule::GetPluginWrapper().SetEyeBufferSharpenType(ovrpLayerSubmitFlag_AutoLayerFilter);
					break;
				default:
					FOculusXRHMDModule::GetPluginWrapper().SetEyeBufferSharpenType(ovrpLayerSubmitFlags(0));
					break;
			}
		}
	}

	bool FOculusXRFunctionLibraryOVR::IsPassthroughRecommended()
	{
		const OculusXRHMD::FOculusXRHMD* OculusHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
		if (OculusHMD != nullptr)
		{
			ovrpPassthroughPreferences Preferences;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPassthroughPreferences(&Preferences)))
			{
				return (Preferences.Flags & ovrpPassthroughPreferenceFlags::ovrpPassthroughPreferenceFlags_DefaultToActive)
					== ovrpPassthroughPreferenceFlags::ovrpPassthroughPreferenceFlags_DefaultToActive;
			};
		}
		return false;
	}

} // namespace OculusXRHMD
