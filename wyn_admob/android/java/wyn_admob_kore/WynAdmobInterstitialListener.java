package wyn_admob_kore;

import android.util.Log;
import com.google.android.gms.ads.AdListener;

public class WynAdmobInterstitialListener extends AdListener {

    public boolean isReady;

    public native void NativeInterstitialDidReceiveAd();
    public native void NativeDidFailToReceiveAdWithError2(String error);
    public native void NativeInterstitialWillPresentScreen();
    public native void NativeInterstitialWillDismissScreen(); // not used
    public native void NativeInterstitialDidDismissScreen();
    public native void NativeInterstitialWillLeaveApplication();

    static {
        // Android Studio can only compile into one module at a time,
        // for kha, it's all in one "kore" module. So just load that up.
        System.loadLibrary("kore");
    }

    @Override
    public void onAdLoaded() {
        // Code to be executed when an ad finishes loading.
        Log.d("WynLog", "WynAdmobInterstitialListener NativeInterstitialDidReceiveAd");
        NativeInterstitialDidReceiveAd();
        isReady = true;
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
        Log.d("WynLog", "WynAdmobInterstitialListener NativeDidFailToReceiveAdWithError2 : "  + errorCode);
        NativeDidFailToReceiveAdWithError2(Integer.toString(errorCode));
        isReady = false;
    }

    @Override
    public void onAdOpened() {
        // Code to be executed when an ad opens an overlay that
        // covers the screen.
        Log.d("WynLog", "WynAdmobInterstitialListener NativeInterstitialWillPresentScreen");
        NativeInterstitialWillPresentScreen();
    }

    @Override
    public void onAdLeftApplication() {
        // Code to be executed when the user has left the app.
        Log.d("WynLog", "WynAdmobInterstitialListener NativeInterstitialWillLeaveApplication");
        NativeInterstitialWillLeaveApplication();
        isReady = false;
    }

    @Override
    public void onAdClosed() {
        // Code to be executed when when the user is about to return
        // to the app after tapping on an ad.
        Log.d("WynLog", "WynAdmobInterstitialListener NativeInterstitialDidDismissScreen");
        NativeInterstitialDidDismissScreen();
        isReady = false;
    }
}
