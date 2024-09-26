// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMDModule.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRHMD.h"
#include "OculusXRHMDPrivateRHI.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRStereoLayersFlagsSupplier.h"
#include "Containers/StringConv.h"
#include "Misc/EngineVersion.h"
#include "Misc/Paths.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatformMisc.h"
#endif
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"
#include "OculusXRTelemetry.h"
#if PLATFORM_WINDOWS
#include "OculusXRSimulator.h"
#include "OculusXRSyntheticEnvironmentServer.h"
#endif

#if !PLATFORM_ANDROID
#if !UE_BUILD_SHIPPING
namespace
{
	void __cdecl OvrpLogCallback2(ovrpLogLevel InLevel, const char* Message, int Length)
	{
		ELogVerbosity::Type OutLevel;
		switch (InLevel)
		{
			case ovrpLogLevel_Debug:
				OutLevel = ELogVerbosity::Log;
				break;
			case ovrpLogLevel_Info:
				OutLevel = ELogVerbosity::Display;
				break;
			case ovrpLogLevel_Error:
				OutLevel = ELogVerbosity::Error;
				break;
			default:
				OutLevel = ELogVerbosity::NoLogging;
		}
		const FString MessageStr(Length, Message);
		GLog->CategorizedLogf(TEXT("LogOVRPlugin"), OutLevel, TEXT("%s"), *MessageStr);
	}
} // namespace
#endif // !UE_BUILD_SHIPPING
#endif // !PLATFORM_ANDROID

//-------------------------------------------------------------------------------------------------
// FOculusXRHMDModule
//-------------------------------------------------------------------------------------------------

OculusPluginWrapper FOculusXRHMDModule::PluginWrapper{};

#if OCULUS_HMD_SUPPORTED_PLATFORMS
OculusPluginWrapper& FOculusXRHMDModule::GetPluginWrapper()
{
	return PluginWrapper;
}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

FOculusXRHMDModule::FOculusXRHMDModule()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	bPreInit = false;
	bPreInitCalled = false;
	OVRPluginHandle = nullptr;
	GraphicsAdapterLuid = 0;
#endif
}

void FOculusXRHMDModule::StartupModule()
{
	IHeadMountedDisplayModule::StartupModule();
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("OculusXR"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/OculusXR"), PluginShaderDir);

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	auto StereoLayersFlagsSupplier = FOculusXRStereoLayersFlagsSupplier::Get();
	if (StereoLayersFlagsSupplier.IsValid())
	{
		IModularFeatures::Get().RegisterModularFeature(IStereoLayersFlagsSupplier::GetModularFeatureName(), StereoLayersFlagsSupplier.Get());
		TArray<IStereoLayersFlagsSupplier*> FlagsSuppliers = IModularFeatures::Get().GetModularFeatureImplementations<IStereoLayersFlagsSupplier>(IStereoLayersFlagsSupplier::GetModularFeatureName());
		if (FlagsSuppliers.Num() > 1)
		{
			UE_LOG(LogHMD, Log, TEXT("OculusXR Stereo Layer Filters CANNOT be used with layer filters!"));
			IModularFeatures::Get().UnregisterModularFeature(IStereoLayersFlagsSupplier::GetModularFeatureName(), StereoLayersFlagsSupplier.Get());
		}
	}
	PreInit();
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)

	ExtensionPluginManager.StartupOpenXRPlugins();
}

void FOculusXRHMDModule::ShutdownModule()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	auto StereoLayersFlagsSupplier = FOculusXRStereoLayersFlagsSupplier::Get();
	if (StereoLayersFlagsSupplier.IsValid())
	{
		IModularFeatures::Get().UnregisterModularFeature(IStereoLayersFlagsSupplier::GetModularFeatureName(), StereoLayersFlagsSupplier.Get());
	}
#endif // !UE_VERSION_OLDER_THAN(5, 4, 0)
	UOculusXRFunctionLibrary::ShutdownXRFunctionLibrary();

	if (PluginWrapper.IsInitialized())
	{
		OculusXRTelemetry::FTelemetryBackend::OnEditorShutdown();
		PluginWrapper.Shutdown2();
		OculusPluginWrapper::DestroyOculusPluginWrapper(&PluginWrapper);
	}

	if (OVRPluginHandle)
	{
		FPlatformProcess::FreeDllHandle(OVRPluginHandle);
		OVRPluginHandle = nullptr;
	}
