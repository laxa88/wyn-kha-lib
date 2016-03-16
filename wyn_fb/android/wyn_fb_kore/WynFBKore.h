#pragma once

namespace WynFBKore
{
	void attachThread ();
	void detachThread ();
	void init ();
	void shareFeed (const char* title, const char* desc, const char* websiteUrl, const char* pictureUrl);
}
