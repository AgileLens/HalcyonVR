// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MeshActor.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitAnchorActorSpawner.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"
#include "Editor/UnrealEdEngine.h"
#include "UnrealEdGlobals.h"
#include "TestHelper.h"

BEGIN_DEFINE_SPEC(FMRUKSpec, TEXT("MR Utility Kit"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UMRUKSubsystem* ToolkitSubsystem;

void SetupMRUKSubsystem();
void LoadSceneFromJson();
void TeardownMRUKSubsystem();
using FAutomationTestBase::TestEqual; // Allows base class function overloads to be accessed
bool TestEqual(const TCHAR* What, const FVector2D Actual, const FVector2D Expected, float Tolerance = UE_KINDA_SMALL_NUMBER);
END_DEFINE_SPEC(FMRUKSpec)

void FMRUKSpec::SetupMRUKSubsystem()
{
	BeforeEach([this]() {
		// Load map and start play in editor
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

	BeforeEach([this]() {
		// Get a reference to the subsystem
		const auto World = GEditor->GetPIEWorldContext()->World();
		const auto GameInstance = World->GetGameInstance();
		ToolkitSubsystem = GameInstance->GetSubsystem<UMRUKSubsystem>();
	});
}

void FMRUKSpec::LoadSceneFromJson()
{
	BeforeEach([this]() {
		// Load scene from Json
		ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomJson);
	});
}

void FMRUKSpec::TeardownMRUKSubsystem()
{
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
}

// There is no TestEqual for FVector2D in FAutomationTestBase, so implement our own here
bool FMRUKSpec::TestEqual(const TCHAR* What, const FVector2D Actual, const FVector2D Expected, float Tolerance)
{
	if (!Expected.Equals(Actual, Tolerance))
	{
		AddError(FString::Printf(TEXT("Expected '%s' to be %s, but it was %s within tolerance %f."), What, *Expected.ToString(), *Actual.ToString(), Tolerance), 1);
		return false;
	}
	return true;
}

void FMRUKSpec::Define()
{
	Describe(TEXT("Interior spawner"), [this] {
		AMRUKAnchorActorSpawner* InteriorSpawner;

		SetupMRUKSubsystem();

		BeforeEach([this, &InteriorSpawner]() {
			const auto World = GEditor->GetPIEWorldContext()->World();
			FActorSpawnParameters Params{};
			InteriorSpawner = World->SpawnActor<AMRUKAnchorActorSpawner>(Params);

			InteriorSpawner->SpawnGroups[FMRUKLabels::Couch].Actors.Push({ AMeshActor::StaticClass() });
			InteriorSpawner->SpawnGroups[FMRUKLabels::WindowFrame].Actors.Push({ AMeshActor::StaticClass() });
		});

		LoadSceneFromJson();

		It(TEXT("Spawns interior correct"), [this]() {
			const auto World = GEditor->GetPIEWorldContext()->World();
			const auto Subsystem = World->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();

			const auto Room = Subsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room is set"), Room))
			{
				return;
			}

			const auto WindowAnchor = Subsystem->GetCurrentRoom()->GetFirstAnchorByLabel(FMRUKLabels::WindowFrame);
			if (!TestNotNull(TEXT("Window anchor is set"), WindowAnchor))
			{
				return;
			}

			TArray<AActor*> WindowChildActors;
			WindowAnchor->GetAttachedActors(WindowChildActors);
			if (!TestFalse(TEXT("Window has child actors"), WindowChildActors.IsEmpty()))
			{
				return;
			}

			const auto WindowMeshActor = WindowChildActors[0];
			if (!TestNotNull(TEXT("Window mesh is set"), WindowMeshActor))
			{
				return;
			}

			constexpr double Tolerance = 0.01;
			TestEqual(TEXT("Window mesh location"), WindowMeshActor->GetActorLocation(), FVector(86.993, 160.305, 27.147), Tolerance);
			TestEqual(TEXT("Window mesh rotation"), WindowMeshActor->GetActorRotation(), FRotator(-0.000010, -168.053020, 0.012821), Tolerance);
			TestEqual(TEXT("Window mesh scale"), WindowMeshActor->GetActorScale(), FVector(1.442, 1.154, 1.729), Tolerance);

			const auto CouchAnchor = Subsystem->GetCurrentRoom()->GetFirstAnchorByLabel("COUCH");
			if (!TestNotNull(TEXT("Couch anchor is set"), CouchAnchor))
			{
				return;
			}

			TArray<AActor*> CouchChildActors;
			CouchAnchor->GetAttachedActors(CouchChildActors);
			if (!TestFalse(TEXT("Couch has child actors"), CouchChildActors.IsEmpty()))
			{
				return;
			}

			const auto CouchMeshActor = CouchChildActors[0];
			if (!TestNotNull(TEXT("Couch mesh is set"), CouchMeshActor))
			{
				return;
			}

			TestEqual(TEXT("Couch mesh location"), CouchMeshActor->GetActorLocation(), FVector(-145.872, 107.079, -101.393), Tolerance);
			TestEqual(TEXT("Couch mesh rotation"), CouchMeshActor->GetActorRotation(), FRotator(0.0, -79.625847, 0.0), Tolerance);
			TestEqual(TEXT("Couch mesh scale"), CouchMeshActor->GetActorScale(), FVector(0.902, 2.029, 0.566), Tolerance);
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Serialization"), [this] {
		SetupMRUKSubsystem();

		It(TEXT("Deserializes correctly"), [this]() {
			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomJson);
			auto Rooms = ToolkitSubsystem->Rooms;
			if (!TestEqual(TEXT("Number of rooms"), Rooms.Num(), 1))
			{
				return;
			}
			auto Room = Rooms[0];
			if (!TestNotNull(TEXT("Room"), Room.Get()))
			{
				return;
			}
			TestEqual(TEXT("Number of anchors"), Room->AllAnchors.Num(), 23);
			TestEqual(TEXT("Number of walls"), Room->WallAnchors.Num(), 8);
			if (TestNotNull(TEXT("Floor anchor"), Room->FloorAnchor.Get()))
			{
				if (TestEqual(TEXT("Number of floor semantic classifications"), Room->FloorAnchor->SemanticClassifications.Num(), 1))
				{
					TestEqual(TEXT("Wall semantic classification"), Room->FloorAnchor->SemanticClassifications[0], FMRUKLabels::Floor);
				}
			}
			if (TestNotNull(TEXT("Ceiling anchor"), Room->CeilingAnchor.Get()))
			{
				if (TestEqual(TEXT("Number of ceiling semantic classifications"), Room->CeilingAnchor->SemanticClassifications.Num(), 1))
				{
					TestEqual(TEXT("Wall semantic classification"), Room->CeilingAnchor->SemanticClassifications[0], FMRUKLabels::Ceiling);
				}
			}
			for (auto Wall : Room->WallAnchors)
			{
				if (!TestNotNull(TEXT("Wall anchor"), Wall.Get()))
				{
					break;
				}
				if (!TestEqual(TEXT("Number of wall semantic classifications"), Wall->SemanticClassifications.Num(), 1))
				{
					break;
				}
				TestEqual(TEXT("Wall semantic classification"), Wall->SemanticClassifications[0], FMRUKLabels::WallFace);
			}
		});

		It(TEXT("Serializes correctly"), [this]() {
			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomJson);
			auto Serialized = ToolkitSubsystem->SaveSceneToJsonString();
			TArray<FString> SerializedLines;
			TArray<FString> SourceLines;
			Serialized.ParseIntoArrayLines(SerializedLines, true);
			FString(ExampleRoomJson).ParseIntoArrayLines(SourceLines, true);
			if (TestEqual(TEXT("Number of lines"), SerializedLines.Num(), SourceLines.Num()))
			{
				// Go line by line in the JSON string and verify they match
				for (int i = 0; i < SerializedLines.Num(); ++i)
				{
					// When serializing/deserializing Rotations it does some conversion between Euler
					// rotation and quaternion. This results in some precision loss and in some cases
					// the same rotation can be represented in different ways so the numbers are quite
					// different even know they represent the same rotation so it is difficult to compare
					// them textually. For now we will just ignore these lines.
					if (SourceLines[i].Contains(TEXT("\"Rotation\"")))
					{
						continue;
					}
					TestEqual(TEXT("JSON line"), SerializedLines[i], SourceLines[i]);
				}
			}
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Room Loading"), [this]() {
		SetupMRUKSubsystem();

		It(TEXT("Load invalid string"), [this]() {
			// Load scene from invalid JSON string
			ToolkitSubsystem->LoadSceneFromJsonString(TEXT("[[["));
			TestEqual("Scene load status", ToolkitSubsystem->SceneLoadStatus, EMRUKInitStatus::Failed);
		});

		It(TEXT("Load empty room"), [this]() {
			// Load scene from empty JSON string
			ToolkitSubsystem->LoadSceneFromJsonString(TEXT(R"({"Rooms": []})"));
			TestEqual("Scene load status", ToolkitSubsystem->SceneLoadStatus, EMRUKInitStatus::Failed);
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Update room"), [this]() {
		SetupMRUKSubsystem();
		LoadSceneFromJson();

		It(TEXT("Change nothing in room"), [this]() {
			auto O = NewObject<URoomAndAnchorObserver>();

			ToolkitSubsystem->OnRoomCreated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomCreated);
			ToolkitSubsystem->OnRoomUpdated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomUpdated);
			ToolkitSubsystem->OnRoomRemoved.AddDynamic(O, &URoomAndAnchorObserver::OnRoomRemoved);

			for (auto Room : ToolkitSubsystem->Rooms)
			{
				Room->OnAnchorCreated.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorCreated);
				Room->OnAnchorUpdated.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorUpdated);
				Room->OnAnchorRemoved.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorRemoved);
			}

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomJson);

			TestEqual(TEXT("No rooms created"), O->RoomsCreated.Num(), 0);
			TestEqual(TEXT("One room updated"), O->RoomsUpdated.Num(), 1);
			TestEqual(TEXT("No rooms removed"), O->RoomsRemoved.Num(), 0);
			TestEqual(TEXT("No anchors created"), O->AnchorsCreated.Num(), 0);
			TestEqual(TEXT("No anchors updated"), O->AnchorsUpdated.Num(), 0);
			TestEqual(TEXT("No anchors removed"), O->AnchorsRemoved.Num(), 0);

			O->MarkAsGarbage();
		});

		It(TEXT("Add, update and remove furniture in room"), [this]() {
			auto O = NewObject<URoomAndAnchorObserver>();

			ToolkitSubsystem->OnRoomCreated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomCreated);
			ToolkitSubsystem->OnRoomUpdated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomUpdated);
			ToolkitSubsystem->OnRoomRemoved.AddDynamic(O, &URoomAndAnchorObserver::OnRoomRemoved);

			for (auto Room : ToolkitSubsystem->Rooms)
			{
				Room->OnAnchorCreated.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorCreated);
				Room->OnAnchorUpdated.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorUpdated);
				Room->OnAnchorRemoved.AddDynamic(O, &URoomAndAnchorObserver::OnAnchorRemoved);
			}

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomFurnitureAddedJson);

			TestEqual(TEXT("No rooms created"), O->RoomsCreated.Num(), 0);
			TestEqual(TEXT("Rooms updated"), O->RoomsUpdated.Num(), 1);
			TestEqual(TEXT("No rooms removed"), O->RoomsRemoved.Num(), 0);
			TestEqual(TEXT("Anchors created"), O->AnchorsCreated.Num(), 2);
			TestEqual(TEXT("No anchors updated"), O->AnchorsUpdated.Num(), 0);
			TestEqual(TEXT("No anchors removed"), O->AnchorsRemoved.Num(), 0);

			O->Clear();

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomMoreFurnitureAddedJson);

			TestEqual(TEXT("No rooms created"), O->RoomsCreated.Num(), 0);
			TestEqual(TEXT("Rooms updated"), O->RoomsUpdated.Num(), 1);
			TestEqual(TEXT("No rooms removed"), O->RoomsRemoved.Num(), 0);
			TestEqual(TEXT("Anchors created"), O->AnchorsCreated.Num(), 1);
			TestEqual(TEXT("No anchors updated"), O->AnchorsUpdated.Num(), 0);
			TestEqual(TEXT("No anchors removed"), O->AnchorsRemoved.Num(), 0);

			O->Clear();

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomFurnitureModifiedJson);

			TestEqual(TEXT("No rooms created"), O->RoomsCreated.Num(), 0);
			TestEqual(TEXT("Rooms updated"), O->RoomsUpdated.Num(), 1);
			TestEqual(TEXT("No rooms removed"), O->RoomsRemoved.Num(), 0);
			TestEqual(TEXT("No anchors created"), O->AnchorsCreated.Num(), 0);
			TestEqual(TEXT("Anchors updated"), O->AnchorsUpdated.Num(), 2);
			TestEqual(TEXT("Anchors removed"), O->AnchorsRemoved.Num(), 1);

			O->Clear();

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleRoomJson);

			TestEqual(TEXT("No rooms created"), O->RoomsCreated.Num(), 0);
			TestEqual(TEXT("Rooms updated"), O->RoomsUpdated.Num(), 1);
			TestEqual(TEXT("No rooms removed"), O->RoomsRemoved.Num(), 0);
			TestEqual(TEXT("No anchors created"), O->AnchorsCreated.Num(), 0);
			TestEqual(TEXT("No anchors updated"), O->AnchorsUpdated.Num(), 0);
			TestEqual(TEXT("Anchors removed"), O->AnchorsRemoved.Num(), 2);

			O->MarkAsGarbage();
		});

		It(TEXT("Add and remove room"), [this]() {
			auto O = NewObject<URoomAndAnchorObserver>();

			ToolkitSubsystem->OnRoomCreated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomCreated);
			ToolkitSubsystem->OnRoomUpdated.AddDynamic(O, &URoomAndAnchorObserver::OnRoomUpdated);
			ToolkitSubsystem->OnRoomRemoved.AddDynamic(O, &URoomAndAnchorObserver::OnRoomRemoved);

			ToolkitSubsystem->LoadSceneFromJsonString(ExampleOtherRoomJson);

			TestEqual(TEXT("Room created"), O->RoomsCreated.Num(), 1);
			TestEqual(TEXT("No rooms updated"), O->RoomsUpdated.Num(), 0);
			TestEqual(TEXT("Rooms removed"), O->RoomsRemoved.Num(), 1);

			O->MarkAsGarbage();
		});

		TeardownMRUKSubsystem();
	});

	Describe("Room", [this]() {
		SetupMRUKSubsystem();
		LoadSceneFromJson();

		It(TEXT("Is initialized"), [this]() {
			TestEqual("Scene load status", ToolkitSubsystem->SceneLoadStatus, EMRUKInitStatus::Complete);
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			TestTrue("Room bounds valid", (bool)Room->RoomBounds.IsValid);
		});

		It(TEXT("Compute Centroid"), [this]() {
			TestEqual("Scene load status", ToolkitSubsystem->SceneLoadStatus, EMRUKInitStatus::Complete);
			const auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			const TArray<TPair<double, FVector>> Inputs = {
				{ 0.0, FVector(-63.212, 41.209, -129.629) },
				{ 0.5, FVector(-65.876, 40.507, 1.873) },
				{ 1.0, FVector(-68.540, 39.804, 133.376) },
			};

			for (int32 I = 0; I < Inputs.Num(); ++I)
			{
				const double Z = Inputs[I].Get<0>();
				const FVector& ExpectedCentroid = Inputs[I].Get<1>();

				const FVector Centroid = Room->ComputeCentroid(Z);
				constexpr double Tolerance = 0.001;
				TestEqual(TEXT("Centroid matches"), Centroid, ExpectedCentroid, Tolerance);
			}
		});

		It(TEXT("Does room have"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			TArray<FString> ContainedLabels = { FMRUKLabels::WallFace, FMRUKLabels::Ceiling, FMRUKLabels::Floor };
			TestTrue(TEXT("Room contains all labels"), Room->DoesRoomHave(ContainedLabels));

			TArray<FString> PartlyContainedLabels = { FMRUKLabels::WallFace, "FOO", FMRUKLabels::Floor };
			TestFalse(TEXT("Room contains not all labels"), Room->DoesRoomHave(PartlyContainedLabels));

			TArray<FString> EmptyLabels;
			TestTrue(TEXT("Room contains empty labels"), Room->DoesRoomHave(EmptyLabels));
		});

		It(TEXT("Get forward facing direction"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			const auto Couch = Room->GetFirstAnchorByLabel("COUCH");
			if (!TestNotNull(TEXT("Couch"), Room))
			{
				return;
			}

			const auto ActualFacingDirection = Couch->GetFacingDirection();
			constexpr double Tolerance = 0.001;
			TestEqual(TEXT("Facing direction"), ActualFacingDirection, FVector{ 0.180, -0.984, 0.000 }, Tolerance);
		});

		It(TEXT("Get anchors by label"), [this] {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			const TArray<AMRUKAnchor*>& Anchors = Room->GetAnchorsByLabel(TEXT("WALL_FACE"));
			TestEqual(TEXT("All walls found"), Anchors.Num(), 8);
		});

		It(TEXT("Try get closest seat pose"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			const auto Couch = Room->GetFirstAnchorByLabel("COUCH");
			if (!TestNotNull(TEXT("Couch"), Room))
			{
				return;
			}

			struct TestData
			{
				FVector RayOrigin;
				FVector RayDirection;
				FVector ExpectedLocation;
				FQuat ExpectedRotation;
				FOculusXRUUID ExpectedAnchorUUID;
			};

			TArray<TestData> AllTestData = {
				{ { -119.510, 51.224, -68.187 },
					{ -0.474, 0.815, -0.332 },
					{ -145.872, 107.079, -85.245 },
					{ 0.0, 0.0, -0.640282977, 0.768139121 },
					{ { 0xBE, 0xEE, 0x3C, 0xD7, 0x5B, 0xC0, 0x2A, 0xBF, 0x21, 0x9D, 0x99, 0x89, 0x48, 0x1A, 0xE7, 0x98 } } }
			};

			for (const auto& TestData : AllTestData)
			{
				FTransform ActualSeatTransform{};
				const auto Actor = Room->TryGetClosestSeatPose(TestData.RayOrigin, TestData.RayDirection, ActualSeatTransform);
				if (!TestNotNull(TEXT("Actor is set"), Actor))
				{
					return;
				}

				constexpr double Tolerance = 0.001;
				TestEqual(TEXT("Actor UUID is the same"), Actor->AnchorUUID, TestData.ExpectedAnchorUUID);
				TestEqual(TEXT("Location is the same"), ActualSeatTransform.GetLocation(), TestData.ExpectedLocation, Tolerance);
				TestTrue(TEXT("Rotation is the same"), ActualSeatTransform.GetRotation().Equals(TestData.ExpectedRotation, Tolerance));
			}
		});

		It(TEXT("Try get closest point in room"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			struct TestData
			{
				FVector WorldLocation;
				TOptional<FVector> ExpectedSurfaceLocation;
				TOptional<FOculusXRUUID> ExpectedAnchorUUID;
			};

			TArray<TestData> AllTestData = {
				{
					{ -157.383, -117.528, -50.459 },
					{ { -155.038, -132.843, -50.459 } },
					{ { { 0xB3, 0x69, 0xDA, 0xC9, 0x91, 0x3F, 0x46, 0x53, 0xCF, 0x00, 0x06, 0xD2, 0x92, 0xB4, 0x7E, 0x67 } } },
				},
				{
					{ 70.723, 34.300, -18.577 },
					{ { 80.085, 36.095, -18.577 } },
					{ { { 0x4F, 0x3D, 0x50, 0x69, 0x41, 0xFC, 0xDF, 0x2C, 0xDE, 0x52, 0x9B, 0x77, 0x8F, 0x7E, 0x2C, 0xA0 } } },
				},
				{
					{ -6.787, 178.944, -15.669 },
					{ { -6.787, 178.944, -25.322 } },
					{ { { 0x39, 0x02, 0x15, 0x4E, 0x70, 0x0E, 0x7D, 0xFC, 0xEF, 0xCD, 0xD3, 0x1C, 0x7C, 0xEE, 0xA2, 0x1D } } },
				},
			};

			FMRUKLabelFilter LabelFilter;
			LabelFilter.ExcludedLabels = { FMRUKLabels::Ceiling, FMRUKLabels::Floor };

			for (const auto& TestData : AllTestData)
			{
				FVector ActualSurfaceLocation{};
				const auto ActualAnchor = ToolkitSubsystem->TryGetClosestSurfacePosition(TestData.WorldLocation, ActualSurfaceLocation, LabelFilter);
				if (TestData.ExpectedAnchorUUID.IsSet())
				{
					if (!TestNotNull(TEXT("Anchor is set"), ActualAnchor))
					{
						continue;
					}
					TestEqual(TEXT("Anchor Uuid"), ActualAnchor->AnchorUUID, TestData.ExpectedAnchorUUID.GetValue());
				}
				else
				{
					TestNull(TEXT("Anchor not set"), ActualAnchor);
				}
				if (TestData.ExpectedSurfaceLocation.IsSet())
				{
					constexpr double Tolerance = 0.01;
					TestEqual(TEXT("Surface location"), ActualSurfaceLocation, TestData.ExpectedSurfaceLocation.GetValue(), Tolerance);
				}
			}
		});

		It(TEXT("Get best pose from raycast"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			struct TestData
			{
				FVector RayOrigin;
				FVector RayDirection;
				double MaxDist;
				FVector ExpectedLocation;
				FQuat ExpectedRotation;
				TOptional<FOculusXRUUID> ExpectedAnchorUUID;
				EMRUKPositioningMethod PositioningMethod;
			};

			TArray<TestData> AllTestData = {
				// Desk
				{
					{ -15.428, 52.817, 36.223 },
					{ 0.519, -0.143, -0.842 },
					0.0,
					{ 19.154, 34.502, -51.185 },
					{ 0.0, 0.0, -0.996050404, 0.088789598 },
					{ { { 0x1E, 0x57, 0x8C, 0x3E, 0x9E, 0x7B, 0x49, 0x5E, 0x9F, 0x8B, 0xB0, 0x0A, 0x37, 0x22, 0xB6, 0x19 } } },
					EMRUKPositioningMethod::Edge },
				// Desk
				{
					{ 0.0, 0.0, 0.0 },
					{ 1.0, 0.0, 0.0 },
					0.0,
					{ 121.404, 0.0, 0.0 },
					{ 0.000000072, 0.000000008, -0.994469644, 0.105024412 },
					{ { { 0x61, 0x34, 0x5A, 0x4C, 0xA1, 0xA0, 0x0C, 0x5C, 0x18, 0xC7, 0xAC, 0x34, 0x23, 0x37, 0x69, 0x01 } } },
					EMRUKPositioningMethod::Default },
				// Desk
				{
					{ 0.0, 0.0, 0.0 },
					{ 0.202, -0.725, -0.659 },
					0.0,
					{ 21.056, -75.154, -52.927 },
					{ 0.0, 0.0, 0.767014414, 0.641629869 },
					{ { { 0xB8, 0x82, 0x3B, 0xA2, 0x41, 0xD6, 0x9E, 0x1B, 0x5A, 0x3E, 0x71, 0x6F, 0xDC, 0x16, 0xC0, 0x35 } } },
					EMRUKPositioningMethod::Center },
				// Wall
				{
					{ 7.062, 83.282, -12.268 },
					{ 0.989, 0.146, 0.021 },
					0.0,
					{ 100.662, 97.104, -10.286 },
					{ 0.000000072, 0.000000008, -0.994469644, 0.105024412 },
					{ { { 0x61, 0x34, 0x5A, 0x4C, 0xA1, 0xA0, 0x0C, 0x5C, 0x18, 0xC7, 0xAC, 0x34, 0x23, 0x37, 0x69, 0x01 } } },
					EMRUKPositioningMethod::Default },
				// Floor
				{
					{ -55.000, 14.315, -64.814 },
					{ 0.054, 0.039, -0.998 },
					0.0,
					{ -51.499, 16.821, -129.629 },
					{ -0.000000000, 0.000000000, -0.952129375, 0.305695361 },
					{ { { 0x44, 0x08, 0xBC, 0xA3, 0x0B, 0x3E, 0xA7, 0x79, 0x99, 0x2A, 0x41, 0x33, 0x9E, 0x9B, 0xD1, 0x5E } } },
					EMRUKPositioningMethod::Default },
			};

			for (const auto& TestData : AllTestData)
			{
				FTransform ActualOutPose{};
				const auto Actor = Room->GetBestPoseFromRaycast(TestData.RayOrigin, TestData.RayDirection, TestData.MaxDist, {}, ActualOutPose, TestData.PositioningMethod);
				if (!TestData.ExpectedAnchorUUID.IsSet())
				{
					TestNull(TEXT("Actor is null"), Actor);
				}
				else
				{
					if (!TestNotNull(TEXT("Actor is set"), Actor))
					{
						return;
					}
					constexpr double Tolerance = 0.15;
					TestEqual(TEXT("Actor UUID is the same"), Actor->AnchorUUID, TestData.ExpectedAnchorUUID.GetValue());
					TestEqual(TEXT("Location is the same"), ActualOutPose.GetLocation(), TestData.ExpectedLocation, Tolerance);
					TestTrue(TEXT("Rotation is the same"), ActualOutPose.GetRotation().Equals(TestData.ExpectedRotation, Tolerance));
				}
			}
		});

		It(TEXT("Get key wall"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			const auto KeyWallAnchor = Room->GetKeyWall();
			if (!TestNotNull(TEXT("Key wall anchor is not null"), KeyWallAnchor))
			{
				return;
			}
			TestEqual(TEXT("Key wall anchor UUID is correct"), KeyWallAnchor->AnchorUUID, FOculusXRUUID({ 0x93, 0x4C, 0xE7, 0x5D, 0x63, 0xF0, 0x85, 0x6A, 0x94, 0x38, 0xDA, 0xB3, 0xAD, 0xA9, 0x54, 0x09 }));
		});

		It(TEXT("Get largest surface"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			auto Anchor = Room->GetLargestSurface(FMRUKLabels::WallArt);
			if (!TestNotNull(TEXT("Anchor is not null"), Anchor))
			{
				return;
			}
			TestEqual(TEXT("Anchor UUID is correct"), Anchor->AnchorUUID, FOculusXRUUID({ 0xDE, 0x8D, 0xDD, 0xD9, 0x90, 0xAD, 0x5F, 0xCB, 0x8E, 0x7E, 0x23, 0x7E, 0x93, 0x8C, 0xB0, 0xD3 }));

			Anchor = Room->GetLargestSurface(FMRUKLabels::Screen);
			if (!TestNotNull(TEXT("Anchor is not null"), Anchor))
			{
				return;
			}
			TestEqual(TEXT("Anchor UUID is correct"), Anchor->AnchorUUID, FOculusXRUUID({ 0x4F, 0x3D, 0x50, 0x69, 0x41, 0xFC, 0xDF, 0x2C, 0xDE, 0x52, 0x9B, 0x77, 0x8F, 0x7E, 0x2C, 0xA0 }));
		});

		It(TEXT("Point inside room"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			TArray<FVector> PointsInRoom = {
				{ 95.046, -12.727, 74.243 },
				{ -135.569, 88.847, -64.303 },
				{ -51.55, 69.412, 81.61 },
				{ 38.378, -21.614, -34.768 },
				{ -241.943, 167.824, 55.476 },
				{ 26.605, -72.533, -39.321 },
				{ -234.718, 147.491, 49.483 },
				{ -114.777, -32.589, -86.116 },
				{ -244.759, 113.77, -88.077 },
				{ 38.533, 24.966, -112.239 },
				{ 94.798, 22.833, 42.658 },
				{ -208.202, 86.037, -4.801 },
				{ -111.049, 140.856, -15.237 },
				{ 15.575, 70.207, 100.421 },
				{ -8.435, 186.92, -33.971 },
				{ 83.304, -1.605, 44.165 },
				{ -142.314, 88.862, -48.251 },
				{ 82.577, -21.908, -80.743 },
				{ -238.493, 105.266, -40.407 },
				{ -14.607, 2.971, -12.6 },
				{ -179.35, 191.319, 27.259 },
				{ -86.745, 75.297, 22.939 },
				{ -200.003, 150.154, 63.187 },
				{ 69.257, 137.913, -79.824 },
				{ -217.763, -15.493, 40.155 },
				{ -175.591, 187.332, -77.132 },
			};
			TArray<FVector> PointsOutsideRoom = {
				{ -245.656, 252.788, 115.908 },
				{ 125.832, 197.925, -136.036 },
				{ -257.614, 152.096, 152.655 },
				{ -249.694, -184.363, -59.927 },
				{ 153.152, -12.065, 122.478 },
				{ -61.405, 91.172, 170.071 },
				{ -85.013, 214.58, 165.639 },
				{ 97.861, 122.995, -74.949 },
				{ -67.454, -164.751, 25.332 },
				{ -307.367, 117.743, 58.999 },
				{ -16.464, -96.471, -146.66 },
				{ -163.323, 258.776, 28.556 },
				{ -195.161, 206.385, 85.72 },
				{ -216.943, 235.398, 126.688 },
				{ -288.013, 219.714, -48.284 },
				{ -222.667, -128.603, -173.879 },
				{ 7.732, 271.929, -105.47 },
				{ 68.097, 168.956, -145.375 },
				{ 55.597, -87.261, 141.444 },
				{ 99.099, -97.089, 0.583 },
				{ -228.267, -126.999, -88.321 },
				{ 181.973, -23.026, 129.291 },
				{ -107.073, -43.962, -158.281 },
				{ 172.614, 114.712, -128.513 },
				{ 161.491, 217.493, 140.58 },
				{ 154.978, 216.728, -52.095 },
				{ -280.619, 16.374, 38.726 },
				{ -195.068, -163.147, -70.396 },
				{ 156.432, 181.094, -58.986 },
				{ 67.725, -186.069, -149.307 },
				{ -256.253, 95.056, -20.023 },
				{ 149.64, 88.759, -59.373 },
				{ 25.693, 122.745, 148.911 },
				{ -62.503, -143.933, -103.133 },
				{ 121.933, 51.698, 168.209 },
				{ 72.676, 20.743, -163.189 },
				{ -284.95, 41.311, 111.688 },
				{ 4.034, 105.002, -160.053 },
				{ 6.185, -177.904, -154.869 },
				{ 21.763, 277.166, 179.376 },
				{ -290.38, -65.427, 134.753 },
				{ 161.042, 119.184, -29.429 },
				{ -292.113, -180.332, 161.352 },
				{ -79.784, 192.026, 119.786 },
				{ -295.718, 6.046, 135.894 },
				{ -273.905, 223.437, -26.792 },
				{ 177.765, 139.767, -13.221 },
				{ 133.273, 5.384, -18.993 },
				{ -199.152, -169.606, -87.036 },
				{ 30.782, -84.009, -134.418 },
				{ -73.394, -175.653, 54.978 },
				{ -44.264, 279.844, -118.853 },
				{ 155.457, 66.602, -94.68 },
				{ 164.383, 267.044, -158.237 },
				{ -25.081, 253.362, -175.43 },
				{ -312.178, -141.447, 154.339 },
				{ -82.336, -10.668, -142.827 },
				{ -312.781, 62.6, -70.972 },
				{ -68.104, 245.8, -18.926 },
				{ -116.402, 241.062, -10.163 },
				{ 123.96, 47.02, -20.643 },
				{ 181.741, -122.821, -64.27 },
				{ -68.568, 288.024, 19.715 },
				{ -285.368, 110.666, -93.628 },
				{ 43.468, -93.616, 164.687 },
				{ 171.453, 103.427, 125.081 },
				{ -204.397, -179.14, 174.834 },
				{ 49.192, 14.358, -143.414 },
				{ -136.188, 15.623, 133.944 },
				{ 77.812, 216.154, -108.196 },
				{ 166.967, 0.175, 66.023 },
				{ -282.119, 168.515, 86.119 },
				{ 80.612, -53.231, 175.787 },
				{ 97.66, -146.566, 35.457 }
			};
			for (auto Point : PointsInRoom)
			{
				TestTrue("Point in room", Room->IsPositionInRoom(Point, true));
			}
			for (auto Point : PointsOutsideRoom)
			{
				TestFalse("Point outside room", Room->IsPositionInRoom(Point, true));
			}
		});

		It(TEXT("Generate random position in room"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			// Generate 100 random positions in the room and verify that they are all indeed inside the room and not in scene volumes
			// using different minimum distances to surfaces
			FRandomStream RandomStream;
			TArray<float> MinDistanceToSurfaces = { 0.0f, 30.0f, 100.0f };
			for (float MinDistanceToSurface : MinDistanceToSurfaces)
			{
				AddInfo(FString::Printf(TEXT("Minimum distance to surface: %f"), MinDistanceToSurface));
				for (int i = 0; i < 100; ++i)
				{
					FVector Position;
					if (TestTrue(TEXT("Generated position successfully"), Room->GenerateRandomPositionInRoomFromStream(Position, RandomStream, MinDistanceToSurface, true)))
					{
						TestTrue(TEXT("Position is in room"), Room->IsPositionInRoom(Position));
						TestNull(TEXT("Position is not in a scene volume"), Room->IsPositionInSceneVolume(Position, true, MinDistanceToSurface));
						if (MinDistanceToSurface > 0.0f)
						{
							FVector SurfacePosition;
							double SurfaceDistance;
							TestNull(TEXT("Position is not within min distance of another surface"), Room->TryGetClosestSurfacePosition(Position, SurfacePosition, SurfaceDistance, {}, MinDistanceToSurface));
						}
					}
				}
			}

			// If the MinDistanceToSurface is too large such that there are no valid points, then it should fail to generate a random position in the room
			constexpr float LargeMinDistance = 300.0f;
			FVector Position;
			TestFalse(TEXT("No valid positions"), Room->GenerateRandomPositionInRoomFromStream(Position, RandomStream, LargeMinDistance));
		});

		It(TEXT("Ray cast"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			struct FRecordedRaycast
			{
				// Input
				FVector Position;
				FVector Direction;
				float MaxDist;
				// Output
				FString Label;
				FVector HitPosition;
				FVector HitNormal;
				float HitDistance;
			};
			TArray<FRecordedRaycast> RecordedRaycasts = {
				// Hits
				{ { 37.393, -14.003, -24.613 }, { 0.990, -0.048, -0.129 }, 0.0f, FMRUKLabels::Screen, { 84.823, -16.322, -30.780 }, { -0.995, 0.100, 0.000 }, 47.885 },
				{ { 37.393, -14.003, -24.613 }, { 0.990, -0.048, -0.129 }, 50.0f, FMRUKLabels::Screen, { 84.823, -16.322, -30.780 }, { -0.995, 0.100, 0.000 }, 47.885 },
				{ { -7.405, 27.794, -12.428 }, { 0.844, 0.003, -0.536 }, 0.0f, FMRUKLabels::Table, { 53.665, 28.008, -51.185 }, { 0.000, 0.000, 1.000 }, 72.33 },
				{ { -22.253, 36.487, 1.660 }, { 0.211, 0.054, -0.976 }, 0.0f, FMRUKLabels::Floor, { 6.171, 43.785, -129.629 }, { 0.000, -0.000, 1.000 }, 134.529 },
				{ { -22.253, 36.487, 1.660 }, { 0.432, 0.270, 0.861 }, 0.0f, FMRUKLabels::Ceiling, { 43.807, 77.766, 133.376 }, { 0.000, -0.000, -1.000 }, 153.026 },
				{ { -77.859, 204.433, -26.619 }, { 0.110, -0.534, -0.839 }, 0.0f, FMRUKLabels::Couch, { -70.131, 166.787, -85.797 }, { -0.180, 0.984, -0.000 }, 70.561 },
				{ { -127.986, 126.202, -94.119 }, { 0.606, -0.593, -0.530 }, 0.0f, FMRUKLabels::Floor, { -87.385, 86.442, -129.629 }, { 0.000, -0.000, 1.000 }, 67.009 },
				{ { -138.228, 108.241, -74.798 }, { -0.950, -0.240, -0.201 }, 0.0f, FMRUKLabels::Couch, { -187.570, 95.756, -85.245 }, { -0.000, 0.000, 1.000 }, 51.958 },
				{ { -298.759, 101.686, -76.521 }, { 0.968, -0.146, -0.204 }, 0.0f, FMRUKLabels::Couch, { -246.590, 93.797, -87.543 }, { -0.984, -0.180, -0.000 }, 53.901 },
				{ { -196.813, 0.663, -71.069 }, { 0.250, 0.908, -0.335 }, 0.0f, FMRUKLabels::Couch, { -181.948, 54.632, -91.002 }, { 0.180, -0.984, 0.000 }, 59.422 },
				{ { -115.905, 47.604, -6.411 }, { -0.199, 0.488, -0.850 }, 0.0f, FMRUKLabels::Couch, { -131.525, 85.882, -73.090 }, { -0.000, 0.000, 1.000 }, 78.456 },
				{ { -127.926, 109.603, 59.458 }, { -0.274, 0.955, -0.115 }, 0.0f, FMRUKLabels::WallArt, { -144.809, 168.482, 52.371 }, { 0.136, -0.991, -0.000 }, 61.66 },
				{ { 17.710, 137.262, 55.542 }, { 0.902, 0.409, -0.139 }, 0.0f, FMRUKLabels::WindowFrame, { 85.375, 167.955, 45.100 }, { -0.978, -0.207, -0.000 }, 75.031 },
				// Misses
				{ { -77.859, 204.433, -26.619 }, { 0.000, 0.000, -1.000 }, 0.0f, TEXT(""), { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
				{ { 37.393, -14.003, -24.613 }, { 0.990, -0.048, -0.129 }, 40.0f, TEXT(""), { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
				{ { -7.405, 27.794, -12.428 }, { 0.844, 0.003, -0.536 }, 70.0f, TEXT(""), { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 0.0f },
			};
			for (const auto& Recorded : RecordedRaycasts)
			{
				FMRUKHit Result;
				auto Anchor = Room->Raycast(Recorded.Position, Recorded.Direction, Recorded.MaxDist, {}, Result);
				// This is a fairly generous tolerance, but necessary because ray pos and direction were only recorded
				// up to 3 decimal places and small changes in direction can result in fairly large differences in hit position
				// over long distances.
				constexpr float Tolerance = 0.1;
				if (Anchor == nullptr)
				{
					TestTrue(TEXT("No hit"), Recorded.Label.IsEmpty());
				}
				else
				{
					TestEqual(TEXT("Hit position"), Result.HitPosition, Recorded.HitPosition, Tolerance);
					TestEqual(TEXT("Hit normal"), Result.HitNormal, Recorded.HitNormal, Tolerance);
					TestEqual(TEXT("Hit distance"), Result.HitDistance, Recorded.HitDistance, Tolerance);
					if (TestTrue(TEXT("Has semantic classification"), Anchor->SemanticClassifications.Num() > 0))
					{
						TestEqual(TEXT("Hit label"), Anchor->SemanticClassifications[0], Recorded.Label);
					}
				}
			}
		});

		It(TEXT("Ray cast all"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			struct FRecordedRaycastHit
			{
				FString Label;
				FVector HitPosition;
				FVector HitNormal;
				float HitDistance;
			};
			struct FRecordedRaycastAll
			{
				// Input
				FVector Position;
				FVector Direction;
				float MaxDist;
				// Output
				TArray<FRecordedRaycastHit> Hits;
			};
			TArray<FRecordedRaycastAll> RecordedRaycasts = {
				{ { 83.193, 58.82, 11.548 }, { 0.044, -0.904, -0.426 }, 0.0f, {
																				  { FMRUKLabels::WallFace, { 90.736, -95.398, -61.109 }, { -0.151, 0.989, 0 }, 170.643 },
																				  { FMRUKLabels::Table, { 89.705, -74.333, -51.185 }, { 0, 0, 1 }, 147.335 },
																				  { FMRUKLabels::Table, { 89.705, -74.333, -51.185 }, { 0, 0, 1 }, 147.335 },
																				  { FMRUKLabels::Screen, { 84.702, 27.972, -2.986 }, { 0, -0, 1 }, 34.133 },
																				  { FMRUKLabels::Screen, { 86.2, -2.658, -17.416 }, { -0.995, 0.1, 0 }, 68.026 },
																			  } }
			};
			for (const auto& Recorded : RecordedRaycasts)
			{
				TArray<FMRUKHit> Hits;
				TArray<AMRUKAnchor*> Anchors;
				Room->RaycastAll(Recorded.Position, Recorded.Direction, Recorded.MaxDist, {}, Hits, Anchors);
				// This is a fairly generous tolerance, but necessary because ray pos and direction were only recorded
				// up to 3 decimal places and small changes in direction can result in fairly large differences in hit position
				// over long distances.
				constexpr float Tolerance = 0.2;
				if (!TestEqual("Number of hits", Hits.Num(), Recorded.Hits.Num()))
				{
					continue;
				}
				if (!TestEqual("Number of anchors", Anchors.Num(), Recorded.Hits.Num()))
				{
					continue;
				}
				for (int i = 0; i < Recorded.Hits.Num(); ++i)
				{
					TestEqual(TEXT("Hit position"), Hits[i].HitPosition, Recorded.Hits[i].HitPosition, Tolerance);
					TestEqual(TEXT("Hit normal"), Hits[i].HitNormal, Recorded.Hits[i].HitNormal, Tolerance);
					TestEqual(TEXT("Hit distance"), Hits[i].HitDistance, Recorded.Hits[i].HitDistance, Tolerance);
					if (TestTrue(TEXT("Has semantic classification"), Anchors[i]->SemanticClassifications.Num() > 0))
					{
						TestEqual(TEXT("Hit label"), Anchors[i]->SemanticClassifications[0], Recorded.Hits[i].Label);
					}
				}
			}
		});

		It(TEXT("Parent/child relationship"), [this]() {
			auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}
			// Verify that child/parent relationship is consistent
			for (const auto& Anchor : Room->AllAnchors)
			{
				for (const auto& ChildAnchor : Anchor->ChildAnchors)
				{
					TestEqual(TEXT("Parent Anchor"), ChildAnchor->ParentAnchor, Anchor);
				}
				if (Anchor->ParentAnchor)
				{
					TestTrue(TEXT("Parent contains anchor in child list"), Anchor->ParentAnchor->ChildAnchors.Contains(Anchor));
				}
			}
			TestEqual(TEXT("Floor has the right number of children"), Room->FloorAnchor->ChildAnchors.Num(), 6);
			for (const auto& Anchor : Room->AllAnchors)
			{
				if (Anchor->SemanticClassifications.IsEmpty())
				{
					continue;
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::Screen)
				{
					if (TestNotNull(TEXT("Screen has parent"), Anchor->ParentAnchor.Get()))
					{
						if (TestTrue(TEXT("Screen parent has label"), !Anchor->ParentAnchor->SemanticClassifications.IsEmpty()))
						{
							TestEqual(TEXT("Screen is on table"), Anchor->ParentAnchor->SemanticClassifications[0], FMRUKLabels::Table);
						}
					}
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::Table)
				{
					TestEqual(TEXT("Table is on the floor"), Anchor->ParentAnchor, Room->FloorAnchor);
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::Storage)
				{
					TestEqual(TEXT("Storage is on the floor"), Anchor->ParentAnchor, Room->FloorAnchor);
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::Couch)
				{
					TestEqual(TEXT("Couch is on the floor"), Anchor->ParentAnchor, Room->FloorAnchor);
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::DoorFrame)
				{
					TestTrue(TEXT("Door frame is on wall"), Room->WallAnchors.Contains(Anchor->ParentAnchor));
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::WindowFrame)
				{
					TestTrue(TEXT("Window frame is on wall"), Room->WallAnchors.Contains(Anchor->ParentAnchor));
				}
				if (Anchor->SemanticClassifications[0] == FMRUKLabels::WallArt)
				{
					TestTrue(TEXT("Wall art is on wall"), Room->WallAnchors.Contains(Anchor->ParentAnchor));
				}
			}
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Toolkit"), [this] {
		SetupMRUKSubsystem();
		LoadSceneFromJson();

		It(TEXT("IsPositionInSceneVolume"), [this]() {
			struct TestData
			{
				FVector WorldPosition;
				bool TestVerticalBounds;
				double Tolerance;
				TOptional<FOculusXRUUID> ExpectedUUID;
			};

			TArray<TestData> AllTestData = {
				{ { 79.121, -20.291, -70.864 },
					true,
					0.0,
					{ { { 0x1E, 0x57, 0x8C, 0x3E, 0x9E, 0x7B, 0x49, 0x5E, 0x9F, 0x8B, 0xB0, 0x0A, 0x37, 0x22, 0xB6, 0x19 } } } },
				{ { 39.355, 0.683, -51.092 },
					true,
					1.0,
					{ { { 0x1E, 0x57, 0x8C, 0x3E, 0x9E, 0x7B, 0x49, 0x5E, 0x9F, 0x8B, 0xB0, 0x0A, 0x37, 0x22, 0xB6, 0x19 } } } },
				{ { 66.716, 4.072, -15.717 },
					false,
					0.0,
					{ { { 0x1E, 0x57, 0x8C, 0x3E, 0x9E, 0x7B, 0x49, 0x5E, 0x9F, 0x8B, 0xB0, 0x0A, 0x37, 0x22, 0xB6, 0x19 } } } },
				{ { 16.802, 23.632, -5.421 },
					false,
					0.0,
					{} },
			};

			for (const auto& TestData : AllTestData)
			{
				const auto ActualActor = ToolkitSubsystem->IsPositionInSceneVolume(TestData.WorldPosition, TestData.TestVerticalBounds, TestData.Tolerance);
				if (TestData.ExpectedUUID.IsSet())
				{
					TestNotNull(TEXT("Actual actor set"), ActualActor);
					TestEqual(TEXT("Actual actor UUID"), ActualActor->AnchorUUID, TestData.ExpectedUUID.GetValue());
				}
				else
				{
					TestNull(TEXT("Actual actor not set"), ActualActor);
				}
			}
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Anchor"), [this] {
		SetupMRUKSubsystem();
		LoadSceneFromJson();

		It(TEXT("HasLabel"), [this]() {
			const auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			if (!TestTrue(TEXT("Wall anchors available"), Room->WallAnchors.Num() > 0))
			{
				return;
			}
			for (const auto& WallAnchor : Room->WallAnchors)
			{
				TestTrue(TEXT("Has WALL_FACE label"), WallAnchor->HasLabel(FMRUKLabels::WallFace));
				TestFalse(TEXT("Has not FLOOR label"), WallAnchor->HasLabel(FMRUKLabels::Floor));
				TestFalse(TEXT("Has not CEILING label"), WallAnchor->HasLabel(FMRUKLabels::Ceiling));
			}

			if (!TestNotNull(TEXT("Floor anchor"), Room->FloorAnchor.Get()))
			{
				return;
			}
			TestTrue(TEXT("Has FLOOR label"), Room->FloorAnchor->HasLabel(FMRUKLabels::Floor));
			TestFalse(TEXT("Has not WALL_FACE label"), Room->FloorAnchor->HasLabel(FMRUKLabels::WallFace));
			TestFalse(TEXT("Has not CEILING label"), Room->FloorAnchor->HasLabel(FMRUKLabels::Ceiling));

			if (!TestNotNull(TEXT("Ceiling anchor"), Room->CeilingAnchor.Get()))
			{
				return;
			}
			TestTrue(TEXT("Has CEILING label"), Room->CeilingAnchor->HasLabel(FMRUKLabels::Ceiling));
			TestFalse(TEXT("Has not FLOOR label"), Room->CeilingAnchor->HasLabel(FMRUKLabels::Floor));
			TestFalse(TEXT("Has not WALL_FACE label"), Room->CeilingAnchor->HasLabel(FMRUKLabels::WallFace));
		});

		It(TEXT("ProceduralMesh"), [this]() {
			const auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			if (!TestNotNull(TEXT("Floor anchor"), Room->FloorAnchor.Get()))
			{
				return;
			}
			Room->FloorAnchor->AttachProceduralMesh();
			auto ProceduralMeshComponent = Room->FloorAnchor->ProceduralMeshComponent;
			if (!TestNotNull(TEXT("Has Procedural Mesh Component"), ProceduralMeshComponent.Get()))
			{
				return;
			}
			auto Section = ProceduralMeshComponent->GetProcMeshSection(0);
			if (!TestNotNull(TEXT("Mesh Section"), Section))
			{
				return;
			}
			TestEqual(TEXT("Floor vertices equal to number of walls"), Section->ProcVertexBuffer.Num(), Room->WallAnchors.Num());
			TestEqual(TEXT("Floor triangles equal to number of walls - 2"), Section->ProcIndexBuffer.Num(), 3 * (Room->WallAnchors.Num() - 2));

			// NOTE: There are a number of valid ways to triangulate the mesh, and it doesn't need to be exactly like this but
			// this will at least highlight if we unexpectedly caused the mesh generation to change its output.
			TArray<int32> ExpectedIndexBuffer = { 7, 0, 1, 1, 2, 3, 7, 1, 3, 7, 3, 4, 7, 4, 5, 5, 6, 7 };
			if (TestEqual(TEXT("Triangle index buffer size"), Section->ProcIndexBuffer.Num(), ExpectedIndexBuffer.Num()))
			{
				for (int i = 0; i < ExpectedIndexBuffer.Num(); i++)
				{
					TestEqual(TEXT("Floor triangle index buffer"), Section->ProcIndexBuffer[i], ExpectedIndexBuffer[i]);
				}
			}

			TArray<FMRUKTexCoordModes> WallTextureCoordinateModes{
				{ EMRUKCoordModeU::Stretch, EMRUKCoordModeV::MaintainAspectRatio },
				{ EMRUKCoordModeU::MetricSeamless, EMRUKCoordModeV::MaintainAspectRatio },
				{ EMRUKCoordModeU::MaintainAspectRatio, EMRUKCoordModeV::Stretch },
				{ EMRUKCoordModeU::MaintainAspectRatioSeamless, EMRUKCoordModeV::Metric },
			};
			Room->AttachProceduralMeshToWalls(WallTextureCoordinateModes, {});

			if (TestTrue(TEXT("Has walls"), !Room->WallAnchors.IsEmpty()))
			{
				ProceduralMeshComponent = Room->WallAnchors[0]->ProceduralMeshComponent;
				if (!TestNotNull(TEXT("Has Procedural Mesh Component"), ProceduralMeshComponent.Get()))
				{
					return;
				}
				Section = ProceduralMeshComponent->GetProcMeshSection(0);
				if (!TestNotNull(TEXT("Mesh Section"), Section))
				{
					return;
				}
				if (TestEqual(TEXT("Vertex buffer size"), Section->ProcVertexBuffer.Num(), 4))
				{
					TestEqual(TEXT("Vertex 0 UV 0"), Section->ProcVertexBuffer[0].UV0, FVector2D(0.770758, 0.184412));
					TestEqual(TEXT("Vertex 0 UV 1"), Section->ProcVertexBuffer[0].UV1, FVector2D(10.790611, 2.581766));
					TestEqual(TEXT("Vertex 0 UV 2"), Section->ProcVertexBuffer[0].UV2, FVector2D(4.179547, 1.000000));
					TestEqual(TEXT("Vertex 0 UV 3"), Section->ProcVertexBuffer[0].UV3, FVector2D(10.790611, 2.630046));
					TestEqual(TEXT("Vertex 1 UV 0"), Section->ProcVertexBuffer[1].UV0, FVector2D(1.000000, 0.184412));
					TestEqual(TEXT("Vertex 1 UV 1"), Section->ProcVertexBuffer[1].UV1, FVector2D(14.000000, 2.581766));
					TestEqual(TEXT("Vertex 1 UV 2"), Section->ProcVertexBuffer[1].UV2, FVector2D(5.422645, 1.000000));
					TestEqual(TEXT("Vertex 1 UV 3"), Section->ProcVertexBuffer[1].UV3, FVector2D(14.000000, 2.630046));
					TestEqual(TEXT("Vertex 2 UV 0"), Section->ProcVertexBuffer[2].UV0, FVector2D(1.000000, -0.000000));
					TestEqual(TEXT("Vertex 2 UV 1"), Section->ProcVertexBuffer[2].UV1, FVector2D(14.000000, -0.000000));
					TestEqual(TEXT("Vertex 2 UV 2"), Section->ProcVertexBuffer[2].UV2, FVector2D(5.422645, -0.000000));
					TestEqual(TEXT("Vertex 2 UV 3"), Section->ProcVertexBuffer[2].UV3, FVector2D(14.000000, -0.000000));
					TestEqual(TEXT("Vertex 3 UV 0"), Section->ProcVertexBuffer[3].UV0, FVector2D(0.770758, -0.000000));
					TestEqual(TEXT("Vertex 3 UV 1"), Section->ProcVertexBuffer[3].UV1, FVector2D(10.790611, -0.000000));
					TestEqual(TEXT("Vertex 3 UV 2"), Section->ProcVertexBuffer[3].UV2, FVector2D(4.179547, -0.000000));
					TestEqual(TEXT("Vertex 3 UV 3"), Section->ProcVertexBuffer[3].UV3, FVector2D(10.790611, -0.000000));
				}
			}
		});

		It(TEXT("ProceduralMesh with holes"), [this]() {
			const auto Room = ToolkitSubsystem->GetCurrentRoom();
			if (!TestNotNull(TEXT("Current room"), Room))
			{
				return;
			}

			Room->AttachProceduralMeshToWalls({}, { FMRUKLabels::WindowFrame, FMRUKLabels::DoorFrame });

			if (TestTrue(TEXT("Has walls"), !Room->WallAnchors.IsEmpty()))
			{
				const auto ProceduralMeshComponent = Room->WallAnchors[6]->ProceduralMeshComponent;
				if (!TestNotNull(TEXT("Has Procedural Mesh Component"), ProceduralMeshComponent.Get()))
				{
					return;
				}
				const auto Section = ProceduralMeshComponent->GetProcMeshSection(0);
				if (!TestNotNull(TEXT("Mesh Section"), Section))
				{
					return;
				}
				if (TestEqual(TEXT("Vertex buffer size"), Section->ProcVertexBuffer.Num(), 8))
				{
					constexpr double Tolerance = 0.001;
					TestEqual(TEXT("Vertex 0"), Section->ProcVertexBuffer[0].Position, FVector(0.0, -168.041, -131.505), Tolerance);
					TestEqual(TEXT("Vertex 1"), Section->ProcVertexBuffer[1].Position, FVector(0.0, 168.041, -131.505), Tolerance);
					TestEqual(TEXT("Vertex 2"), Section->ProcVertexBuffer[2].Position, FVector(0.0, 168.041, 131.505), Tolerance);
					TestEqual(TEXT("Vertex 3"), Section->ProcVertexBuffer[3].Position, FVector(0.0, -168.041, 131.505), Tolerance);
					TestEqual(TEXT("Vertex 4"), Section->ProcVertexBuffer[4].Position, FVector(0.0, 28.075, 111.358), Tolerance);
					TestEqual(TEXT("Vertex 5"), Section->ProcVertexBuffer[5].Position, FVector(0.0, 143.493, 111.358), Tolerance);
					TestEqual(TEXT("Vertex 6"), Section->ProcVertexBuffer[6].Position, FVector(0.0, 143.493, -61.585), Tolerance);
					TestEqual(TEXT("Vertex 7"), Section->ProcVertexBuffer[7].Position, FVector(0.0, 28.075, -61.585), Tolerance);
				}

				if (TestEqual(TEXT("Index buffer size"), Section->ProcIndexBuffer.Num(), 24))
				{
					TestEqual(TEXT("Index 0"), Section->ProcIndexBuffer[0], 1);
					TestEqual(TEXT("Index 1"), Section->ProcIndexBuffer[1], 5);
					TestEqual(TEXT("Index 2"), Section->ProcIndexBuffer[2], 6);
					TestEqual(TEXT("Index 3"), Section->ProcIndexBuffer[3], 0);
					TestEqual(TEXT("Index 4"), Section->ProcIndexBuffer[4], 1);
					TestEqual(TEXT("Index 5"), Section->ProcIndexBuffer[5], 6);
					TestEqual(TEXT("Index 6"), Section->ProcIndexBuffer[6], 0);
					TestEqual(TEXT("Index 7"), Section->ProcIndexBuffer[7], 6);
					TestEqual(TEXT("Index 8"), Section->ProcIndexBuffer[8], 7);
					TestEqual(TEXT("Index 9"), Section->ProcIndexBuffer[9], 3);
					TestEqual(TEXT("Index 10"), Section->ProcIndexBuffer[10], 0);
					TestEqual(TEXT("Index 11"), Section->ProcIndexBuffer[11], 7);
					TestEqual(TEXT("Index 12"), Section->ProcIndexBuffer[12], 3);
					TestEqual(TEXT("Index 13"), Section->ProcIndexBuffer[13], 7);
					TestEqual(TEXT("Index 14"), Section->ProcIndexBuffer[14], 4);
					TestEqual(TEXT("Index 15"), Section->ProcIndexBuffer[15], 3);
					TestEqual(TEXT("Index 16"), Section->ProcIndexBuffer[16], 4);
					TestEqual(TEXT("Index 17"), Section->ProcIndexBuffer[17], 5);
					TestEqual(TEXT("Index 18"), Section->ProcIndexBuffer[18], 5);
					TestEqual(TEXT("Index 19"), Section->ProcIndexBuffer[19], 1);
					TestEqual(TEXT("Index 20"), Section->ProcIndexBuffer[20], 2);
					TestEqual(TEXT("Index 21"), Section->ProcIndexBuffer[21], 5);
					TestEqual(TEXT("Index 22"), Section->ProcIndexBuffer[22], 2);
					TestEqual(TEXT("Index 23"), Section->ProcIndexBuffer[23], 3);
				}
			}
		});

		TeardownMRUKSubsystem();
	});

	Describe(TEXT("Utilities"), [this] {
		It(TEXT("Label Filter"), [this]() {
			FMRUKLabelFilter Filter;
			Filter.IncludedLabels.Push("FOO");
			Filter.IncludedLabels.Push("BAR");
			Filter.ExcludedLabels.Push("BAZ");
			Filter.ExcludedLabels.Push("QUX");
			TestTrue(TEXT("BAM, BAR Passes Filter"), Filter.PassesFilter({ { TEXT("BAM"), TEXT("BAR") } }));
			TestFalse(TEXT("BAZ Fails Filter"), Filter.PassesFilter({ { TEXT("BAZ") } }));
			TestFalse(TEXT("BAR, QUX Fails Filter"), Filter.PassesFilter({ { TEXT("BAR"), TEXT("QUX") } }));
			TestFalse(TEXT("BAM Fails Filter"), Filter.PassesFilter({ { TEXT("BAM") } }));

			Filter.IncludedLabels.Empty();
			TestTrue(TEXT("BAM Passes Filter"), Filter.PassesFilter({ { TEXT("BAM") } }));
		});
	});
}
