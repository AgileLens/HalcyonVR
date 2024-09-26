// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitSeatsComponent.h"
#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitRoom.h"
#include "Kismet/KismetMathLibrary.h"

void UMRUKSeatsComponent::CalculateSeatPoses(double SeatWidth)
{
	const auto Anchor = Cast<AMRUKAnchor>(GetOwner());
	if (!Anchor)
	{
		return;
	}

	SeatPoses.Empty();

	const auto SurfaceDimensions = Anchor->PlaneBounds.GetExtent();
	const auto SurfaceRatio = SurfaceDimensions.X / SurfaceDimensions.Y;
	const auto SeatForward = Anchor->GetFacingDirection();
	const auto SeatUp = FVector::UpVector;
	const auto SeatRotation = UKismetMathLibrary::MakeRotFromXZ(SeatForward, SeatUp).Quaternion();

	if (SurfaceRatio < 2.0 && SurfaceRatio > 0.5)
	{
		// If the surface dimensions are mostly square (likely a chair), just have one centered seat.
		FTransform SeatPose{};
		SeatPose.SetLocation(Anchor->GetActorLocation());
		SeatPose.SetRotation(SeatRotation);
		SeatPoses.Add(SeatPose);
	}
	else
	{
		const auto XLong = SurfaceDimensions.X > SurfaceDimensions.Y;
		const auto LongestDimension = XLong ? SurfaceDimensions.X : SurfaceDimensions.Y;
		const auto NumSeats = FMath::Floor(LongestDimension / SeatWidth);

		const auto SeatPadding = (LongestDimension - (NumSeats * SeatWidth)) / NumSeats;
		const auto FirstSeatOffset = (-LongestDimension + SeatPadding + SeatWidth) * 0.5;

		for (int i = 0; i < NumSeats; ++i)
		{
			const auto SeatRight = XLong ? Anchor->GetActorRightVector() : Anchor->GetActorUpVector();

			const auto Offset = FirstSeatOffset + (SeatWidth + SeatPadding) * i;
			const auto SeatPosition = Anchor->GetActorLocation() + SeatRight * Offset;

			FTransform SeatPose{};
			SeatPose.SetLocation(SeatPosition);
			SeatPose.SetRotation(SeatRotation);
			SeatPoses.Add(SeatPose);
		}
	}
}
