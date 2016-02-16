#include <WynGAKore.h>
#include <Kore/Android.h>

namespace WynGAKore
{
	void init (const char* id)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ga_kore.WynGAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;)V");
		jstring jid = env->NewStringUTF(id);
		env->CallStaticVoidMethod(cls, methodId, jid);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void sendEvent (const char* category, const char* action, const char* label, const char* value)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ga_kore.WynGAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "sendEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jcategory = env->NewStringUTF(category);
		jstring jaction = env->NewStringUTF(action);
		jstring jlabel = env->NewStringUTF(label);
		jstring jvalue = env->NewStringUTF(value);
		env->CallStaticVoidMethod(cls, methodId, jcategory, jaction, jlabel, jvalue);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void sendSocial (const char* network, const char* action, const char* target)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ga_kore.WynGAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "sendSocial", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jnetwork = env->NewStringUTF(network);
		jstring jaction = env->NewStringUTF(action);
		jstring jtarget = env->NewStringUTF(target);
		env->CallStaticVoidMethod(cls, methodId, jnetwork, jaction, jtarget);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}

	void sendTiming (const char* category, const char* variable, const char* value, const char* label)
	{
		JNIEnv* env;
		KoreAndroid::getActivity()->vm->AttachCurrentThread(&env, NULL);
		jclass cls = KoreAndroid::findClass(env, "wyn_ga_kore.WynGAKore");

		jmethodID methodId = env->GetStaticMethodID(cls, "sendTiming", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jcategory = env->NewStringUTF(category);
		jstring jvariable = env->NewStringUTF(variable);
		jstring jvalue = env->NewStringUTF(value);
		jstring jlabel = env->NewStringUTF(label);
		env->CallStaticVoidMethod(cls, methodId, jcategory, jvariable, jvalue, jlabel);

		KoreAndroid::getActivity()->vm->DetachCurrentThread();
	}
}
