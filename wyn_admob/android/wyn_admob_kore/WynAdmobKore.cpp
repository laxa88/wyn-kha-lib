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

	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity)
	{
		LOG("createBanner");

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
		LOG("toggleBanner");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "toggleBanner", "(Ljava/lang/String;Z)V");
		jstring jadName = env->NewStringUTF(adName);
		env->CallStaticVoidMethod(cls, methodId, jadName, visible);

		detachThread();
	}

	void createInterstitial (const char* adName, const char* adUnitId)
	{
		LOG("createInterstitial");

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "createInterstitial", "(Ljava/lang/String;Ljava/lang/String;)V");
		jstring jadName = env->NewStringUTF(adName);
		jstring jadUnitId = env->NewStringUTF(adUnitId);
		env->CallStaticVoidMethod(cls, methodId, jadName, jadUnitId);

		detachThread();
	}
}
