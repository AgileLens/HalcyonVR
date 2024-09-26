// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc\EngineVersionComparison.h"
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
#include "IStereoLayersFlagsSupplier.h"
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

class FOculusXRStereoLayersFlagsSupplier
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	: public IStereoLayersFlagsSupplier
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)
{
	// Required for creating a TSharedPtr because this class has a private constructor.
	template <typename, ESPMode>
	friend class SharedPointerInternals::TIntrusiveReferenceController;

public:
	/** Returns instance of this class. If it doesn't exist yet, it creates one and collects all the flags. */
	OCULUSXRHMD_API static TSharedPtr<FOculusXRStereoLayersFlagsSupplier> Get();

	virtual ~FOculusXRStereoLayersFlagsSupplier()
	{
		if (Instance.IsValid())
		{
			Instance.Reset();
		}
	}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual void EnumerateFlags(TSet<FName>& OutFlags) override
	{
		OutFlags.Append(SupportedFilters);
	}
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

	OCULUSXRHMD_API int GetOvrpFlag(uint32 DescFlags, bool bMQSR = true);

private:
	FOculusXRStereoLayersFlagsSupplier();

	static TSharedPtr<FOculusXRStereoLayersFlagsSupplier> Instance;

	TMap<uint32, uint32> UnrealFlagValOvrpFlagValMap;
	TArray<FName> SupportedFilters;
};
