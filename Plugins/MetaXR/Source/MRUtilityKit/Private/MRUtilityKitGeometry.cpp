// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGeometry.h"

#include "MRUtilityKit.h"

namespace
{
	bool IsConvex(const FVector2D& PrevPoint, const FVector2D& CurrPoint, const FVector2D& NextPoint)
	{
		const FVector2D Edge1 = PrevPoint - CurrPoint;
		const FVector2D Edge2 = NextPoint - CurrPoint;

		const double CrossProductZ = Edge1.X * Edge2.Y - Edge1.Y * Edge2.X;

		return CrossProductZ <= 0;
	}

	bool PointInTriangle(const FVector2D& A, const FVector2D& B, const FVector2D& C, const FVector2D& P)
	{
		const FVector2D AB = B - A;
		const FVector2D BC = C - B;
		const FVector2D CA = A - C;

		const FVector2D AP = P - A;
		const FVector2D BP = P - B;
		const FVector2D CP = P - C;

		const double CrossProductZ1 = AB.X * AP.Y - AB.Y * AP.X;
		const double CrossProductZ2 = BC.X * BP.Y - BC.Y * BP.X;
		const double CrossProductZ3 = CA.X * CP.Y - CA.Y * CP.X;

		return ((CrossProductZ1 >= 0) && (CrossProductZ2 >= 0) && (CrossProductZ3 >= 0)) || ((CrossProductZ1 <= 0) && (CrossProductZ2 <= 0) && (CrossProductZ3 <= 0));
	}

	bool IsEar(const TArray<FVector2D>& Vertices, const TArray<int32>& Indices, int32 PrevIndex, int32 CurrIndex, int32 NextIndex)
	{
		const int32 NumPoints = Indices.Num();

		const FVector2D& PrevPoint = Vertices[PrevIndex];
		const FVector2D& CurrPoint = Vertices[CurrIndex];
		const FVector2D& NextPoint = Vertices[NextIndex];

		for (int32 i = 0; i < NumPoints; ++i)
		{
			const int32 Index = Indices[i];
			if (Index != PrevIndex && Index != CurrIndex && Index != NextIndex)
			{
				const FVector2D TestPoint = Vertices[Index];

				if (PointInTriangle(PrevPoint, CurrPoint, NextPoint, TestPoint))
				{
					return false;
				}
			}
		}

		return true;
	}

	bool IsPositionInPolygon(const FVector2D& Position, TArray<FVector2D>& Polygon)
	{
		int LineCrosses = 0;
		for (int i = 0; i < Polygon.Num(); i++)
		{
			const FVector2D& P1 = Polygon[i];
			const FVector2D& P2 = Polygon[(i + 1) % Polygon.Num()];

			if (Position.Y > FMath::Min(P1.Y, P2.Y) && Position.Y <= FMath::Max(P1.Y, P2.Y))
			{
				if (Position.X <= FMath::Max(P1.X, P2.X))
				{
					if (P1.Y != P2.Y)
					{
						const double Frac = (Position.Y - P1.Y) / (P2.Y - P1.Y);
						const double XIntersection = P1.X + Frac * (P2.X - P1.X);
						if (P1.X == P2.X || Position.X <= XIntersection)
						{
							++LineCrosses;
						}
					}
				}
			}
		}

		return (LineCrosses % 2) == 1;
	}

	FVector2D Perpendicular(const FVector2D& A)
	{
		return { -A.Y, A.X };
	}
} // namespace

TArray<int32> MRUKTriangulatePoints(const TArray<FVector2D>& Vertices)
{
	TArray<int32> Indices;

	Indices.Reserve(Vertices.Num());
	for (int i = 0; i < Vertices.Num(); ++i)
	{
		Indices.Push(i);
	}

	return MRUKTriangulateMesh({ Vertices, Indices });
}

