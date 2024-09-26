// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "khronos/openxr/openxr.h"
#include "RHI.h"
#include "HeadMountedDisplayTypes.h"

#ifdef WITH_OCULUS_BRANCH
#include "OpenXRCore.h"
#endif

#define ENSURE_XRCMD(cmd) \
	OculusXR::CheckXrResult(cmd, #cmd);

namespace OculusXR
{

#if defined(WITH_OCULUS_BRANCH)
	template <typename T>
	static void XRGetInstanceProcAddr(XrInstance InInstance, const char* Name, T* Function)
	{
		if (XR_FAILED(OpenXRDynamicAPI::xrGetInstanceProcAddr(InInstance, Name, reinterpret_cast<PFN_xrVoidFunction*>(Function))))
		{
			UE_LOG(LogHMD, Fatal, TEXT("Failed to bind OpenXR entry %s."), ANSI_TO_TCHAR(Name));
		}
	}

	template <typename T>
	static void XRGetInstanceProcAddr(XrInstance InInstance, const char* Name, TOptional<T>* Function)
	{
		if (XR_FAILED(OpenXRDynamicAPI::xrGetInstanceProcAddr(InInstance, Name, reinterpret_cast<PFN_xrVoidFunction*>(Function))))
		{
			UE_LOG(LogHMD, Warning, TEXT("Unable to bind optional OpenXR entry %s."), ANSI_TO_TCHAR(Name));
		}
	}
#else
	// Don't call xrGetInstanceProcAddr on marketplace build. This prevents the linker
	// from adding a dependency on OpenXr. On the marketplace build OpenXR loading is
	// currently disabled
	template <typename T>
	static void XRGetInstanceProcAddr(XrInstance InInstance, const char* Name, T* Function)
	{
		(void)InInstance;
		(void)Name;
		(void)Function;
		UE_LOG(LogHMD, Warning, TEXT("Failed to bind OpenXR entry %s."), ANSI_TO_TCHAR(Name));
	}

	template <typename T>
	static void XRGetInstanceProcAddr(XrInstance InInstance, const char* Name, TOptional<T>* Function)
	{
		(void)InInstance;
		(void)Name;
		(void)Function;
		UE_LOG(LogHMD, Warning, TEXT("Unable to bind optional OpenXR entry %s."), ANSI_TO_TCHAR(Name));
	}
#endif

	XrResult CheckXrResult(XrResult res, const char* cmd);

} // namespace OculusXR
