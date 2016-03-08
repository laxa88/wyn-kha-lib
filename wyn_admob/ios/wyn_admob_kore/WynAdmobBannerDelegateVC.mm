#import "WynAdmobBannerDelegateVC.h"
#include <GoogleMobileAds/GoogleMobileAds.h>

iOsType* staticPointer;

@implementation WynAdmobBannerDelegateVC

#pragma mark - GADBannerViewDelegate

- (void)setCallbacks:(iOsType*)callback {
    staticPointer = callback;
}

/// Tells the delegate an ad request loaded an ad.
- (void)adViewDidReceiveAd:(GADBannerView *)adView {
    NSLog(@"adViewDidReceiveAd");
    // if (self.adViewDidReceiveAdBlock != nil)
    //     self.adViewDidReceiveAdBlock(adView);
    // staticPointer->adViewDidReceiveAdCB();
}

/// Tells the delegate an ad request failed.
- (void)adView:(GADBannerView *)adView
didFailToReceiveAdWithError:(GADRequestError *)error {
    NSLog(@"adView:didFailToReceiveAdWithError: %@", [error localizedDescription]);
    // if (self.didFailToReceiveAdWithErrorBlock != nil)
    //     self.didFailToReceiveAdWithErrorBlock(error);
    // staticPointer->didFailToReceiveAdWithErrorCB([error.localizedDescription UTF8String]);
}

/// Tells the delegate that a full screen view will be presented in response
/// to the user clicking on an ad.
- (void)adViewWillPresentScreen:(GADBannerView *)adView {
    NSLog(@"adViewWillPresentScreen");
    // self.adViewWillPresentScreenBlock(adView);
    // staticPointer->adViewWillPresentScreenCB();
}

/// Tells the delegate that the full screen view will be dismissed.
- (void)adViewWillDismissScreen:(GADBannerView *)adView {
    NSLog(@"adViewWillDismissScreen");
    // self.adViewWillDismissScreenBlock(adView);
    // staticPointer->adViewWillDismissScreenCB();
}

/// Tells the delegate that the full screen view has been dismissed.
- (void)adViewDidDismissScreen:(GADBannerView *)adView {
    NSLog(@"adViewDidDismissScreen");
    // self.adViewDidDismissScreenBlock(adView);
    // staticPointer->adViewDidDismissScreenCB();
}

/// Tells the delegate that a user click will open another app (such as
/// the App Store), backgrounding the current app.
- (void)adViewWillLeaveApplication:(GADBannerView *)adView {
    NSLog(@"adViewWillLeaveApplication");
    // self.adViewWillLeaveApplicationBlock(adView);
    // staticPointer->adViewWillLeaveApplicationCB();
}

@end