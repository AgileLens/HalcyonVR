// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include <memory>
#include "OculusXRAnchorTypes.generated.h"

#define OCULUSXR_UUID_SIZE 16

typedef uint8 ovrpXRUuidArray[OCULUSXR_UUID_SIZE];

UENUM(BlueprintType)
namespace EOculusXRAnchorResult
{
	enum Type
	{
		Success = 0,
		Success_EventUnavailable = 1,
		Success_Pending = 2,

		/// Failure
		Failure = -1000,
		Failure_InvalidParameter = -1001,
		Failure_NotInitialized = -1002,
		Failure_InvalidOperation = -1003,
		Failure_Unsupported = -1004,
		Failure_NotYetImplemented = -1005,
		Failure_OperationFailed = -1006,
		Failure_InsufficientSize = -1007,
		Failure_DataIsInvalid = -1008,
		Failure_DeprecatedOperation = -1009,
		Failure_ErrorLimitReached = -1010,
		Failure_ErrorInitializationFailed = -1011,

		/// Space error cases
		Failure_SpaceCloudStorageDisabled = -2000,
		Failure_SpaceMappingInsufficient = -2001,
		Failure_SpaceLocalizationFailed = -2002,
		Failure_SpaceNetworkTimeout = -2003,
		Failure_SpaceNetworkRequestFailed = -2004,


		/// APD warnings and error cases
		Failure_SpaceInsufficientResources = -9000,
		Failure_SpaceStorageAtCapacity = -9001,
		Failure_SpaceInsufficientView = -9002,
		Failure_SpacePermissionInsufficient = -9003,
		Failure_SpaceRateLimited = -9004,
		Failure_SpaceTooDark = -9005,
		Failure_SpaceTooBright = -9006,

		// Boundary visibility
		Warning_BoundaryVisibilitySuppressionNotAllowed = 9030,
	};
} // namespace EOculusXRAnchorResult

