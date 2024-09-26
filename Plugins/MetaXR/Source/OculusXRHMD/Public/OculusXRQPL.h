// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Misc/DateTime.h"

namespace OculusXRTelemetry
{
	enum class OCULUSXRHMD_API EAction : short
	{
		Start = 1,
		Success = 2,
		Fail = 3,
		Cancel = 4,
		DrawComplete = 5,
		OnResume = 6
	};

	class OCULUSXRHMD_API FTelemetryInstanceKey
	{
	public:
		constexpr FTelemetryInstanceKey(const int InstanceKey)
			: Value(InstanceKey){};

		constexpr int GetValue() const { return Value; }

	private:
		int Value;
	};

	constexpr FTelemetryInstanceKey DefaultTelemetryInstance = FTelemetryInstanceKey(0);

	class OCULUSXRHMD_API FTelemetryTimestamp
	{
		static constexpr int OneHundredNsToMs = 1000;

	public:
		FTelemetryTimestamp(FDateTime Timestamp)
			: TotalMs(Timestamp.GetTicks() / OneHundredNsToMs){};
		constexpr FTelemetryTimestamp(int64 TimestampMs)
			: TotalMs(TimestampMs){};

		constexpr int64 GetTimestamp() const { return TotalMs; }

	private:
		int64 TotalMs;
	};

	constexpr FTelemetryTimestamp AutoSetTimestamp = FTelemetryTimestamp(-1);

	struct OCULUSXRHMD_API FEmptyBackend
	{
		static bool MarkerStart(int, FTelemetryInstanceKey, FTelemetryTimestamp) { return false; };
		static bool MarkerEnd(int, EAction, FTelemetryInstanceKey, FTelemetryTimestamp) { return false; };
		static bool MarkerPoint(int, const char*, FTelemetryInstanceKey, FTelemetryTimestamp) { return false; };
		static bool MarkerPointCached(int, int, FTelemetryInstanceKey, FTelemetryTimestamp) { return false; };
		static bool MarkerAnnotation(int, const char*, const char*, FTelemetryInstanceKey) { return false; };
		static bool CreateMarkerHandle(const char*, int*) { return false; };
		static bool DestroyMarkerHandle(int) { return false; };
		static bool OnEditorShutdown() { return false; };
		static constexpr bool IsNullBackend() { return true; };
	};
	struct OCULUSXRHMD_API FQPLBackend
	{
		static bool MarkerStart(int MarkerId, FTelemetryInstanceKey InstanceKey, FTelemetryTimestamp Timestamp);
		static bool MarkerEnd(int MarkerId, EAction Action, FTelemetryInstanceKey InstanceKey, FTelemetryTimestamp Timestamp);
		static bool MarkerPoint(int MarkerId, const char* Name, FTelemetryInstanceKey InstanceKey, FTelemetryTimestamp Timestamp);
		static bool MarkerPointCached(int MarkerId, int NameHandle, FTelemetryInstanceKey InstanceKey, FTelemetryTimestamp Timestamp);
		static bool MarkerAnnotation(int MarkerId, const char* AnnotationKey, const char* AnnotationValue, FTelemetryInstanceKey InstanceKey);
		static bool CreateMarkerHandle(const char* Name, int* NameHandle);
		static bool DestroyMarkerHandle(int NameHandle);
		static bool OnEditorShutdown();
		static constexpr bool IsNullBackend() { return false; };
	};
} // namespace OculusXRTelemetry
