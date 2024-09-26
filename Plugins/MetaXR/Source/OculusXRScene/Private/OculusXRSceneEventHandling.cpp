// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSceneEventHandling.h"

#include "OculusXRHMD.h"
#include "IOculusXRSceneModule.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRSceneDelegates.h"
#include "OculusXRSceneEventDelegates.h"
#include "OculusXRSceneModule.h"

namespace OculusXRScene
{
	template <typename T>
	void GetEventData(ovrpEventDataBuffer& Buffer, T& OutEventData)
	{
		unsigned char* BufData = Buffer.EventData;
		BufData -= sizeof(Buffer.EventType); // Offset buffer data to get to the actual event payload

		memcpy(&OutEventData, BufData, sizeof(T));
	}

	void FOculusXRSceneEventHandling::OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult)
	{
		ovrpEventDataBuffer& buf = *EventDataBuffer;
		EventPollResult = true;

		switch (buf.EventType)
		{

			case ovrpEventType_BoundaryVisibilityChanged:
			{
				ovrpEventDataBoundaryVisibilityChanged visibilityChangedEvent;
				GetEventData(buf, visibilityChangedEvent);

				ovrpBoundaryVisibility newVisibility = visibilityChangedEvent.BoundaryVisibility;
				EOculusXRBoundaryVisibility ueVisibility = EOculusXRBoundaryVisibility::Invalid;
				switch (newVisibility)
				{
					case ovrpBoundaryVisibility_Suppressed:
						ueVisibility = EOculusXRBoundaryVisibility::Suppressed;
						break;

					case ovrpBoundaryVisibility_NotSuppressed:
						ueVisibility = EOculusXRBoundaryVisibility::NotSuppressed;
						break;

					default:
						UE_LOG(LogOculusXRScene, Error, TEXT("Unknown ovrp boundary type in BoundaryVisibilityChanged event! Enum value(%d)"), newVisibility);
				}

				UE_LOG(LogOculusXRScene, Log, TEXT("FOculusXRSceneEventHandling - Boundary visibility changed. Visibility(%s)"), *UEnum::GetValueAsString(ueVisibility));

				FOculusXRSceneEventDelegates::OculusBoundaryVisibilityChanged.Broadcast(ueVisibility);
				UOculusXRSceneEventDelegates* eventDelegates = GEngine->GetEngineSubsystem<UOculusXRSceneEventDelegates>();
				if (eventDelegates != nullptr)
				{
					eventDelegates->OnBoundaryVisibilityChanged.Broadcast(ueVisibility);
				}

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
} // namespace OculusXRScene
