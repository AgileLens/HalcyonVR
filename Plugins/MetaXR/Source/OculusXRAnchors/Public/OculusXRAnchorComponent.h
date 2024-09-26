// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRAnchorTypes.h"
#include "Components/ActorComponent.h"
#include "OculusXRAnchorComponent.generated.h"

UCLASS(meta = (DisplayName = "Oculus Anchor Component"))
class OCULUSXRANCHORS_API UOculusXRAnchorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UOculusXRAnchorComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintPure, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	FOculusXRUInt64 GetHandle() const;

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	void SetHandle(FOculusXRUInt64 Handle);

	UFUNCTION(BlueprintPure, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	bool HasValidHandle() const;

	UFUNCTION(BlueprintPure, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	FOculusXRUUID GetUUID() const;

	void SetUUID(FOculusXRUUID NewUUID);

	UFUNCTION(BlueprintPure, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	bool IsStoredAtLocation(EOculusXRSpaceStorageLocation Location) const;

	// Not exposed to BP because this is managed in code
	void SetStoredLocation(EOculusXRSpaceStorageLocation Location, bool Stored);

	UFUNCTION(BlueprintPure, Category = "OculusXR|Anchor", meta = (DefaultToSelf = Target))
	bool IsSaved() const;

protected:
	bool bUpdateHeadSpaceTransform;

private:
	FOculusXRUInt64 AnchorHandle;
	FOculusXRUUID AnchorUUID;
	int32 StorageLocations;

	UPROPERTY()
	class APlayerCameraManager* PlayerCameraManager;

	void UpdateAnchorTransform() const;
	bool ToWorldSpacePose(FTransform CameraTransform, FTransform& OutTrackingSpaceTransform) const;
};
