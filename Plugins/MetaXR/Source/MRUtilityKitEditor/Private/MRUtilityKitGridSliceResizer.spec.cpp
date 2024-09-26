// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "GridSliceResizerTestData.h"
#include "MRUtilityKitGridSliceResizer.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"
#include "TestHelper.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"

BEGIN_DEFINE_SPEC(FMRUKGridSliceResizerSpec, TEXT("MR Utility Kit"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FMRUKGridSliceResizerSpec)

void FMRUKGridSliceResizerSpec::Define()
{
	Describe(TEXT("Grid Slice Resizer"), [this] {
		BeforeEach([this]() {
			// Load map
			const auto ContentDir = FPaths::ProjectContentDir();
			FAutomationEditorCommonUtils::LoadMap(ContentDir + "/Common/Maps/TestLevel.umap");
			StartPIE(true);
		});

		BeforeEach(EAsyncExecution::ThreadPool, []() {
			while (!GEditor->IsPlayingSessionInEditor())
			{
				// Wait until play session starts
				FGenericPlatformProcess::Yield();
			}
		});

		It(TEXT("Slice mesh"), [this] {
			const auto World = GEditor->GetPIEWorldContext()->World();
			const FActorSpawnParameters Params{};
			AMeshResizer* Resizer = World->SpawnActor<AMeshResizer>(Params);

			UMRUKGridSliceResizerComponent* ResizerComponent = Resizer->GridSliceResizerComponent;

			struct FTestData
			{
				FVector Scale;
				uint8 ScaleCenterMode;
				double BorderXNegative;
				double BorderXPositive;
				double BorderYNegative;
				double BorderYPositive;
				double BorderZNegative;
				double BorderZPositive;
				FVector SlicerPivotOffset;
				const TArray<FVector>& ExpectedPositions;
			};

			TArray TestDataContainer = {
				// Test without pivot offset
				FTestData{
					FVector(2.0, 2.0, 2.0),
					(uint8)EMRUKScaleCenterMode::XAxis | (uint8)EMRUKScaleCenterMode::YAxis | (uint8)EMRUKScaleCenterMode::ZAxis,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, 0.0),
					ExpectedPositionsPivotCenter,
				},
				// Test with pivot offset
				FTestData{
					FVector(2.0, 2.0, 2.0),
					(uint8)EMRUKScaleCenterMode::XAxis | (uint8)EMRUKScaleCenterMode::YAxis | (uint8)EMRUKScaleCenterMode::ZAxis,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, -40.0),
					ExpectedPositionsPivotOffset,
				},
				// Test with pivot outside of bounding box
				FTestData{
					FVector(2.0, 2.0, 2.0),
					(uint8)EMRUKScaleCenterMode::XAxis | (uint8)EMRUKScaleCenterMode::YAxis | (uint8)EMRUKScaleCenterMode::ZAxis,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, -160.0),
					ExpectedPositionsPivotOutside,
				},
				// Test scaled down with pivot offset
				FTestData{
					FVector(0.2, 0.2, 0.2),
					(uint8)EMRUKScaleCenterMode::XAxis | (uint8)EMRUKScaleCenterMode::YAxis | (uint8)EMRUKScaleCenterMode::ZAxis,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, 20.0),
					ExpectedPositionsScaledDown,
				},
				// Test without center scale
				FTestData{
					FVector(2.0, 2.0, 2.0),
					(uint8)EMRUKScaleCenterMode::None,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, 0.0),
					ExpectedPositionsCenterNotScaled,
				},
				// Test without center scale but scaled down
				FTestData{
					FVector(0.2, 0.2, 0.2),
					(uint8)EMRUKScaleCenterMode::None,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					0.8,
					FVector(0.0, 0.0, 0.0),
					ExpectedPositionsScaledDownCenterNotScaled,
				}
			};

			constexpr double Tolerance = 0.001;

			for (const FTestData& TestData : TestDataContainer)
			{
				ResizerComponent->ScaleCenterMode = TestData.ScaleCenterMode;
				ResizerComponent->BorderXNegative = TestData.BorderXNegative;
				ResizerComponent->BorderXPositive = TestData.BorderXPositive;
				ResizerComponent->BorderYNegative = TestData.BorderYNegative;
				ResizerComponent->BorderYPositive = TestData.BorderYPositive;
				ResizerComponent->BorderZNegative = TestData.BorderZNegative;
				ResizerComponent->BorderZPositive = TestData.BorderZPositive;
				ResizerComponent->SlicerPivotOffset = TestData.SlicerPivotOffset;

				Resizer->SetActorScale3D(TestData.Scale);
				Resizer->GridSliceResizerComponent->SliceMesh();

				const FProcMeshSection* MeshSection = Resizer->GridSliceResizerComponent->ProcMesh->GetProcMeshSection(0);
				if (!TestNotNull(TEXT("Mesh section is not null"), MeshSection))
				{
					return;
				}

				const TArray<uint32>& Indices = MeshSection->ProcIndexBuffer;
				const TArray<FProcMeshVertex>& Vertices = MeshSection->ProcVertexBuffer;

				TestEqual(TEXT("Triangles count matches"), Indices.Num(), ExpectedTriangles.Num());
				for (int32 I = 0; I < Indices.Num(); ++I)
				{
					TestEqual(TEXT("Index matches"), Indices[I], ExpectedTriangles[I]);
				}

				TestEqual(TEXT("Positions count matches"), Vertices.Num(), TestData.ExpectedPositions.Num());
				for (int32 I = 0; I < Vertices.Num(); ++I)
				{
					TestEqual(TEXT("Position matches"), Vertices[I].Position, TestData.ExpectedPositions[I], Tolerance);
				}
			}
		});

		// Caution: Order of these statements is important

		AfterEach(EAsyncExecution::ThreadPool, []() {
			while (GEditor->IsPlayingSessionInEditor())
			{
				// Wait until play session ends
				FGenericPlatformProcess::Yield();
			}
		});

		AfterEach([]() {
			// Request end of play session
			GUnrealEd->RequestEndPlayMap();
		});
	});
}
