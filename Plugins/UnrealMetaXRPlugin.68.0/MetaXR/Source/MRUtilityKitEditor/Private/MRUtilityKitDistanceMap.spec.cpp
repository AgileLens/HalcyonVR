// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "DistanceMapTestData.h"
#include "MRUtilityKitDistanceMapGenerator.h"
#include "MRUtilityKitSubsystem.h"
#include "TestHelper.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/CanvasRenderTarget2D.h"
#include "Tests/AutomationEditorCommon.h"

static void WriteTGA(const FString& FilePath, const TArray<FColor>& Pixels, int32 Width, int32 Height)
{
	// Create file
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenWrite(*FilePath);
	if (FileHandle)
	{
		// TGA File Header
		uint8 TGAHeader[18] = {};
		TGAHeader[2] = 2; // Uncompressed Type
		TGAHeader[12] = Width & 0xFF;
		TGAHeader[13] = (Width >> 8) & 0xFF;
		TGAHeader[14] = Height & 0xFF;
		TGAHeader[15] = (Height >> 8) & 0xFF;
		TGAHeader[16] = 32;	  // Bits per Pixel
		TGAHeader[17] = 0x20; // Top-Down, Non-Interlaced
		// Write TGA Header
		FileHandle->Write(TGAHeader, sizeof(TGAHeader));
		// Write Pixels
		for (int32 i = 0; i < Width * Height; i++)
		{
			const FColor& Pixel = Pixels[i];
			uint8 BGRA[4] = { Pixel.B, Pixel.G, Pixel.R, Pixel.A };
			FileHandle->Write(BGRA, sizeof(BGRA));
		}

		// Close the file
		delete FileHandle;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to open file for writing: %s"), *FilePath);
	}
}

static TArray<FColor> ReadTGAFromMemory(const uint8* Data, size_t DataSize)
{
	TArray<FColor> Pixels;

	// Read TGA Header
	uint8 TGAHeader[18];
	memcpy(TGAHeader, Data, sizeof(TGAHeader));
	// Get image dimensions from header
	const int32 Width = TGAHeader[12] | (TGAHeader[13] << 8);
	const int32 Height = TGAHeader[14] | (TGAHeader[15] << 8);

	if (Width * Height > DataSize)
	{
		return {};
	}

	// Resize pixel array
	Pixels.SetNumUninitialized(Width * Height);
	// Read Pixels
	uint32 Offset = sizeof(TGAHeader);
	for (int32 i = 0; i < Width * Height; i++)
	{
		uint8 BGRA[4];
		memcpy(BGRA, Data + Offset, sizeof(BGRA));
		Offset += sizeof(BGRA);
		// Convert from BGRA to RGBA
		Pixels[i] = FColor(BGRA[2], BGRA[1], BGRA[0], BGRA[3]);
	}

	return Pixels;
}

static TArray<FColor> ReadTGAFromFile(const FString& FilePath)
{
	IFileHandle* FileHandle = FPlatformFileManager::Get().GetPlatformFile().OpenRead(*FilePath);
	TArray<uint8_t> Data;
	Data.SetNum(FileHandle->Size());
	FileHandle->Read(Data.GetData(), Data.Num());
	return ReadTGAFromMemory(Data.GetData(), Data.Num());
}

