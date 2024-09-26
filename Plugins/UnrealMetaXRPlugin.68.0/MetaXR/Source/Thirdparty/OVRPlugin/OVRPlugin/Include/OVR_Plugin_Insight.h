/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 *
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OVR_Plugin_Insight_h
#define OVR_Plugin_Insight_h

#include "OVR_Plugin_Types.h"

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

/// Tests if Insight Passthrough is supported on the device
OVRP_EXPORT ovrpResult ovrp_IsInsightPassthroughSupported(ovrpBool* supported);

/// Initialize Insight Passthrough functionality
OVRP_EXPORT ovrpResult ovrp_InitializeInsightPassthrough();

/// Shutdown Insight Passthrough functionality
OVRP_EXPORT ovrpResult ovrp_ShutdownInsightPassthrough();

/// Check whether Insight Passthrough functionality has been initialized
OVRP_EXPORT ovrpBool ovrp_GetInsightPassthroughInitialized();

/// Check whether Insight Passthrough functionality has been initialized
OVRP_EXPORT ovrpResult ovrp_GetInsightPassthroughInitializationState();

/// Create and initialize an Insight Passthrough triangle mesh
OVRP_EXPORT ovrpResult ovrp_CreateInsightTriangleMesh(
    int layerId,
    float* vertices,
    int vertexCount,
    int* triangles,
    int triangleCount,
    uint64_t* outMeshHandle);

/// Destroy a triangle mesh
OVRP_EXPORT ovrpResult ovrp_DestroyInsightTriangleMesh(uint64_t meshHandle);

/// Add a triangle mesh to the passthrough projection surface
OVRP_EXPORT ovrpResult ovrp_AddInsightPassthroughSurfaceGeometry(
    int layerId,
    uint64_t meshHandle,
    ovrpMatrix4f transformation,
    uint64_t* geometryInstanceHandle);

/// Remove a geometry instance from the passthrough projection surface and destroy it.
OVRP_EXPORT ovrpResult ovrp_DestroyInsightPassthroughGeometryInstance(uint64_t geometryInstanceHandle);

/// Update a transform of a geometry instance.
OVRP_EXPORT ovrpResult
ovrp_UpdateInsightPassthroughGeometryTransform(uint64_t geometryInstanceHandle, ovrpMatrix4f transformation);

OVRP_EXPORT ovrpResult ovrp_SetInsightPassthroughStyle(int layerId, ovrpInsightPassthroughStyle style);

// Set hands intensity
OVRP_EXPORT ovrpResult
ovrp_SetInsightPassthroughKeyboardHandsIntensity(int layerId, ovrpInsightPassthroughKeyboardHandsIntensity intensity);

// Gets passthrough capabilities.
OVRP_EXPORT ovrpResult ovrp_GetPassthroughCapabilityFlags(ovrpInsightPassthroughCapabilityFlags* capabilities);
OVRP_EXPORT ovrpResult ovrp_GetPassthroughCapabilities(ovrpInsightPassthroughCapabilities* capabilities);

OVRP_EXPORT ovrpResult ovrp_SetInsightPassthroughStyle2(int layerId, const ovrpInsightPassthroughStyle* style);

OVRP_EXPORT ovrpResult ovrp_CreatePassthroughColorLut(
    ovrpPassthroughColorLutChannels channels,
    ovrpUInt32 resolution,
    ovrpPassthroughColorLutData data,
    ovrpPassthroughColorLut* colorLut);

OVRP_EXPORT ovrpResult ovrp_DestroyPassthroughColorLut(ovrpPassthroughColorLut colorLut);

OVRP_EXPORT ovrpResult
ovrp_UpdatePassthroughColorLut(ovrpPassthroughColorLut colorLut, ovrpPassthroughColorLutData data);


















OVRP_EXPORT ovrpResult ovrp_GetPassthroughPreferences(ovrpPassthroughPreferences* preferences);

#ifdef __cplusplus
}
#endif

#endif // OVR_Plugin_Insight_h
