package wyn_ga_kore;

import android.util.Log;
import com.ktxsoftware.kore.KoreActivity;
import com.google.android.gms.analytics.HitBuilders;
import com.google.android.gms.analytics.GoogleAnalytics;
import com.google.android.gms.analytics.Tracker;

// References:
// https://developers.google.com/analytics/devguides/collection/android/v4/
// http://stackoverflow.com/questions/30527369/error-could-not-find-com-google-gmsgoogle-services1-0-when-adding-google-ser
// https://guides.codepath.com/android/Getting-Started-with-Gradle

public class WynGAKore {
	private static Tracker mTracker;

	synchronized public static void init (String id, boolean enableAdvertisingTracking) {
		// NOTE: id isn't used, because it's set from 'google-services.json' config
		// file, refer to this link for instructions to get the json:
		// https://developers.google.com/analytics/devguides/collection/android/v4/

		// Obtain the shared Tracker instance.
		if (mTracker == null) {
			KoreActivity activity = KoreActivity.getInstance();
			GoogleAnalytics analytics = GoogleAnalytics.getInstance(activity);
			mTracker = analytics.newTracker("default");

            if (enableAdvertisingTracking) {
                // https://support.google.com/analytics/answer/2444872?hl=en&utm_id=ad#web
                mTracker.enableAdvertisingIdCollection(true);
            }
		}

		Log.d("WynLog", "WynGAKore init : " + id);
	}

	public static void sendEvent (String category, String action, String label, String value) {
        if (mTracker == null) {
            Log.e("WynLog", "sendEvent error, mTracker is null");
            return;
        }

        HitBuilders.EventBuilder builder = new HitBuilders.EventBuilder();
        if (category != null) builder.setCategory(category);
        if (action != null) builder.setAction(action);
        if (label != null) builder.setLabel(label);
        if (value != null) builder.setValue(Long.parseLong(value));
        mTracker.send(builder.build());

        Log.d("WynLog", "WynGAKore sendEvent : " + category + " , " + action + " , " + label + " , " + value);
	}

	public static void sendSocial (String network, String action, String target) {
        if (mTracker == null) {
            Log.e("WynLog", "sendSocial error, mTracker is null");
            return;
        }

        HitBuilders.SocialBuilder builder = new HitBuilders.SocialBuilder();
        if (network != null) builder.setNetwork(network);
        if (action != null) builder.setAction(action);
        if (target != null) builder.setTarget(target);
        mTracker.send(builder.build());

		Log.d("WynLog", "WynGAKore sendSocial : " + network + " , " + action + " , " + target);
	}

	public static void sendTiming (String category, String variable, String value, String label) {
        if (mTracker == null) {
            Log.e("WynLog", "sendTiming error, mTracker is null");
            return;
        }

        HitBuilders.TimingBuilder builder = new HitBuilders.TimingBuilder();
        if (category != null) builder.setCategory(category);
        if (variable != null) builder.setVariable(variable);
        if (value != null) builder.setValue(Long.parseLong(value));
        if (label != null) builder.setLabel(label);
        mTracker.send(builder.build());

		Log.d("WynLog", "WynGAKore sendTiming : " + category + " , " + variable + " , " + value + " , " + label);
	}
}
