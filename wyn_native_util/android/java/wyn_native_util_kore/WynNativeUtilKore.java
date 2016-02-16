package wyn_native_util_kore;

import android.content.Intent;
import android.net.Uri;
import android.util.Log;
import com.ktxsoftware.kore.KoreActivity;

public class WynNativeUtilKore {
    public static void openUrl (String url) {

        Intent i = new Intent(Intent.ACTION_VIEW);
        i.setData(Uri.parse(url));
        KoreActivity activity = KoreActivity.getInstance();
        activity.startActivity(i);

        Log.d("WynLog", "WynNativeUtilKore openUrl : " + url);
    }
}
