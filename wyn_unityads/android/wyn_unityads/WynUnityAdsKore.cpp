#include <android/log.h>
#include "WynUnityAdsKore.h"

namespace WynUnityAdsKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;

	void attachThread ()
	{
		kactivity->vm->AttachCurrentThread(&env, NULL);
		cls = KoreAndroid::findClass(env, "wyn_unityads.WynUnityAdsKore");
	}

	void detachThread ()
	{
		kactivity->vm->DetachCurrentThread();
	}

	void init (const char* id)
	{
		kactivity = KoreAndroid::getActivity();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;)V");
		jstring jid = env->NewStringUTF(id);
		env->CallStaticVoidMethod(cls, methodId, jid);

		detachThread();
	}

	void changeActivity ()
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "changeActivity", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}

	void setDebugMode (bool val)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setDebugMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);

		detachThread();
	}

	void setTestMode (bool val)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setTestMode", "(Z)V");
		env->CallStaticVoidMethod(cls, methodId, val);

		detachThread();
	}

	void setZone (const char* zone)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "setZone", "(Ljava/lang/String;)V");
		jstring jzone = env->NewStringUTF(zone);
		env->CallStaticVoidMethod(cls, methodId, jzone);

		detachThread();
	}

	bool canShow ()
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "canShow", "()V");
		jboolean result = env->CallStaticBooleanMethod(cls, methodId);

		detachThread();

		return result;
	}

	void show ()
	{
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
		// __android_log_print(ANDROID_LOG_INFO, "GAME", "#something wynunityadskore setCallbacks");

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
