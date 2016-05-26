#include <WynGAKore.h>
#include <Kore/Android.h>

namespace WynGAKore
{
	static ANativeActivity* kactivity;
	static JNIEnv* env;
	static jclass cls;

	// TODO 2016-05-26
	// allow multiple trackers via "name" variable

	void attachThread ()
	{
		kactivity->vm->AttachCurrentThread(&env, NULL);
		cls = KoreAndroid::findClass(env, "wyn_ga_kore.WynGAKore");
	}

	void detachThread ()
	{
		kactivity->vm->DetachCurrentThread();
	}
	
	void init (const char* id, const char* name, bool enableAdvertisingTracking)
	{
		kactivity = KoreAndroid::getActivity();

		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "init", "(Ljava/lang/String;Ljava/lang/String;Z)V");
		jstring jid = env->NewStringUTF(id);
		jstring jname = env->NewStringUTF(name);
		env->CallStaticVoidMethod(cls, methodId, jid, jname, enableAdvertisingTracking);

		detachThread();
	}

	void sendEvent (const char* name, const char* category, const char* action, const char* label, const char* value)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "sendEvent", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jname = env->NewStringUTF(name);
		jstring jcategory = env->NewStringUTF(category);
		jstring jaction = env->NewStringUTF(action);
		jstring jlabel = env->NewStringUTF(label);
		jstring jvalue = env->NewStringUTF(value);
		env->CallStaticVoidMethod(cls, methodId, jname, jcategory, jaction, jlabel, jvalue);

		detachThread();
	}

	void sendSocial (const char* name, const char* network, const char* action, const char* target)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "sendSocial", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jname = env->NewStringUTF(name);
		jstring jnetwork = env->NewStringUTF(network);
		jstring jaction = env->NewStringUTF(action);
		jstring jtarget = env->NewStringUTF(target);
		env->CallStaticVoidMethod(cls, methodId, jname, jnetwork, jaction, jtarget);

		detachThread();
	}

	void sendTiming (const char* name, const char* category, const char* variable, const char* value, const char* label)
	{
		attachThread();

		jmethodID methodId = env->GetStaticMethodID(cls, "sendTiming", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
		jstring jname = env->NewStringUTF(name);
		jstring jcategory = env->NewStringUTF(category);
		jstring jvariable = env->NewStringUTF(variable);
		jstring jvalue = env->NewStringUTF(value);
		jstring jlabel = env->NewStringUTF(label);
		env->CallStaticVoidMethod(cls, methodId, jname, jcategory, jvariable, jvalue, jlabel);

		detachThread();
	}
}
