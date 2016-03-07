#pragma once

namespace WynAdmobKore
{
	void attachThread ();
	void detachThread ();
	void init ();
	//void setCallbacks ();
	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity);
	void toggleBanner (const char* adName, bool visible);
	void createInterstitial (const char* adUnitId);
	void showInterstitial ();
}
