// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Modules/ModuleManager.h"
#include "GameFramework/Actor.h"

#include "MRUtilityKit.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMRUK, Log, All);

UENUM(BlueprintType)
enum class EMRUKInitStatus : uint8
{
	/// Not Initialized.
	None,
	/// Is busy Initializing.
	Busy,
	/// Has finished Initializing.
	Complete,
	/// Failed to initialize.
	Failed,
};

UENUM(BlueprintType)
enum class EMRUKCoordModeU : uint8
{
	/// The texture coordinates start at 0 and increase by 1 unit every meter.
	Metric,
	/// The texture coordinates start at 0 and increase by 1 unit every meter but are adjusted to end on a whole number to avoid seams.
	MetricSeamless,
	/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained.
	MaintainAspectRatio,
	/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained but are adjusted to end on a whole number to avoid seams.
	MaintainAspectRatioSeamless,
	/// The texture coordinates range from 0 to 1.
	Stretch,
};

UENUM(BlueprintType)
enum class EMRUKCoordModeV : uint8
{
	/// The texture coordinates start at 0 and increase by 1 unit every meter.
	Metric,
	/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained.
	MaintainAspectRatio,
	/// The texture coordinates range from 0 to 1.
	Stretch,
};

UENUM(BlueprintType)
enum class EMRUKSpawnerSelectionMode : uint8
{
	/// Pick one at random.
	Random,
	/// Pick the closest size.
	ClosestSize,
	/// Used in the AMRUKAnchorActorSpawner to use allow for a custom selection mode.
	Custom,
};

UENUM(BlueprintType)
enum class EMRUKSpawnerScalingMode : uint8
{
	/// Stretch each axis to exactly match the size of the Plane/Volume.
	Stretch,
	/// Scale each axis by the same amount to maintain the correct aspect ratio.
	UniformScaling,
	/// Scale the X and Y axes uniformly but the Z scale can be different.
	UniformXYScale,
	/// Don't perform any scaling.
	NoScaling,
	/// Used in the AMRUKAnchorActorSpawner to use allow for a custom scaling.
	Custom,
};

