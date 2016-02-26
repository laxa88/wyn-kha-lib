package wyn_unityads_kore;

//import android.widget.Toast;
import com.ktxsoftware.kore.KoreActivity;
import com.unity3d.ads.android.IUnityAdsListener;
import com.unity3d.ads.android.UnityAds;

public class WynUnityAdsKore implements IUnityAdsListener {

	// http://unityads.unity3d.com/help/monetization/integration-guide-android

	static KoreActivity kactivity;
	static WynUnityAdsKore instance;

	public static void init (String id) {
		kactivity = KoreActivity.getInstance();
		instance = new WynUnityAdsKore();

		// example: "103000"
		UnityAds.init(kactivity, id, instance);
	}

	public static void changeActivity () {
		// use this in activity's onResume, but if behaviour is wonky, put in onCreate.
		UnityAds.changeActivity(kactivity);
	}

	public static void setDebugMode (boolean val) {
		// You can turn on debug mode on get a more verbose print of
		// what happens in UnityAds while integration. You will need
		// to recompile the SDK in order to get debug mode working
		// properly as the production libs do not include debug print
		// code at all
		UnityAds.setDebugMode(val);
	}

	public static void setTestMode (boolean val) {
		// The test mode will ensure a limitless supply of test ads
		// for integration test purposes
		UnityAds.setTestMode(val);
	}

	public static void setZone (String zone) {
		// Note: The way this API works is that you either don't call
		// setZone at all and use the default ad placement settings
		// everywhere, or you explicitly call setZone always before
		// calling show.

		// example: "12540-1392899280"
		UnityAds.setZone(zone);
	}

	public static boolean canShow () {
		// This is already used in show(), but as a safety
		// measure, you can still use this to pre-check.
		return UnityAds.canShow();
	}

	public static void show () {
		// Automatically checks whether ad can be shown, and if true, shows ad.
		if (UnityAds.canShow()) {
			UnityAds.show();
		}
	}



	public native void NativeOnHide();
	public native void NativeOnShow();
	public native void NativeOnVideoStarted();
	public native void NativeOnVideoCompleted(String itemKey, boolean skipped);
	public native void NativeOnFetchCompleted();
	public native void NativeOnFetchFailed();

	static {
		// Android Studio can only compile into one module at a time,
		// for kha, it's all in one "kore" module. So just load that up.
		System.loadLibrary("kore");
	}

    public void onHide() {
    	// Called when the Unity Ads is closed by the user
		NativeOnHide();
		// Toast.makeText(kactivity, "onHide", Toast.LENGTH_SHORT).show();
	}

	public void onShow() {
    	// Called when the Unity Ads is shown to the user
		NativeOnShow();
		// Toast.makeText(kactivity, "onShow", Toast.LENGTH_SHORT).show();
    }

	public void onVideoStarted() {
    	// Called when video playback is initiated by the user
		NativeOnVideoStarted();
		// Toast.makeText(kactivity, "onVideoStarted", Toast.LENGTH_SHORT).show();
    }

	public void onVideoCompleted(String itemKey, boolean skipped) {
    	// Called when the video playback is completed. This step also notifies you that the user should be rewarded.
		NativeOnVideoCompleted(itemKey, skipped);
		// Toast.makeText(kactivity, "onVideoCompleted : " + itemKey + "," + skipped, Toast.LENGTH_SHORT).show();
    }

	public void onFetchCompleted() {
    	// Called when ad content is loaded
		NativeOnFetchCompleted();
		// Toast.makeText(kactivity, "onFetchCompleted", Toast.LENGTH_SHORT).show();
    }

	public void onFetchFailed() {
    	// Called when ad content failed to load
		NativeOnFetchFailed();
		// Toast.makeText(kactivity, "onFetchFailed", Toast.LENGTH_SHORT).show();
    }
}
