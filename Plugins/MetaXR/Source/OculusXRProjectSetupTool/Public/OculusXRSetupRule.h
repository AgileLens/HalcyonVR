// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"

/**
 * Rule categories
 */
enum class ESetupRuleCategory : uint8
{
	Compatibility = 0,
	Rendering = 1,
	Quality = 2,
	Physics = 3,
	Plugins = 4,
	Features = 5,
	Miscellaneous = 6
};

/**
 * Rule severities
 */
enum class ESetupRuleSeverity : uint8
{
	Warning = 0,
	Performance = 1,
	Critical = 2
};

/**
 * Rule platforms
 */

UENUM()
enum class ESetupRulePlatform : uint32
{
	// None
	None = 0,
	// Link
	MetaLink = 0x1 UMETA(DisplayName = "Link"),

	// Quest
	MetaQuest_2 = 0x2 UMETA(DisplayName = "Quest 2"),
	MetaQuest_3 = 0x4 UMETA(DisplayName = "Quest 3"),
	MetaQuest_Pro = 0x8 UMETA(DisplayName = "Quest Pro")
};

ENUM_CLASS_FLAGS(ESetupRulePlatform)

static constexpr ESetupRulePlatform MetaQuest_All = ESetupRulePlatform::MetaQuest_2 | ESetupRulePlatform::MetaQuest_3 | ESetupRulePlatform::MetaQuest_Pro;

static constexpr ESetupRulePlatform All_Platforms = MetaQuest_All | ESetupRulePlatform::MetaLink;

class OCULUSXRPROJECTSETUPTOOL_API ISetupRule
{
public:
	ISetupRule(
		const FName& InId,
		const FText& InDisplayName,
		const FText& InDescription,
		const ESetupRuleCategory InCategory,
		const ESetupRuleSeverity InSeverity,
		const ESetupRulePlatform InPlatform = All_Platforms);
	virtual ~ISetupRule() = default;
	virtual bool IsApplied() const = 0;

	// Returns true if rule is valid. For example, Rule that checks if passthrough enabled is checked and can be applied only if PassthroughComponent is added.
	virtual bool IsValid();

	bool IsIgnored() const;
	void SetIgnoreRule(bool bIgnore, bool bSendMetrics = true);

	const FName& GetId() const;
	FText GetDisplayName() const;
	FText GetDescription() const;

	ESetupRuleCategory GetCategory() const;
	ESetupRuleSeverity GetSeverity() const;
	ESetupRulePlatform GetPlatform() const;

	void Apply(bool& OutShouldRestartEditor);

protected:
	virtual void ApplyImpl(bool& OutShouldRestartEditor) = 0;

private:
	/** Id for the rule */
	FName Id;

	/** Display name of the rule */
	FText DisplayName;

	/** Description of the rule */
	FText Description;

	/** Category of the rule */
	ESetupRuleCategory Category;

	/** Severity of the rule */
	ESetupRuleSeverity Severity;

	/** Platforms the rule applies to */
	ESetupRulePlatform Platform;

	/** Is rule ignored */
	bool bIsIgnored = false;
};

typedef TSharedPtr<ISetupRule, ESPMode::ThreadSafe> SetupRulePtr;

/**
 * Setup rule symbol database hash.
 */
struct FSetupRuleKeyFunc
{
	enum
	{
		bAllowDuplicateKeys = 0
	};
	typedef TCallTraits<FName>::ParamType KeyInitType;
	typedef TCallTraits<SetupRulePtr>::ParamType ElementInitType;

	/**
	 * @return The key used to index the given element.
	 */
	static FORCEINLINE KeyInitType GetSetKey(ElementInitType Element)
	{
		return Element->GetId();
	}

	/**
	 * @return True if the keys match.
	 */
	static FORCEINLINE bool Matches(KeyInitType A, KeyInitType B)
	{
		return A == B;
	}

	/** Calculates a hash index for a key. */
	static FORCEINLINE uint32 GetKeyHash(KeyInitType Key)
	{
		return GetTypeHash(Key);
	}
};
