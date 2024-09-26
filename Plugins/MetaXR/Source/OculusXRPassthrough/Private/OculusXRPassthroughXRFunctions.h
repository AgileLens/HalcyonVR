// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "khronos/openxr/openxr.h"
#include "Misc/Optional.h"

namespace XRPassthrough
{
	extern PFN_xrCreatePassthroughFB xrCreatePassthroughFB;
	extern PFN_xrDestroyPassthroughFB xrDestroyPassthroughFB;
	extern PFN_xrPassthroughStartFB xrPassthroughStartFB;
	extern PFN_xrPassthroughPauseFB xrPassthroughPauseFB;
	extern PFN_xrCreatePassthroughLayerFB xrCreatePassthroughLayerFB;
	extern PFN_xrDestroyPassthroughLayerFB xrDestroyPassthroughLayerFB;
	extern PFN_xrPassthroughLayerPauseFB xrPassthroughLayerPauseFB;
	extern PFN_xrPassthroughLayerResumeFB xrPassthroughLayerResumeFB;
	extern PFN_xrPassthroughLayerSetStyleFB xrPassthroughLayerSetStyleFB;
	extern TOptional<PFN_xrCreateTriangleMeshFB> xrCreateTriangleMeshFB;
	extern TOptional<PFN_xrDestroyTriangleMeshFB> xrDestroyTriangleMeshFB;
	extern PFN_xrCreateGeometryInstanceFB xrCreateGeometryInstanceFB;
	extern PFN_xrDestroyGeometryInstanceFB xrDestroyGeometryInstanceFB;
	extern PFN_xrGeometryInstanceSetTransformFB xrGeometryInstanceSetTransformFB;

	void InitOpenXRFunctions(XrInstance InInstance);
} // namespace XRPassthrough
