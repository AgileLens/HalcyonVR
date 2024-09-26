// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MRUtilityKitGridSliceResizer.generated.h"

UENUM(BlueprintType, Meta = (Bitflags))
enum class EMRUKScaleCenterMode : uint8
{
	None = 0 UMETA(Hidden),
	XAxis = 1,
	YAxis = 2,
	ZAxis = 4,
};

/**
 * The GridSliceResizerComponent is a versatile tool designed to maintain the proportions of
 * specific areas of 3D meshes while allowing others to stretch during scaling. This component
 * should replace the static mesh component, rather than being used in conjunction with it.
 *
 * The concept of the GridSliceResizerComponent is similar to the popular 9-Slice-Scaling technique
 * used in 2D graphics, which keeps the borders of sprites unstretched while the inner rectangle is
 * stretched. In essence, the GridSliceResizerComponent is a 27-Slice-Scaler for 3D meshes.
 *
 * The component operates by dividing the bounding box of a 3D mesh into 27 cuboids, as illustrated below.
 * Not all cuboids are visible in this picture. Only the once that are front facing:
 *
 *     +-----+-----------+-----+
 *    /_____/___________/_____/|
 *   /_____/___________/_____/||
 *  /     /           /     /|||
 * +-----+-----------+-----+ |||
 * |  A  |     B     |  C  |/|||
 * +-----+-----------+-----+ |||
 * |     |           |     | |||
 * |  D  |     E     |  F  | |||
 * |     |           |     |/||/
 * +-----+-----------+-----+ |/
 * |  G  |     H     |  I  | /
 * +-----+-----+-----+-----+
 *
 * The scaling behaviour is as follows (assuming all other faces of the bounding box are divided as the
 * front facing one):
 *
 * Center Cuboid (E): Vertices within this cuboid stretch on two axes (Y, Z).
 * Corner Cuboids (A, C, G, I): These cuboids do not stretch on any axis.
 * Middle Cuboids (B, H): These cuboids stretch horizontally but not vertically.
 * Middle Cuboids (D, F): These cuboids stretch vertically but not horizontally.
 *
 * The slicing areas are defined by the SlicerPivotOffset and BorderXNegative, BorderXPositive, etc.
 * These border values range from 0 to 1 and extend from the mesh's pivot (which may be offset by SlicerPivotOffset)
 * to the maximum or minimum of the bounding box's axis.
 * If all borders are set to 1, the mesh will stretch like a regular mesh during scaling. If set to 0, no stretching
 * will occur. Typically, you'll want the pivot in the middle of the mesh and the borders set to around 0.8.
 *
 * You can visualize the borders and pivot in the Actor editor preview using bDebugDrawPivot, bDebugDrawBorderX, etc.
 *
 * This component is only compatible with static meshes that have CPU access enabled. Ensure you enable CPU
 * access in the static mesh editor.
 */
UCLASS(ClassGroup = MRUtilityKit, Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent, DisplayName = "MR Utility Kit Grid Slice Resizer Component"))
class MRUTILITYKIT_API UMRUKGridSliceResizerComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	/**
	 * The static mesh to slice. Make sure to enable CPU access on it.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	class UStaticMesh* Mesh;

	/**
	 * Slice border for the negative X axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderXNegative = 1.0;

	/**
	 * Slice border for the positive X axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderXPositive = 1.0;

	/**
	 * Slice border for the negative Y axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderYNegative = 1.0;

	/**
	 * Slice border for the positive Y axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderYPositive = 1.0;

	/**
	 * Slice border for the negative Z axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderZNegative = 1.0;

	/**
	 * Slice border for the positive Z axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit|Slices", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	double BorderZPositive = 1.0;

	/**
	 * How much the meshes pivot should be offset when applying the slice borders.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	FVector SlicerPivotOffset;

	/**
	 * This parameter determines whether the center part of the object should be scaled.
	 * If set to false, the center vertices will remain stationary. This is particularly useful when
	 * you want to maintain the proportions of certain geometrical features in the center part, such
	 * as a doorknob. By keeping the center vertices in place, you can avoid unwanted stretching effects,
	 * resulting in a more visually appealing outcome.
	 * However, it's important to note that for a convincing visual effect, the texture applied to the object should also not stretch.
	 * If you encounter issues with texture stretching, consider adding an additional loop cut.
	 * This can help maintain the texture's proportions and prevent it from distorting.
	 * In case the mesh gets scaled down and some of the center vertices fall outside of the scaled down center
	 * all vertices that are inside the center will be scaled down uniformly.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit", meta = (Bitmask, BitmaskEnum = "EMRUKScaleCenterMode"))
	uint8 ScaleCenterMode = 0;

	/**
	 * Whether or not a collision mesh should be created for the static mesh.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool bGenerateCollision = true;

#if WITH_EDITORONLY_DATA
	/**
	 * Show the pivot of the mesh that gets used for the slice borders.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool bDebugDrawPivot = false;

	/**
	 * Show the slice borders on the X axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool bDebugDrawBorderX = false;

	/**
	 * Show the slice borders on the Y axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool bDebugDrawBorderY = false;

	/**
	 * Show the slice borders on the Z axis.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool bDebugDrawBorderZ = false;
#endif

	/**
	 * Slice the mesh. This gets automatically called whenever
	 * the scale of the owning Actor changes.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void SliceMesh();

public:
	UMRUKGridSliceResizerComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
	virtual void OnRegister() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	friend class FMRUKGridSliceResizerSpec;

	UPROPERTY(Transient)
	class UProceduralMeshComponent* ProcMesh;

	FVector ResizerScale = FVector::OneVector;
};
