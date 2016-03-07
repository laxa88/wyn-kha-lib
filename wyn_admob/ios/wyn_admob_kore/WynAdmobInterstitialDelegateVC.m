#import "WynAdmobInterstitialDelegateVC.h"
#include <GoogleMobileAds/GoogleMobileAds.h>

@implementation WynAdmobInterstitialDelegateVC

#pragma mark - GADInterstitialDelegate

/// Called when an interstitial ad request succeeded.
- (void)interstitialDidReceiveAd:(GADInterstitial *)ad {
    NSLog(@"interstitialDidReceiveAd");
    self.interstitialDidReceiveAdBlock(ad);
}

/// Called when an interstitial ad request failed.
- (void)interstitial:(GADInterstitial *)ad
    didFailToReceiveAdWithError:(GADRequestError *)error {
        NSLog(@"interstitial:didFailToReceiveAdWithError: %@", [error localizedDescription]);
        self.didFailToReceiveAdWithErrorBlock(error);
}

/// Called just before presenting an interstitial.
- (void)interstitialWillPresentScreen:(GADInterstitial *)ad {
    NSLog(@"interstitialWillPresentScreen");
    self.interstitialWillPresentScreenBlock(ad);
}

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(GADInterstitial *)ad {
    NSLog(@"interstitialWillDismissScreen");
    self.interstitialWillDismissScreenBlock(ad);
}

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(GADInterstitial *)ad {
    NSLog(@"interstitialDidDismissScreen");
    self.interstitialDidDismissScreenBlock(ad);
}

/// Called just before the app will background or terminate because the user clicked on an
/// ad that will launch another app (such as the App Store).
- (void)interstitialWillLeaveApplication:(GADInterstitial *)ad {
    NSLog(@"interstitialWillLeaveApplication");
    self.interstitialWillLeaveApplicationBlock(ad);
}

@end