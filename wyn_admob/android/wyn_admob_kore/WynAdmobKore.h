#pragma once
#include <Kore/Android.h>
#include "hxcpp.h"

namespace WynAdmobKore
{
	void attachThread ();
	void detachThread ();
	void init ();
	void setBannerCallbacks (Dynamic a, Dynamic b, Dynamic c, Dynamic d, Dynamic e, Dynamic f);
	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity);
	void toggleBanner (const char* adName, bool visible);
	void setInterstitialCallbacks (Dynamic a, Dynamic b, Dynamic c, Dynamic d, Dynamic e, Dynamic f);
	void createInterstitial (const char* adUnitId);
	void showInterstitial ();
	bool isInterstitialReady ();

	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewDidReceiveAd( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeDidFailToReceiveAdWithError( JNIEnv* pEnv, jobject jCaller, jstring jError );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillPresentScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillDismissScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewDidDismissScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillLeaveApplication( JNIEnv* pEnv, jobject jCaller );

	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialDidReceiveAd( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeDidFailToReceiveAdWithError2( JNIEnv* pEnv, jobject jCaller, jstring jError );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillPresentScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillDismissScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialDidDismissScreen( JNIEnv* pEnv, jobject jCaller );
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillLeaveApplication( JNIEnv* pEnv, jobject jCaller );
}
