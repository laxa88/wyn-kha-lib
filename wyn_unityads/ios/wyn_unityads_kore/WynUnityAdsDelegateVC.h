#import <UIKit/UIKit.h>
#import <UnityAds/UnityAds.h>

@interface WynUnityAdsDelegateVC : UIViewController<UnityAdsDelegate>

@property(nonatomic, strong) void (^unityAdsDidShowBlock)();
@property(nonatomic, strong) void (^unityAdsDidHideBlock)();
@property(nonatomic, strong) void (^unityAdsVideoStartedBlock)();
@property(nonatomic, strong) void (^unityAdsVideoCompletedBlock)(NSString*, BOOL);
@property(nonatomic, strong) void (^unityAdsFetchCompletedBlock)();
@property(nonatomic, strong) void (^unityAdsFetchFailedBlock)();

@end