// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRSpatialAnchorComponent.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRRoomLayoutManagerComponent.generated.h"

UCLASS(meta = (DisplayName = "OculusXR Room Layout Manager Component", BlueprintSpawnableComponent))
class OCULUSXRANCHORS_API UOculusXRRoomLayoutManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOculusXRRoomLayoutManagerComponent(const FObjectInitializer& ObjectInitializer);

	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

	virtual void OnRegister() override;
	virtual void OnUnregister() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOculusXRRoomLayoutSceneCaptureCompleteDelegate,
		FOculusXRUInt64, requestId,
		bool, result);

	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRRoomLayoutSceneCompleteNativeDelegate, FOculusXRUInt64 /*requestId*/, bool /*success*/);
	FOculusXRRoomLayoutSceneCompleteNativeDelegate OculusXRRoomLayoutSceneCaptureCompleteNative;

	UPROPERTY(BlueprintAssignable, Category = "OculusXR|Room Layout Manager")
	FOculusXRRoomLayoutSceneCaptureCompleteDelegate OculusXRRoomLayoutSceneCaptureComplete;

	// Requests to launch Capture Flow
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Room Layout Manager")
	bool LaunchCaptureFlow();

	// Gets room layout for a specific space
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Room Layout Manager")
	bool GetRoomLayout(FOculusXRUInt64 Space, UPARAM(ref) FOculusXRRoomLayout& RoomLayoutOut, int32 MaxWallsCapacity = 64);

	// Loads mesh data (vertices, indeces) associated with the space into UProceduralMeshComponent
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Room Layout Manager")
	bool LoadTriangleMesh(FOculusXRUInt64 Space, class UProceduralMeshComponent* Mesh, bool CreateCollision) const;

protected:
	UPROPERTY(Transient)
	TSet<uint64> EntityRequestList;

	UPROPERTY(Transient)
	TMap<FOculusXRUInt64, FOculusXRRoomLayout> RoomLayouts;

private:
	UFUNCTION()
	void OculusRoomLayoutSceneCaptureComplete_Handler(FOculusXRUInt64 RequestId, bool bSuccess)
	{
		if (EntityRequestList.Find(RequestId.Value) != nullptr)
		{
			OculusXRRoomLayoutSceneCaptureComplete.Broadcast(RequestId, bSuccess);
			OculusXRRoomLayoutSceneCaptureCompleteNative.Broadcast(RequestId, bSuccess);
			EntityRequestList.Remove(RequestId.Value);
		}
	}
};
