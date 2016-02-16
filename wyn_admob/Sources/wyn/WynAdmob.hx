package wyn;

#if (sys_ios || sys_android_native)

@:headerCode('
#include <WynAdmobKore.h>
')

class WynAdmob
{
	@:functionCode('WynAdmobKore::init();')
	public static function init () : Void {}

	@:functionCode('WynAdmobKore::createBanner(adName, adUnitId, adType, adGravity);')
	public static function createBanner (adName:String, adUnitId:String, adType:String, adGravity:String) : Void {}

	@:functionCode('WynAdmobKore::toggleBanner(adName, visible);')
	public static function toggleBanner (adName:String, visible:Bool) : Void {}

	@:functionCode('WynAdmobKore::createInterstitial(adName, adUnitId);')
	public static function createInterstitial (adName:String, adUnitId:String) : Void {}
}

#else

class WynAdmob
{
	public static function init () : Void {}
	public static function createBanner (adName:String, adUnitId:String, adType:String, adGravity:String) : Void {}
	public static function toggleBanner (adName:String, visible:Bool) : Void {}
	public static function createInterstitial (adName:String, adUnitId:String) : Void {}
}

#end