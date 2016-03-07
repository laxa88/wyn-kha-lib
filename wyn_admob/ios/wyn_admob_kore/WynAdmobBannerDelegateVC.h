#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GoogleMobileAds.h>

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

@end