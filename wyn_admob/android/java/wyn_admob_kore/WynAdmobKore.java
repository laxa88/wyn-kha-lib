package wyn_admob_kore;

import android.content.res.Resources;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.Toast;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.InterstitialAd;
import com.ktxsoftware.kore.KoreActivity;

import java.util.HashMap;
import java.util.Map;

public class WynAdmobKore {

	// http://stackoverflow.com/questions/12670266/view-in-native-activity
	// http://www.dynadream.com/ddweb/index.php/Special_Blog?id=20
	// http://stackoverflow.com/questions/5255184/android-and-setting-width-and-height-programmatically-in-dp-units

	private static KoreActivity kactivity;
	private static AdRequest adReq;
	private static Map<String, WynAdmobData> bannerDict;
	private static LinearLayout ml;
	private static ViewGroup.MarginLayoutParams viewParams;



	public static void init () {

		kactivity = KoreActivity.getInstance();

		// Build the generic ad request
		adReq = new AdRequest.Builder()
			.addTestDevice(AdRequest.DEVICE_ID_EMULATOR)
			.addTestDevice("AC98C820A50B4AD8A2106EDE96FB87D4")
			.build();

		bannerDict = new HashMap<String, WynAdmobData>();

		viewParams = new ViewGroup.MarginLayoutParams(
				ViewGroup.LayoutParams.MATCH_PARENT,
				ViewGroup.LayoutParams.MATCH_PARENT);
		viewParams.setMargins(0, 0, 0, 0);

		// Create layout for the popup
		ml = new LinearLayout(kactivity);
	}

	// public static void setCallbacks ()
	// {
	// }

	public static void createBanner (String adName, String adUnitId, String adType, String adGravity) {

		Log.d("WynLog", "WynAdmobKore createAd : " + adType + " , " + adUnitId + " , " + adGravity);

		AdSize size = AdSize.BANNER;
		switch (adType) {
			case "BANNER": size = AdSize.BANNER; break;
			case "FLUID": size = AdSize.FLUID; break;
			case "FULL_BANNER": size = AdSize.FULL_BANNER; break;
			case "LARGE_BANNER": size = AdSize.LARGE_BANNER; break;
			case "LEADERBOARD": size = AdSize.LEADERBOARD; break;
			case "MEDIUM_RECTANGLE": size = AdSize.MEDIUM_RECTANGLE; break;
			case "SMART_BANNER": size = AdSize.SMART_BANNER; break;
			case "WIDE_SKYSCRAPER": size = AdSize.WIDE_SKYSCRAPER; break;
			default:
				Log.d("WynLog", "WynAdmobKore unhandled adType : " + adType);
				break;
		}

		int gravity = Gravity.CENTER;
		switch (adGravity) {
			case "TOP": gravity = Gravity.TOP; break;
			case "CENTER": gravity = Gravity.CENTER; break;
			case "BOTTOM": gravity = Gravity.BOTTOM; break;
			case "LEFT": gravity = Gravity.LEFT; break;
			case "RIGHT": gravity = Gravity.RIGHT; break;

			// TODO : handle other cases

			default:
				Log.d("WynLog", "WynAdmobKore unhandled adGravity : " + adGravity);
		}



		AdView adView = new AdView(kactivity);
		adView.setAdUnitId(adUnitId); // Example from google: "ca-app-pub-3940256099942544/6300978111"
		adView.setAdSize(size);
		adView.setAdListener(new AdListener() {
			public void onAdLoaded() {

				Log.d("WynLog", "Ad banner loaded");
				// Toast.makeText(kactivity, "Ad banner loaded", Toast.LENGTH_LONG).show();

				// TODO
			}

			public void onAdFailedToLoad(int errorcode) {

				Log.d("WynLog", "Fail to get Banner: " + errorcode);

				// TODO notify or callback when this happens
			}
		});



		// Build the adview on the UI thread
		final String uiAdName = adName;
		final AdView uiAdView = adView;
		final int uiAdGravity = gravity;
		final String uiAdType = adType;

		kactivity.runOnUiThread(new Runnable() {
			public void run() {

				Log.d("WynLog", "Creating adview UI...");

				// Create generic popup on top of game
				PopupWindow popup = new PopupWindow(kactivity);

				int padding = 10;
				int oriW = 320 + padding;
				int oriH = 50 + padding;

				// https://developers.google.com/android/reference/com/google/android/gms/ads/AdSize
				// https://developers.google.com/admob/android/banner?hl=en_US
				switch (uiAdType) {
					case "BANNER":
						oriW = 320 + padding;
						oriH = 50 + padding;
						break;

					case "FULL_BANNER":
						oriW = 468 + padding;
						oriH = 60 + padding;
						break;

					case "LARGE_BANNER":
						oriW = 320 + padding;
						oriH = 100 + padding;
						break;

					case "LEADERBOARD":
						oriW = 728 + padding;
						oriH = 90 + padding;
						break;

					case "MEDIUM_RECTANGLE":
						oriW = 300 + padding;
						oriH = 250 + padding;
						break;

					case "WIDE_SKYSCRAPER":
						oriW = 160 + padding;
						oriH = 600 + padding;
						break;
				}

				// Set size via dp instead of px.
				Resources r = kactivity.getResources();
				final float scale = r.getDisplayMetrics().density;
				// NOTE: actual minimum size is 320x50, but somehow the calculation
				// for this is never correct (returns 317x49, which is not big enough
				// to show the adView). As such, I add some padding.
				int dpW = (int) (oriW * scale);
				int dpH = (int) (oriH * scale);
				popup.setWidth(dpW);
				popup.setHeight(dpH);
				popup.setClippingEnabled(false);

				LinearLayout ll = new LinearLayout(kactivity);
				ll.setOrientation(LinearLayout.VERTICAL);
				// The layout system for the PopupWindow will kill some pixels due
				// to margins/paddings etc… (No way to remove it), so pad it to adjust.
				// ll.setPadding(-5, -5, -5, -5); // NOTE: these are px, not dp, so it can't be used...

				ll.addView(uiAdView, viewParams);
				popup.setContentView(ll);
				kactivity.setContentView(ml, viewParams);

				// Show the popup window
				// [activity > ml] > [popup > ll > adView]
				// popup.showAtLocation(ml, uiAdGravity, 0, 0);
				// popup.update();

				// you can only load the banner's ad inside the UI thread
				uiAdView.loadAd(adReq);
				uiAdView.setVisibility(View.VISIBLE);

				// Save banner data to dictionary for toggling later
				WynAdmobData data = new WynAdmobData();
				data.gravity = uiAdGravity;
				data.popup = popup;
				bannerDict.put(uiAdName, data);
			}
		});
	}

