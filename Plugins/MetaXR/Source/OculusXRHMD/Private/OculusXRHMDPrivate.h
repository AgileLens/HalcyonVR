// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "GameFramework/WorldSettings.h"
#include "IOculusXRHMDModule.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRPassthroughLayerShapes.h"
#include "StereoRendering.h"
#include "HAL/RunnableThread.h"
#include "RHI.h"
#include <functional>

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#define OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11 PLATFORM_WINDOWS
#define OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12 PLATFORM_WINDOWS
#define OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN (PLATFORM_WINDOWS || PLATFORM_ANDROID)
#else
#define OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11 0
#define OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12 0
#define OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN 0
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

//-------------------------------------------------------------------------------------------------
// OVRPlugin
//-------------------------------------------------------------------------------------------------

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRPluginWrapper.h"
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

//-------------------------------------------------------------------------------------------------
// Utility functions
//-------------------------------------------------------------------------------------------------

namespace OculusXRHMD
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	struct FPose
	{
		FQuat Orientation;
		FVector Position;

		FPose()
			: Orientation(EForceInit::ForceInit)
			, Position(EForceInit::ForceInit)
		{
		}

		FPose(const FQuat& InOrientation, const FVector& InPosition)
			: Orientation(InOrientation), Position(InPosition) {}

		FPose Inverse() const
		{
			FQuat InvOrientation = Orientation.Inverse();
			FVector InvPosition = InvOrientation.RotateVector(-Position);
			return FPose(InvOrientation, InvPosition);
		}

		FPose operator*(const FPose& other) const
		{
			return FPose(Orientation * other.Orientation, Orientation.RotateVector(other.Position) + Position);
		}
	};

	/** Converts ovrpQuatf to FQuat */
	FORCEINLINE FQuat ToFQuat(const ovrpQuatf& InQuat)
	{
		return FQuat(-InQuat.z, InQuat.x, InQuat.y, -InQuat.w);
	}

	/** Converts FQuat to ovrpQuatf */
	FORCEINLINE ovrpQuatf ToOvrpQuatf(const FQuat& InQuat)
	{
		return ovrpQuatf{ static_cast<float>(InQuat.Y), static_cast<float>(InQuat.Z), static_cast<float>(-InQuat.X), static_cast<float>(-InQuat.W) };
	}

	/** Converts vector from Oculus to Unreal */
	FORCEINLINE FVector ToFVector(const ovrpVector3f& InVec)
	{
		return FVector(-InVec.z, InVec.x, InVec.y);
	}

	/** Converts vector from Unreal to Oculus. */
	FORCEINLINE ovrpVector3f ToOvrpVector3f(const FVector& InVec)
	{
		return ovrpVector3f{ static_cast<float>(InVec.Y), static_cast<float>(InVec.Z), static_cast<float>(-InVec.X) };
	}

	FORCEINLINE FMatrix ToFMatrix(const ovrpMatrix4f& vtm)
	{
		// Rows and columns are swapped between ovrpMatrix4f and FMatrix
		return FMatrix(
			FPlane(vtm.M[0][0], vtm.M[1][0], vtm.M[2][0], vtm.M[3][0]),
			FPlane(vtm.M[0][1], vtm.M[1][1], vtm.M[2][1], vtm.M[3][1]),
			FPlane(vtm.M[0][2], vtm.M[1][2], vtm.M[2][2], vtm.M[3][2]),
			FPlane(vtm.M[0][3], vtm.M[1][3], vtm.M[2][3], vtm.M[3][3]));
	}

	FORCEINLINE ovrpVector4f LinearColorToOvrpVector4f(const FLinearColor& InColor)
	{
		return ovrpVector4f{ InColor.R, InColor.G, InColor.B, InColor.A };
	}

	FORCEINLINE ovrpRecti ToOvrpRecti(const FIntRect& rect)
	{
		return ovrpRecti{ { rect.Min.X, rect.Min.Y }, { rect.Size().X, rect.Size().Y } };
	}

	FORCEINLINE ovrpColorf ToOvrpColorf(const FLinearColor LinearColor)
	{
		return ovrpColorf{ LinearColor.R, LinearColor.G, LinearColor.B, LinearColor.A };
	}

	FORCEINLINE ovrpMatrix4f ToOvrpMatrix(FMatrix Matrix)
	{
		ovrpMatrix4f Result;

		Result.M[0][0] = Matrix.M[0][0];
		Result.M[0][1] = Matrix.M[0][1];
		Result.M[0][2] = Matrix.M[0][2];
		Result.M[0][3] = Matrix.M[0][3];

		Result.M[1][0] = Matrix.M[1][0];
		Result.M[1][1] = Matrix.M[1][1];
		Result.M[1][2] = Matrix.M[1][2];
		Result.M[1][3] = Matrix.M[1][3];

		Result.M[2][0] = Matrix.M[2][0];
		Result.M[2][1] = Matrix.M[2][1];
		Result.M[2][2] = Matrix.M[2][2];
		Result.M[2][3] = Matrix.M[2][3];

		Result.M[3][0] = Matrix.M[3][0];
		Result.M[3][1] = Matrix.M[3][1];
		Result.M[3][2] = Matrix.M[3][2];
		Result.M[3][3] = Matrix.M[3][3];

		return Result;
	}

	/** Helper that converts ovrTrackedDeviceType to EOculusXRTrackedDeviceType */
	FORCEINLINE EOculusXRTrackedDeviceType ToEOculusXRTrackedDeviceType(ovrpNode Source)
	{
		EOculusXRTrackedDeviceType Destination = EOculusXRTrackedDeviceType::All; // Best attempt at initialization

		switch (Source)
		{
			case ovrpNode_None:
				Destination = EOculusXRTrackedDeviceType::None;
				break;
			case ovrpNode_Head:
				Destination = EOculusXRTrackedDeviceType::HMD;
				break;
			case ovrpNode_HandLeft:
				Destination = EOculusXRTrackedDeviceType::LTouch;
				break;
			case ovrpNode_HandRight:
				Destination = EOculusXRTrackedDeviceType::RTouch;
				break;
			case ovrpNode_DeviceObjectZero:
				Destination = EOculusXRTrackedDeviceType::DeviceObjectZero;
				break;
			default:
				break;
		}
		return Destination;
	}

	/** Helper that converts EOculusXRTrackedDeviceType to ovrTrackedDeviceType */
	FORCEINLINE ovrpNode ToOvrpNode(EOculusXRTrackedDeviceType Source)
	{
		ovrpNode Destination = ovrpNode_None; // Best attempt at initialization

		switch (Source)
		{
			case EOculusXRTrackedDeviceType::None:
				Destination = ovrpNode_None;
				break;
			case EOculusXRTrackedDeviceType::HMD:
				Destination = ovrpNode_Head;
				break;
			case EOculusXRTrackedDeviceType::LTouch:
				Destination = ovrpNode_HandLeft;
				break;
			case EOculusXRTrackedDeviceType::RTouch:
				Destination = ovrpNode_HandRight;
				break;
			case EOculusXRTrackedDeviceType::DeviceObjectZero:
				Destination = ovrpNode_DeviceObjectZero;
				break;
			default:
				break;
		}
		return Destination;
	}

	FORCEINLINE int32 ToExternalDeviceId(const ovrpNode Source)
	{
		int32 ExternalDeviceId = INDEX_NONE;
		switch (Source)
		{
			case ovrpNode_Head:
				// required to be zero (see IXRTrackingSystem::HMDDeviceId)
				ExternalDeviceId = 0;
				break;
			case ovrpNode_None:
			case ovrpNode_Count:
			case ovrpNode_EnumSize:
				// ExternalDeviceId = INDEX_NONE;
				break;
			default:
				// add one, in case the enum value is zero (conflicting with the HMD)
				ExternalDeviceId = 1 + (int32)Source;
				break;
		}
		return ExternalDeviceId;
	}

	FORCEINLINE ovrpNode ToOvrpNode(const int32 ExternalDeviceId)
	{
		ovrpNode Destination = ovrpNode_None;
		switch (ExternalDeviceId)
		{
			case 0:
				// zero implies HMD (see ToExternalDeviceId/IXRTrackingSystem::HMDDeviceId)
				Destination = ovrpNode_Head;
				break;
			case -1:
				// Destination = ovrpNode_None;
				break;
			default:
				// we added one to avoid collision with the HMD's ID (see ToExternalDeviceId)
				Destination = ovrpNode(ExternalDeviceId - 1);
				break;
		}
		return Destination;
	}

	bool ConvertPose_Internal(const FPose& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale);

	bool ConvertPose_Internal(const ovrpPosef& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale);

	bool ConvertPose_Internal(const FPose& InPose, ovrpPosef& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale);

	FORCEINLINE ovrpInsightPassthroughColorMapType ToOVRPColorMapType(EOculusXRColorMapType InColorMapType)
	{
		switch (InColorMapType)
		{
			case ColorMapType_GrayscaleToColor:
				return ovrpInsightPassthroughColorMapType_MonoToRgba;
			case ColorMapType_Grayscale:
				return ovrpInsightPassthroughColorMapType_MonoToMono;
			case ColorMapType_ColorAdjustment:
				return ovrpInsightPassthroughColorMapType_BrightnessContrastSaturation;
			case ColorMapType_ColorLut:
				return ovrpInsightPassthroughColorMapType_ColorLut;
			case ColorMapType_ColorLut_Interpolated:
				return ovrpInsightPassthroughColorMapType_InterpolatedColorLut;
			default:
				return ovrpInsightPassthroughColorMapType_None;
		}
	}

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

	/** Check currently executing from Game thread */
	OCULUSXRHMD_API bool InGameThread();

	FORCEINLINE void CheckInGameThread()
	{
#if DO_CHECK
		check(InGameThread());
#endif
	}

	/** Check currently executing from Render thread */
	OCULUSXRHMD_API bool InRenderThread();

	FORCEINLINE void CheckInRenderThread()
	{
#if DO_CHECK
		check(InRenderThread());
#endif
	}

	/** Check currently executing from RHI thread */
	OCULUSXRHMD_API bool InRHIThread();

	FORCEINLINE void CheckInRHIThread()
	{
#if DO_CHECK
		check(InRHIThread());
#endif
	}

	FORCEINLINE bool GetUnitScaleFactorFromSettings(UWorld* World, float& outWorldToMeters)
	{
		if (IsValid(World))
		{
			const auto* WorldSettings = World->GetWorldSettings();
			if (IsValid(WorldSettings))
			{
				outWorldToMeters = WorldSettings->WorldToMeters;
				return true;
			}
		}
		return false;
	}

} // namespace OculusXRHMD
