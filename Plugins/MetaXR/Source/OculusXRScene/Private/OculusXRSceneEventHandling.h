/*
Copyright (c) Meta Platforms, Inc. and affiliates.
All rights reserved.

This source code is licensed under the license found in the
LICENSE file in the root directory of this source tree.
*/
#pragma once

#include "CoreMinimal.h"
#include "OculusXRHMDPrivate.h"

namespace OculusXRScene
{
	struct OCULUSXRSCENE_API FOculusXRSceneEventHandling
	{
		static void OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult);
	};
} // namespace OculusXRScene