	public static void toggleBanner (String adName, boolean visible) {

		// Modify the code here accordingly, make sure bannerId matches
		// the bannerIds created in init() above.

		if (bannerDict.containsKey(adName)) {

			final WynAdmobData data = bannerDict.get(adName);

			if (visible) {
				kactivity.runOnUiThread(new Runnable() {
					public void run() {
						data.popup.showAtLocation(ml, data.gravity, 0, 0);
						data.popup.update();
					}
				});
			}
			else {
				kactivity.runOnUiThread(new Runnable() {
					public void run() {
						data.popup.dismiss();
					}
				});
			}

			Log.d("WynLog", "WynAdmobKore toggled : " + adName + " , " + visible);
		}
		else
		{
			Log.d("WynLog", "WynAdmobKore toggle not found : " + adName);
		}
	}

	public static void createInterstitial (String adUnitId) {

		Log.d("WynLog", "Creating interstitial...");

		final InterstitialAd interstitial;
		interstitial = new InterstitialAd(kactivity);
		interstitial.setAdUnitId(adUnitId);
		interstitial.setAdListener(new AdListener() {
			public void onAdLoaded() {

				Log.d("WynLog", "interstitial onAdLoaded");
				// Toast.makeText(kactivity, "interstitial onAdLoaded", Toast.LENGTH_SHORT).show();

				// TODO don't show immediately. Do a callback and let user handle manually.
				interstitial.show();
			}

			public void onAdFailedToLoad(int errorcode) {
				Log.d("WynLog", "interstitial onAdFailedToLoad: " + errorcode);
				// Toast.makeText(kactivity, "onAdFailedToLoad", Toast.LENGTH_SHORT).show();
				// TODO Do a callback and let user handle manually.
			}

			public void onAdClosed() {
				Log.d("WynLog", "onAdClosed");
				// Toast.makeText(kactivity, "interstitial onAdClosed", Toast.LENGTH_SHORT).show();
				// TODO Do a callback and let user handle manually.
			}
		});

		kactivity.runOnUiThread(new Runnable() {
			public void run() {

				Log.d("WynLog", "createInterstitial");
				// Toast.makeText(kactivity, "createInterstitial", Toast.LENGTH_SHORT).show();
				interstitial.loadAd(adReq);

			}
		});
	}

	public static void showInterstitial () {
	}
}
