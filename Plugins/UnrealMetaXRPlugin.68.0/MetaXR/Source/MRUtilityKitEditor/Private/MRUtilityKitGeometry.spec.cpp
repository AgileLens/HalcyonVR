// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGeometry.h"

namespace
{
	double CalculateTriangleArea(const FVector2D& P1, const FVector2D& P2, const FVector2D& P3)
	{
		return (P1.X * (P2.Y - P3.Y) + P2.X * (P3.Y - P1.Y) + P3.X * (P1.Y - P2.Y)) / 2.0f;
	}

	// Use the triangulated area as a proxy to ensure the triangulation worked as expected
	double CalculateTriangulatedArea(const TArray<FVector2D>& Vertices, const TArray<int32>& Indices)
	{
		double Area = 0.0;
		for (int i = 0; i < Indices.Num(); i += 3)
		{
			const FVector2D& P1 = Vertices[Indices[i]];
			const FVector2D& P2 = Vertices[Indices[i + 1]];
			const FVector2D& P3 = Vertices[Indices[i + 2]];
			const double TriangleArea = CalculateTriangleArea(P1, P2, P3);
			check(TriangleArea >= 0.0);
			Area += TriangleArea;
		}

		return Area;
	}
} // namespace

BEGIN_DEFINE_SPEC(FMRUKGeometrySpec, TEXT("MR Utility Kit"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FMRUKGeometrySpec)

void FMRUKGeometrySpec::Define()
{
	Describe(TEXT("Triangulation"), [this] {
		It(TEXT("Triangulate quad"), [this] {
			const TArray<FVector2D> Vertices = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
			const TArray<int32> Indices = MRUKTriangulatePoints(Vertices);
			TestEqual(TEXT("Correct number of indices"), 6, Indices.Num());
			TestEqual(TEXT("Correct area triangulated"), 1.0, CalculateTriangulatedArea(Vertices, Indices));
		});

		It(TEXT("Triangulate quad with hole"), [this] {
			const TArray<FVector2D> Vertices = { { 0.0f, 0.0f }, { 2.0f, 0.0f }, { 2.0f, 2.0f }, { 0.0f, 2.0f } };
			const TArray<TArray<FVector2D>> Holes = { { { 0.5f, 0.5f }, { 0.5f, 1.5f }, { 1.5f, 1.5f }, { 1.5f, 0.5f } } };

			const FMRUKOutline Outline = MRUKComputeOutline(Vertices, Holes);
			const TArray<int32> Indices = MRUKTriangulateMesh(Outline);

			TestEqual(TEXT("Correct number of indices"), Indices.Num(), 24);
			TestEqual(TEXT("Correct area triangulated"), CalculateTriangulatedArea(Outline.Vertices, Indices), 3.0);
		});

		It(TEXT("Triangulate quad with four holes"), [this] {
			const TArray<FVector2D> Vertices = { { 0.0f, 0.0f }, { 4.0f, 0.0f }, { 4.0f, 4.0f }, { 0.0f, 4.0f } };
			TArray<TArray<FVector2D>> Holes;
			for (int32 I = 0; I < 4; ++I)
			{
				const FVector2D Offset(0.5 + 2.0 * (I / 2), 0.5 + 2.0 * (I % 2));
				Holes.Push({ Offset + FVector2D(0.0, 0.0), Offset + FVector2D(0.0, 1.0), Offset + FVector2D(1.0, 1.0), Offset + FVector2D(1.0, 0.0) });
			}

			const FMRUKOutline Outline = MRUKComputeOutline(Vertices, Holes);
			const TArray<int32> Indices = MRUKTriangulateMesh(Outline);

			TestEqual(TEXT("Correct number of indices"), Indices.Num(), 78);
			TestEqual(TEXT("Correct area triangulated"), CalculateTriangulatedArea(Outline.Vertices, Indices), 12.0);
		});

		It(TEXT("Triangulate quad with two close holes"), [this] {
			const TArray<FVector2D> Vertices = {
				{ 101.985214, 113.8258 },
				{ -101.985214, 113.8258 },
				{ -101.985214, -113.8258 },
				{ 101.985214, -113.8258 },
			};

			const TArray<TArray<FVector2D>> Holes = {
				{ { 18.395055731633885, 9.0596833 }, { -72.518264268366110, 9.0596833 }, { -72.518264268366110, 67.2252527 }, { 18.395055731633885, 67.2252527 } },
				{ { 18.395055731633885, -53.4203167 }, { -72.518264268366110, -53.4203167 }, { -72.518264268366110, 4.7452569 }, { 18.395055731633885, 4.7452569 } },
			};

			const FMRUKOutline Outline = MRUKComputeOutline(Vertices, Holes);
			const TArray<int32> Indices = MRUKTriangulateMesh(Outline);

			TestEqual(TEXT("Correct number of indices"), Indices.Num(), 42);
			TestEqual(TEXT("Correct area triangulated"), CalculateTriangulatedArea(Outline.Vertices, Indices), 35858.143857);
		});

		It(TEXT("Triangulate LShape"), [this] {
			const TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 1.0, 2.0 }, { 1.0, 1.0 }, { 0.0, 1.0 } };
			const TArray<int32> Indices = MRUKTriangulatePoints(Vertices);

			TestEqual(TEXT("Correct number of indices"), Indices.Num(), 12);
			TestEqual(TEXT("Correct area triangulated"), CalculateTriangulatedArea(Vertices, Indices), 3.0);
		});

		It(TEXT("Triangulate CShape"), [this] {
			const TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 1.0 }, { 1.0, 1.0 }, { 1.0, 2.0 }, { 2.0, 2.0 }, { 2.0, 3.0 }, { 0.0, 3.0 } };
			const TArray<int32> Indices = MRUKTriangulatePoints(Vertices);

			TestEqual(TEXT("Correct number of indices"), Indices.Num(), 18);
			TestEqual(TEXT("Correct area triangulated"), CalculateTriangulatedArea(Vertices, Indices), 5.0);
		});

		It(TEXT("Find line intersection1"), [this] {
			FVector2D Intersection;
			double U1, U2;
			const bool FoundIntersection = MRUKFindLineIntersection(FVector2D(0.0, 0.0), FVector2D(0.0, 1.0), FVector2D(-1.0, 1.0), FVector2D(1.0, 1.0), Intersection, U1, U2);
			TestTrue(TEXT("Intersects"), FoundIntersection);
			TestEqual(TEXT("Intersection matches"), Intersection, FVector2D(0.0, 1.0));
			TestEqual(TEXT("U1 matches"), U1, 1.0);
			TestEqual(TEXT("U2 matches"), U2, 0.5);
		});

		It(TEXT("Find line intersection2"), [this] {
			FVector2D Intersection;
			double U1, U2;
			const bool FoundIntersection = MRUKFindLineIntersection(FVector2D(0.0, 0.0), FVector2D(2.0, 2.0), FVector2D(1.0, 0.0), FVector2D(0.0, 1.0), Intersection, U1, U2);
			TestTrue(TEXT("Intersects"), FoundIntersection);
			TestEqual(TEXT("Intersection matches"), Intersection, FVector2D(0.5, 0.5));
			TestEqual(TEXT("U1 matches"), U1, 0.25);
			TestEqual(TEXT("U2 matches"), U2, 0.5);
		});

		It(TEXT("Merge polygons bottom middle"), [this] {
			// Tests that ClipPolygon works as expected with a hole cut out of a quad at the bottom middle section
			// __________
			// |        |
			// |  ____  |
			// |__|  |__|
			TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } };
			TArray<FVector2D> Hole = { { 0.5, -0.5 }, { 0.5, 1.5 }, { 1.5, 1.5 }, { 1.5, -0.5 } };
			MRUKClipPolygon(Vertices, Hole);
			TestEqual(TEXT("Vertices match"), Vertices, { { 0.0, 0.0 }, { 0.5, 0.0 }, { 0.5, 1.5 }, { 1.5, 1.5 }, { 1.5, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } });
			TestEqual(TEXT("Hole count matches"), Hole.Num(), 0);
		});

		It(TEXT("Merge polygons bottom middle overlap"), [this] {
			// Tests that MergePolygons works as expected with a hole cut out of a quad at the bottom middle section and
			// one of the hole edges exactly overlaps with one of the edges of the polygon
			// __________
			// |        |
			// |  ____  |
			// |__|  |__|
			TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } };
			TArray<FVector2D> Hole = { { 0.5, 0.0 }, { 0.5, 1.5 }, { 1.5, 1.5 }, { 1.5, 0.0 } };
			MRUKClipPolygon(Vertices, Hole);
			TestEqual(TEXT("Vertices match"), Vertices, { { 0.0, 0.0 }, { 0.5, 0.0 }, { 0.5, 1.5 }, { 1.5, 1.5 }, { 1.5, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } });
			TestEqual(TEXT("Hole count matches"), Hole.Num(), 0);
		});

		It(TEXT("Merge polygons bottom left corner"), [this] {
			// Tests that MergePolygons works as expected with a hole cut out of a quad at the bottom left section
			// __________
			// |        |
			// |___     |
			//    |_____|
			TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } };
			TArray<FVector2D> Hole = { { -0.5, -0.5 }, { -0.5, 1.5 }, { 1.5, 1.5 }, { 1.5, -0.5 } };
			MRUKClipPolygon(Vertices, Hole);
			TestEqual(TEXT("Vertices match"), Vertices, { { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 }, { 0.0, 1.5 }, { 1.5, 1.5 }, { 1.5, 0.0 } });
			TestEqual(TEXT("Hole count matches"), Hole.Num(), 0);
		});

		It(TEXT("Merge polygons right middle"), [this] {
			// Tests that MergePolygons works as expected with a hole cut out of a quad at the right middle section
			// __________
			// |    ____|
			// |    |___
			// |________|
			TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } };
			TArray<FVector2D> Hole = { { 0.5, 0.5 }, { 0.5, 1.5 }, { 2.5, 1.5 }, { 2.5, 0.5 } };
			MRUKClipPolygon(Vertices, Hole);
			TestEqual(TEXT("Vertices match"), Vertices, { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 0.5 }, { 0.5, 0.5 }, { 0.5, 1.5 }, { 2.0, 1.5 }, { 2.0, 2.0 }, { 0.0, 2.0 } });
			TestEqual(TEXT("Hole count matches"), Hole.Num(), 0);
		});

		It(TEXT("Merge polygons top half"), [this] {
			// Tests that MergePolygons works as expected with a hole cut out of a quad encapsulating the top half of the quad
			//
			//
			// __________
			// |________|
			TArray<FVector2D> Vertices = { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 2.0 }, { 0.0, 2.0 } };
			TArray<FVector2D> Hole = { { -0.5, 0.5 }, { -0.5, 2.5 }, { 2.5, 2.5 }, { 2.5, 0.5 } };
			MRUKClipPolygon(Vertices, Hole);
			TestEqual(TEXT("Vertices match"), Vertices, { { 0.0, 0.0 }, { 2.0, 0.0 }, { 2.0, 0.5 }, { 0.0, 0.5 } });
			TestEqual(TEXT("Hole count matches"), Hole.Num(), 0);
		});
	});
}
