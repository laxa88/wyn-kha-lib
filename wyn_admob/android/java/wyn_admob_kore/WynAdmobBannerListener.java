package wyn_admob_kore;

import android.util.Log;
import com.google.android.gms.ads.AdListener;

public class WynAdmobBannerListener extends AdListener {

    public native void NativeAdViewDidReceiveAd();
    public native void NativeDidFailToReceiveAdWithError(String error);
    public native void NativeAdViewWillPresentScreen();
    public native void NativeAdViewWillDismissScreen(); // not used
    public native void NativeAdViewDidDismissScreen();
    public native void NativeAdViewWillLeaveApplication();

    static {
        // Android Studio can only compile into one module at a time,
        // for kha, it's all in one "kore" module. So just load that up.
        System.loadLibrary("kore");
    }

    @Override
    public void onAdLoaded() {
        // Code to be executed when an ad finishes loading.
        Log.d("WynLog", "WynAdmobBannerListener NativeAdViewDidReceiveAd");
        NativeAdViewDidReceiveAd();
    }

    @Override
    public void onAdFailedToLoad(int errorCode) {
        // https://developers.google.com/android/reference/com/google/android/gms/ads/AdListener
        // Possible errorCodes:
        // ERROR_CODE_INTERNAL_ERROR = 0
        // ERROR_CODE_INVALID_REQUEST = 1
        // ERROR_CODE_NETWORK_ERROR = 2
        // ERROR_CODE_NO_FILL = 3

        // Code to be executed when an ad request fails.
        Log.d("WynLog", "WynAdmobBannerListener NativeDidFailToReceiveAdWithError2 : " + errorCode);
        NativeDidFailToReceiveAdWithError(Integer.toString(errorCode));
    }

    @Override
    public void onAdOpened() {
        // Code to be executed when an ad opens an overlay that
        // covers the screen.
        Log.d("WynLog", "WynAdmobBannerListener NativeAdViewWillPresentScreen");
        NativeAdViewWillPresentScreen();
    }

    @Override
    public void onAdLeftApplication() {
        // Code to be executed when the user has left the app.
        Log.d("WynLog", "WynAdmobBannerListener NativeAdViewWillLeaveApplication");
        NativeAdViewWillLeaveApplication();
    }

    @Override
    public void onAdClosed() {
        // Code to be executed when when the user is about to return
        // to the app after tapping on an ad.
        Log.d("WynLog", "WynAdmobBannerListener NativeAdViewDidDismissScreen");
        NativeAdViewDidDismissScreen();
    }
}
