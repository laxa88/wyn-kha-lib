#include <WynUnityAdsKore.h>
#include <Kore/Android.h>

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

}
