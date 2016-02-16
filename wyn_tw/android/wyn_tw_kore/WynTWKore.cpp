#include <WynTWKore.h>
#include <Kore/Android.h>

namespace WynTWKore
{
	void tweet (const char* message)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_tw_kore.WynTWKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "tweet", "(Ljava/lang/String;)V");
		jstring jmessage = env->NewStringUTF(message);
		env->CallStaticVoidMethod(cls, methodId, jmessage);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
