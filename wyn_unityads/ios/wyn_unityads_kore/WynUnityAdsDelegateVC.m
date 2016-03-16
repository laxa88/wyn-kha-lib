#import "WynUnityAdsDelegateVC.h"
#include <UnityAds/UnityAds.h>

@implementation WynUnityAdsDelegateVC

// Referred to UnityAds.h for possible delegates

// - (void)unityAdsWillShow {}
- (void)unityAdsDidShow {
	NSLog(@"WynUnityAdsDelegateVC unityAdsDidShow");
	if (self.unityAdsDidShowBlock != nil)
		self.unityAdsDidShowBlock();
}
// - (void)unityAdsWillHide {}
- (void)unityAdsDidHide {
	NSLog(@"WynUnityAdsDelegateVC unityAdsDidHide");
	if (self.unityAdsDidHideBlock != nil)
		self.unityAdsDidHideBlock();
}
// - (void)unityAdsWillLeaveApplication {}
- (void)unityAdsVideoStarted {
	NSLog(@"WynUnityAdsDelegateVC unityAdsVideoStarted");
	if (self.unityAdsVideoStartedBlock != nil)
		self.unityAdsVideoStartedBlock();
}
- (void)unityAdsVideoCompleted:(NSString *)rewardItemKey skipped:(BOOL)skipped {
	NSLog(@"WynUnityAdsDelegateVC unityAdsVideoCompleted : %@ %d", rewardItemKey, skipped);
	if (self.unityAdsVideoCompletedBlock != nil)
		self.unityAdsVideoCompletedBlock(rewardItemKey, skipped);
}
- (void)unityAdsFetchCompleted {
	NSLog(@"WynUnityAdsDelegateVC unityAdsFetchCompleted");
	if (self.unityAdsFetchCompletedBlock != nil)
		self.unityAdsFetchCompletedBlock();
}
- (void)unityAdsFetchFailed {
	NSLog(@"WynUnityAdsDelegateVC unityAdsFetchFailed");
	if (self.unityAdsFetchFailedBlock != nil)
		self.unityAdsFetchFailedBlock();
}

@end