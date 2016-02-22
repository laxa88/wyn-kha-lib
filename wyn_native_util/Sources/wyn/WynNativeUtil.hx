package wyn;

#if js

@:native('wyn_native_util')
extern class WynNativeUtil
{
	public static function openUrl (url:String) : Void;
}

#elseif (sys_ios || sys_android_native)

@:headerCode('
#include <WynNativeUtilKore.h>
')

class WynNativeUtil
{
	// references
	// http://stackoverflow.com/questions/2201917/how-can-i-open-a-url-in-androids-web-browser-from-my-application
	// http://stackoverflow.com/questions/3004515/android-sending-an-intent-to-browser-to-open-specific-url/

	@:functionCode('WynNativeUtilKore::openUrl(url);')
	public static function openUrl (url:String) : Void {}
}

#else

class WynNativeUtil
{
	public static function openUrl (url:String) : Void {}
}

#end
