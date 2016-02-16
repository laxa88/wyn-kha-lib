#include <WynAdmobKore.h>
#include <Kore/Android.h>

namespace WynAdmobKore
{
	void init ()
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "createBanner", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		jstring jadType = env->NewStringUTF(adType);
		jstring jadGravity = env->NewStringUTF(adGravity);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId, jadType, jadGravity);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void toggleBanner (const char* adName, bool visible)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "toggleBanner", "(Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		env->CallStaticVoidMethod(cls, methodId, jadName, visible);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void createInterstitial (const char* adName, const char* adUnitId)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_admob_kore.WynAdmobKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "createInterstitial", "(Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