#endif
}

OculusXR::FOculusXRExtensionPluginManager& FOculusXRHMDModule::GetExtensionPluginManager()
{
	return ExtensionPluginManager;
}

#if PLATFORM_ANDROID
extern bool AndroidThunkCpp_IsOculusMobileApplication();
#endif

FString FOculusXRHMDModule::GetModuleKeyName() const
{
	return FString(TEXT("OculusXRHMD"));
}

void FOculusXRHMDModule::GetModuleAliases(TArray<FString>& AliasesOut) const
{
	// Pre-OculusXR rename (5.0.3 v44)
	AliasesOut.Add(TEXT("OculusHMD"));
}

bool FOculusXRHMDModule::PreInit()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	if (!bPreInitCalled)
	{
		bPreInit = false;

#if PLATFORM_ANDROID
		bPreInitCalled = true;
		if (!AndroidThunkCpp_IsOculusMobileApplication())
		{
			UE_LOG(LogHMD, Log, TEXT("App is not packaged for Oculus Mobile"));
			return false;
		}
#endif

		// Init module if app can render
		if (FApp::CanEverRender())
		{
			// Load OVRPlugin
			OVRPluginHandle = GetOVRPluginHandle();

			if (!OVRPluginHandle)
			{
				UE_LOG(LogHMD, Log, TEXT("Failed loading OVRPlugin %s"), TEXT(OVRP_VERSION_STR));
				return false;
			}

			if (!OculusPluginWrapper::InitializeOculusPluginWrapper(&PluginWrapper))
			{
				UE_LOG(LogHMD, Log, TEXT("Failed InitializeOculusPluginWrapper"));
				return false;
			}

			// Initialize OVRPlugin
			ovrpRenderAPIType PreinitApiType = ovrpRenderAPI_None;
#if PLATFORM_ANDROID
			void* Activity = (void*)FAndroidApplication::GetGameActivityThis();
			PreinitApiType = ovrpRenderAPI_Vulkan;
#else
			void* Activity = nullptr;
#endif

#if !PLATFORM_ANDROID
#if !UE_BUILD_SHIPPING
			PluginWrapper.SetLogCallback2(OvrpLogCallback2);
#endif // !UE_BUILD_SHIPPING
#endif // !PLATFORM_ANDROID

			// Determine Preinit flag based on platform
			ovrpPreinitializeFlags PreinitFlag = ovrpPreinitializeFlags::ovrpPreinitializeFlag_None;
#if WITH_EDITOR && PLATFORM_WINDOWS
			PreinitFlag = ovrpPreinitializeFlags::ovrpPreinitializeFlag_DisableLogSystemError;
#endif
			if (OVRP_FAILURE(PluginWrapper.PreInitialize5(Activity, PreinitApiType, PreinitFlag)))
			{
				UE_LOG(LogHMD, Log, TEXT("Failed initializing OVRPlugin %s"), TEXT(OVRP_VERSION_STR));
#if WITH_EDITOR && PLATFORM_WINDOWS
				// In the editor, we want to allow the headset to connect after the editor has booted.
				// To do this, we must have PreInit() return true, to prevent the HMD module from being unloaded.
				return GIsEditor;
#else
				return false;
#endif
			}

#if PLATFORM_WINDOWS
			bPreInitCalled = true;
			const LUID* DisplayAdapterId;
			if (OVRP_SUCCESS(PluginWrapper.GetDisplayAdapterId2((const void**)&DisplayAdapterId)) && DisplayAdapterId)
			{
				SetGraphicsAdapterLuid(*(const uint64*)DisplayAdapterId);
			}
			else
			{
				UE_LOG(LogHMD, Log, TEXT("Could not determine HMD display adapter"));
			}

			const WCHAR* AudioInDeviceId;
			if (OVRP_SUCCESS(PluginWrapper.GetAudioInDeviceId2((const void**)&AudioInDeviceId)) && AudioInDeviceId)
			{
				GConfig->SetString(TEXT("Oculus.Settings"), TEXT("AudioInputDevice"), AudioInDeviceId, GEngineIni);
			}
			else
			{
				UE_LOG(LogHMD, Log, TEXT("Could not determine HMD audio input device"));
			}

			const WCHAR* AudioOutDeviceId;
			if (OVRP_SUCCESS(PluginWrapper.GetAudioOutDeviceId2((const void**)&AudioOutDeviceId)) && AudioOutDeviceId)
			{
				GConfig->SetString(TEXT("Oculus.Settings"), TEXT("AudioOutputDevice"), AudioOutDeviceId, GEngineIni);
			}
			else
			{
				UE_LOG(LogHMD, Log, TEXT("Could not determine HMD audio output device"));
			}
#endif

			float ModulePriority;
			if (!GConfig->GetFloat(TEXT("HMDPluginPriority"), *GetModuleKeyName(), ModulePriority, GEngineIni))
			{
				// if user doesn't set priority set it for them to allow this hmd to be used if enabled
				ModulePriority = 45.0f;
				GConfig->SetFloat(TEXT("HMDPluginPriority"), *GetModuleKeyName(), ModulePriority, GEngineIni);
			}

			UE_LOG(LogHMD, Log, TEXT("FOculusXRHMDModule PreInit successfully"));

			bPreInit = true;
		}
	}

	return bPreInit;