TArray<int32> MRUKTriangulateMesh(const FMRUKOutline& Outline)
{
	const TArray<FVector2D>& Vertices = Outline.Vertices;
	TArray<int32> Indices = Outline.Indices;
	TArray<int32> Triangles;
	Triangles.Reserve(3 * FMath::Max(Indices.Num() - 2, 0));

	while (Indices.Num() > 3)
	{
		bool EarFound = false;

		for (int32 i = 0; i < Indices.Num(); ++i)
		{
			int32 PrevIndex = Indices[(i + Indices.Num() - 1) % Indices.Num()];
			int32 CurrIndex = Indices[i];
			int32 NextIndex = Indices[(i + 1) % Indices.Num()];

			if (IsConvex(Vertices[PrevIndex], Vertices[CurrIndex], Vertices[NextIndex]) && IsEar(Vertices, Indices, PrevIndex, CurrIndex, NextIndex))
			{
				Triangles.Add(PrevIndex);
				Triangles.Add(CurrIndex);
				Triangles.Add(NextIndex);

				Indices.RemoveAt(i);
				EarFound = true;
				break;
			}
		}

		if (!EarFound)
		{
			UE_LOG(LogMRUK, Error, TEXT("Failed to triangulate points."));
			break;
		}
	}

	if (Indices.Num() == 3)
	{
		Triangles.Append(Indices);
	}

	return Triangles;
}

FMRUKOutline MRUKComputeOutline(TArray<FVector2D> Vertices, TArray<TArray<FVector2D>> Holes)
{
	for (int32 I = 0; I < Holes.Num();)
	{
		MRUKClipPolygon(Vertices, Holes[I]);
		if (Holes[I].IsEmpty())
		{
			// Hole was merged or removed, so remove it from the list
			Holes.RemoveAt(I);
		}
		else
		{
			++I;
		}
	}

	FMRUKOutline Outline{};
	Outline.Vertices = Vertices;

	int32 TotalVerticesCount = Vertices.Num();
	for (const TArray<FVector2D>& Hole : Holes)
	{
		TotalVerticesCount += Hole.Num();
	}

	Outline.Vertices.Reserve(TotalVerticesCount);
	Outline.Indices.Reserve(TotalVerticesCount + 2 * Holes.Num());

	for (int32 I = 0; I < Vertices.Num(); ++I)
	{
		Outline.Indices.Push(I);
	}

	while (Holes.Num() > 0)
	{
		double MaxX = -DBL_MAX;
		int32 HoleToMerge = -1;
		int32 VertexToMerge = -1;
		for (int32 I = 0; I < Holes.Num(); ++I)
		{
			const TArray<FVector2D>& Hole = Holes[I];
			check(Hole.Num() == 4);
			for (int32 J = 0; J < Hole.Num(); ++J)
			{
				const FVector2D& Vertex = Hole[J];
				if (Vertex.X > MaxX)
				{
					MaxX = Vertex.X;
					HoleToMerge = I;
					VertexToMerge = J;
				}
			}
		}
		check(Holes.Num() > 0);
		check(HoleToMerge != -1);

		const FVector2D& HolePosition = Holes[HoleToMerge][VertexToMerge];
		double ClosestXIntersection = DBL_MAX;
		int32 MergeWithIndex = -1;
		FVector2D MergeWith{};
		for (int32 I = 0; I < Outline.Indices.Num(); ++I)
		{
			const int32 I1 = Outline.Indices[I];
			const int32 I2 = Outline.Indices[(I + 1) % Outline.Indices.Num()];

			const FVector2D& P1 = Outline.Vertices[I1];
			const FVector2D& P2 = Outline.Vertices[I2];

			if ((P1.Y != P2.Y) && (P2.Y >= HolePosition.Y && P1.Y <= HolePosition.Y))
			{
				const double Frac = (HolePosition.Y - P1.Y) / (P2.Y - P1.Y);
				const double XIntersection = P1.X + Frac * (P2.X - P1.X);
				if (XIntersection >= HolePosition.X && XIntersection < ClosestXIntersection)
				{
					ClosestXIntersection = XIntersection;
					MergeWithIndex = I;
					MergeWith = P1;
				}
			}
		}
		if (MergeWithIndex != -1)
		{
			FVector2D Intersection(ClosestXIntersection, HolePosition.Y);
			const int32 MergeWithVertexIndex = Outline.Indices[MergeWithIndex];
			for (int32 I = 0; I < Outline.Indices.Num(); ++I)
			{
				const int32 PrevVertexIndex = Outline.Indices[(I + Outline.Indices.Num() - 1) % Outline.Indices.Num()];
				const int32 VertexIndex = Outline.Indices[I];
				const int32 NextVertexIndex = Outline.Indices[(I + 1) % Outline.Indices.Num()];

				FVector2D PrevVertex = Outline.Vertices[PrevVertexIndex];
				FVector2D CandidateVertex = Outline.Vertices[VertexIndex];
				FVector2D NextVertex = Outline.Vertices[NextVertexIndex];
				if (MergeWithVertexIndex != VertexIndex && !IsConvex(PrevVertex, CandidateVertex, NextVertex))
				{
					if (CandidateVertex.X < MergeWith.X && CandidateVertex.X > HolePosition.X && PointInTriangle(HolePosition, MergeWith, Intersection, CandidateVertex))
					{
						MergeWith = CandidateVertex;
						MergeWithIndex = I;
					}
				}
			}

			const int32 StartIndex = Outline.Vertices.Num();
			const int32 HoleVertexCount = Holes[HoleToMerge].Num();
			TArray<int32> InsertedIndices;
			InsertedIndices.Reserve(HoleVertexCount + 2);
			Outline.Vertices.Append(Holes[HoleToMerge]);
			for (int32 J = 0; J < HoleVertexCount; ++J)
			{
				InsertedIndices.Push(StartIndex + (J + VertexToMerge) % HoleVertexCount);
			}
			InsertedIndices.Add(StartIndex + VertexToMerge);
			InsertedIndices.Add(Outline.Indices[MergeWithIndex]);
			Outline.Indices.Insert(InsertedIndices, MergeWithIndex + 1);
		}
		Holes.RemoveAt(HoleToMerge);
	}

	return Outline;
}

