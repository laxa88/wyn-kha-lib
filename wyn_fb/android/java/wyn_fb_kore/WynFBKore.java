package wyn_fb_kore;

import android.content.Intent;
import android.net.Uri;
import android.util.Log;

// import com.facebook.CallbackManager;
// import com.facebook.FacebookActivity;
// import com.facebook.FacebookCallback;
// import com.facebook.FacebookException;
// import com.facebook.share.Sharer;
import com.facebook.share.model.ShareLinkContent;
import com.facebook.share.widget.ShareDialog;
import com.ktxsoftware.kore.KoreActivity;
import com.facebook.FacebookSdk;

/*

Installation
https://developers.facebook.com/docs/android/getting-started

1) in AndroidManifest.xml, add this inside <application>:

	<uses-permission android:name="android.permission.INTERNET"/>

2) In app-level build.gradle, add this before 'dependencies':

	repositories {
		mavenCentral()
	}

3) In app-level build.gradle, add this in model.android (after defaultConfig)

	dependencies {
		compile 'com.facebook.android:facebook-android-sdk:4.+'
	}

4) Make sure to gradle sync doesn't produce errors

*/

public class WynFBKore {
	public static void init () {

		KoreActivity activity = KoreActivity.getInstance();
		FacebookSdk.sdkInitialize(activity);

		// NOTE:
		// Facebook app Id is defined in the AndroidManifest.xml
		// https://developers.facebook.com/docs/android/getting-started/

		/*
		// Use this inside an activity's OnResume and OnPause to record app usage
		if (FacebookSdk.isInitialized()) {
			// Logs 'app deactivate' App Event.
			String facebookAppId = "145634995501895"; // FB debug app Id
			AppEventsLogger.deactivateApp(this, facebookAppId);
			Log.d("WynKoreActivity", "onPause");
		}
		*/

		Log.d("WynLog", "WynFBKore init");
	}

	public static void shareFeed (String title, String desc, String caption, String pictureUrl) {

		ShareLinkContent.Builder builder = new ShareLinkContent.Builder();
		if (title != null) builder.setContentTitle(title);
		if (desc != null) builder.setContentDescription(desc);
		// NOTE: for android, caption is the URL of the HTML5 game's page OR the app store link, TBD by developer
		// e.g. "http://funfe.com"
		if (caption != null) builder.setContentUrl(Uri.parse(caption)); // e.g. "https://developers.facebook.com"
		if (pictureUrl != null) builder.setImageUrl(Uri.parse(pictureUrl));
		ShareLinkContent content = builder.build();

		KoreActivity activity = KoreActivity.getInstance();
		ShareDialog dialog = new ShareDialog(activity);

		// CallbackManager cbManager = CallbackManager.Factory.create();
		// dialog.registerCallback(cbManager, new FacebookCallback<Sharer.Result>() {
		//     @Override
		//     public void onSuccess(Sharer.Result result) {
		//         Log.d("WynLog", "WynFBKore CB onSuccess : " + result.toString());
		//     }

		//     @Override
		//     public void onCancel() {
		//         Log.d("WynLog", "WynFBKore CB onCancel");
		//     }

		//     @Override
		//     public void onError(FacebookException error) {
		//         Log.d("WynLog", "WynFBKore CB onError : " + error.toString());
		//     }
		// });

		dialog.show(content);

		Log.d("WynLog", "WynFBKore shareFeed : " + title + " , " + desc + " , " + caption + " , " + pictureUrl);
	}
}
