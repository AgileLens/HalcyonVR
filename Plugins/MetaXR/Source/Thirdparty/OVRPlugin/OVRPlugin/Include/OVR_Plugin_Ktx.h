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

#ifndef OVR_Plugin_KtxLoader_h
#define OVR_Plugin_KtxLoader_h

#include "OVR_Plugin_Types.h"
#include <ktx.h>

#ifdef __cplusplus
extern "C" {
#endif

OVRP_EXPORT ovrpResult ovrp_KtxLoadFromMemory(unsigned char** data, unsigned int length, ktxTexture2** texture);
OVRP_EXPORT ovrpResult ovrp_KtxDestroy(ktxTexture2* texture);

OVRP_EXPORT ovrpResult ovrp_KtxNeedsTranscoding(ktxTexture2* texture, bool* needsTranscoding);
OVRP_EXPORT ovrpResult ovrp_KtxTranscode(ktxTexture2* texture, unsigned int format);

OVRP_EXPORT ovrpResult ovrp_KtxTextureWidth(ktxTexture2* texture, unsigned int* width);
OVRP_EXPORT ovrpResult ovrp_KtxTextureHeight(ktxTexture2* texture, unsigned int* height);
OVRP_EXPORT ovrpResult ovrp_KtxTextureSize(ktxTexture2* texture, unsigned int* size);

OVRP_EXPORT ovrpResult ovrp_KtxGetTextureData(ktxTexture2* texture, unsigned char* data, unsigned int bufferSize);

#ifdef __cplusplus
}
#endif

#endif
