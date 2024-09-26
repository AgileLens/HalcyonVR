// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_Layer.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FDeferredDeletionQueue
	//-------------------------------------------------------------------------------------------------

	class FDeferredDeletionQueue
	{
	public:
		void AddLayerToDeferredDeletionQueue(const FLayerPtr& ptr);
		void AddOVRPLayerToDeferredDeletionQueue(const uint32 layerID);
		void HandleLayerDeferredDeletionQueue_RenderThread(bool bDeleteImmediately = false);

	private:
		struct DeferredDeletionEntry
		{
			enum class DeferredDeletionEntryType
			{
				Layer,
				OvrpLayer
			};

			FLayerPtr Layer;
			uint32 OvrpLayerId;

			uint32 FrameEnqueued;
			DeferredDeletionEntryType EntryType;
		};

		TArray<DeferredDeletionEntry> DeferredDeletionArray;
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
