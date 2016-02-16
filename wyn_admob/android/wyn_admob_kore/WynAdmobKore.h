#pragma once

namespace WynAdmobKore
{
	void init ();
	void createBanner (const char* adName, const char* adUnitId, const char* adType, const char* adGravity);
	void toggleBanner (const char* adName, bool visible);
	void createInterstitial (const char* adName, const char* adUnitId);
}
