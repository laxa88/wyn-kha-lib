package wyn_tw_kore;

import android.content.Intent;
import android.net.Uri;
import android.util.Log;

import com.ktxsoftware.kore.KoreActivity;

public class WynTWKore {
	public static void tweet (String message) {

		// http://stackoverflow.com/questions/2077008/android-intent-for-twitter-application
        // http://stackoverflow.com/questions/14664763/android-sharing-on-twitter
        // Opens the "choose application" window, which allows users to select
        // Twitter or normal browsers to tweet the message.

        KoreActivity activity = KoreActivity.getInstance();
        String tweetUrl = "https://twitter.com/intent/tweet?text=" + Uri.encode(message);
        Uri uri = Uri.parse(tweetUrl);
        activity.startActivity(new Intent(Intent.ACTION_VIEW, uri));

		Log.d("WynLog", "WynTWKore tweet : " + message);
	}
}
