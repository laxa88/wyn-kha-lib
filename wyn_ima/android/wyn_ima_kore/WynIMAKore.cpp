#include <WynIMAKore.h>
#include <Kore/Android.h>

namespace WynIMAKore
{
	void init ()
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ima_kore.WynIMAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void show ()
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ima_kore.WynIMAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "show", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
