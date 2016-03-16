#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

@interface WynAdmobInterstitialDelegateVC : UIViewController<GADInterstitialDelegate>

// https://developers.google.com/admob/ios/ad-events#implementing_banner_events
// http://stackoverflow.com/questions/12201292/callback-from-c-to-objective-c
// http://www.plungeinteractive.com/blog/2012/08/05/obj-c-to-cpp-callbacks/

@property(nonatomic, strong) void (^interstitialDidReceiveAdBlock)(GADInterstitial*);
@property(nonatomic, strong) void (^didFailToReceiveAdWithErrorBlock)(GADRequestError*);
@property(nonatomic, strong) void (^interstitialWillPresentScreenBlock)(GADInterstitial*);
@property(nonatomic, strong) void (^interstitialWillDismissScreenBlock)(GADInterstitial*);
@property(nonatomic, strong) void (^interstitialDidDismissScreenBlock)(GADInterstitial*);
@property(nonatomic, strong) void (^interstitialWillLeaveApplicationBlock)(GADInterstitial*);

@end