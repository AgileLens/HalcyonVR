// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRHMD_init() {}
	OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature();
	OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature();
	OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_OculusXRHMD;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_OculusXRHMD()
	{
		if (!Z_Registration_Info_UPackage__Script_OculusXRHMD.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/OculusXRHMD",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x7F509005,
				0x94C09F4D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_OculusXRHMD.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_OculusXRHMD.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_OculusXRHMD(Z_Construct_UPackage__Script_OculusXRHMD, TEXT("/Script/OculusXRHMD"), Z_Registration_Info_UPackage__Script_OculusXRHMD, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7F509005, 0x94C09F4D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
