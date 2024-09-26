// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughEventHandling.h"

#include "OculusXRHMD.h"
#include "OculusXRPassthroughModule.h"
#include "OculusXRPassthroughSubsystem.h"

namespace OculusXRPassthrough
{
	FOculusXRPassthroughEventDelegates::FOculusXRPassthroughLayerResumedDelegate FOculusXRPassthroughEventDelegates::OculusPassthroughLayerResumed;

	template <typename T>
	void GetEventData(ovrpEventDataBuffer& Buffer, T& OutEventData)
	{
		unsigned char* BufData = Buffer.EventData;
		BufData -= sizeof(Buffer.EventType); // Offset buffer data to get to the actual event payload

		memcpy(&OutEventData, BufData, sizeof(T));
	}

	void FOculusXRPassthroughEventHandling::OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult)
	{
		ovrpEventDataBuffer& buf = *EventDataBuffer;
		EventPollResult = true;

		switch (buf.EventType)
		{
			case ovrpEventType_PassthroughLayerResumed:
			{
				OculusXRHMD::FOculusXRHMD* HMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();

				check(HMD);

				ovrpEventDataPassthroughLayerResumed passthroughLayerResumedEvent;
				GetEventData(buf, passthroughLayerResumedEvent);

				// Convert OVR plugin layerID to UE layerID
				int ovrpID = passthroughLayerResumedEvent.LayerId;
				uint32 LayerID = HMD->GetLayerIdFromOvrpId(ovrpID);

				UE_LOG(LogOculusXRPassthrough, Log, TEXT("FOculusXRPassthroughEventHandling - Passthrough Layer #%d resumed"), LayerID);

				// Send event
				FOculusXRPassthroughEventDelegates::OculusPassthroughLayerResumed.Broadcast(LayerID);

				break;
			}

			case ovrpEventType_None:
			default:
			{
				EventPollResult = false;
				break;
			}
		}
	}
} // namespace OculusXRPassthrough
