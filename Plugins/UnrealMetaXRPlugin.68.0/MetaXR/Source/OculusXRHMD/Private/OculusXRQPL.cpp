// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRQPL.h"
#include "OculusXRHMDModule.h"
#include "OculusXRPluginWrapper.h"

namespace OculusXRTelemetry
{
	namespace QPL
	{
		bool MarkerStart(const int MarkerId, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplMarkerStart(
				MarkerId,
				InstanceKey.GetValue(),
				Timestamp.GetTimestamp());

			return OVRP_SUCCESS(Result);
		}
		bool MarkerEnd(const int MarkerId, const EAction Action, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplMarkerEnd(
				MarkerId,
				static_cast<short>(Action),
				InstanceKey.GetValue(),
				Timestamp.GetTimestamp());

			return OVRP_SUCCESS(Result);
		}

		bool MarkerPoint(const int MarkerId, const char* Name, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplMarkerPoint(
				MarkerId,
				Name,
				InstanceKey.GetValue(),
				Timestamp.GetTimestamp());

			return OVRP_SUCCESS(Result);
		}

		bool MarkerPointCached(const int MarkerId, const int NameHandle, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplMarkerPointCached(
				MarkerId,
				NameHandle,
				InstanceKey.GetValue(),
				Timestamp.GetTimestamp());

			return OVRP_SUCCESS(Result);
		}

		bool MarkerAnnotation(const int MarkerId, const char* AnnotationKey, const char* AnnotationValue, const FTelemetryInstanceKey InstanceKey)
		{
			if (nullptr == AnnotationValue)
			{
				return false;
			}
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplMarkerAnnotation(
				MarkerId,
				AnnotationKey,
				AnnotationValue,
				InstanceKey.GetValue());

			return OVRP_SUCCESS(Result);
		}

		bool CreateMarkerHandle(const char* Name, int* NameHandle)
		{
			if (nullptr == NameHandle)
			{
				return false;
			}

			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplCreateMarkerHandle(
				Name,
				NameHandle);

			return OVRP_SUCCESS(Result);
		}

		bool DestroyMarkerHandle(const int NameHandle)
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().QplDestroyMarkerHandle(
				NameHandle);

			return OVRP_SUCCESS(Result);
		}

		bool OnEditorShutdown()
		{
			const ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().OnEditorShutdown();

			return OVRP_SUCCESS(Result);
		}

	} // namespace QPL
	bool FQPLBackend::MarkerStart(const int MarkerId, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
	{
		return QPL::MarkerStart(MarkerId, InstanceKey, Timestamp);
	}
	bool FQPLBackend::MarkerEnd(const int MarkerId, const EAction Action, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
	{
		return QPL::MarkerEnd(MarkerId, Action, InstanceKey, Timestamp);
	};
	bool FQPLBackend::MarkerPoint(const int MarkerId, const char* Name, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
	{
		return QPL::MarkerPoint(MarkerId, Name, InstanceKey, Timestamp);
	};
	bool FQPLBackend::MarkerPointCached(const int MarkerId, const int NameHandle, const FTelemetryInstanceKey InstanceKey, const FTelemetryTimestamp Timestamp)
	{
		return QPL::MarkerPointCached(MarkerId, NameHandle, InstanceKey, Timestamp);
	};
	bool FQPLBackend::MarkerAnnotation(const int MarkerId, const char* AnnotationKey, const char* AnnotationValue, const FTelemetryInstanceKey InstanceKey)
	{
		return QPL::MarkerAnnotation(MarkerId, AnnotationKey, AnnotationValue, InstanceKey);
	};
	bool FQPLBackend::CreateMarkerHandle(const char* Name, int* NameHandle)
	{
		return QPL::CreateMarkerHandle(Name, NameHandle);
	};
	bool FQPLBackend::DestroyMarkerHandle(const int NameHandle)
	{
		return QPL::DestroyMarkerHandle(NameHandle);
	};
	bool FQPLBackend::OnEditorShutdown()
	{
		return QPL::OnEditorShutdown();
	};
} // namespace OculusXRTelemetry
