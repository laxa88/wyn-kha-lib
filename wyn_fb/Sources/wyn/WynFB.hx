package wyn;

#if js

@:native('wyn_fb')
extern class WynFB
{
	public static function init (appId:String) : Void;

	// appId is only required for when FB API is not loaded,
	// but to be safe, always provide the appId
	public static function shareFeed (title:String, desc:String, websiteUrl:String, pictureUrl:String) : Void;
}

#elseif (sys_ios || sys_android_native)

@:headerCode('
#include <WynFBKore.h>
')

class WynFB
{
	@:functionCode('WynFBKore::init();')
	public static function init (appId:String) : Void {}

	@:functionCode('WynFBKore::shareFeed(title, desc, websiteUrl, pictureUrl);')
	public static function shareFeed (title:String, desc:String, websiteUrl:String, pictureUrl:String) : Void {}
}

#else

// TODO - handle this for other targets

class WynFB
{
	public static function init () {}
    public static function shareFeed (title:String, desc:String, websiteUrl:String, pictureUrl:String) {}
}

#end