UENUM(BlueprintType, meta = (Bitflags))
enum class EOculusLocationFlags : uint8
{
	None = 0, // required for the metadata generation
	OrientationValid = (1 << 0),
	PositionValid = (1 << 1),
	OrientationTracked = (1 << 2),
	PositionTracked = (1 << 3)
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRAnchorLocationFlags
{
	GENERATED_BODY()
public:
	FOculusXRAnchorLocationFlags(uint32 InFlags = 0)
		: Flags(InFlags) {}

	bool OrientationValid() const
	{
		return Flags & static_cast<uint32>(EOculusLocationFlags::OrientationValid);
	}

	bool PositionValid() const
	{
		return Flags & static_cast<uint32>(EOculusLocationFlags::PositionValid);
	}

	bool OrientationTracked() const
	{
		return Flags & static_cast<uint32>(EOculusLocationFlags::OrientationTracked);
	}

	bool PositionTracked() const
	{
		return Flags & static_cast<uint32>(EOculusLocationFlags::PositionTracked);
	}

	bool IsValid() const
	{
		return OrientationValid() && PositionValid();
	}

private:
	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|SpatialAnchor", meta = (AllowPrivateAccess = "true", Bitmask, BitmaskEnum = "EOculusLocationFlags"))
	int32 Flags;
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRUUID
{
	GENERATED_BODY()

	FOculusXRUUID();
	FOculusXRUUID(const ovrpXRUuidArray& UuidArray);

	bool operator==(const FOculusXRUUID& Other) const;
	bool operator!=(const FOculusXRUUID& Other) const;

	bool IsValidUUID() const;

	bool IsEqual(const FOculusXRUUID& Other) const;
	friend uint32 GetTypeHash(const FOculusXRUUID& Other);
	bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);

	OCULUSXRANCHORS_API friend FArchive& operator<<(FArchive& Ar, FOculusXRUUID& UUID);
	bool Serialize(FArchive& Ar);

	FString ToString() const;

	uint8 UUIDBytes[OCULUSXR_UUID_SIZE];
};

template <>
struct TStructOpsTypeTraits<FOculusXRUUID> : public TStructOpsTypeTraitsBase2<FOculusXRUUID>
{
	enum
	{
		WithIdenticalViaEquality = true,
		WithNetSerializer = true,
		WithSerializer = true
	};
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRUInt64
{
	GENERATED_BODY()

	FOculusXRUInt64()
		: FOculusXRUInt64(0) {}
	FOculusXRUInt64(const uint64& Value) { this->Value = Value; }

	operator uint64() const { return Value; }
	bool operator==(const FOculusXRUInt64& Right) const;
	bool operator!=(const FOculusXRUInt64& Right) const;

	UPROPERTY()
	uint64 Value;

	bool IsEqual(const FOculusXRUInt64& Other) const
	{
		return Other.Value == Value;
	}

	friend uint32 GetTypeHash(const FOculusXRUInt64& Other)
	{
		return FCrc::MemCrc_DEPRECATED(&Other.Value, sizeof(Other.Value));
	}

	uint64 GetValue() const { return Value; };

	void SetValue(const uint64 Val) { Value = Val; };
};

template <>
struct TStructOpsTypeTraits<FOculusXRUInt64> : public TStructOpsTypeTraitsBase2<FOculusXRUInt64>
{
	enum
	{
		WithIdenticalViaEquality = true,
	};
};

UENUM(BlueprintType)
enum class EOculusXRSpaceQueryFilterType : uint8
{
	None = 0 UMETA(DisplayName = "No Filter"),
	FilterByIds = 1 UMETA(DisplayName = "Filter queries by UUIDs"),
	FilterByComponentType = 2 UMETA(DisplayName = "Filter queries by component type"),
};

// This is used as a bit-mask
UENUM(BlueprintType)
enum class EOculusXRSpaceStorageLocation : uint8
{
	Invalid = 0 UMETA(DisplayName = "Invalid"),
	Local = 1 << 0 UMETA(DisplayName = "Local"),
	Cloud = 1 << 1 UMETA(DisplayName = "Cloud")
};

UENUM(BlueprintType)
enum class EOculusXRSpaceStoragePersistenceMode : uint8
{
	Invalid = 0 UMETA(Hidden),
	Indefinite = 1 UMETA(DisplayName = "Indefinite"),
};

UENUM(BlueprintType)
enum class EOculusXRSpaceComponentType : uint8
{
	Locatable = 0 UMETA(DisplayName = "Locatable"),
	Storable = 1 UMETA(DisplayName = "Storable"),
	Sharable = 2 UMETA(DisplayName = "Sharable"),
	ScenePlane = 3 UMETA(DisplayName = "ScenePlane"),
	SceneVolume = 4 UMETA(DisplayName = "SceneVolume"),
	SemanticClassification = 5 UMETA(DisplayName = "SemanticClassification"),
	RoomLayout = 6 UMETA(DisplayName = "RoomLayout"),
	SpaceContainer = 7 UMETA(DisplayName = "SpaceContainer"),
	Undefined = 8 UMETA(DisplayName = "Not defined"),
	TriangleMesh = 9 UMETA(DisplayName = "TriangleMesh"),

};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRSpaceQueryInfo
{
	GENERATED_BODY()
public:
	FOculusXRSpaceQueryInfo()
		: MaxQuerySpaces(1024), Timeout(0), Location(EOculusXRSpaceStorageLocation::Local), FilterType(EOculusXRSpaceQueryFilterType::None)
	{
	}

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	int MaxQuerySpaces;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	float Timeout;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	EOculusXRSpaceStorageLocation Location;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	EOculusXRSpaceQueryFilterType FilterType;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	TArray<FOculusXRUUID> IDFilter;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	TArray<EOculusXRSpaceComponentType> ComponentFilter;
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRSpaceQueryResult
{
	GENERATED_BODY()
public:
	FOculusXRSpaceQueryResult()
		: Space(0), UUID(), Location(EOculusXRSpaceStorageLocation::Invalid) {}
	FOculusXRSpaceQueryResult(FOculusXRUInt64 SpaceHandle, FOculusXRUUID ID, EOculusXRSpaceStorageLocation SpaceLocation)
		: Space(SpaceHandle), UUID(ID), Location(SpaceLocation) {}

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	FOculusXRUInt64 Space;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	FOculusXRUUID UUID;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	EOculusXRSpaceStorageLocation Location;
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRSpaceQueryFilterValues
{
	GENERATED_BODY()
public:
	TArray<FOculusXRUUID> Uuids;						// used if filtering by UUIDs
	TArray<EOculusXRSpaceComponentType> ComponentTypes; // used if filtering by component types
};

struct ovrpSpaceDiscoveryFilterHeader_;
typedef ovrpSpaceDiscoveryFilterHeader_ ovrpSpaceDiscoveryFilterHeader;

UCLASS(BlueprintType)
class OCULUSXRANCHORS_API UOculusXRSpaceDiscoveryFilterBase : public UObject
{
	GENERATED_BODY()
public:
	virtual const ovrpSpaceDiscoveryFilterHeader* GenerateOVRPFilter()
	{
		return nullptr;
	}
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRSpaceDiscoveryInfo
{
	GENERATED_BODY()
public:
	FOculusXRSpaceDiscoveryInfo()
	{
	}

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	TArray<UOculusXRSpaceDiscoveryFilterBase*> Filters;
};

USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRAnchorsDiscoverResult
{
	GENERATED_BODY()
public:
	FOculusXRAnchorsDiscoverResult()
		: Space(0), UUID() {}
	FOculusXRAnchorsDiscoverResult(FOculusXRUInt64 SpaceHandle, FOculusXRUUID ID)
		: Space(SpaceHandle), UUID(ID) {}

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	FOculusXRUInt64 Space;

	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	FOculusXRUUID UUID;
};

struct ovrpSpaceDiscoveryFilterIds_;
typedef ovrpSpaceDiscoveryFilterIds_ ovrpSpaceDiscoveryFilterIds;
struct ovrpSpaceDiscoveryFilterIdsDelete
{
	void operator()(ovrpSpaceDiscoveryFilterIds* ptr) const;
};

struct DiscoveryUuidWrapper
{
	unsigned char data[16];
};

UCLASS(Blueprintable, Category = "OculusXR|SpatialAnchor")
class OCULUSXRANCHORS_API UOculusXRSpaceDiscoveryIdsFilter : public UOculusXRSpaceDiscoveryFilterBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	TArray<FOculusXRUUID> Uuids;

	TArray<DiscoveryUuidWrapper> wrappedUUIDs;

	virtual const ovrpSpaceDiscoveryFilterHeader* GenerateOVRPFilter() override;

private:
	std::unique_ptr<ovrpSpaceDiscoveryFilterIds, ovrpSpaceDiscoveryFilterIdsDelete> OVRPFilterIds;
};

struct ovrpSpaceDiscoveryFilterComponents_;
typedef ovrpSpaceDiscoveryFilterComponents_ ovrpSpaceDiscoveryFilterComponents;
struct ovrpSpaceDiscoveryFilterComponentsDelete
{
	void operator()(ovrpSpaceDiscoveryFilterComponents* ptr) const;
};

UCLASS(Blueprintable, Category = "OculusXR|SpatialAnchor")
class OCULUSXRANCHORS_API UOculusXRSpaceDiscoveryComponentsFilter : public UOculusXRSpaceDiscoveryFilterBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "OculusXR|SpatialAnchor")
	EOculusXRSpaceComponentType ComponentType;

	virtual const ovrpSpaceDiscoveryFilterHeader* GenerateOVRPFilter() override;

private:
	std::unique_ptr<ovrpSpaceDiscoveryFilterComponents, ovrpSpaceDiscoveryFilterComponentsDelete> OVRPFilterComponent;
};

// Represents a room layout within a specific space
USTRUCT(BlueprintType)
struct OCULUSXRANCHORS_API FOculusXRRoomLayout
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	FOculusXRUInt64 RoomAnchorHandle;

	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	FOculusXRUUID RoomUuid;


	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	FOculusXRUUID FloorUuid;

	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	FOculusXRUUID CeilingUuid;

	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	TArray<FOculusXRUUID> WallsUuid;

	UPROPERTY(BlueprintReadOnly, Category = "OculusXR|Anchors")
	TArray<FOculusXRUUID> RoomObjectUUIDs;
};
