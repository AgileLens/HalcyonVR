// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMDPrivate.h"
#include "RHICommandList.h"
#include "RenderingThread.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// Utility functions
	//-------------------------------------------------------------------------------------------------

	// TODO: Change in case of parallel game threads
	bool InGameThread()
	{
		if (GIsGameThreadIdInitialized)
		{
			return FPlatformTLS::GetCurrentThreadId() == GGameThreadId;
		}
		else
		{
			return true;
		}
	}

	bool InRenderThread()
	{
		if (GIsThreadedRendering && !GIsRenderingThreadSuspended.Load(EMemoryOrder::Relaxed))
		{
			return IsInParallelRenderingThread();
		}
		else
		{
			return InGameThread();
		}
	}

	// TODO: Change in case of parallel RHI threads
	bool InRHIThread()
	{
		if (GIsThreadedRendering && !GIsRenderingThreadSuspended.Load(EMemoryOrder::Relaxed))
		{
			if (IsRHIThreadRunning())
			{
				if (IsInRHIThread())
				{
					return true;
				}

				if (IsInParallelRenderingThread())
				{
					return GetImmediateCommandList_ForRenderCommand().Bypass();
				}

				return false;
			}
			else
			{
				return IsInParallelRenderingThread();
			}
		}
		else
		{
			return InGameThread();
		}
	}

	bool ConvertPose_Internal(const FPose& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
	{
		// apply base orientation correction
		OutPose.Orientation = BaseOrientation.Inverse() * InPose.Orientation;
		OutPose.Orientation.Normalize();

		// correct position according to BaseOrientation and BaseOffset.
		OutPose.Position = (InPose.Position - BaseOffset) * WorldToMetersScale;
		OutPose.Position = BaseOrientation.Inverse().RotateVector(OutPose.Position);

		return true;
	}

	bool ConvertPose_Internal(const ovrpPosef& InPose, FPose& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
	{
		return ConvertPose_Internal(FPose(ToFQuat(InPose.Orientation), ToFVector(InPose.Position)), OutPose, BaseOrientation, BaseOffset, WorldToMetersScale);
	}

	bool ConvertPose_Internal(const FPose& InPose, ovrpPosef& OutPose, const FQuat BaseOrientation, const FVector BaseOffset, float WorldToMetersScale)
	{
		OutPose.Orientation = ToOvrpQuatf(BaseOrientation * InPose.Orientation);
		OutPose.Position = ToOvrpVector3f(BaseOrientation.RotateVector(InPose.Position) / WorldToMetersScale + BaseOffset);
		return true;
	}

} // namespace OculusXRHMD
