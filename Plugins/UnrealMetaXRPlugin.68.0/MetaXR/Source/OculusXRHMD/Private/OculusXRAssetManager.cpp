// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRAssetManager.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMDModule.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/SoftObjectPath.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"
#include "OculusXRAssetDirectory.h"
#include "UObject/GCObject.h"

/* FOculusAssetDirectory
 *****************************************************************************/

enum EOculusAsset
{
	LeftTouchRiftS,
	RightTouchRiftS,
	LeftTouchQuest2,
	RightTouchQuest2,
	LeftTouchQuestPro,
	RightTouchQuestPro,
	LeftTouchQuest3,
	RightTouchQuest3,
	OculusAssetTotal
};

FSoftObjectPath FOculusAssetDirectory::AssetListing[OculusAssetTotal] = {
	FString(TEXT("/OculusXR/Meshes/LeftTouchForQuestRiftSController.LeftTouchForQuestRiftSController")),
	FString(TEXT("/OculusXR/Meshes/RightTouchForQuestRiftSController.RightTouchForQuestRiftSController")),
	FString(TEXT("/OculusXR/Meshes/LeftTouchForQuest2.LeftTouchForQuest2")),
	FString(TEXT("/OculusXR/Meshes/RightTouchForQuest2.RightTouchForQuest2")),
	FString(TEXT("/OculusXR/Meshes/LeftMetaQuestTouchPro.LeftMetaQuestTouchPro")),
	FString(TEXT("/OculusXR/Meshes/RightMetaQuestTouchPro.RightMetaQuestTouchPro")),
	FString(TEXT("/OculusXR/Meshes/LeftMetaQuestTouchPlus.LeftMetaQuestTouchPlus")),
	FString(TEXT("/OculusXR/Meshes/RightMetaQuestTouchPlus.RightMetaQuestTouchPlus")),
};

#if WITH_EDITORONLY_DATA
class FOculusAssetRepo : public FGCObject, public TArray<UObject*>
{
public:
	// made an on-demand singleton rather than a static global, to avoid issues with FGCObject initialization
	static FOculusAssetRepo& Get()
	{
		static FOculusAssetRepo AssetRepository;
		return AssetRepository;
	}

	UObject* LoadAndAdd(const FSoftObjectPath& AssetPath)
	{
		UObject* AssetObj = AssetPath.TryLoad();
		if (AssetObj != nullptr)
		{
			AddUnique(AssetObj);
		}
		return AssetObj;
	}

public:
	//~ FGCObject interface
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override
	{
		Collector.AddReferencedObjects(*this);
	}
	virtual FString GetReferencerName() const override
	{
		return TEXT("FOculusAssetRepo");
	}
};

void FOculusAssetDirectory::LoadForCook()
{
	FOculusAssetRepo& AssetRepro = FOculusAssetRepo::Get();
	for (int32 AssetIndex = 0; AssetIndex < UE_ARRAY_COUNT(FOculusAssetDirectory::AssetListing); ++AssetIndex)
	{
		AssetRepro.LoadAndAdd(FOculusAssetDirectory::AssetListing[AssetIndex]);
	}
}

void FOculusAssetDirectory::ReleaseAll()
{
	FOculusAssetRepo::Get().Empty();
}
#endif // WITH_EDITORONLY_DATA

/* OculusAssetManager_Impl
 *****************************************************************************/