#else
	return false;
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
}

bool FOculusXRHMDModule::IsHMDConnected()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	UOculusXRHMDRuntimeSettings* HMDSettings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
	if (FApp::CanEverRender() && HMDSettings->XrApi != EOculusXRXrApi::NativeOpenXR)
	{
		return true;
	}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
	return false;
}

uint64 FOculusXRHMDModule::GetGraphicsAdapterLuid()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11 || OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
	if (!GraphicsAdapterLuid)
	{
		int GraphicsAdapter;

		if (GConfig->GetInt(TEXT("Oculus.Settings"), TEXT("GraphicsAdapter"), GraphicsAdapter, GEngineIni) && GraphicsAdapter >= 0)
		{
			TRefCountPtr<IDXGIFactory> DXGIFactory;
			TRefCountPtr<IDXGIAdapter> DXGIAdapter;
			DXGI_ADAPTER_DESC DXGIAdapterDesc;

			if (SUCCEEDED(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)DXGIFactory.GetInitReference())) && SUCCEEDED(DXGIFactory->EnumAdapters(GraphicsAdapter, DXGIAdapter.GetInitReference())) && SUCCEEDED(DXGIAdapter->GetDesc(&DXGIAdapterDesc)))
			{
				FMemory::Memcpy(&GraphicsAdapterLuid, &DXGIAdapterDesc.AdapterLuid, sizeof(GraphicsAdapterLuid));
			}
		}
	}
#endif

#if OCULUS_HMD_SUPPORTED_PLATFORMS
	return GraphicsAdapterLuid;
#else
	return 0;
#endif
}

FString FOculusXRHMDModule::GetAudioInputDevice()
{
	FString AudioInputDevice;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	GConfig->GetString(TEXT("Oculus.Settings"), TEXT("AudioInputDevice"), AudioInputDevice, GEngineIni);
#endif
	return AudioInputDevice;
}

FString FOculusXRHMDModule::GetAudioOutputDevice()
{
	FString AudioOutputDevice;
#if OCULUS_HMD_SUPPORTED_PLATFORMS
#if PLATFORM_WINDOWS
	if (bPreInit)
	{
		if (FApp::CanEverRender())
		{
			const WCHAR* audioOutDeviceId;
			if (OVRP_SUCCESS(PluginWrapper.GetAudioOutDeviceId2((const void**)&audioOutDeviceId)) && audioOutDeviceId)
			{
				AudioOutputDevice = audioOutDeviceId;
			}
		}
	}
#else
	GConfig->GetString(TEXT("Oculus.Settings"), TEXT("AudioOutputDevice"), AudioOutputDevice, GEngineIni);
#endif
#endif
	return AudioOutputDevice;
}

