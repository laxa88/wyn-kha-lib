package wyn;

#if (sys_ios || sys_android_native)

// Unity ads only work on Android and iOS

@:headerCode('
#include <WynUnityAdsKore.h>
')

class WynUnityAds
{
	@:functionCode('WynUnityAdsKore::attachThread();')
	public static function attachThread () : Void {}

	@:functionCode('WynUnityAdsKore::detachThread();')
	public static function detachThread () : Void {}

	@:functionCode('WynUnityAdsKore::init(id);')
	public static function init (id:String) : Void {}

	@:functionCode('WynUnityAdsKore::changeActivity();')
	public static function changeActivity () : Void {}

	@:functionCode('WynUnityAdsKore::setDebugMode(val);')
	public static function setDebugMode (val:Bool) : Void {}

	@:functionCode('WynUnityAdsKore::setTestMode(val);')
	public static function setTestMode (val:Bool) : Void {}

	@:functionCode('WynUnityAdsKore::setZone(zone);')
	public static function setZone (zone:String) : Void {}

	@:functionCode('return WynUnityAdsKore::canShow();')
	public static function canShow () : Bool { return false; }

	@:functionCode('WynUnityAdsKore::show();')
	public static function show () : Void {}
}

#else

class WynUnityAds
{
    public static function attachThread () : Void {}
	public static function detachThread () : Void {}
	public static function init (id:String) : Void {}
	public static function changeActivity () : Void {}
	public static function setDebugMode (val:Bool) : Void {}
	public static function setTestMode (val:Bool) : Void {}
	public static function setZone (zone:String) : Void {}
	public static function canShow () : Bool { return false; }
	public static function show () : Void {}
}

#end