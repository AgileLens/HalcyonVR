// Georgy Treshchev 2024.

#if WITH_RUNTIMEAUDIOIMPORTER_CAPTURE_SUPPORT
#if PLATFORM_ANDROID

#include "Sound/Android/AudioCaptureAndroid.h"

#include "RuntimeAudioImporterDefines.h"

#include "Codecs/RAW_RuntimeCodec.h"
#include <Android/AndroidApplication.h>
#include <Android/AndroidJNI.h>

static JNIEnv* JavaEnv;
static jmethodID AndroidThunkJava_AndroidStartCapture = nullptr;
static jmethodID AndroidThunkJava_AndroidStopCapture = nullptr;
static Audio::FAudioCaptureAndroid* AudioCaptureAndroidForCallback = nullptr;

extern "C"
{
	JNIEXPORT void
#if !UE_VERSION_OLDER_THAN(5,0,0)
Java_com_epicgames_unreal_GameActivity_audioCapturePayload
#else
Java_com_epicgames_ue4_GameActivity_audioCapturePayload
#endif
	(JNIEnv* jenv, jobject thiz, jshortArray shortPCMDataArray, jint readSize)
	{
		UE_LOG(LogRuntimeAudioImporter, Verbose, TEXT("Processing Android audio capture payload with %d samples"), readSize);

		if (readSize > 0)
		{
			TArray<int16> Int16PCMData;
			Int16PCMData.Reserve(readSize * 2);
			{
				jshort* shortPCMDataArrayElements = jenv->GetShortArrayElements(shortPCMDataArray, nullptr);
				for (int32 SampleIndex = 0; SampleIndex < readSize; ++SampleIndex) {
					jshort Int16PCMDataSample = shortPCMDataArrayElements[SampleIndex];
					Int16PCMData.Add(static_cast<int16>(Int16PCMDataSample));		
				}
				jenv->ReleaseShortArrayElements(shortPCMDataArray, shortPCMDataArrayElements, 0);
			}

			float* FloatPCMDataPtr = nullptr;
			FRAW_RuntimeCodec::TranscodeRAWData<int16, float>(Int16PCMData.GetData(), Int16PCMData.Num(), FloatPCMDataPtr);
			if (AudioCaptureAndroidForCallback)
			{
				AudioCaptureAndroidForCallback->OnAudioCapture(FloatPCMDataPtr, readSize, 0.0, false);
			}
			FMemory::Free(FloatPCMDataPtr);
		}
	} 
}

Audio::FAudioCaptureAndroid::FAudioCaptureAndroid()
{
	AudioCaptureAndroidForCallback = this;
}

Audio::FAudioCaptureAndroid::~FAudioCaptureAndroid()
{
	AudioCaptureAndroidForCallback = nullptr;
}

bool Audio::FAudioCaptureAndroid::GetCaptureDeviceInfo(Audio::FCaptureDeviceInfo& OutInfo, int32 DeviceIndex)
{
	OutInfo.DeviceName = TEXT("Default Android Audio Device");
	OutInfo.InputChannels = NumChannels;
	OutInfo.PreferredSampleRate = SampleRate;

	return true;
}

bool RequestCapturePermissions()
{
	TArray<FString> Permissions = {"android.permission.RECORD_AUDIO"};
	return RuntimeAudioImporter::CheckAndRequestPermissions(Permissions);
}

bool Audio::FAudioCaptureAndroid::
#if UE_VERSION_NEWER_THAN(5, 2, 9)
	OpenAudioCaptureStream
#else
	OpenCaptureStream
#endif
	(const Audio::FAudioCaptureDeviceParams& InParams,
#if UE_VERSION_NEWER_THAN(5, 2, 9)
	FOnAudioCaptureFunction InOnCapture
#else
	FOnCaptureFunction InOnCapture
#endif
	, uint32 NumFramesDesired)
{
	if (bIsStreamOpen)
	{
		UE_LOG(LogRuntimeAudioImporter, Error, TEXT("Unable to open capture stream because it is already open"));
		return true;
	}

	bPermissionsGranted = RequestCapturePermissions();

	if (!bPermissionsGranted)
	{
		UE_LOG(LogRuntimeAudioImporter, Error, TEXT("Unable to open capture stream because permissions are not granted"));
		return false;
	}

	OnCapture = MoveTemp(InOnCapture);
	bIsStreamOpen = true;
	return true;
}

