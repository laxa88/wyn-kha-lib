# Wyn Unity Ads
Simple Unity Ads library for Kha

## Installation

Project installation:
- download SDK from: https://github.com/Applifier/unity-ads-sdk
- in Android Studio, File > New > New Module
- import .JAR/.AAR package
- right-click "app" folder in project view > Open Module Settings > Dependencies
- click "+" > Module Dependency > Unity Ads module

When rebuilding the project, the unityads module will not be linked,
but attempting to reinstall will have errors. To fix, just delete the
unityads folder in your builds/android-native-build/YourProject/ folder,
and repeat the above installation steps.

installation and usage reference:
http://unityads.unity3d.com/help/monetization/integration-guide-android

## Usage

Simple, straightforward usage in your haxe code:

    wyn.WynUnityAds.init("103000");

	wyn.WynUnityAds.setZone("12540-1392899280");
	
    wyn.WynUnityAds.show();