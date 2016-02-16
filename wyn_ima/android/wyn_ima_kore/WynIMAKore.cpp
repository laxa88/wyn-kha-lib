#include <WynIMAKore.h>
#include <Kore/Android.h>

namespace WynIMAKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;

	void attachThread ()
	{
		kactivity->vm->AttachCurrentThread(&env, NULL);
		cls = KoreAndroid::findClass(env, "wyn_ima_kore.WynIMAKore");
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

	void show ()
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "show", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		detachThread();
	}
}
