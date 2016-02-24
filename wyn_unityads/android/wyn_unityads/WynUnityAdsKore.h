#pragma once
#include <Kore/Android.h>
#include <hxcpp.h>
#include <Dynamic.h>
#include <hx/CFFI.h>

namespace WynUnityAdsKore
{
	void attachThread ();
	void detachThread (void *env);
	void init (const char* id);
	void changeActivity ();
	void setDebugMode (bool val);
	void setTestMode (bool val);
	void setZone (const char* zone);
	bool canShow ();
	void show ();
	void setCallbacks (Dynamic onHide, Dynamic onShow, Dynamic onVideoStarted, Dynamic onVideoCompleted, Dynamic onFetchCompleted, Dynamic onFetchFailed);

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnHide( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnShow( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnVideoStarted( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnVideoCompleted( JNIEnv* pEnv, jobject jCaller, jstring itemKey, jboolean skipped );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnFetchCompleted( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnFetchFailed( JNIEnv* pEnv, jobject jCaller );

	// References
	// https://github.com/openfl/openfl-native/issues/216
	// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidCommon.h#L19
	// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidFrame.cpp#L754
	struct AutoHaxe
	{
		int base;
		const char *message;
		AutoHaxe(const char *inMessage)
		{
			base = 0;
			message = inMessage;
			gc_set_top_of_stack(&base,true);
			//__android_log_print(ANDROID_LOG_VERBOSE, "NME", "Enter %s %p", message, pthread_self());
		}
		~AutoHaxe()
		{
			//__android_log_print(ANDROID_LOG_VERBOSE, "NME", "Leave %s %p", message, pthread_self());
			gc_set_top_of_stack(0,true);
		}
	};
}
