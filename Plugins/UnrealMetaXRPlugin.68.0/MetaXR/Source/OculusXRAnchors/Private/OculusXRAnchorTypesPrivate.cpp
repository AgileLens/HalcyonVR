// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRAnchorTypesPrivate.h"

ovrpSpaceComponentType ConvertToOvrpComponentType(const EOculusXRSpaceComponentType ComponentType)
{
	ovrpSpaceComponentType ovrpType = ovrpSpaceComponentType_Max;
	switch (ComponentType)
	{
		case EOculusXRSpaceComponentType::Locatable:
			ovrpType = ovrpSpaceComponentType_Locatable;
			break;
		case EOculusXRSpaceComponentType::Sharable:
			ovrpType = ovrpSpaceComponentType_Sharable;
			break;
		case EOculusXRSpaceComponentType::Storable:
			ovrpType = ovrpSpaceComponentType_Storable;
			break;
		case EOculusXRSpaceComponentType::ScenePlane:
			ovrpType = ovrpSpaceComponentType_Bounded2D;
			break;
		case EOculusXRSpaceComponentType::SceneVolume:
			ovrpType = ovrpSpaceComponentType_Bounded3D;
			break;
		case EOculusXRSpaceComponentType::SemanticClassification:
			ovrpType = ovrpSpaceComponentType_SemanticLabels;
			break;
		case EOculusXRSpaceComponentType::RoomLayout:
			ovrpType = ovrpSpaceComponentType_RoomLayout;
			break;
		case EOculusXRSpaceComponentType::SpaceContainer:
			ovrpType = ovrpSpaceComponentType_SpaceContainer;
			break;
		case EOculusXRSpaceComponentType::TriangleMesh:
			ovrpType = ovrpSpaceComponentType_TriangleMesh;
			break;
		default:;
	}

	return ovrpType;
}

EOculusXRSpaceComponentType ConvertToUEComponentType(const ovrpSpaceComponentType ComponentType)
{
	EOculusXRSpaceComponentType ueComponentType = EOculusXRSpaceComponentType::Undefined;
	switch (ComponentType)
	{
		case ovrpSpaceComponentType_Locatable:
			ueComponentType = EOculusXRSpaceComponentType::Locatable;
			break;
		case ovrpSpaceComponentType_Sharable:
			ueComponentType = EOculusXRSpaceComponentType::Sharable;
			break;
		case ovrpSpaceComponentType_Storable:
			ueComponentType = EOculusXRSpaceComponentType::Storable;
			break;
		case ovrpSpaceComponentType_Bounded2D:
			ueComponentType = EOculusXRSpaceComponentType::ScenePlane;
			break;
		case ovrpSpaceComponentType_Bounded3D:
			ueComponentType = EOculusXRSpaceComponentType::SceneVolume;
			break;
		case ovrpSpaceComponentType_SemanticLabels:
			ueComponentType = EOculusXRSpaceComponentType::SemanticClassification;
			break;
		case ovrpSpaceComponentType_RoomLayout:
			ueComponentType = EOculusXRSpaceComponentType::RoomLayout;
			break;
		case ovrpSpaceComponentType_SpaceContainer:
			ueComponentType = EOculusXRSpaceComponentType::SpaceContainer;
			break;
		case ovrpSpaceComponentType_TriangleMesh:
			ueComponentType = EOculusXRSpaceComponentType::TriangleMesh;
			break;
		default:;
	}

	return ueComponentType;
}