namespace OculusAssetManager_Impl
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	struct FRenderableDevice
	{
		ovrpNode OVRNode;
		ovrpSystemHeadset MinDeviceRange;
		ovrpSystemHeadset MaxDeviceRange;
		FSoftObjectPath MeshAssetRef;
	};

	static FRenderableDevice RenderableDevices[] = {
#if PLATFORM_ANDROID
		// Quest 1 & 2
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Oculus_Quest, ovrpSystemHeadset_Oculus_Quest_2, FOculusAssetDirectory::AssetListing[LeftTouchQuest2] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Oculus_Quest, ovrpSystemHeadset_Oculus_Quest_2, FOculusAssetDirectory::AssetListing[RightTouchQuest2] },

		// Quest Pro
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Meta_Quest_Pro, ovrpSystemHeadset_Meta_Quest_Pro, FOculusAssetDirectory::AssetListing[LeftTouchQuestPro] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Meta_Quest_Pro, ovrpSystemHeadset_Meta_Quest_Pro, FOculusAssetDirectory::AssetListing[RightTouchQuestPro] },

		// Quest 3
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Meta_Quest_3, ovrpSystemHeadset_Meta_Quest_3, FOculusAssetDirectory::AssetListing[LeftTouchQuest3] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Meta_Quest_3, ovrpSystemHeadset_Meta_Quest_3, FOculusAssetDirectory::AssetListing[RightTouchQuest3] },
#else
		// PC - Rift S
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Rift_S, ovrpSystemHeadset_Rift_S, FOculusAssetDirectory::AssetListing[LeftTouchRiftS] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Rift_S, ovrpSystemHeadset_Rift_S, FOculusAssetDirectory::AssetListing[RightTouchRiftS] },

		// PC - Quest 1 & 2
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Oculus_Link_Quest, ovrpSystemHeadset_Oculus_Link_Quest_2, FOculusAssetDirectory::AssetListing[LeftTouchQuest2] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Oculus_Link_Quest, ovrpSystemHeadset_Oculus_Link_Quest_2, FOculusAssetDirectory::AssetListing[RightTouchQuest2] },

		// PC - Quest Pro
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Meta_Link_Quest_Pro, ovrpSystemHeadset_Meta_Link_Quest_Pro, FOculusAssetDirectory::AssetListing[LeftTouchQuestPro] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Meta_Link_Quest_Pro, ovrpSystemHeadset_Meta_Link_Quest_Pro, FOculusAssetDirectory::AssetListing[RightTouchQuestPro] },

		// Quest 3
		{ ovrpNode_HandLeft, ovrpSystemHeadset_Meta_Link_Quest_3, ovrpSystemHeadset_Meta_Link_Quest_3, FOculusAssetDirectory::AssetListing[LeftTouchQuest3] },
		{ ovrpNode_HandRight, ovrpSystemHeadset_Meta_Link_Quest_3, ovrpSystemHeadset_Meta_Link_Quest_3, FOculusAssetDirectory::AssetListing[RightTouchQuest3] },
#endif
	};

	static uint32 RenderableDeviceCount = sizeof(RenderableDevices) / sizeof(RenderableDevices[0]);
#endif // #if OCULUS_HMD_SUPPORTED_PLATFORMS

	static UObject* FindDeviceMesh(const int32 DeviceID);
}; // namespace OculusAssetManager_Impl

static UObject* OculusAssetManager_Impl::FindDeviceMesh(const int32 DeviceID)
{
	UObject* DeviceMesh = nullptr;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	const ovrpNode DeviceOVRNode = OculusXRHMD::ToOvrpNode(DeviceID);

	bool bUseSystemHeadsetType = false;
	ovrpSystemHeadset HeadsetType;
	if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetSystemHeadsetType2(&HeadsetType)))
	{
		bUseSystemHeadsetType = true;
	}

	if (DeviceOVRNode != ovrpNode_None)
	{
		for (uint32 DeviceIndex = 0; DeviceIndex < RenderableDeviceCount; ++DeviceIndex)
		{
			const FRenderableDevice& RenderableDevice = RenderableDevices[DeviceIndex];
			if (RenderableDevice.OVRNode == DeviceOVRNode)
			{
				// If we have information about the current headset, load the model based of the headset information, otherwise load defaults.
				if (bUseSystemHeadsetType)
				{
					if (HeadsetType >= RenderableDevice.MinDeviceRange && HeadsetType <= RenderableDevice.MaxDeviceRange)
					{
						DeviceMesh = RenderableDevice.MeshAssetRef.TryLoad();
						break;
					}
				}
				else
				{
					DeviceMesh = RenderableDevice.MeshAssetRef.TryLoad();
					break;
				}
			}
		}
	}
#endif
	return DeviceMesh;
}

/* FOculusAssetManager
*****************************************************************************/

FOculusAssetManager::FOculusAssetManager()
{
	IModularFeatures::Get().RegisterModularFeature(IXRSystemAssets::GetModularFeatureName(), this);

	ResourceHolder = NewObject<UOculusXRResourceHolder>();
	ResourceHolder->AddToRoot();
}