TSharedPtr<class IXRTrackingSystem, ESPMode::ThreadSafe> FOculusXRHMDModule::CreateTrackingSystem()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	if (bPreInit || (GIsEditor && PLATFORM_WINDOWS))
	{
		// If -HMDSimulator is used as the command option to launch UE, use simulator runtime instead of the physical HMD runtime (like PC-Link).
		if (FParse::Param(FCommandLine::Get(), TEXT("HMDSimulator")) && GetMutableDefault<UOculusXRHMDRuntimeSettings>()->MetaXRJsonPath.FilePath.Len())
		{
			if (!IsSimulatorActivated())
			{
				ToggleOpenXRRuntime();
			}
		}

		OculusXRHMD::FOculusXRHMDPtr OculusXRHMD = FSceneViewExtensions::NewExtension<OculusXRHMD::FOculusXRHMD>();

		if (OculusXRHMD->Startup())
		{
			HeadMountedDisplay = OculusXRHMD;
			return OculusXRHMD;
		}
	}
	HeadMountedDisplay = nullptr;
#endif
	return nullptr;
}

TSharedPtr<IHeadMountedDisplayVulkanExtensions, ESPMode::ThreadSafe> FOculusXRHMDModule::GetVulkanExtensions()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	if (bPreInit)
	{
		if (!VulkanExtensions.IsValid())
		{
			VulkanExtensions = MakeShareable(new OculusXRHMD::FVulkanExtensions);
		}
	}
#if WITH_EDITOR && PLATFORM_WINDOWS
	else if (GIsEditor)
	{
		// OpenXR has no ability to query for possible vulkan extensions without connecting a HMD.
		// This is a problem, because we need to create our VkInstance and VkDevice to render in 2D and there's no HMD.
		// For now, as a workaround, we hardcode the extensions that Oculus's OpenXR implementation needs.
		// Eventually, one of three things has to happen for a proper fix:
		//
		// 1. OculusXRHMD (or, better, OVRPlugin) maintains a separate VkInstance that has the right extensions,
		//      and uses the vk_external extensions to transfer data between them when needed.
		// 2. OpenXR changes to allow querying instance and device extensions without an active HMD.
		//      It may still require a physical device handle to list device extensions.
		// 3. Oculus's Link implementation for OpenXR changes to allow an XrSystemId to be created before a headset
		//      is connected (possibly as an opt-in OpenXR extension for backwards compatibility).
		//
		// (2) or (3) are preferable, but if OpenXR is held constant we will have to do (1).
		if (!VulkanExtensions.IsValid())
		{
			VulkanExtensions = MakeShareable(new OculusXRHMD::FEditorVulkanExtensions);
		}
	}
#endif
	return VulkanExtensions;
#endif
	return nullptr;
}

FString FOculusXRHMDModule::GetDeviceSystemName()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	ovrpSystemHeadset SystemHeadset;
	if (PluginWrapper.IsInitialized() && OVRP_SUCCESS(PluginWrapper.GetSystemHeadsetType2(&SystemHeadset)))
	{
		switch (SystemHeadset)
		{
			case ovrpSystemHeadset_Oculus_Quest:
				return FString("Oculus Quest");

			case ovrpSystemHeadset_Oculus_Quest_2:
			default:
				return FString("Oculus Quest2");

#ifdef WITH_OCULUS_BRANCH
			case ovrpSystemHeadset_Meta_Quest_Pro:
				return FString("Meta Quest Pro");

			case ovrpSystemHeadset_Meta_Quest_3:
				return FString("Meta Quest 3");
#endif // WITH_OCULUS_BRANCH
		}
	}
	return FString();
#else
	return FString();
#endif
}

bool FOculusXRHMDModule::IsStandaloneStereoOnlyDevice()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceMake() == FString("Oculus");
#else
	return false;
#endif
}

bool FOculusXRHMDModule::IsSimulatorActivated()
{
#if PLATFORM_WINDOWS
	return FMetaXRSimulator::IsSimulatorActivated();
#else
	return false;
#endif
}

void FOculusXRHMDModule::ToggleOpenXRRuntime()
{
#if PLATFORM_WINDOWS
	FMetaXRSimulator::ToggleOpenXRRuntime();
#endif
}