UENUM(BlueprintType)
enum class EMRUKAlignMode : uint8
{
	/// Do not perform any alignment
	None,
	/// Align the bottom of the bounding boxes and center the rest
	Default,
	/// Center the bounding box in the anchor bounding box
	CenterOnCenter,
	/// Align the bottom of the bounding boxes and center the rest
	BottomOnBottom,
	/// Align the top of the bounding boxes and center the rest
	TopOnTop,
	/// Align the left of the bounding boxes and center the rest
	LeftOnLeft,
	/// Align the right of the bounding boxes and center the rest
	RightOnRight,
	/// Align the front of the bounding boxes and center the rest
	FrontOnFront,
	/// Align the back of the bounding boxes and center the rest
	BackOnBack,
	/// Align the top to the bottom of the anchor bounding box and center the rest
	BottomOnTop,
	/// Align the bottom to the top of the anchor bounding box and center the rest
	TopOnBottom,
	/// Align the left to the right of the anchor bounding box and center the rest
	LeftOnRight,
	/// Align the right to the left of the anchor bounding box and center the rest
	RightOnLeft,
	/// Align the front to the back of the anchor bounding box and center the rest
	FrontOnBack,
	/// Align the back to the front of the anchor bounding box and center the rest
	BackOnFront,
	/// Use custom alignment mode
	Custom,
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKHit
{
	GENERATED_BODY()

	/**
	 * The position where the raycast hit.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "MR Utility Kit")
	FVector HitPosition = FVector::ZeroVector;

	/**
	 * The normal of the surface that was hit.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "MR Utility Kit")
	FVector HitNormal = FVector::ZeroVector;

	/**
	 * The distance between the origin of the ray to the hit position.
	 */
	UPROPERTY(BlueprintReadOnly, Category = "MR Utility Kit")
	float HitDistance = 0.0f;
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKLabelFilter
{
	GENERATED_BODY()

	/**
	 * If included labels is not empty then the anchor must have at
	 * least one of the labels in this list.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TArray<FString> IncludedLabels;

	/**
	 * Anchors with any of the labels in this exclusion list
	 * will be ignored.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TArray<FString> ExcludedLabels;

	/**
	 * Check if the labels pass the given label filter
	 * @param Labels The labels to check.
	 * @return Whether the filter passes or not.
	 */
	bool PassesFilter(const TArray<FString>& Labels) const;
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKPlaneUV
{
	GENERATED_BODY()

	/**
	 * Offset applied to the UV texture coordinates.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	FVector2D Offset = FVector2D::ZeroVector;

	/**
	 * Scale applied to the UV texture coordinates.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	FVector2D Scale = FVector2D::UnitVector;
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKTexCoordModes
{
	GENERATED_BODY()

	/**
	 * Texture Coordinate mode for the U direction.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKCoordModeU U = EMRUKCoordModeU::Metric;

	/**
	 * Texture Coordinate mode for the V direction.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKCoordModeV V = EMRUKCoordModeV::Metric;
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKSpawnActor
{
	GENERATED_BODY()

	/**
	 * The class of actor to spawn.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TSubclassOf<AActor> Actor;

	/**
	 * When match aspect ratio is enabled then the actor will be rotated
	 * to try and match the aspect ratio of the volume as closely as possible.
	 * This is most useful for long and thin volumes, keep this disabled for
	 * objects with an aspect ratio close to 1:1. Only applies to volumes.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	bool MatchAspectRatio = false;

	/**
	 * When calculate facing direction is enabled the actor will be rotated to
	 * face away from the closest wall. If match aspect ratio is also enabled
	 * then that will take precedence and it will be constrained to a choice
	 * between 2 directions only. Only applies to volumes.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	bool CalculateFacingDirection = false;

	/**
	 * Set what scaling mode to apply to the actor. By default the actor will
	 * be stretched to fit the size of the plane/volume. But in some cases
	 * this may not be desirable and can be customized here.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKSpawnerScalingMode ScalingMode = EMRUKSpawnerScalingMode::Stretch;

	/**
	 * Set what alignment mode to apply to the actor. By default the actor will
	 * be aligned that its bounding box matches the one from the anchor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKAlignMode AlignMode = EMRUKAlignMode::Default;
};

UENUM(BlueprintType)
enum class EMRUKFallbackToProceduralOverwrite : uint8
{
	/// Don't override the fallback to procedural standard behaviour.
	Default,
	/// Fallback to a procedural mesh.
	Fallback,
	/// Don't fallback to a procedural mesh.
	NoFallback,
};

USTRUCT(BlueprintType)
struct MRUTILITYKIT_API FMRUKSpawnGroup
{
	GENERATED_BODY()

	/**
	 * List of actors to choose from, multiple actors can be specified and
	 * the selection criteria will be determined by the SelectionMode option.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TArray<FMRUKSpawnActor> Actors;

	/**
	 * Set the selection mode when multiple different actors are specified.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKSpawnerSelectionMode SelectionMode = EMRUKSpawnerSelectionMode::Random;

	/**
	 * Control if there should happen a fallback to spawning a procedural mesh
	 * in case no actor class has been specified for this label. The global
	 * fallback behaviour can be specified in the AMRUKAnchorActorSpawner.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKFallbackToProceduralOverwrite FallbackToProcedural = EMRUKFallbackToProceduralOverwrite::Default;
};

/**
 * Implements the settings for the MRUtilityKit plugin.
 */
UCLASS(config = Game, defaultconfig)
class MRUTILITYKIT_API UMRUKSettings : public UObject
{
	GENERATED_BODY()

public:
	UMRUKSettings(const FObjectInitializer& obj);

	/**
	 * When world locking is enabled the position of the VR Pawn will be adjusted each frame to ensure
	 * the room anchors are where they should be relative to the camera position. This is necessary to
	 * ensure the position of the virtual objects in the world do not get out of sync with the real world.
	 */
	UPROPERTY(config, EditAnywhere, Category = "MR Utility Kit")
	bool EnableWorldLock = true;

};

struct MRUTILITYKIT_API FMRUKLabels
{
	static const FString Floor;
	static const FString WallFace;
	static const FString InvisibleWallFace;
	static const FString Ceiling;
	static const FString DoorFrame;
	static const FString WindowFrame;
	static const FString Couch;
	static const FString Table;
	static const FString Screen;
	static const FString Bed;
	static const FString Lamp;
	static const FString Plant;
	static const FString Storage;
	static const FString WallArt;
	static const FString GlobalMesh;
	static const FString Other;
};

UENUM(BlueprintType)
enum class EMRUKSpawnMode : uint8
{
	/// Do not spawn anything on loading a scene or rooms.
	None = 0,

	/// Will only take the current room into account. This enables legacy single room behaviour. Keep in mind that if your
	/// experience loads multiple rooms and you use that mode the behaviour might be undefined.
	CurrentRoomOnly,

	/// Spawn in every room and keep on spawning whenever a new room was discovered.
	AllRooms
};

class FMRUKModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
