#include <WynFBKore.h>
#include <Kore/Android.h>

namespace WynFBKore
{
	void init ()
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_fb_kore.WynFBKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "()V");
		env->CallStaticVoidMethod(cls, methodId);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void shareFeed (const char* title, const char* desc, const char* caption, const char* pictureUrl)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_fb_kore.WynFBKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "shareFeed", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jtitle= env->NewStringUTF(title);
		jstring jdesc = env->NewStringUTF(desc);
		jstring jcaption = env->NewStringUTF(caption);
		jstring jpictureUrl = env->NewStringUTF(pictureUrl);
		env->CallStaticVoidMethod(cls, methodId, jtitle, jdesc, jcaption, jpictureUrl);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