FOculusAssetManager::~FOculusAssetManager()
{
	if (ResourceHolder)
	{
		ResourceHolder->ConditionalBeginDestroy();
		ResourceHolder = nullptr;
	}

	IModularFeatures::Get().UnregisterModularFeature(IXRSystemAssets::GetModularFeatureName(), this);
}

bool FOculusAssetManager::EnumerateRenderableDevices(TArray<int32>& DeviceListOut)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	using namespace OculusAssetManager_Impl;
	DeviceListOut.Empty(RenderableDeviceCount);

	for (uint32 DeviceIndex = 0; DeviceIndex < RenderableDeviceCount; ++DeviceIndex)
	{
		const FRenderableDevice& RenderableDevice = RenderableDevices[DeviceIndex];

		const int32 ExternalDeviceId = OculusXRHMD::ToExternalDeviceId(RenderableDevice.OVRNode);
		DeviceListOut.Add(ExternalDeviceId);
	}

	return true;
#else
	return false;
#endif
}

int32 FOculusAssetManager::GetDeviceId(EControllerHand ControllerHand)
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	ovrpNode ControllerOVRNode = ovrpNode_None;

	switch (ControllerHand)
	{
		case EControllerHand::AnyHand:
			// @TODO: maybe check if the right is tracking, if not choose left (if tracking)?
		case EControllerHand::Right:
			ControllerOVRNode = ovrpNode_HandRight;
			break;
		case EControllerHand::Left:
			ControllerOVRNode = ovrpNode_HandLeft;
			break;

		case EControllerHand::ExternalCamera:
			ControllerOVRNode = ovrpNode_TrackerZero;
			break;
			// 	case EControllerHand::Special_1:
			// 		ControllerOVRNode = ovrpNode_TrackerOne;
			// 		break;
			// 	case EControllerHand::Special_2:
			// 		ControllerOVRNode = ovrpNode_TrackerTwo;
			// 		break;
			// 	case EControllerHand::Special_3:
			// 		ControllerOVRNode = ovrpNode_TrackerThree;
			// 		break;

			// 	case EControllerHand::Special_4:
			// 		ControllerOVRNode = ovrpNode_DeviceObjectZero;
			// 		break;

		default:
			// ControllerOVRNode = ovrpNode_None => returns -1
			break;
	}
	return OculusXRHMD::ToExternalDeviceId(ControllerOVRNode);
#else
	return INDEX_NONE;
#endif
}

UPrimitiveComponent* FOculusAssetManager::CreateRenderComponent(const int32 DeviceId, AActor* Owner, EObjectFlags Flags, const bool /*bForceSynchronous*/, const FXRComponentLoadComplete& OnLoadComplete)
{
	UPrimitiveComponent* NewRenderComponent = nullptr;
	if (UObject* DeviceMesh = OculusAssetManager_Impl::FindDeviceMesh(DeviceId))
	{
		if (UStaticMesh* AsStaticMesh = Cast<UStaticMesh>(DeviceMesh))
		{
			const FName ComponentName = MakeUniqueObjectName(Owner, UStaticMeshComponent::StaticClass(), *FString::Printf(TEXT("%s_Device%d"), TEXT("Oculus"), DeviceId));
			UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(Owner, ComponentName, Flags);

			MeshComponent->SetStaticMesh(AsStaticMesh);
			NewRenderComponent = MeshComponent;
		}
		else if (USkeletalMesh* AsSkeletalMesh = Cast<USkeletalMesh>(DeviceMesh))
		{
			const FName ComponentName = MakeUniqueObjectName(Owner, USkeletalMeshComponent::StaticClass(), *FString::Printf(TEXT("%s_Device%d"), TEXT("Oculus"), DeviceId));
			USkeletalMeshComponent* SkelMeshComponent = NewObject<USkeletalMeshComponent>(Owner, ComponentName, Flags);

			SkelMeshComponent->SetSkeletalMesh(AsSkeletalMesh);
			NewRenderComponent = SkelMeshComponent;
		}
		NewRenderComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	OnLoadComplete.ExecuteIfBound(NewRenderComponent);
	return NewRenderComponent;
}
