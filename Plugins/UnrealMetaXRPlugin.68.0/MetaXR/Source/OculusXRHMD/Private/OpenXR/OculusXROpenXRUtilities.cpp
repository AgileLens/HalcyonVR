// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXROpenXRUtilities.h"
#include "RHICommandList.h"
#include "RenderingThread.h"

namespace OculusXR
{
	XrResult CheckXrResult(XrResult Result, const char* Cmd)
	{
		if (!XR_SUCCEEDED(Result))
		{
			UE_LOG(LogHMD, Error, TEXT("%hs failed"), Cmd);
		}
		return Result;
	}
} // namespace OculusXR