BEGIN_DEFINE_SPEC(FMRUKDistanceMapSpec, TEXT("MR Utility Kit"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FMRUKDistanceMapSpec)

void FMRUKDistanceMapSpec::Define()
{
	Describe(TEXT("Distance map"), [this] {
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

		It(TEXT("Capture distance map"), [this] {
			const auto World = GEditor->GetPIEWorldContext()->World();
			const auto GameInstance = World->GetGameInstance();
			UMRUKSubsystem* Subsystem = GameInstance->GetSubsystem<UMRUKSubsystem>();
			Subsystem->LoadSceneFromJsonString(ExampleRoomJson);

			// Create and setup distance map generator
			const FActorSpawnParameters Params{};
			AMRUKDistanceMapGenerator* DistanceMapGenerator = World->SpawnActor<AMRUKDistanceMapGenerator>(Params);
			DistanceMapGenerator->SetActorLocation(FVector(0.0, 0.0, 200.0));
			DistanceMapGenerator->SetActorRotation(FRotator::MakeFromEuler(FVector(0.0, -90.0, 0.0)));

			UCanvasRenderTarget2D* RenderTarget = Cast<UCanvasRenderTarget2D>(DistanceMapGenerator->CaptureDistanceMap());
			FTextureRenderTargetResource* RenderTargetResource = RenderTarget->GameThread_GetRenderTargetResource();
			// Create an array to store the pixel data
			TArray<FColor> PixelData;
			// Read the pixel data from the Render Target
			ENQUEUE_RENDER_COMMAND(ReadSurfaceCommand)
			(
				[RenderTargetResource, &PixelData](FRHICommandListImmediate& RHICmdList) {
					const FTexture2DRHIRef Texture2DRHI = RenderTargetResource->GetRenderTargetTexture();
					RHICmdList.ReadSurfaceData(
						Texture2DRHI,
						FIntRect(0, 0, Texture2DRHI->GetSizeX(), Texture2DRHI->GetSizeY()),
						PixelData,
						FReadSurfaceDataFlags());
				});
			// Wait for the rendering thread to finish executing the command
			FlushRenderingCommands();

			// Compare result

			const TArray<FColor> ExpectedPixels = ReadTGAFromMemory(DistanceMapTestData, sizeof(DistanceMapTestData));

			bool Success = true;
			if (!TestEqual(TEXT("Pixel count matches"), PixelData.Num(), ExpectedPixels.Num()))
			{
				Success = false;
			}
			for (int32 I = 0; I < PixelData.Num() && Success; ++I)
			{
				if (!TestEqual(TEXT("R channel matches"), PixelData[I].R, ExpectedPixels[I].R))
				{
					Success = false;
					break;
				}
				if (!TestEqual(TEXT("G channel matches"), PixelData[I].G, ExpectedPixels[I].G))
				{
					Success = false;
					break;
				}
				if (!TestEqual(TEXT("B channel matches"), PixelData[I].B, ExpectedPixels[I].B))
				{
					Success = false;
					break;
				}
				if (!TestEqual(TEXT("A channel matches"), PixelData[I].A, ExpectedPixels[I].A))
				{
					Success = false;
					break;
				}
			}

			if (!Success)
			{
				const FString& TestResultsPath = FPaths::Combine(FPaths::ProjectIntermediateDir(), "TestResults");

				IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
				if (!PlatformFile.DirectoryExists(*TestResultsPath))
				{
					PlatformFile.CreateDirectory(*TestResultsPath);
				}

				const FString& ActualPixelsFilename = FPaths::CreateTempFilename(*TestResultsPath, TEXT("DistanceMapTest_ActualPixels"), TEXT(".tga"));
				const FString& ExpectedPixelsFilename = FPaths::CreateTempFilename(*TestResultsPath, TEXT("DistanceMapTest_ExpectedPixels"), TEXT(".tga"));
				// The resulting binary data can be converted to C array with the tool found here https://github.com/AntumDeluge/bin2header
				WriteTGA(ActualPixelsFilename, PixelData, RenderTarget->SizeX, RenderTarget->SizeY);
				WriteTGA(ExpectedPixelsFilename, PixelData, RenderTarget->SizeX, RenderTarget->SizeY);
				UE_LOG(LogTemp, Warning, TEXT("Expected pixels have been saved as tga file in %s"), *ExpectedPixelsFilename);
				UE_LOG(LogTemp, Warning, TEXT("Actual pixels have been saved as tga file in %s"), *ActualPixelsFilename);
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
