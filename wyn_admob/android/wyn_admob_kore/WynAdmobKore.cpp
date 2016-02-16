#include <WynAdmobKore.h>
#include <Kore/Android.h>

namespace WynAdmobKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;
	
	void attachThread ()
	{
		kactivity->vm->AttachCurrentThread(&env, NULL);
		cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");
	}

	void detachThread ()
	{
		kactivity->vm->DetachCurrentThread();
	}

	void init ()
	{
		kactivity = KoreAndroid::getActivity();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}

	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createBanner", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		jstring jadType = env->NewStringUTF(adType);
		jstring jadGravity = env->NewStringUTF(adGravity);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId, jadType, jadGravity);

		detachThread();
	}

	void toggleBanner (const char* adName, bool visible)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "toggleBanner", "(Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		env->CallStaticVoidMethod(cls, methodId, jadName, visible);

		detachThread();
	}

	void createInterstitial (const char* adName, const char* adUnitId)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createInterstitial", "(Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId);

		detachThread();
	}
}
