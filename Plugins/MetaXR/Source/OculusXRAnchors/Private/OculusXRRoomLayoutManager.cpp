// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRRoomLayoutManager.h"
#include "OculusXRHMD.h"
#include "OculusXRAnchorDelegates.h"
#include "OculusXRAnchorsModule.h"

namespace OculusXRAnchors
{
	void FOculusXRRoomLayoutManager::OnPollEvent(ovrpEventDataBuffer* EventDataBuffer, bool& EventPollResult)
	{
		ovrpEventDataBuffer& buf = *EventDataBuffer;

		switch (buf.EventType)
		{
			case ovrpEventType_None:
				break;
			case ovrpEventType_SceneCaptureComplete:
			{
				ovrpEventSceneCaptureComplete sceneCaptureComplete;
				unsigned char* bufData = buf.EventData;

				memcpy(&sceneCaptureComplete.requestId, bufData, sizeof(sceneCaptureComplete.requestId));
				bufData += sizeof(ovrpUInt64); // move forward
				memcpy(&sceneCaptureComplete.result, bufData, sizeof(sceneCaptureComplete.result));

				FOculusXRAnchorEventDelegates::OculusSceneCaptureComplete.Broadcast(FOculusXRUInt64(sceneCaptureComplete.requestId), sceneCaptureComplete.result >= 0);
				break;
			}

			default:
			{
				EventPollResult = false;
				break;
			}
		}

		EventPollResult = true;
	}

	/**
	 * @brief Requests the launch of Capture Flow
	 * @param OutRequestID The requestId returned by the system
	 * @return returns true if sucessfull
	 */
	bool FOculusXRRoomLayoutManager::RequestSceneCapture(uint64& OutRequestID)
	{
		OutRequestID = 0;

		ovrpSceneCaptureRequest sceneCaptureRequest;
		sceneCaptureRequest.request = nullptr;
		sceneCaptureRequest.requestByteCount = 0;

		const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().RequestSceneCapture(&sceneCaptureRequest, &OutRequestID);
		if (OVRP_FAILURE(Result))
		{
			return false;
		}

		return true;
	}

	/**
	 * @brief Gets the room layout for a specific space
	 * @param Space The space to get the room layout for
	 * @param MaxWallsCapacity Maximum number of walls to query
	 * @param OutCeilingUuid The ceiling entity's uuid
	 * @param OutFloorUuid The floor entity's uuid
	 * @param OutWallsUuid Array of uuids belonging to the walls in the room layout
	 * @return returns true if successful
	 */
	bool FOculusXRRoomLayoutManager::GetSpaceRoomLayout(const uint64 Space, const uint32 MaxWallsCapacity,
		FOculusXRUUID& OutCeilingUuid, FOculusXRUUID& OutFloorUuid, TArray<FOculusXRUUID>& OutWallsUuid)
	{
		ovrpRoomLayout roomLayout;
		roomLayout.wallUuidCapacityInput = 0;
		roomLayout.wallUuidCountOutput = 0;

		// First call to get output size
		const ovrpResult firstCallResult = FOculusXRHMDModule::GetPluginWrapper().GetSpaceRoomLayout(&Space, &roomLayout);
		if (OVRP_FAILURE(firstCallResult))
		{
			return false;
		}

		// Set the input size and pointer to the uuid array
		TArray<ovrpUuid> uuids;
		uuids.InsertZeroed(0, roomLayout.wallUuidCountOutput);

		roomLayout.wallUuidCapacityInput = roomLayout.wallUuidCountOutput;
		roomLayout.wallUuids = uuids.GetData();

		const ovrpResult secondCallResult = FOculusXRHMDModule::GetPluginWrapper().GetSpaceRoomLayout(&Space, &roomLayout);
		if (OVRP_FAILURE(secondCallResult))
		{
			return false;
		}

		OutCeilingUuid = FOculusXRUUID(roomLayout.ceilingUuid.data);
		OutFloorUuid = FOculusXRUUID(roomLayout.floorUuid.data);

		OutWallsUuid.Empty();
		OutWallsUuid.InsertZeroed(0, uuids.Num());

		for (int32 i = 0; i < uuids.Num(); ++i)
		{
			OutWallsUuid[i] = FOculusXRUUID(roomLayout.wallUuids[i].data);
		}

		return true;
	}

	bool FOculusXRRoomLayoutManager::GetSpaceTriangleMesh(uint64 Space, TArray<FVector>& Vertices, TArray<int32>& Triangles)
	{
		ovrpTriangleMesh OVRPMesh = { 0, 0, nullptr, 0, 0, nullptr };

		ovrpResult CountResult = FOculusXRHMDModule::GetPluginWrapper().GetSpaceTriangleMesh(&Space, &OVRPMesh);
		if (OVRP_FAILURE(CountResult))
		{
			UE_LOG(LogOculusXRAnchors, Warning, TEXT("Failed to load TriangleMesh info - Space: %llu - Result: %d"), Space, CountResult);
			return false;
		}
		OVRPMesh.indexCapacityInput = OVRPMesh.indexCountOutput;
		OVRPMesh.vertexCapacityInput = OVRPMesh.vertexCountOutput;

		TArray<ovrpVector3f> OVRPVertices;
		OVRPVertices.SetNum(OVRPMesh.vertexCapacityInput);
		OVRPMesh.vertices = OVRPVertices.GetData();
		Triangles.SetNum(OVRPMesh.indexCapacityInput);
		check(sizeof(TRemoveReference<decltype(Triangles)>::Type::ElementType) == sizeof(TRemovePointer<decltype(OVRPMesh.indices)>::Type));
		OVRPMesh.indices = Triangles.GetData();

		const ovrpResult MeshResult = FOculusXRHMDModule::GetPluginWrapper().GetSpaceTriangleMesh(&Space, &OVRPMesh);
		if (OVRP_FAILURE(MeshResult))
		{
			UE_LOG(LogOculusXRAnchors, Warning, TEXT("Failed to load TriangleMesh data - Space: %llu - Result: %d"), Space, MeshResult);
			return false;
		}

		UE_LOG(LogOculusXRAnchors, Verbose, TEXT("Loaded TriangleMesh data - Space: %llu - Vertices: %d - Faces: %d"),
			Space, OVRPMesh.vertexCapacityInput, OVRPMesh.indexCapacityInput);

		Vertices.Empty(OVRPVertices.Num());
		Algo::Transform(OVRPVertices, Vertices, [](const auto& Vertex) { return OculusXRHMD::ToFVector(Vertex); });
		return true;
		return false;
	}
} // namespace OculusXRAnchors
