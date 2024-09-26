// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGridSliceResizerVisualization.h"

#include "MRUtilityKitGridSliceResizer.h"
#include "ProceduralMeshComponent.h"

namespace
{
	void DrawSliceBorder(FPrimitiveDrawInterface* PDI, FVector Scale, FVector Pivot, FVector ScaledPivot, const UProceduralMeshComponent* ProcMesh, const FVector& Size, double BorderPos, double BorderNeg, int32 Axis)
	{
		// Scaled bounding box of the mesh that gets displayed
		FBox BBox = ProcMesh->GetLocalBounds().GetBox();
		BBox.Min *= Scale;
		BBox.Max *= Scale;

		const FVector InvSize = FVector(1.0, 1.0, 1.0) / Scale;
		// Unscaled bounding box
		const FBox BBoxOriginal = FBox(BBox.Min * InvSize, BBox.Max * InvSize);

		double Positive = BBox.Max[Axis] - (BBoxOriginal.Max[Axis] - (FMath::Abs(BBoxOriginal.Max[Axis] - Pivot[Axis]) * BorderPos + Pivot[Axis]));
		if (Positive + Pivot[Axis] < 0.0)
		{
			// Clamp to the bounding box in case the bounding box is smaller than the stubs
			Positive = BBox.Max[Axis];
		}
		if (Pivot[Axis] > BBox.Max[Axis])
		{
			// Clamp to the pivot if the pivot is outside of the bounding box
			Positive = FMath::Min(ScaledPivot[Axis], Positive);
		}

		double Negative = BBox.Min[Axis] - (BBoxOriginal.Min[Axis] - (-FMath::Abs(BBoxOriginal.Min[Axis] - Pivot[Axis]) * BorderNeg + Pivot[Axis]));
		if (Negative - Pivot[Axis] > 0.0)
		{
			// Clamp to the bounding box in case the bounding box is smaller than the stubs
			Negative = BBox.Min[Axis];
		}
		if (Pivot[Axis] < BBox.Min[Axis])
		{
			// Clamp to the pivot if the pivot is outside of the bounding box
			Negative = FMath::Max(ScaledPivot[Axis], Negative);
		}

		double PosNeg[2] = { Positive, Negative };
		for (int32 J = 0; J < 2; ++J)
		{
			FVector Max;
			FVector Min;
			for (int32 I = 0; I < 3; ++I)
			{
				if (I == Axis)
				{
					Min[I] = PosNeg[J];
					Max[I] = PosNeg[J];
				}
				else
				{
					Min[I] = BBox.Min[I];
					Max[I] = BBox.Max[I];
				}
			}

			// TODO: Fix visualization for in editor playing. Meaning applying the world transform.
			const FBox Box(Min, Max);
			DrawWireBox(PDI, Box, FLinearColor(1.0f, 0.0f, 0.0f), SDPG_Foreground, 0.2f);
		}
	}
} // namespace

void FMRUKGridSliceResizerVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	const UMRUKGridSliceResizerComponent* Resizer = Cast<const UMRUKGridSliceResizerComponent>(Component);
	if (!Resizer || !Resizer->GetOwner())
	{
		return;
	}

	const FVector Size = Resizer->GetOwner()->GetActorScale();
	const FVector Location = Resizer->GetComponentLocation();
	const FVector Pivot = Location + Resizer->SlicerPivotOffset;
	const FVector ScaledPivot = Location + Resizer->SlicerPivotOffset * Size;

	if (Resizer->bDebugDrawPivot)
	{
		// Draw pivot
		DrawWireSphere(PDI, ScaledPivot, FLinearColor(0.0f, 1.0f, 1.0f), 2.0, 16, SDPG_Foreground, 0.5f);
	}

	if (const auto ProcMesh = Resizer->GetOwner()->GetComponentByClass<UProceduralMeshComponent>())
	{
		if (Resizer->bDebugDrawBorderX)
		{
			DrawSliceBorder(PDI, Size, Pivot, ScaledPivot, ProcMesh, Size, Resizer->BorderXPositive, Resizer->BorderXNegative, 0);
		}
		if (Resizer->bDebugDrawBorderY)
		{
			DrawSliceBorder(PDI, Size, Pivot, ScaledPivot, ProcMesh, Size, Resizer->BorderYPositive, Resizer->BorderYNegative, 1);
		}
		if (Resizer->bDebugDrawBorderZ)
		{
			DrawSliceBorder(PDI, Size, Pivot, ScaledPivot, ProcMesh, Size, Resizer->BorderZPositive, Resizer->BorderZNegative, 2);
		}
	}
}
