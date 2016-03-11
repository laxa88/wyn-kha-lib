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

2. Include GoogleMobileAds.framework into your XCode project.
	* In your project settings, go to "Build Phases" tab
	* In "Link Binary with Libraries" section, click on "+" button
	* Click "Add Other..." button and select your downloaded "GoogleMobileAds.framework" file

## Usage

1. Simple, straightforward usage in your haxe code:

		wyn.WynAdmob.init();
		wyn.WynAdmob.createBanner("bottomBanner", "ca-app-pub-1234512345123456/1234567890", "BANNER", "BOTTOM");
		wyn.WynAdmob.createBanner("gameoverBanner", "ca-app-pub-1234512345123456/1234567890", "MEDIUM_RECTANGLE", "TOP");

2. Refer to 'WynAdmobKore.java' for possible parameter values