bool MRUKFindLineIntersection(const FVector2D& Start1, const FVector2D& End1, const FVector2D& Start2, const FVector2D& End2, FVector2D& OutIntersection, double& OutU1, double& OutU2)
{
	// Calculate direction vectors
	const FVector2D Dir1 = End1 - Start1;
	const FVector2D Dir2 = End2 - Start2;

	// Calculate normal vector
	const FVector2D Perp1 = Perpendicular(Dir1);
	const FVector2D Perp2 = Perpendicular(Dir2);

	// Calculate dot product
	const double Dot = Perp2.Dot(Dir1);

	// Check if lines are parallel
	if (Dot == 0)
	{
		OutU1 = 0.0;
		OutU2 = 0.0;
		OutIntersection = FVector2D::ZeroVector;
		return false; // No intersection
	}

	// Calculate distance to intersection point
	OutU1 = Perp2.Dot(Start2 - Start1) / Dot;
	OutU2 = Perp1.Dot(Start2 - Start1) / Dot;

	OutIntersection = Start1 + (End1 - Start1) * OutU1;

	return OutU1 >= 0.0 && OutU1 <= 1.0 && OutU2 >= 0.0 && OutU2 <= 1.0;
}

struct FMergedVertex
{
	FVector2D Position;
	int32 NextVertex;
	int32 NextHole;
};

