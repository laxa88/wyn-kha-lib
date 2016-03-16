package wyn;

// NOTES
// - callback functions have to be static
// - callback functions have to be stored in a global variable
// so that the callback stays in memory when events are triggered.
// e.g. var adReceivedCB:Void->Void = adViewDidReceiveAd;

#if (sys_ios || sys_android_native)

@:headerCode('
#include <WynAdmobKore.h>
')

class WynAdmob
{
	@:functionCode('WynAdmobKore::init();')
	public static function init () : Void {}

	@:functionCode('WynAdmobKore::setBannerCallbacks(adViewDidReceiveAd,didFailToReceiveAdWithError,adViewWillPresentScreen,adViewWillDismissScreen,adViewDidDismissScreen,adViewWillLeaveApplication);')
	public static function setBannerCallbacks (adViewDidReceiveAd:Void->Void, didFailToReceiveAdWithError:String->Void, adViewWillPresentScreen:Void->Void, adViewWillDismissScreen:Void->Void, adViewDidDismissScreen:Void->Void, adViewWillLeaveApplication:Void->Void) {}

	@:functionCode('WynAdmobKore::createBanner(adName, adUnitId, adType, adGravity);')
	public static function createBanner (adName:String, adUnitId:String, adType:String, adGravity:String) : Void {}

	@:functionCode('WynAdmobKore::toggleBanner(adName, visible);')
	public static function toggleBanner (adName:String, visible:Bool) : Void {}

	@:functionCode('WynAdmobKore::setInterstitialCallbacks(interstitialDidReceiveAd,didFailToReceiveAdWithError,interstitialWillPresentScreen,interstitialWillDismissScreen,interstitialDidDismissScreen,interstitialWillLeaveApplication);')
	public static function setInterstitialCallbacks (interstitialDidReceiveAd:Void->Void, didFailToReceiveAdWithError:String->Void, interstitialWillPresentScreen:Void->Void, interstitialWillDismissScreen:Void->Void, interstitialDidDismissScreen:Void->Void, interstitialWillLeaveApplication:Void->Void) {}

	@:functionCode('WynAdmobKore::createInterstitial(adUnitId);')
	public static function createInterstitial (adUnitId:String) : Void {}

	@:functionCode('WynAdmobKore::showInterstitial();')
	public static function showInterstitial () : Void {}

	@:functionCode('return WynAdmobKore::isInterstitialReady();')
	public static function isInterstitialReady () : Bool { return false; }
}

#else

class WynAdmob
{
	public static function init () : Void {}
	public static function setBannerCallbacks (adViewDidReceiveAd:Void->Void, didFailToReceiveAdWithError:String->Void, adViewWillPresentScreen:Void->Void, adViewWillDismissScreen:Void->Void, adViewDidDismissScreen:Void->Void, adViewWillLeaveApplication:Void->Void) {}
	public static function createBanner (adName:String, adUnitId:String, adType:String, adGravity:String) : Void {}
	public static function toggleBanner (adName:String, visible:Bool) : Void {}
	public static function setInterstitialCallbacks (interstitialDidReceiveAd:Void->Void, didFailToReceiveAdWithError:String->Void, interstitialWillPresentScreen:Void->Void, interstitialWillDismissScreen:Void->Void, interstitialDidDismissScreen:Void->Void, interstitialWillLeaveApplication:Void->Void) {}
	public static function createInterstitial (adUnitId:String) : Void {}
	public static function showInterstitial () : Void {}
	public static function isInterstitialReady () : Bool { return false; }
}

#end