bool Audio::FAudioCaptureAndroid::CloseStream()
{
	StopStream();
	bIsStreamOpen = false;
	return true;
}

bool Audio::FAudioCaptureAndroid::StartStream()
{
	if (bPermissionsGranted)
	{
		bHasCaptureStarted = AndroidCaptureStart(SampleRate);
		return bHasCaptureStarted;
	}
	UE_LOG(LogRuntimeAudioImporter, Error, TEXT("Unable to start audio capture because permissions are not granted"));
	return false;
}

bool Audio::FAudioCaptureAndroid::StopStream()
{
	AndroidCaptureStop();
	bHasCaptureStarted = false;
	return true;
}

bool Audio::FAudioCaptureAndroid::AbortStream()
{
	return CloseStream();
}

bool Audio::FAudioCaptureAndroid::GetStreamTime(double& OutStreamTime)
{
	OutStreamTime = 0.0f;
	return true;
}

bool Audio::FAudioCaptureAndroid::IsStreamOpen() const
{
	return bIsStreamOpen;
}

bool Audio::FAudioCaptureAndroid::IsCapturing() const
{
	return bHasCaptureStarted;
}

void Audio::FAudioCaptureAndroid::OnAudioCapture(void* InBuffer, uint32 InBufferFrames, double StreamTime, bool bOverflow)
{
	OnCapture(static_cast<float*>(InBuffer), InBufferFrames, NumChannels, SampleRate, StreamTime, bOverflow);
}

bool Audio::FAudioCaptureAndroid::GetInputDevicesAvailable(TArray<FCaptureDeviceInfo>& OutDevices)
{
	OutDevices.Reset();

	FCaptureDeviceInfo& DeviceInfo = OutDevices.AddDefaulted_GetRef();
	GetCaptureDeviceInfo(DeviceInfo, 0);

	return true;
}

bool Audio::FAudioCaptureAndroid::AndroidCaptureStart(int32 TargetSampleRate)
{
	JavaEnv = FAndroidApplication::GetJavaEnv();
	if (!JavaEnv)
	{
		UE_LOG(LogRuntimeAudioImporter, Error, TEXT("Unable to capture audio because JavaEnv is null"));
		return false;
	}

	if (!AndroidThunkJava_AndroidStartCapture)
	{
		AndroidThunkJava_AndroidStartCapture = FJavaWrapper::FindMethod(JavaEnv, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AndroidStartCapture", "(I)Z", false);
	}

	if (!AndroidThunkJava_AndroidStartCapture)
	{
		UE_LOG(LogRuntimeAudioImporter, Warning, TEXT("Unable to find AndroidThunkJava_AndroidStartCapture"));
		return false;
	}

	jboolean bResult = FJavaWrapper::CallBooleanMethod(JavaEnv, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidStartCapture, TargetSampleRate);
	return bResult;
}

void Audio::FAudioCaptureAndroid::AndroidCaptureStop()
{
	JavaEnv = FAndroidApplication::GetJavaEnv();
	if (!JavaEnv)
	{
		UE_LOG(LogRuntimeAudioImporter, Error, TEXT("Unable to stop audio capture because JavaEnv is null"));
		return;
	}

	if (!AndroidThunkJava_AndroidStopCapture)
	{
		AndroidThunkJava_AndroidStopCapture = FJavaWrapper::FindMethod(JavaEnv, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AndroidStopCapture", "()V", false);
	}

	if (!AndroidThunkJava_AndroidStopCapture || !JavaEnv)
	{
		UE_LOG(LogRuntimeAudioImporter, Warning, TEXT("Unable to find AndroidThunkJava_AndroidStopCapture (%d) or JavaEnv (%d)"), AndroidThunkJava_AndroidStopCapture == NULL, JavaEnv == NULL);
		return;
	}

	FJavaWrapper::CallVoidMethod(JavaEnv, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidStopCapture);
}
#endif
#endif