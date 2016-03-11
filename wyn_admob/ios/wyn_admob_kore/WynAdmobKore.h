#pragma once

class Dynamic;

namespace WynAdmobKore
{
	void init ();
    void setBannerCallbacks (Dynamic adViewDidReceiveAd, Dynamic didFailToReceiveAdWithError, Dynamic adViewWillPresentScreen, Dynamic adViewWillDismissScreen, Dynamic adViewDidDismissScreen, Dynamic adViewWillLeaveApplication);
	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity);
	void toggleBanner (const char* adName, bool visible);
	void setInterstitialCallbacks (Dynamic interstitialDidReceiveAd, Dynamic didFailToReceiveAdWithError, Dynamic interstitialWillPresentScreen, Dynamic interstitialWillDismissScreen, Dynamic interstitialDidDismissScreen, Dynamic interstitialWillLeaveApplication);
	void createInterstitial (const char* adUnitId);
	void showInterstitial ();
	bool isInterstitialReady ();
}