// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRPluginWrapper.h"
#include "CoreMinimal.h"
#include "OculusXRHMDPrivate.h"

namespace OculusXRPassthrough
{
	class FOculusXRPassthroughEventDelegates
	{
	public:
		/* ovrpEventType_PassthroughLayerResumed
		 *
		 *        PassthroughLayerResumed
		 * Prefix:
		 * FOculusXRPassthroughLayerResumed
		 * Suffix:
		 * FOculusXRPassthroughLayerResumedDelegate
		 */
		DECLARE_MULTICAST_DELEGATE_OneParam(FOculusXRPassthroughLayerResumedDelegate, int /*layerId*/);
		static OCULUSXRPASSTHROUGH_API FOculusXRPassthroughLayerResumedDelegate OculusPassthroughLayerResumed;
	};

	struct FOculusXRPassthroughEventHandling
	{
	public:
		static void OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult);
	};

} // namespace OculusXRPassthrough
