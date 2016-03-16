# Wyn Admob
Simple Admob library for Kha

## Notes

Adbmob only works for mobile targets (iOS, Android).

## Installation

1. Copy the 'wyn_admob' and 'wyn_common' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_admob');
		project.addLibrary('wyn_common');

### Android (Android Studio additional steps)

Reference:

	https://developers.google.com/admob/android/quick-start

1. In the app-level 'build.gradle', add (should be inside 'model.android'):

		dependencies {
			compile 'com.google.android.gms:play-services-ads:8.4.0'
		}

### iOS

1. Download GoogleMobileAds.framework from this page: (https://developers.google.com/admob/ios/download)

2. Drag-and-drop the following into your XCode project's Frameworks folder:

		GoogleMobileAds.framework

## Usage

1. Simple, straightforward usage in your haxe code:

		// NOTE: don't assign function callbacks directly in the function,
		// due to some quirkiness of Haxe. Instead, you have to create global
		// or class variables that store references to your callbacks.
		// Also, your callback functions have to be static.
		
		var a:Void->Void = adViewDidReceiveAd;
		var b:String->Void = didFailToReceiveAdWithError;
		var c:Void->Void = adViewWillPresentScreen;
		var d:Void->Void = adViewWillDismissScreen;
		var e:Void->Void = adViewDidDismissScreen;
		var f:Void->Void = adViewWillLeaveApplication;

		var a2:Void->Void = interstitialDidReceiveAd;
		var b2:String->Void = didFailToReceiveAdWithError2;
		var c2:Void->Void = interstitialWillPresentScreen;
		var d2:Void->Void = interstitialWillDismissScreen;
		var e2:Void->Void = interstitialDidDismissScreen;
		var f2:Void->Void = interstitialWillLeaveApplication;

		

		// Always do this before you call other methods
		wyn.WynAdmob.init();

		// Immediately after init, you can add listeners.
		wyn.WynAdmob.setBannerCallbacks(a,b,c,d,e,f);
		wyn.WynAdmob.setInterstitialCallbacks(a2,b2,c2,d2,e2,f2);

		// Example banners
		// Refer to 'WynAdmobKore.java' or 'WynAdmobKore.mm' for possible parameter values
		wyn.WynAdmob.createBanner("bottomBanner", "ca-app-pub-3940256099942544/6300978111", "BANNER", "BOTTOM");
		wyn.WynAdmob.createBanner("gameoverBanner", "ca-app-pub-3940256099942544/6300978111", "MEDIUM_RECTANGLE", "TOP");

		// Example interstitial
		wyn.WynAdmob.createInterstitial("ca-app-pub-3940256099942544/1033173712");

		// Toggle visiblity
		wyn.WynAdmob.toggleBanner("bottomBanner", false);
		wyn.WynAdmob.toggleBanner("gameoverBanner", false);

		// Show interstitial
		if (wyn.WynAdmob.isInterstitialReady())
			wyn.WynAdmob.showInterstitial();
