#pragma once

class Dynamic;

namespace WynUnityAdsKore
{
	void init (const char* adId);
	// void changeActivity ();
	void setDebugMode (bool val);
	void setTestMode (bool val);
	void setZone (const char* zone);
	bool canShow ();
	void show ();
	void setCallbacks (Dynamic onHide, Dynamic onShow, Dynamic onVideoStarted, Dynamic onVideoCompleted, Dynamic onFetchCompleted, Dynamic onFetchFailed);
}