void FOculusXRHMDModule::LaunchEnvironment(FString EnvironmentName)
{
#if PLATFORM_WINDOWS
	FMetaXRSES::LaunchEnvironment(EnvironmentName);
#endif
}

void FOculusXRHMDModule::LaunchMoreRoomsEnvironment(FString EnvironmentName)
{
#if PLATFORM_WINDOWS
	FMetaXRSES::LaunchMoreRoomsEnvironment(EnvironmentName);
#endif
}

void FOculusXRHMDModule::StopServer()
{
#if PLATFORM_WINDOWS
	FMetaXRSES::StopServer();
#endif
}

#if OCULUS_HMD_SUPPORTED_PLATFORMS
void* FOculusXRHMDModule::GetOVRPluginHandle()
{
	void* OVRPluginHandle = nullptr;

#if PLATFORM_WINDOWS
	FString XrApi;
	if (!FModuleManager::Get().IsModuleLoaded("OpenXRHMD") || !GConfig->GetString(TEXT("/Script/OculusXRHMD.OculusXRHMDRuntimeSettings"), TEXT("XrApi"), XrApi, GEngineIni) || XrApi.Equals(FString("OVRPluginOpenXR")))
	{
		FString BinariesPath = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("OculusXR"))->GetBaseDir(), TEXT("/Source/ThirdParty/OVRPlugin/OVRPlugin/Lib/Win64"));
		FPlatformProcess::PushDllDirectory(*BinariesPath);
		OVRPluginHandle = FPlatformProcess::GetDllHandle(*(BinariesPath / "OpenXR/OVRPlugin.dll"));
		FPlatformProcess::PopDllDirectory(*BinariesPath);
	}
#elif PLATFORM_ANDROID
	OVRPluginHandle = FPlatformProcess::GetDllHandle(TEXT("libOVRPlugin.so"));
#endif // PLATFORM_ANDROID

	return OVRPluginHandle;
}

bool FOculusXRHMDModule::PoseToOrientationAndPosition(const FQuat& InOrientation, const FVector& InPosition, FQuat& OutOrientation, FVector& OutPosition) const
{
	OculusXRHMD::CheckInGameThread();

	OculusXRHMD::FOculusXRHMD* OculusXRHMD = static_cast<OculusXRHMD::FOculusXRHMD*>(HeadMountedDisplay.Pin().Get());

	if (OculusXRHMD)
	{
		ovrpPosef InPose;
		InPose.Orientation = OculusXRHMD::ToOvrpQuatf(InOrientation);
		InPose.Position = OculusXRHMD::ToOvrpVector3f(InPosition);
		OculusXRHMD::FPose OutPose;

		if (OculusXRHMD->ConvertPose(InPose, OutPose))
		{
			OutOrientation = OutPose.Orientation;
			OutPosition = OutPose.Position;
			return true;
		}
	}

	return false;
}

void FOculusXRHMDModule::SetGraphicsAdapterLuid(uint64 InLuid)
{
	GraphicsAdapterLuid = InLuid;

#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11 || OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
	TRefCountPtr<IDXGIFactory> DXGIFactory;

	if (SUCCEEDED(CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)DXGIFactory.GetInitReference())))
	{
		for (int32 adapterIndex = 0;; adapterIndex++)
		{
			TRefCountPtr<IDXGIAdapter> DXGIAdapter;
			DXGI_ADAPTER_DESC DXGIAdapterDesc;

			if (FAILED(DXGIFactory->EnumAdapters(adapterIndex, DXGIAdapter.GetInitReference())) || FAILED(DXGIAdapter->GetDesc(&DXGIAdapterDesc)))
			{
				break;
			}

			if (!FMemory::Memcmp(&GraphicsAdapterLuid, &DXGIAdapterDesc.AdapterLuid, sizeof(GraphicsAdapterLuid)))
			{
				// Remember this adapterIndex so we use the right adapter, even when we startup without HMD connected
				GConfig->SetInt(TEXT("Oculus.Settings"), TEXT("GraphicsAdapter"), adapterIndex, GEngineIni);
				break;
			}
		}
	}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11 || OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
}
#endif // OCULUS_HMD_SUPPORTED_PLATFORMS

IMPLEMENT_MODULE(FOculusXRHMDModule, OculusXRHMD)
