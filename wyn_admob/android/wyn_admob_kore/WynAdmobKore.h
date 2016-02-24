#pragma once

namespace WynAdmobKore
{
	void attachThread ();
	void detachThread (void *env);
	void init ();
	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity);
	void toggleBanner (const char* adName, bool visible);
	void createInterstitial (const char* adName, const char* adUnitId);
}
