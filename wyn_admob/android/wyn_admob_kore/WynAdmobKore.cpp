#include <WynAdmobKore.h>
#include <Kore/Android.h>
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynAdmobKore", msg, ## args)

namespace WynAdmobKore
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
			// LOG("attachThread");

			if (kactivity->vm->AttachCurrentThread(&env, 0) != 0)
				LOG("Failed to attach");

			pthread_key_create(&s_thread_key, detachThread);
			pthread_setspecific (s_thread_key, &env);
		}

		cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");
	}

	void detachThread (void *env)
	{
		// LOG("detachThread");

		kactivity->vm->DetachCurrentThread();
	}

	void init ()
	{
		// LOG("init");

		kactivity = KoreAndroid::getActivity();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);
	}

	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity)
	{
		// LOG("createBanner");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createBanner", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		jstring jadType = env->NewStringUTF(adType);
		jstring jadGravity = env->NewStringUTF(adGravity);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId, jadType, jadGravity);
	}

	void toggleBanner (const char* adName, bool visible)
	{
		// LOG("toggleBanner");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "toggleBanner", "(Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		env->CallStaticVoidMethod(cls, methodId, jadName, visible);
	}

	void createInterstitial (const char* adName, const char* adUnitId)
	{
		// LOG("createInterstitial");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createInterstitial", "(Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId);
	}
}
