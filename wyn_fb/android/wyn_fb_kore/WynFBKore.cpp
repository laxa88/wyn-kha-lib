#include <WynFBKore.h>
#include <Kore/Android.h>

namespace WynFBKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;

	void attachThread ()
	{
		kactivity->vm->AttachCurrentThread(&env, NULL);
		cls = KoreAndroid::findClass(env, "wyn_fb_kore.WynFBKore");
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

	void shareFeed (const char* title, const char* desc, const char* caption, const char* pictureUrl)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "shareFeed", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jtitle= env->NewStringUTF(title);
		jstring jdesc = env->NewStringUTF(desc);
		jstring jcaption = env->NewStringUTF(caption);
		jstring jpictureUrl = env->NewStringUTF(pictureUrl);
		env->CallStaticVoidMethod(cls, methodId, jtitle, jdesc, jcaption, jpictureUrl);

		detachThread();
	}
}
