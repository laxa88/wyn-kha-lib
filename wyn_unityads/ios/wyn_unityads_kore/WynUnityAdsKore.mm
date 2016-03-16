#include <WynUnityAdsKore.h>
#include <Foundation/Foundation.h>
#include <hxcpp.h>
#include <WynUnityAdsDelegateVC.h>
#import <UnityAds/UnityAds.h>

// Self note:
// If <hxcpp.h> and "Dynamic" gives an ambiguous class error,
// make sure to require the correct requisite classes. In
// the case above, we have to use <Foundation.h> before <hxcpp.h>

namespace WynUnityAdsKore
{
    WynUnityAdsDelegateVC *vc;
    
	Dynamic NativeOnHide;
	Dynamic NativeOnShow;
	Dynamic NativeOnVideoStarted;
	Dynamic NativeOnVideoCompleted;
	Dynamic NativeOnFetchCompleted;
	Dynamic NativeOnFetchFailed;

	void init (const char* adId)
	{
		NSLog(@"init");
        
        // Initialize Unity Ads
        NSString * sAdId = [NSString stringWithUTF8String:adId];
        UIWindow* window = [UIApplication sharedApplication].keyWindow;
        [[UnityAds sharedInstance] startWithGameId:sAdId andViewController:window.rootViewController];

        vc = [WynUnityAdsDelegateVC new];
        [[UnityAds sharedInstance] setDelegate:vc];
	}

	// void changeActivity ()
	// {
	// 	NSLog(@"changeActivity");
	// }

	void setDebugMode (bool val)
	{
        // Shows debug messages in the console output
		NSLog(@"setDebugMode");
        [[UnityAds sharedInstance] setDebugMode:NO];
	}

	void setTestMode (bool val)
	{
        // Shows test ads instead of actual ads
		NSLog(@"setTestMode");
        [[UnityAds sharedInstance] setTestMode:val];
	}

	void setZone (const char* zone)
	{
		NSLog(@"setZone");
        [[UnityAds sharedInstance] setZone:[NSString stringWithUTF8String:zone]];
	}

	bool canShow ()
	{
		NSLog(@"canShow");
        return [[UnityAds sharedInstance] canShow];
	}

	void show ()
	{
		NSLog(@"show");
		if ([[UnityAds sharedInstance] canShow]) {
        	[[UnityAds sharedInstance] show];
		}
	}

	void setCallbacks (Dynamic onHide, Dynamic onShow, Dynamic onVideoStarted, Dynamic onVideoCompleted, Dynamic onFetchCompleted, Dynamic onFetchFailed)
	{
		NativeOnShow = onShow;
		NativeOnHide = onHide;
		NativeOnVideoStarted = onVideoStarted;
		NativeOnVideoCompleted = onVideoCompleted;
		NativeOnFetchCompleted = onFetchCompleted;
		NativeOnFetchFailed = onFetchFailed;

		vc.unityAdsDidShowBlock = ^() {
			if (NativeOnShow != null()) {
				NativeOnShow().Cast<void>();
			}
		};
		vc.unityAdsDidHideBlock = ^() {
			if (NativeOnHide != null()) {
				NativeOnHide().Cast<void>();
			}
		};
		vc.unityAdsVideoStartedBlock = ^() {
			if (NativeOnVideoStarted != null()) {
				NativeOnVideoStarted().Cast<void>();
			}
		};
		vc.unityAdsVideoCompletedBlock = ^(NSString *rewardItemKey, BOOL skipped) {
            // Make sure to default to empty string if it's nil
            if (rewardItemKey == nil)
                rewardItemKey = @"";
			if (NativeOnVideoCompleted != null()) {
				NativeOnVideoCompleted((String)rewardItemKey, skipped).Cast<void>();
			}
		};
		vc.unityAdsFetchCompletedBlock = ^() {
			if (NativeOnFetchCompleted != null()) {
				NativeOnFetchCompleted().Cast<void>();
			}
		};
		vc.unityAdsFetchFailedBlock = ^() {
			if (NativeOnFetchFailed != null()) {
				NativeOnFetchFailed().Cast<void>();
			}
		};
	}
}
