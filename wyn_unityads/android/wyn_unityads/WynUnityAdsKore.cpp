#include "WynUnityAdsKore.h"
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynUnityAdsKore", msg, ## args)

namespace WynUnityAdsKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;
	static pthread_key_t s_thread_key;

	void attachThread ()
	{
		int getEnvStat = kactivity->vm->GetEnv((void**)&env, JNI_VERSION_1_4);
		if (getEnvStat == JNI_EDETACHED)
		{
			LOG("attachThread");

			if (kactivity->vm->AttachCurrentThread(&env, 0) != 0)
				LOG("Failed to attach");

			pthread_key_create(&s_thread_key, detachThread);
			pthread_setspecific (s_thread_key, &env);
		}

		cls = KoreAndroid::findClass(env, "wyn_unityads.WynUnityAdsKore");
	}

	void detachThread (void *env)
	{
		// LOG("detachThread");

		kactivity->vm->DetachCurrentThread();
	}

	void init (const char* id)
	{
		// LOG("init");

		kactivity = KoreAndroid::getActivity();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;)V");
		jstring jid = env->NewStringUTF(id);
		env->CallStaticVoidMethod(cls, methodId, jid);
	}

	void changeActivity ()
	{
		// LOG("changeActivity");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "changeActivity", "()V");
		env->CallStaticVoidMethod(cls, methodId);
	}

	void setDebugMode (bool val)
	{
		// LOG("setDebugMode");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setDebugMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);
	}

	void setTestMode (bool val)
	{
		// LOG("setTestMode");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setTestMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);
	}

	void setZone (const char* zone)
	{
		// LOG("setZone");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setZone", "(Ljava/lang/String;)V");
		jstring jzone = env->NewStringUTF(zone);
		env->CallStaticVoidMethod(cls, methodId, jzone);
	}

	bool canShow ()
	{
		// LOG("canShow");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "canShow", "()Z");
		jboolean result = env->CallStaticBooleanMethod(cls, methodId);

		return result;
	}

	void show ()
	{
		// LOG("show");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "show", "()V");
		env->CallStaticVoidMethod(cls, methodId);
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



	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnHide( JNIEnv* pEnv, jobject jCaller )
	{
		// References
		// https://github.com/openfl/openfl-native/issues/216
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidCommon.h#L19
		// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidFrame.cpp#L754

		// This wizardry fixes unregistered thread error. Try uncommenting this,
		// the game will break when the callback is invoked below (check the
		// error for the message).
		AutoHaxe haxe("NativeOnHide");

		if (NativeOnHide != null()) {
			NativeOnHide().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnShow( JNIEnv* pEnv, jobject jCaller )
	{
		AutoHaxe haxe("NativeOnShow");

		if (NativeOnShow != null()) {
			NativeOnShow().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnVideoStarted( JNIEnv* pEnv, jobject jCaller )
	{
		AutoHaxe haxe("NativeOnVideoStarted");

		if (NativeOnVideoStarted != null()) {
			NativeOnVideoStarted().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnVideoCompleted( JNIEnv* pEnv, jobject jCaller, jstring itemKey, jboolean skipped )
	{
		AutoHaxe haxe("NativeOnVideoCompleted");

		if (NativeOnVideoCompleted != null()) {
			NativeOnVideoCompleted((const char*)itemKey, (bool)skipped).Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnFetchCompleted( JNIEnv* pEnv, jobject jCaller )
	{
		AutoHaxe haxe("NativeOnFetchCompleted");

		if (NativeOnFetchCompleted != null()) {
			NativeOnFetchCompleted().Cast< Void >();
		}
	}

	extern "C" JNIEXPORT void JNICALL Java_wyn_1unityads_WynUnityAdsKore_NativeOnFetchFailed( JNIEnv* pEnv, jobject jCaller )
	{
		AutoHaxe haxe("NativeOnFetchFailed");

		if (NativeOnFetchFailed != null()) {
			NativeOnFetchFailed().Cast< Void >();
		}
	}
}
