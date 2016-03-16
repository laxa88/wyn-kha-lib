#include <WynUnityAdsKore.h>
#include <WynCommonKore.h>
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynUnityAdsKore", msg, ## args)

namespace WynUnityAdsKore
{
	static JNIEnv* env;
	static jclass cls;

	void attachThread ()
	{
		env = WynCommonKore::attachThread();
		cls = KoreAndroid::findClass(env, "wyn_unityads_kore.WynUnityAdsKore");
	}

	void detachThread ()
	{
		WynCommonKore::detachThread();
	}

	void init (const char* id)
	{
		LOG("init");

		WynCommonKore::init();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;)V");
		jstring jid = env->NewStringUTF(id);
		env->CallStaticVoidMethod(cls, methodId, jid);

		detachThread();
	}

	// void changeActivity ()
	// {
	// 	LOG("changeActivity");

	// 	attachThread();

	// 	jmethodID methodId = env->GetStaticMethodID(cls, "changeActivity", "()V");
	// 	env->CallStaticVoidMethod(cls, methodId);

	// 	detachThread();
	// }

	void setDebugMode (bool val)
	{
		LOG("setDebugMode");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setDebugMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);

		detachThread();
	}

	void setTestMode (bool val)
	{
		LOG("setTestMode");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setTestMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);

		detachThread();
	}

	void setZone (const char* zone)
	{
		LOG("setZone");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setZone", "(Ljava/lang/String;)V");
		jstring jzone = env->NewStringUTF(zone);
		env->CallStaticVoidMethod(cls, methodId, jzone);

		detachThread();
	}

	bool canShow ()
	{
		LOG("canShow");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "canShow", "()Z");
		jboolean result = env->CallStaticBooleanMethod(cls, methodId);

		detachThread();

		return result;
	}

	void show ()
	{
		LOG("show");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "show", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}

	Dynamic NativeOnHide;
	Dynamic NativeOnShow;
	Dynamic NativeOnVideoStarted;
	Dynamic NativeOnVideoCompleted;
	Dynamic NativeOnFetchCompleted;
	Dynamic NativeOnFetchFailed;

	void setCallbacks (Dynamic onHide, Dynamic onShow, Dynamic onVideoStarted, Dynamic onVideoCompleted, Dynamic onFetchCompleted, Dynamic onFetchFailed)
	{
		NativeOnHide = onHide;
		NativeOnShow = onShow;
		NativeOnVideoStarted = onVideoStarted;
		NativeOnVideoCompleted = onVideoCompleted;
		NativeOnFetchCompleted = onFetchCompleted;
		NativeOnFetchFailed = onFetchFailed;
	}



	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnHide( JNIEnv* pEnv, jobject jCaller )
	{
		// References
		// https://github.com/openfl/openfl-native/issues/216
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidCommon.h#L19
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidFrame.cpp#L754

		// This wizardry fixes unregistered thread error. Try uncommenting this,
		// the game will break when the callback is invoked below (check the
		// error for the message).
		WynCommonKore::AutoHaxe haxe("NativeOnHide");
		LOG("NativeOnHide");

		if (NativeOnHide != null()) {
			NativeOnHide().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnShow( JNIEnv* pEnv, jobject jCaller )
	{
		WynCommonKore::AutoHaxe haxe("NativeOnShow");
		LOG("NativeOnShow");

		if (NativeOnShow != null()) {
			NativeOnShow().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnVideoStarted( JNIEnv* pEnv, jobject jCaller )
	{
		WynCommonKore::AutoHaxe haxe("NativeOnVideoStarted");
		LOG("NativeOnVideoStarted");

		if (NativeOnVideoStarted != null()) {
			NativeOnVideoStarted().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnVideoCompleted( JNIEnv* pEnv, jobject jCaller, jstring itemKey, jboolean skipped )
	{
		WynCommonKore::AutoHaxe haxe("NativeOnVideoCompleted");
		LOG("NativeOnVideoCompleted");

		if (NativeOnVideoCompleted != null()) {
			NativeOnVideoCompleted((const char*)itemKey, (bool)skipped).Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnFetchCompleted( JNIEnv* pEnv, jobject jCaller )
	{
		WynCommonKore::AutoHaxe haxe("NativeOnFetchCompleted");
		LOG("NativeOnFetchCompleted");

		if (NativeOnFetchCompleted != null()) {
			NativeOnFetchCompleted().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_1kore_WynUnityAdsKore_NativeOnFetchFailed( JNIEnv* pEnv, jobject jCaller )
	{
		WynCommonKore::AutoHaxe haxe("NativeOnFetchFailed");
		LOG("NativeOnFetchFailed");

		if (NativeOnFetchFailed != null()) {
			NativeOnFetchFailed().Cast< Void >();
		}
	}
}