void MRUKClipPolygon(TArray<FVector2D>& Vertices, TArray<FVector2D>& Hole)
{
	TArray<FMergedVertex> MergedVertices;
	MergedVertices.Reserve(Vertices.Num() + Hole.Num());

	for (int32 I = 0; I < Vertices.Num(); ++I)
	{
		MergedVertices.Push({ Vertices[I], (I + 1) % Vertices.Num(), -1 });
	}

	const int32 HoleStart = Vertices.Num();
	for (int32 I = 0; I < Hole.Num(); ++I)
	{
		for (int32 J = 0; J < Vertices.Num(); ++J)
		{
			ensureMsgf(Hole[I] != Vertices[J], TEXT("Overlapping vertices and holes are not supported"));
		}
		MergedVertices.Push({ Hole[I], -1, HoleStart + (I + 1) % Hole.Num() });
	}

	// Iterate through all the edges of the vertices polygon
	bool FoundIntersection = false;
	int32 VertexStart = 0;
	int32 VertexIndex = VertexStart;
	while (true)
	{
		FMergedVertex MergedVertex = MergedVertices[VertexIndex];
		const FVector2D& O1 = MergedVertices[VertexIndex].Position;
		const FVector2D& O2 = MergedVertices[MergedVertex.NextVertex].Position;

		double ClosestU = DBL_MAX;
		FVector2D ClosestIntersect = FVector2D::ZeroVector;
		int32 ClosestHoleIndex = -1;

		// Iterate through all the edges of the hole polygon and find the closest intersection to O1
		int32 HoleIndex = HoleStart;
		while (true)
		{
			const FMergedVertex& HoleMerged = MergedVertices[HoleIndex];
			const FVector2D& H1 = MergedVertices[HoleIndex].Position;
			const FVector2D& H2 = MergedVertices[HoleMerged.NextHole].Position;

			if (HoleIndex != VertexIndex && HoleMerged.NextHole != VertexIndex && HoleIndex != MergedVertex.NextVertex && HoleMerged.NextHole != MergedVertex.NextVertex)
			{
				FVector2D Intersection = FVector2D::ZeroVector;
				double U1 = 0.0, U2 = 0.0;
				if (MRUKFindLineIntersection(O1, O2, H1, H2, Intersection, U1, U2))
				{
					if (U1 < ClosestU)
					{
						ClosestU = U1;
						ClosestIntersect = Intersection;
						ClosestHoleIndex = HoleIndex;
					}
				}
			}

			HoleIndex = HoleMerged.NextHole;
			if (HoleIndex == HoleStart)
			{
				break;
			}
		}

		// If an intersection was found then create a new vertex at the intersection point and update
		// the linked list pointers to insert it
		if (ClosestHoleIndex != -1)
		{
			FoundIntersection = true;
			FMergedVertex HoleMerged = MergedVertices[ClosestHoleIndex];
			MergedVertices.Push({ ClosestIntersect, MergedVertex.NextVertex, HoleMerged.NextHole });

			MergedVertex.NextVertex = MergedVertices.Num() - 1;
			MergedVertices[VertexIndex] = MergedVertex;

			HoleMerged.NextHole = MergedVertices.Num() - 1;
			MergedVertices[ClosestHoleIndex] = HoleMerged;
		}

		VertexIndex = MergedVertex.NextVertex;
		if (VertexIndex == VertexStart)
		{
			break;
		}
	}

	if (FoundIntersection)
	{
		// Find the first vertex that is not inside the hole
		VertexIndex = VertexStart;
		while (true)
		{
			const FMergedVertex& MergedVertex = MergedVertices[VertexIndex];
			if (!IsPositionInPolygon(MergedVertex.Position, Hole))
			{
				break;
			}

			VertexIndex = MergedVertex.NextVertex;
			ensureMsgf(VertexIndex != VertexStart, TEXT("Unable to find a starting vertex outside of the hole"));
		}

		// Clear the hole and vertices, we are going to merge them together into the vertices list
		Hole.Empty();
		Vertices.Empty();

		// Start at the first vertex not in the hole
		VertexStart = VertexIndex;
		bool FollowingVertices = true;
		while (true)
		{
			const FMergedVertex& MergedVertex = MergedVertices[VertexIndex];
			Vertices.Add(MergedVertex.Position);

			if (MergedVertex.NextHole != -1 && (FollowingVertices || MergedVertex.NextVertex == -1))
			{
				VertexIndex = MergedVertex.NextHole;
				FollowingVertices = false;
			}
			else if (MergedVertex.NextVertex != -1)
			{
				VertexIndex = MergedVertex.NextVertex;
				FollowingVertices = true;
			}
			else
			{
				ensureMsgf(0, TEXT("Unable to follow next vertex or hole, the node is invalid"));
			}

			if (VertexIndex == VertexStart)
			{
				break;
			}
		}
	}
	ensureMsgf(!IsPositionInPolygon(Vertices[0], Hole), TEXT("Vertices are completely encapsulated within the hole"));
}
