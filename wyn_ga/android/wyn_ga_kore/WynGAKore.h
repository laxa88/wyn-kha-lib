#pragma once

namespace WynGAKore
{
	void init (const char* id);

	void sendEvent (const char* category, const char* action, const char* label, const char* value);

	void sendSocial (const char* network, const char* action, const char* target);

	void sendTiming (const char* category, const char* variable, const char* value, const char* label);
}
