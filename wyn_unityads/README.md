# Wyn Unity Ads
Simple Unity Ads library for Kha

## Notes

Unity Ads only works for mobile targets (iOS, Android).

## Installation

1. Copy the 'wyn_unityads' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_unityads');

### Android (Android Studio additional steps)

1. Download SDK from: https://github.com/Applifier/unity-ads-sdk
2. In Android Studio, File > New > New Module > Import .JAR/.AAR package
3. Right-click "app" folder in Project View > Open Module Settings
4. In the Dependencies Tab, click "+" > Module Dependency > Unity Ads module > Finish

When rebuilding the project, the unityads module link may be broken, but attempting to reinstall will cause errors. My manual way of fix is, just delete the 'unityads' folder in path/to/game-project/builds/android-native-build/game-project/ folder, and repeat steps 2 to 4 above.

Installation and usage reference:

	http://unityads.unity3d.com/help/monetization/integration-guide-android

### iOS

- none yet

## Usage

Simple, straightforward usage in your haxe code:

	wyn.WynUnityAds.init("ad-id");
	wyn.WynUnityAds.setZone("zone-id"); // optional
    wyn.WynUnityAds.show();
