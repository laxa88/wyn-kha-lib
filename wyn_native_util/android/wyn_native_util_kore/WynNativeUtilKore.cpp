#include <WynNativeUtilKore.h>
#include <Kore/Android.h>

namespace WynNativeUtilKore
{
	void openUrl (const char* url)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_native_util_kore.WynNativeUtilKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "openUrl", "(Ljava/lang/String;)V");
		jstring jurl = env->NewStringUTF(url);
		env->CallStaticVoidMethod(cls, methodId, jurl);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
