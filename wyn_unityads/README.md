# Wyn Unity Ads
Simple Unity Ads library for Kha

## Notes

Unity Ads only works for mobile targets (iOS, Android).

## Installation

1. Copy the 'wyn_unityads' and 'wyn_common' folder to your Libraries folder

2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_unityads');
		project.addLibrary('wyn_common');

### Android (Android Studio additional steps)

Reference:

		http://unityads.unity3d.com/help/monetization/integration-guide-android

1. Download SDK from: https://github.com/Applifier/unity-ads-sdk

2. In Android Studio, File > New > New Module > Import .JAR/.AAR package, then import "unity-ads.aar" from the downloaded SDK.

3. Right-click "app" folder in Project View > Open Module Settings

4. In the Dependencies Tab, click "+" > Module Dependency > Unity Ads module > Finish

	When rebuilding the project, the unityads module link may be broken, but attempting to reinstall will cause errors. My manual way of fix is, just delete the 'unityads' folder in path/to/game-project/builds/android-native-build/game-project/ folder, and repeat steps 2 to 4 above.

### iOS

Reference:

		http://unityads.unity3d.com/help/monetization/integration-guide-ios
		http://forum.unity3d.com/threads/crash-game-for-unity-ads.289993/

1. Download SDK from: https://github.com/Applifier/unity-ads-sdk

2. Drag-and-drop the following files into your XCode project's "Frameworks" folder. Make sure to check "Copy items if needed".

		UnityAds.framework
		UnityAds.bundle

	Note: When rebuilding the project, the unityads framework and bundle link may be broken. To fix, go to your Xcode Project > Build Phases > Link Binary With Libraries, click on the "+" icon, click "Add Other...", and select the framework and bundle (it should already be in your XCode project's root folder).

3. Go to Xcode Project > Build Phases > Copy Bundle Resources, click on the "+". Search for your "UnityAds.bundle" file that you just drag-and-dropped (which should be in the Frameworks folder). This step is required, otherwise the game will crash with an error message that hints for the solution:

		Terminating app due to uncaught exception 'NSInternalInconsistencyException', reason: 'Please move the UnityAds.bundle into the Resource Directory of your Application!'

## Usage

Simple, straightforward usage in your haxe code:

	// init
	wyn.WynUnityAds.setCallbacks( ... );
	wyn.WynUnityAds.init("ad-id"); // will fetch the first ad upon init

	// show ad
	wyn.WynUnityAds.setZone("zone-id"); // optional
    wyn.WynUnityAds.show();
