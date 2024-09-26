// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughXRFunctions.h"
#include "OpenXRCore.h"
#include "OpenXR/OculusXROpenXRUtilities.h"

namespace XRPassthrough
{
	PFN_xrCreatePassthroughFB xrCreatePassthroughFB = nullptr;
	PFN_xrDestroyPassthroughFB xrDestroyPassthroughFB = nullptr;
	PFN_xrPassthroughStartFB xrPassthroughStartFB = nullptr;
	PFN_xrPassthroughPauseFB xrPassthroughPauseFB = nullptr;
	PFN_xrCreatePassthroughLayerFB xrCreatePassthroughLayerFB = nullptr;
	PFN_xrDestroyPassthroughLayerFB xrDestroyPassthroughLayerFB = nullptr;
	PFN_xrPassthroughLayerPauseFB xrPassthroughLayerPauseFB = nullptr;
	PFN_xrPassthroughLayerResumeFB xrPassthroughLayerResumeFB = nullptr;
	PFN_xrPassthroughLayerSetStyleFB xrPassthroughLayerSetStyleFB = nullptr;
	TOptional<PFN_xrCreateTriangleMeshFB> xrCreateTriangleMeshFB = nullptr;
	TOptional<PFN_xrDestroyTriangleMeshFB> xrDestroyTriangleMeshFB = nullptr;
	PFN_xrCreateGeometryInstanceFB xrCreateGeometryInstanceFB = nullptr;
	PFN_xrDestroyGeometryInstanceFB xrDestroyGeometryInstanceFB = nullptr;
	PFN_xrGeometryInstanceSetTransformFB xrGeometryInstanceSetTransformFB = nullptr;

	void InitOpenXRFunctions(XrInstance InInstance)
	{
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrCreatePassthroughFB", &xrCreatePassthroughFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrDestroyPassthroughFB", &xrDestroyPassthroughFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPassthroughStartFB", &xrPassthroughStartFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPassthroughPauseFB", &xrPassthroughPauseFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrCreatePassthroughLayerFB", &xrCreatePassthroughLayerFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrDestroyPassthroughLayerFB", &xrDestroyPassthroughLayerFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPassthroughLayerPauseFB", &xrPassthroughLayerPauseFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPassthroughLayerResumeFB", &xrPassthroughLayerResumeFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrPassthroughLayerSetStyleFB", &xrPassthroughLayerSetStyleFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrCreateTriangleMeshFB", &xrCreateTriangleMeshFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrDestroyTriangleMeshFB", &xrDestroyTriangleMeshFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrCreateGeometryInstanceFB", &xrCreateGeometryInstanceFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrDestroyGeometryInstanceFB", &xrDestroyGeometryInstanceFB);
		OculusXR::XRGetInstanceProcAddr(InInstance, "xrGeometryInstanceSetTransformFB", &xrGeometryInstanceSetTransformFB);
	}

} // namespace XRPassthrough
