// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRScene_init() {}
	OCULUSXRSCENE_API UFunction* Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_OculusXRScene;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_OculusXRScene()
	{
		if (!Z_Registration_Info_UPackage__Script_OculusXRScene.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/OculusXRScene",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xACE9CFA3,
				0x9D341CFE,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_OculusXRScene.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_OculusXRScene.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_OculusXRScene(Z_Construct_UPackage__Script_OculusXRScene, TEXT("/Script/OculusXRScene"), Z_Registration_Info_UPackage__Script_OculusXRScene, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xACE9CFA3, 0x9D341CFE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
