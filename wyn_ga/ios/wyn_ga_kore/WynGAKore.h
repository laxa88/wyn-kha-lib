#pragma once

namespace WynGAKore
{
	// TODO 2016-05-26
	// allow multiple trackers via "name" variable
	
	void init (const char* id, const char* name, bool enableAdvertisingTracking);
	void sendEvent (const char* name, const char* category, const char* action, const char* label, const char* value);
	void sendSocial (const char* name, const char* network, const char* action, const char* target);
	void sendTiming (const char* name, const char* category, const char* variable, const char* value, const char* label);
}