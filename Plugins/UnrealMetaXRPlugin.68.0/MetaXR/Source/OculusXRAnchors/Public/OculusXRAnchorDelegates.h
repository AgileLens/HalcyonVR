// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreTypes.h"
#include "OculusXRAnchorTypes.h"
#include "Delegates/Delegate.h"

class FOculusXRAnchorEventDelegates
{
public:
	/* ovrpEventType_SpatialAnchorCreateComplete
	 *
	 *        SpatialAnchorCreateComplete
	 * Prefix:
	 * FOculusXRSpatialAnchorCreateComplete
	 * Suffix:
	 * FOculusXRSpatialAnchorCreateCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_FourParams(FOculusXRSpatialAnchorCreateCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/, FOculusXRUInt64 /*space*/, FOculusXRUUID /*uuid*/);
	static OCULUSXRANCHORS_API FOculusXRSpatialAnchorCreateCompleteDelegate OculusSpatialAnchorCreateComplete;

	/* ovrpEventType_SpaceSetComponentStatusComplete
	 *
	 *        SpaceSetComponentStatusComplete
	 * Prefix:
	 * FOculusXRSpaceSetComponentStatusComplete
	 * Suffix:
	 * FOculusXRSpaceSetComponentStatusCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_SixParams(FOculusXRSpaceSetComponentStatusCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/, FOculusXRUInt64 /*space*/, FOculusXRUUID /*uuid*/, EOculusXRSpaceComponentType /*componenttype */, bool /*enabled*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceSetComponentStatusCompleteDelegate OculusSpaceSetComponentStatusComplete;

	/* ovrpEventType_SpaceQueryResults
	 *
	 *        SpaceQueryResults
	 * Prefix:
	 * FOculusXRSpaceQueryResults
	 * Suffix:
	 * FOculusXRSpaceQueryResultsDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_OneParam(FOculusXRSpaceQueryResultsDelegate, FOculusXRUInt64 /*requestId*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceQueryResultsDelegate OculusSpaceQueryResults;

	/* SpaceQueryResult (no ovrp event type)
	 *
	 *        SpaceQueryResult
	 * Prefix:
	 * FOculusXRSpaceQueryResult
	 * Suffix:
	 * FOculusXRSpaceQueryResultDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FOculusXRSpaceQueryResultDelegate, FOculusXRUInt64 /*requestId*/, FOculusXRUInt64 /* space*/, FOculusXRUUID /*uuid*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceQueryResultDelegate OculusSpaceQueryResult;

	/* ovrpEventType_SpaceQueryComplete
	 *
	 *        SpaceQueryComplete
	 * Prefix:
	 * FOculusXRSpaceQueryComplete
	 * Suffix:
	 * FOculusXRSpaceQueryCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRSpaceQueryCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceQueryCompleteDelegate OculusSpaceQueryComplete;

	/* ovrpEventType_SpaceSaveComplete
	 *
	 *        SpaceSaveComplete
	 * Prefix:
	 * FOculusXRSpaceSaveComplete
	 * Suffix:
	 * FOculusXRSpaceSaveCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_FiveParams(FOculusXRSpaceSaveCompleteDelegate, FOculusXRUInt64 /*requestId*/, FOculusXRUInt64 /* space*/, bool /* sucess*/, int /*result*/, FOculusXRUUID /*uuid*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceSaveCompleteDelegate OculusSpaceSaveComplete;

	/* ovrpEventType_SpaceListSaveResult
	 *
	 *        SpaceListSaveComplete
	 * Prefix:
	 * FOculusSpaceListSaveComplete
	 * Suffix:
	 * FOculusSpaceListSaveCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRSpaceListSaveCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceListSaveCompleteDelegate OculusSpaceListSaveComplete;

	/* ovrpEventType_SpaceEraseComplete
	 *
	 *        SpaceEraseComplete
	 * Prefix:
	 * FOculusXRSpaceEraseComplete
	 * Suffix:
	 * FOculusXRSpaceEraseCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_FourParams(FOculusXRSpaceEraseCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /* result*/, FOculusXRUUID /*uuid*/, EOculusXRSpaceStorageLocation /*location*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceEraseCompleteDelegate OculusSpaceEraseComplete;

	/* ovrpEventType_SpaceShareSpaceResult
	 *
	 *        SpaceShareComplete
	 * Prefix:
	 * FOculusSpaceShareSpacesComplete
	 * Suffix:
	 * FOculusSpaceShareSpacesCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRSpaceShareCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRSpaceShareCompleteDelegate OculusSpaceShareComplete;

	/* ovrpEventType_SceneCaptureComplete
	 *
	 *        SceneCaptureComplete
	 * Prefix:
	 * FOculusXRSceneCaptureComplete
	 * Suffix:
	 * FOculusXRSceneCaptureCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRSceneCaptureCompleteDelegate, FOculusXRUInt64 /*requestId*/, bool /*success*/);
	static OCULUSXRANCHORS_API FOculusXRSceneCaptureCompleteDelegate OculusSceneCaptureComplete;

	/* ovrpEventType_SpaceDiscoveryComplete
	 *
	 *        SpaceDiscoveryComplete
	 * Prefix:
	 * FOculusXRSpaceDiscoveryComplete
	 * Suffix:
	 * FOculusXRDiscoverSpacesCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRAnchorsDiscoverCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRAnchorsDiscoverCompleteDelegate OculusAnchorsDiscoverComplete;

	/* ovrpEventType_SpaceDiscoveryResultsAvailable
	 *
	 *        SpaceDiscoveryResults
	 * Prefix:
	 * FOculusXRAnchorsDiscoverResults
	 * Suffix:
	 * FOculusXRAnchorsDiscoverResultsDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRAnchorsDiscoverResultsDelegate, FOculusXRUInt64 /*requestId*/, const TArray<FOculusXRAnchorsDiscoverResult>& /*results*/);
	static OCULUSXRANCHORS_API FOculusXRAnchorsDiscoverResultsDelegate OculusAnchorsDiscoverResults;

	/* ovrpEventType_SpacesSaveResult
	 *
	 *        SpacesSaveComplete
	 * Prefix:
	 * FOculusXRAnchorsSaveComplete
	 * Suffix:
	 * FOculusXRAnchorsSaveCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRAnchorsSaveCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRAnchorsSaveCompleteDelegate OculusAnchorsSaveComplete;

	/* ovrpEventType_SpacesEraseResult
	 *
	 *        SpacesEraseResult
	 * Prefix:
	 * FOculusXRAnchorsEraseComplete
	 * Suffix:
	 * FOculusXRAnchorsEraseCompleteDelegate
	 */
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOculusXRAnchorsEraseCompleteDelegate, FOculusXRUInt64 /*requestId*/, int /*result*/);
	static OCULUSXRANCHORS_API FOculusXRAnchorsEraseCompleteDelegate OculusAnchorsEraseComplete;
};
