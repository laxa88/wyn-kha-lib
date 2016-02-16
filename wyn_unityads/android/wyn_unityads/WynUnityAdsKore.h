#pragma once

namespace WynUnityAdsKore
{
	void attachThread ();
	void detachThread ();
	void init (const char* id);
	void changeActivity ();
	void setDebugMode (bool val);
	void setTestMode (bool val);
	void setZone (const char* zone);
	bool canShow ();
	void show ();
}
