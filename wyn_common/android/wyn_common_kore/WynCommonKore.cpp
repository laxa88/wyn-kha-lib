#include <WynCommonKore.h>
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynCommonKore", msg, ## args)

namespace WynCommonKore
{
	static ANativeActivity* kactivity;
	static pthread_key_t s_thread_key;
	static bool isInit = false;
	static bool attached = false;

	void init ()
	{
		if (!isInit)
		{
			LOG("init");

			kactivity = KoreAndroid::getActivity();
			pthread_key_create(&s_thread_key, destroyThread);

			isInit = true;
		}
	}

	void destroyThread (void *env)
	{
		LOG("detachThread");
		kactivity->vm->DetachCurrentThread();
	}

	JNIEnv* attachThread ()
	{
		JNIEnv *env;
		int getEnvStat = kactivity->vm->GetEnv((void**)&env, JNI_VERSION_1_4);
		if (getEnvStat == JNI_EDETACHED)
		{
			attached = true;
			LOG("attachThread - new thread");
			if (kactivity->vm->AttachCurrentThread(&env, 0) != 0)
				LOG("Failed to attach");

			pthread_setspecific (s_thread_key, &env);
		}
		else
		{
			attached = false;
			LOG("attachThread - get existing");
		}

		return env;
	}

	void detachThread ()
	{
		// Don't detach if there is still code running on thread
		if (attached) {
			LOG("detachThread YES");
			kactivity->vm->DetachCurrentThread();
		}
		else {
			LOG("detachThread NO");
		}
	}
}
