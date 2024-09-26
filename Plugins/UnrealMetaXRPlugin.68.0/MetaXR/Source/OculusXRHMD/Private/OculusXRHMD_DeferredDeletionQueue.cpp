// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_DeferredDeletionQueue.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMDPrivate.h"
#include "XRThreadUtils.h"
#include "OculusXRHMDModule.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FDeferredDeletionQueue
	//-------------------------------------------------------------------------------------------------
	uint32 GOculusXRHMDLayerDeletionFrameNumber = 0;
	const uint32 NUM_FRAMES_TO_WAIT_FOR_LAYER_DELETE = 3;
	const uint32 NUM_FRAMES_TO_WAIT_FOR_OVRP_LAYER_DELETE = 7;

	void FDeferredDeletionQueue::AddLayerToDeferredDeletionQueue(const FLayerPtr& ptr)
	{
		DeferredDeletionEntry Entry;
		Entry.Layer = ptr;
		Entry.FrameEnqueued = GOculusXRHMDLayerDeletionFrameNumber;
		Entry.EntryType = DeferredDeletionEntry::DeferredDeletionEntryType::Layer;
		DeferredDeletionArray.Add(Entry);
	}

	void FDeferredDeletionQueue::AddOVRPLayerToDeferredDeletionQueue(const uint32 layerID)
	{
		DeferredDeletionEntry Entry;
		Entry.OvrpLayerId = layerID;
		Entry.FrameEnqueued = GOculusXRHMDLayerDeletionFrameNumber;
		Entry.EntryType = DeferredDeletionEntry::DeferredDeletionEntryType::OvrpLayer;
		DeferredDeletionArray.Add(Entry);
	}

	void FDeferredDeletionQueue::HandleLayerDeferredDeletionQueue_RenderThread(bool bDeleteImmediately)
	{
		// Traverse list backwards so the swap switches to elements already tested
		for (int32 Index = DeferredDeletionArray.Num() - 1; Index >= 0; --Index)
		{
			DeferredDeletionEntry* Entry = &DeferredDeletionArray[Index];
			if (Entry->EntryType == DeferredDeletionEntry::DeferredDeletionEntryType::Layer)
			{
				if (bDeleteImmediately || GOculusXRHMDLayerDeletionFrameNumber > Entry->FrameEnqueued + NUM_FRAMES_TO_WAIT_FOR_LAYER_DELETE)
				{
					DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
				}
			}
			else if (Entry->EntryType == DeferredDeletionEntry::DeferredDeletionEntryType::OvrpLayer)
			{
				if (bDeleteImmediately || GOculusXRHMDLayerDeletionFrameNumber > Entry->FrameEnqueued + NUM_FRAMES_TO_WAIT_FOR_OVRP_LAYER_DELETE)
				{
					ExecuteOnRHIThread_DoNotWait([OvrpLayerId = Entry->OvrpLayerId]() {
						UE_LOG(LogHMD, Warning, TEXT("Destroying layer %d"), OvrpLayerId);
						FOculusXRHMDModule::GetPluginWrapper().DestroyLayer(OvrpLayerId);
					});
					DeferredDeletionArray.RemoveAtSwap(Index, 1, false);
				}
			}
		}

		// if the function is to be called multiple times, move this increment somewhere unique!
		++GOculusXRHMDLayerDeletionFrameNumber;
	}

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
