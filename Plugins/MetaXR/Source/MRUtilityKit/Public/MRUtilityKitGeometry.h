// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Math/Vector2D.h"

struct FMRUKOutline
{
	TArray<FVector2D> Vertices;
	TArray<int32> Indices;
};

MRUTILITYKIT_API TArray<int32> MRUKTriangulatePoints(const TArray<FVector2D>& Vertices);

MRUTILITYKIT_API TArray<int32> MRUKTriangulateMesh(const FMRUKOutline& Outline);

MRUTILITYKIT_API FMRUKOutline MRUKComputeOutline(TArray<FVector2D> Vertices, TArray<TArray<FVector2D>> Holes);

MRUTILITYKIT_API bool MRUKFindLineIntersection(const FVector2D& Start1, const FVector2D& End1, const FVector2D& Start2, const FVector2D& End2, FVector2D& OutIntersection, double& OutU1, double& OutU2);

MRUTILITYKIT_API void MRUKClipPolygon(TArray<FVector2D>& Vertices, TArray<FVector2D>& Hole);
