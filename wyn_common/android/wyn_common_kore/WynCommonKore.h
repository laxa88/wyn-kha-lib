#pragma once
#include <Kore/Android.h>
#include <hx/CFFI.h>
#include <android/log.h>

#undef LOG
#define LOG(msg,args...) __android_log_print(ANDROID_LOG_INFO, "#_# WynCommonKore", msg, ## args)

namespace WynCommonKore
{
	void init ();
	void destroyThread (void *env);
	JNIEnv* attachThread ();
	void detachThread ();

	// References
	// https://github.com/openfl/openfl-native/issues/216
	// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidCommon.h#L19
	// https://github.com/haxenme/nme/blob/master/project/src/android/AndroidFrame.cpp#L754
	struct AutoHaxe
	{
		int base;
		const char *message;
		AutoHaxe(const char *inMessage)
		{
			base = 0;
			message = inMessage;
			gc_set_top_of_stack(&base, true);

			LOG("AutoHaxe Enter %s %p", message, pthread_self());
		}
		~AutoHaxe()
		{
			LOG("AutoHaxe Leave %s %p", message, pthread_self());
			gc_set_top_of_stack(0, true);
		}
	};
}
