#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GoogleMobileAds.h>
//#import "WynAdmobCallbacks.h"
#import "iOSHelper.h"

typedef struct iOSHelper iOsType;

@interface WynAdmobBannerDelegateVC : UIViewController<GADBannerViewDelegate>

// https://developers.google.com/admob/ios/ad-events#implementing_banner_events
// http://stackoverflow.com/questions/12201292/callback-from-c-to-objective-c
// http://www.plungeinteractive.com/blog/2012/08/05/obj-c-to-cpp-callbacks/

@property(nonatomic, strong) void (^adViewDidReceiveAdBlock)(GADBannerView*);
@property(nonatomic, strong) void (^didFailToReceiveAdWithErrorBlock)(GADRequestError*);
@property(nonatomic, strong) void (^adViewWillPresentScreenBlock)(GADBannerView*);
@property(nonatomic, strong) void (^adViewWillDismissScreenBlock)(GADBannerView*);
@property(nonatomic, strong) void (^adViewDidDismissScreenBlock)(GADBannerView*);
@property(nonatomic, strong) void (^adViewWillLeaveApplicationBlock)(GADBannerView*);
//@property(nonatomic, strong) void WynAdmobCallbacks* callbacks;

// - (void)adViewDidReceiveAd:(GADBannerView *)adView;
// - (void)adView:(GADBannerView *)adView didFailToReceiveAdWithError:(GADRequestError *)error;
// - (void)adViewWillPresentScreen:(GADBannerView *)adView;
// - (void)adViewWillDismissScreen:(GADBannerView *)adView;
// - (void)adViewDidDismissScreen:(GADBannerView *)adView;
// - (void)adViewWillLeaveApplication:(GADBannerView *)adView;
- (void)setCallbacks:(iOsType*)callback;

@end