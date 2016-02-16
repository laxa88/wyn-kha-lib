# Wyn Facebook
Simple Facebook library for Kha

## Installation

Add the following in your project's 'khafile.js':

  project.addLibrary('wyn_fb');

### HTML5

- Include the code in your html5 page, e.g.:

  <script type="text/javascript" src="wyn_fb.js"></script>

- Copy 'wyn_fb.js' into your 'builds/html5' folder

### Android

- Reference:

  https://developers.facebook.com/docs/android/getting-started/
  https://developers.facebook.com/docs/sharing/android

- Copy 'wyn_fb' folder into your kha project 'Libraries' folder
- In your android project's 'AndroidManifest.xml', add:

  <uses-permission android:name="android.permission.INTERNET"/>

- In the app-level 'build.gradle', add (should be inside 'model.android'):

  repositories {
    mavenCentral()
  }

  dependencies {
    compile 'com.facebook.android:facebook-android-sdk:4.+'
  }

- Add in 'strings.xml', usually located in 'app/src/main/res/values':

  <string name="facebook_app_id">212567345748161</string>

- Add in AndroidManifest, in <application> scope:

  <meta-data android:name="com.facebook.sdk.ApplicationId" android:value="@string/facebook_app_id"/>

  <activity android:name="com.facebook.FacebookActivity"
    android:configChanges="keyboard|keyboardHidden|screenLayout|screenSize|orientation"
    android:theme="@android:style/Theme.Translucent.NoTitleBar"
    android:label="@string/app_name" />

  <provider android:authorities="com.facebook.app.FacebookContentProvider1234"
    android:name="com.facebook.FacebookContentProvider"
    android:exported="true" />

- Replace the "1234" value with your actual facebook_app_id, e.g. if your app id is "123456781234567" then it would look like this:

  <provider android:authorities="com.facebook.app.FacebookContentProvider123456781234567"
    android:name="com.facebook.FacebookContentProvider"
    android:exported="true" />

- (optional #1) Add in KoreActivity.onCreate(), e.g.:

  FacebookSdk.sdkInitialize(this);

- (optional #2) Add resume/pause tracking (requires step #1) , e.g.:

  @Override
  protected void onResume() {
    super.onResume();

    if (FacebookSdk.isInitialized()) {
      // Logs 'install' and 'app activate' App Events.
      String facebookAppId = "212567345748161";
      AppEventsLogger.activateApp(this, facebookAppId);
      Log.d("WynKoreActivity", "onResume");
    }
  }

  @Override
  protected void onPause() {
    super.onPause();

    if (FacebookSdk.isInitialized()) {
      // Logs 'app deactivate' App Event.
      String facebookAppId = "212567345748161";
      AppEventsLogger.deactivateApp(this, facebookAppId);
      Log.d("WynKoreActivity", "onPause");
    }
  }

### iOS

- none yet

## Usage

- If you did not do optional step #1, then remember to init via haxe:

  wyn.WynFB.init();

- Simple, straightforward usage in your haxe code:

  wyn.WynFB.shareFeed(title, desc, caption);