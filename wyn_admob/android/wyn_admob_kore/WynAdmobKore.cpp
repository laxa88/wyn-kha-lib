#include <WynAdmobKore.h>
#include <WynCommonKore.h>
#include <Kore/Android.h>
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynAdmobKore", msg, ## args)

namespace WynAdmobKore
{
	static JNIEnv* env;
	static jclass cls;

	Dynamic adViewDidReceiveAd;
	Dynamic didFailToReceiveAdWithError;
	Dynamic adViewWillPresentScreen;
	Dynamic adViewWillDismissScreen;
	Dynamic adViewDidDismissScreen;
	Dynamic adViewWillLeaveApplication;

	Dynamic interstitialDidReceiveAd;
	Dynamic didFailToReceiveAdWithError2;
	Dynamic interstitialWillPresentScreen;
	Dynamic interstitialWillDismissScreen;
	Dynamic interstitialDidDismissScreen;
	Dynamic interstitialWillLeaveApplication;

	void attachThread ()
	{
		env = WynCommonKore::attachThread();
		cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");
	}

	void detachThread ()
	{
		WynCommonKore::detachThread();
	}

	void init ()
	{
		LOG("init");

		WynCommonKore::init();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}

	void setBannerCallbacks (Dynamic a, Dynamic b, Dynamic c, Dynamic d, Dynamic e, Dynamic f)
	{
		LOG("setBannerCallbacks");

		adViewDidReceiveAd = a;
		didFailToReceiveAdWithError = b;
		adViewWillPresentScreen = c;
		adViewWillDismissScreen = d;
		adViewDidDismissScreen = e;
		adViewWillLeaveApplication = f;
	}

	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity, bool visible)
	{
		LOG("createBanner");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createBanner", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		jstring jadType = env->NewStringUTF(adType);
		jstring jadGravity = env->NewStringUTF(adGravity);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId, jadType, jadGravity, visible);

		detachThread();
	}

	void toggleBanner (const char* adName, bool visible)
	{
		LOG("toggleBanner");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "toggleBanner", "(Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		env->CallStaticVoidMethod(cls, methodId, jadName, visible);

		detachThread();
	}

	void setInterstitialCallbacks (Dynamic a, Dynamic b, Dynamic c, Dynamic d, Dynamic e, Dynamic f)
	{
		LOG("setInterstitialCallbacks");

		interstitialDidReceiveAd = a;
		didFailToReceiveAdWithError2 = b;
		interstitialWillPresentScreen = c;
		interstitialWillDismissScreen = d;
		interstitialDidDismissScreen = e;
		interstitialWillLeaveApplication = f;
	}

	void createInterstitial (const char* adUnitId)
	{
		LOG("createInterstitial");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createInterstitial", "(Ljava/lang/String;)V");
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		env->CallStaticVoidMethod(cls, methodId, jadUnitId);

		detachThread();
	}

	void showInterstitial ()
	{
		LOG("showInterstitial");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "showInterstitial", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}

	bool isInterstitialReady ()
	{
		LOG("canShow");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "isInterstitialReady", "()Z");
		jboolean result = env->CallStaticBooleanMethod(cls, methodId);

		detachThread();

		return result;
	}



	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewDidReceiveAd( JNIEnv* pEnv, jobject jCaller ) {
		// References
		// https://github.com/openfl/openfl-native/issues/216
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidCommon.h#L19
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidFrame.cpp#L754

		// This wizardry fixes unregistered thread error. Try uncommenting this,
		// the game will break when the callback is invoked below (check the
		// error for the message).
		WynCommonKore::AutoHaxe haxe("adViewDidReceiveAd");
		LOG("adViewDidReceiveAd");

		if (adViewDidReceiveAd != null()) {
			adViewDidReceiveAd().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeDidFailToReceiveAdWithError( JNIEnv* pEnv, jobject jCaller, jstring jError) {
		WynCommonKore::AutoHaxe haxe("didFailToReceiveAdWithError");
		LOG("didFailToReceiveAdWithError");

		// http://stackoverflow.com/questions/5859673/should-you-call-releasestringutfchars-if-getstringutfchars-returned-a-copy
		const char *nativeString = pEnv->GetStringUTFChars(jError, JNI_FALSE);
		String cstring = String(nativeString);
		pEnv->ReleaseStringUTFChars(jError, nativeString); // prevent memory leak

		if (didFailToReceiveAdWithError != null()) {
			didFailToReceiveAdWithError(cstring).Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillPresentScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("adViewWillPresentScreen");
		LOG("adViewWillPresentScreen");

		if (adViewWillPresentScreen != null()) {
			adViewWillPresentScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillDismissScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("adViewWillDismissScreen");
		LOG("adViewWillDismissScreen");

		if (adViewWillDismissScreen != null()) {
			adViewWillDismissScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewDidDismissScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("adViewDidDismissScreen");
		LOG("adViewDidDismissScreen");

		if (adViewDidDismissScreen != null()) {
			adViewDidDismissScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobBannerListener_NativeAdViewWillLeaveApplication( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("adViewWillLeaveApplication");
		LOG("adViewWillLeaveApplication");

		if (adViewWillLeaveApplication != null()) {
			adViewWillLeaveApplication().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialDidReceiveAd( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("interstitialDidReceiveAd");
		LOG("interstitialDidReceiveAd");

		if (interstitialDidReceiveAd != null()) {
			interstitialDidReceiveAd().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeDidFailToReceiveAdWithError2( JNIEnv* pEnv, jobject jCaller, jstring jError ) {
		WynCommonKore::AutoHaxe haxe("didFailToReceiveAdWithError2");
		LOG("didFailToReceiveAdWithError2");

		if (didFailToReceiveAdWithError2 != null()) {
			didFailToReceiveAdWithError2((const char*)jError).Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillPresentScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("interstitialWillPresentScreen");
		LOG("interstitialWillPresentScreen");

		if (interstitialWillPresentScreen != null()) {
			interstitialWillPresentScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillDismissScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("interstitialWillDismissScreen");
		LOG("interstitialWillDismissScreen");

		if (interstitialWillDismissScreen != null()) {
			interstitialWillDismissScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialDidDismissScreen( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("interstitialDidDismissScreen");
		LOG("interstitialDidDismissScreen");

		if (interstitialDidDismissScreen != null()) {
			interstitialDidDismissScreen().Cast< Void >();
		}
	}
	extern "C" JNIEXPORT void JNICALL Java_wyn_1admob_1kore_WynAdmobInterstitialListener_NativeInterstitialWillLeaveApplication( JNIEnv* pEnv, jobject jCaller ) {
		WynCommonKore::AutoHaxe haxe("interstitialWillLeaveApplication");
		LOG("interstitialWillLeaveApplication");

		if (interstitialWillLeaveApplication != null()) {
			interstitialWillLeaveApplication().Cast< Void >();
		}
	}
}
