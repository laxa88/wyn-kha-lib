#include <WynGAKore.h>
#import <Foundation/Foundation.h>
#import <Google/Analytics.h>

namespace WynGAKore
{
	GAI *gInstance;
	id<GAITracker> gTracker;

	// TODO 2016-05-26
	// allow multiple trackers via "name" variable

	void init (const char* id, const char* name, bool enableAdvertisingTracking)
	{
		NSLog(@"WynGAKore init : %s", id);

		// NOTES:
		// - If the value for NSNumber is an empty string, it will return nil (null).
		// This is what empty values should default to.

		// Initialize a tracker using a Google Analytics property ID.
		gInstance = [GAI sharedInstance];
		gTracker = [gInstance trackerWithTrackingId:[NSString stringWithUTF8String:id]];

		if (enableAdvertisingTracking) {
			// https://support.google.com/analytics/answer/2444872?hl=en&utm_id=ad#web
			// Enable IDFA collection.
			gTracker.allowIDFACollection = YES;
		}
	}

	void sendEvent (const char* name, const char* category, const char* action, const char* label, const char* value)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/events
		NSLog(@"WynGAKore sendEvent : %s , %s , %s , %s", category, action, label, value);

		// Retrieve tracker with placeholder property ID.
		NSString *sCategory = nil;
		NSString *sAction = nil;
		NSString *sLabel = nil;
		NSString *sValue = nil;
		NSNumber *nValue = nil;

		if (category != nil) sCategory = [NSString stringWithUTF8String:category];
		if (action != nil) sAction = [NSString stringWithUTF8String:action];
		if (label != nil) sLabel = [NSString stringWithUTF8String:label];
		if (value != nil) {
			sValue = [NSString stringWithUTF8String:value];
			NSNumberFormatter *f = [[NSNumberFormatter alloc] init];
			f.numberStyle = NSNumberFormatterDecimalStyle;
			nValue = [f numberFromString:sValue];
		}

		// DEBUG
		// NSLog(@"WynGAKore sendEvent : %@ , %@ , %@ , %@ , %@", sCategory, sAction, sLabel, sValue, nValue);

		[gTracker send:[[GAIDictionaryBuilder createEventWithCategory:sCategory action:sAction label:sLabel value:nValue] build]];
	}

	void sendSocial (const char* name, const char* network, const char* action, const char* target)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/social
		NSLog(@"WynGAKore sendSocial : %s , %s , %s", network, action, target);

		NSString *sNetwork = nil;
		NSString *sAction = nil;
		NSString *sTarget = nil;

		if (network != nil) sNetwork = [NSString stringWithUTF8String:network];
		if (action != nil) sAction = [NSString stringWithUTF8String:action];
		if (target != nil) sTarget = [NSString stringWithUTF8String:target];

		// DEBUG
		// NSLog(@"WynGAKore sendSocial : %@ , %@ , %@", sNetwork, sAction, sTarget);

		[gTracker send:[[GAIDictionaryBuilder createSocialWithNetwork:sNetwork action:sAction target:sTarget] build]];
	}

	void sendTiming (const char* name, const char* category, const char* variable, const char* value, const char* label)
	{
		// https://developers.google.com/analytics/devguides/collection/ios/v3/usertimings
		NSLog(@"WynGAKore sendTiming : %s , %s , %s , %s", category, variable, value, label);

		NSString *sCategory = nil;
		NSString *sName = nil;
		NSString *sValue = nil;
		NSString *sLabel = nil;
		NSNumber *nValue = nil;

		if (category != nil) sCategory = [NSString stringWithUTF8String:category];
		if (variable != nil) sName = [NSString stringWithUTF8String:variable];
		if (value != nil) {
			sValue = [NSString stringWithUTF8String:value];
			NSNumberFormatter *f = [[NSNumberFormatter alloc] init];
			f.numberStyle = NSNumberFormatterDecimalStyle;
			nValue = [f numberFromString:sValue];
		}
		if (label != nil) sLabel = [NSString stringWithUTF8String:label];

		// DEBUG
		// NSLog(@"WynGAKore sendTiming : %@ , %@ , %@ , %@ , %@", sCategory, sName, sValue, sLabel, nValue);

		[gTracker send:[[GAIDictionaryBuilder createTimingWithCategory:sCategory interval:nValue name:sName label:sLabel] build]];
	}
}
