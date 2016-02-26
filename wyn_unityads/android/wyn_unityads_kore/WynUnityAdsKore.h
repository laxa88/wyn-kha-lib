#pragma once
#include <Kore/Android.h>
#include <hxcpp.h>
#include <Dynamic.h>
#include <hx/CFFI.h>

namespace WynUnityAdsKore
{
	void attachThread ();
	void detachThread ();
	void init (const char* id);
	void changeActivity ();
	void setDebugMode (bool val);
	void setTestMode (bool val);
	void setZone (const char* zone);
	bool canShow ();
	void show ();
	void setCallbacks (Dynamic onHide, Dynamic onShow, Dynamic onVideoStarted, Dynamic onVideoCompleted, Dynamic onFetchCompleted, Dynamic onFetchFailed);

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnHide( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnShow( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnVideoStarted( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnVideoCompleted( JNIEnv* pEnv, jobject jCaller, jstring itemKey, jboolean skipped );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnFetchCompleted( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnFetchFailed( JNIEnv* pEnv, jobject jCaller );
}
