// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Dom/JsonObject.h"
#include "OculusXRAnchorTypes.h"
#include "OculusXRRoomLayoutManagerComponent.h"

TSharedPtr<FJsonValue> MRUKSerialize(const FString& String);

void MRUKDeserialize(const FJsonValue& Value, FString& String);

TSharedPtr<FJsonValue> MRUKSerialize(const FOculusXRUUID& UUID);

void MRUKDeserialize(const FJsonValue& Value, FOculusXRUUID& UUID);

TSharedPtr<FJsonValue> MRUKSerialize(const double& Number);

void MRUKDeserialize(const FJsonValue& Value, double& Number);

TSharedPtr<FJsonValue> MRUKSerialize(const FOculusXRRoomLayout& RoomLayout);

void MRUKDeserialize(const FJsonValue& Value, FOculusXRRoomLayout& RoomLayout);

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TVector2<T>& Vector)
{
	return MakeShareable(new FJsonValueArray({ MakeShareable(new FJsonValueNumber(Vector.X)), MakeShareable(new FJsonValueNumber(Vector.Y)) }));
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TVector2<T>& Vector)
{
	if (auto Array = Value.AsArray(); Array.Num() == 2)
	{
		MRUKDeserialize(*Array[0], Vector.X);
		MRUKDeserialize(*Array[1], Vector.Y);
	}
	else
	{
		UE_LOG(LogJson, Error, TEXT("Json Array is of length %d (expected 2) when deserializing TVector2"), Array.Num());
		Vector = UE::Math::TVector2<T>::ZeroVector;
	}
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TVector<T>& Vector)
{
	return MakeShareable(new FJsonValueArray({ MakeShareable(new FJsonValueNumber(Vector.X)), MakeShareable(new FJsonValueNumber(Vector.Y)), MakeShareable(new FJsonValueNumber(Vector.Z)) }));
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TVector<T>& Vector)
{
	auto Array = Value.AsArray();
	if (Array.Num() == 3)
	{
		MRUKDeserialize(*Array[0], Vector.X);
		MRUKDeserialize(*Array[1], Vector.Y);
		MRUKDeserialize(*Array[2], Vector.Z);
	}
	else
	{
		UE_LOG(LogJson, Error, TEXT("Json Array is of length %d (expected 3) when deserializing TVector"), Array.Num());
		Vector = UE::Math::TVector<T>::ZeroVector;
	}
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TRotator<T>& Rotation)
{
	return MakeShareable(new FJsonValueArray({ MakeShareable(new FJsonValueNumber(Rotation.Pitch)), MakeShareable(new FJsonValueNumber(Rotation.Yaw)), MakeShareable(new FJsonValueNumber(Rotation.Roll)) }));
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TRotator<T>& Rotation)
{
	auto Array = Value.AsArray();
	if (Array.Num() == 3)
	{
		MRUKDeserialize(*Array[0], Rotation.Pitch);
		MRUKDeserialize(*Array[1], Rotation.Yaw);
		MRUKDeserialize(*Array[2], Rotation.Roll);
	}
	else
	{
		UE_LOG(LogJson, Error, TEXT("Json Array is of length %d (expected 3) when deserializing TRotator"), Array.Num());
		Rotation = UE::Math::TRotator<T>::ZeroRotator;
	}
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TBox2<T>& Box)
{
	if (Box.bIsValid)
	{
		const TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		JsonObject->SetField(TEXT("Min"), MRUKSerialize(Box.Min));
		JsonObject->SetField(TEXT("Max"), MRUKSerialize(Box.Max));
		return MakeShareable(new FJsonValueObject(JsonObject));
	}
	else
	{
		return MakeShareable(new FJsonValueNull());
	}
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TBox2<T>& Box)
{
	if (Value.IsNull())
	{
		Box.Init();
	}
	else
	{
		const auto Object = Value.AsObject();
		MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Min")), Box.Min);
		MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Max")), Box.Max);
		Box.bIsValid = true;
	}
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TBox<T>& Box)
{
	if (Box.IsValid)
	{
		const TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		JsonObject->SetField(TEXT("Min"), MRUKSerialize(Box.Min));
		JsonObject->SetField(TEXT("Max"), MRUKSerialize(Box.Max));
		return MakeShareable(new FJsonValueObject(JsonObject));
	}
	else
	{
		return MakeShareable(new FJsonValueNull());
	}
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TBox<T>& Box)
{
	if (Value.IsNull())
	{
		Box.Init();
	}
	else
	{
		const auto Object = Value.AsObject();
		MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Min")), Box.Min);
		MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Max")), Box.Max);
		Box.IsValid = 1;
	}
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const UE::Math::TTransform<T>& Transform)
{
	const TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetField(TEXT("Translation"), MRUKSerialize(Transform.GetTranslation()));
	JsonObject->SetField(TEXT("Rotation"), MRUKSerialize(Transform.Rotator()));
	JsonObject->SetField(TEXT("Scale"), MRUKSerialize(Transform.GetScale3D()));
	return MakeShareable(new FJsonValueObject(JsonObject));
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, UE::Math::TTransform<T>& Transform)
{
	const auto Object = Value.AsObject();
	UE::Math::TVector<T> Translation;
	UE::Math::TRotator<T> Rotation;
	UE::Math::TVector<T> Scale;
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Translation")), Translation);
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Rotation")), Rotation);
	MRUKDeserialize(*Object->GetField<EJson::None>(TEXT("Scale")), Scale);

	Transform.SetComponents(UE::Math::TQuat<T>(Rotation), Translation, Scale);
}

template <typename T>
TSharedPtr<FJsonValue> MRUKSerialize(const TArray<T>& Array)
{
	TArray<TSharedPtr<FJsonValue>> JsonArray;
	JsonArray.Reserve(Array.Num());
	for (const auto& Item : Array)
	{
		JsonArray.Add(MRUKSerialize(Item));
	}
	return MakeShareable(new FJsonValueArray(JsonArray));
}

template <typename T>
void MRUKDeserialize(const FJsonValue& Value, TArray<T>& OutArray)
{
	auto Array = Value.AsArray();
	OutArray.Empty();
	OutArray.Reserve(Array.Num());
	for (const auto& Item : Array)
	{
		T ItemDeserialized;
		MRUKDeserialize(*Item, ItemDeserialized);
		OutArray.Push(ItemDeserialized);
	}
}
