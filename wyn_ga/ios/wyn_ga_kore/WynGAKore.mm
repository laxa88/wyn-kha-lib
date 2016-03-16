#include <WynGAKore.h>
#import <Foundation/Foundation.h>
#import <Google/Analytics.h>

namespace WynGAKore
{
	GAI *gInstance;
	id<GAITracker> gTracker;

	void init (const char* id)
	{
		NSLog(@"WynGAKore init : %s", id);

		// NOTES:
		// - If the value for NSNumber is an empty string, it will return nil (null).
		// This is what empty values should default to.

		// Initialize a tracker using a Google Analytics property ID.
		gInstance = [GAI sharedInstance];
		gTracker = [gInstance trackerWithTrackingId:[NSString stringWithUTF8String:id]];
	}

	void sendEvent (const char* category, const char* action, const char* label, const char* value)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/events
		NSLog(@"WynGAKore sendEvent : %s , %s , %s , %s", category, action, label, value);

		// Retrieve tracker with placeholder property ID.
		NSString *sCategory = [NSString stringWithUTF8String:category];
		NSString *sAction = [NSString stringWithUTF8String:action];
		NSString *sLabel = [NSString stringWithUTF8String:label];
		NSString *sValue = [NSString stringWithUTF8String:value];
		NSNumberFormatter *f = [[NSNumberFormatter alloc] init];
		f.numberStyle = NSNumberFormatterDecimalStyle;
		NSNumber *nValue = [f numberFromString:sValue];

		// DEBUG
		// NSLog(@"WynGAKore sendEvent : %@ , %@ , %@ , %@ , %@", sCategory, sAction, sLabel, sValue, nValue);

		[gTracker send:[[GAIDictionaryBuilder createEventWithCategory:sCategory action:sAction label:sLabel value:nValue] build]];
	}

	void sendSocial (const char* network, const char* action, const char* target)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/social
		NSLog(@"WynGAKore sendSocial : %s , %s , %s", network, action, target);

		NSString *sNetwork = [NSString stringWithUTF8String:network];
		NSString *sAction = [NSString stringWithUTF8String:action];
		NSString *sTarget = [NSString stringWithUTF8String:target];

		// DEBUG
		// NSLog(@"WynGAKore sendSocial : %@ , %@ , %@", sNetwork, sAction, sTarget);

		[gTracker send:[[GAIDictionaryBuilder createSocialWithNetwork:sNetwork action:sAction target:sTarget] build]];
	}

	void sendTiming (const char* category, const char* variable, const char* value, const char* label)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/usertimings
		NSLog(@"WynGAKore sendTiming : %s , %s , %s , %s", category, variable, value, label);

		NSString *sCategory = [NSString stringWithUTF8String:category];
		NSString *sName = [NSString stringWithUTF8String:variable];
		NSString *sValue = [NSString stringWithUTF8String:value];
		NSNumberFormatter *f = [[NSNumberFormatter alloc] init];
		f.numberStyle = NSNumberFormatterDecimalStyle;
		NSNumber *nValue = [f numberFromString:sValue];
		NSString *sLabel = [NSString stringWithUTF8String:label];

		// DEBUG
		// NSLog(@"WynGAKore sendTiming : %@ , %@ , %@ , %@ , %@", sCategory, sName, sValue, sLabel, nValue);

		[gTracker send:[[GAIDictionaryBuilder createTimingWithCategory:sCategory interval:nValue name:sName label:sLabel] build]];
	}
}
