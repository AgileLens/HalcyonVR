// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "ILiveLinkSource.h"
#include "LiveLinkTypes.h"
#include "Roles/LiveLinkAnimationRole.h"
#include "Roles/LiveLinkAnimationTypes.h"
#include "Roles/LiveLinkBasicRole.h"
#include "Tickable.h"

#include "OculusXRMovementTypes.h"

#define LOCTEXT_NAMESPACE "MetaOculusXRMovement"

namespace MetaXRMovement
{

	template <typename MetaXRState, typename RoleTypeStaticData, typename RoleTypeFrameData, typename RoleT>
	class TSubject
	{
	public:
		explicit TSubject();
		using Role = RoleT;

		const FLiveLinkSubjectName Name;

		FLiveLinkStaticDataStruct StaticData() const;
		FLiveLinkFrameDataStruct FrameData();
		bool IsLastFrameValid() const { return bLastFrameIsValid; };
		bool Start();
		bool Stop();
		static bool IsSupported();

	private:
		bool bLastFrameIsValid;
		bool bStarted;
		MetaXRState LastState;

		void InitializeRoleStaticData(RoleTypeStaticData& StaticData) const;
		void UpdateFrame(RoleTypeFrameData& FrameData);
	};

	using FEyeSubject = TSubject<FOculusXREyeGazesState, FLiveLinkSkeletonStaticData, FLiveLinkAnimationFrameData, ULiveLinkAnimationRole>;
	using FFaceSubject = TSubject<FOculusXRFaceState, FLiveLinkBaseStaticData, FLiveLinkBaseFrameData, ULiveLinkBasicRole>;
	using FBodySubject = TSubject<FOculusXRBodyState, FLiveLinkSkeletonStaticData, FLiveLinkAnimationFrameData, ULiveLinkAnimationRole>;

	class LiveLinkSource : public ILiveLinkSource, public FTickableGameObject
	{
	public:
		LiveLinkSource();
		virtual ~LiveLinkSource() override = default;

		// ILiveLinkSource implementation

		virtual void ReceiveClient(ILiveLinkClient* InClient, FGuid InSourceGuid) override;
		virtual bool IsSourceStillValid() const override;
		virtual bool RequestSourceShutdown() override;
		virtual FText GetSourceType() const override;
		virtual FText GetSourceMachineName() const override;
		virtual FText GetSourceStatus() const override;

		// FTickableGameObject implementation

		virtual void Tick(float DeltaTime) override;
		virtual bool IsTickable() const override { return bAnySupported && Client; };
		virtual TStatId GetStatId() const override
		{
			RETURN_QUICK_DECLARE_CYCLE_STAT(FOculusXRMovementLiveLink, STATGROUP_Tickables);
		}
		virtual bool IsTickableInEditor() const override { return true; }
		virtual bool IsTickableWhenPaused() const override { return true; }

	private:
		enum class ESubjectInitializationResult
		{
			Started = 0,
			StartFailed = 1,
			NotSupported = 2
		};

		static constexpr const char* ResultToText[]{ "started", "start_failed", "not_supported" };

		template <typename SubjectT>
		ESubjectInitializationResult InitializeMovementSubject(TOptional<FLiveLinkSubjectKey>& Key, SubjectT& Subject);
		void InitializeMovementSubjects();
		template <typename SubjectT>
		void UpdateMovementSubject(const TOptional<FLiveLinkSubjectKey>& Key, SubjectT& Subject);
		void UpdateMovementSubjects();

		// LiveLink Data
		// The local client to push data updates to
		ILiveLinkClient* Client{ nullptr };
		// Our identifier in LiveLink
		FGuid SourceGuid;

		// Whenever any of the trackers is supported.
		const bool bAnySupported;

		// This subject's keys. Initialized only if a tracker is supported.
		TOptional<FLiveLinkSubjectKey> KeyEye;
		TOptional<FLiveLinkSubjectKey> KeyFace;
		TOptional<FLiveLinkSubjectKey> KeyBody;

		// Subjects
		FEyeSubject Eye;
		FFaceSubject Face;
		FBodySubject Body;
	};
} // namespace MetaXRMovement
#undef LOCTEXT_NAMESPACE
