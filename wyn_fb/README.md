# Wyn Facebook
Simple Facebook library for Kha

## Installation

1. Copy the 'wyn_fb' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_fb');

3. (html5) Include this code in your index.html, typically after including 'kha.js':

		<script type="text/javascript" src="wyn_fb.js"></script>

4. (html5) Manually copy 'wyn_fb.js' from 'wyn_fb/html5' into your 'builds/html5' folder

5. (html5) Don't forget to include the SDK code (directly after the opening <body>):

		// refer to: https://developers.facebook.com/docs/javascript/quickstart/v2.5

		<script>
			window.fbAsyncInit = function() {
				FB.init({
					appId      : 'your-app-id',
					xfbml      : true,
					version    : 'v2.5'
				});
			};

			(function(d, s, id){
				var js, fjs = d.getElementsByTagName(s)[0];
				if (d.getElementById(id)) {return;}
				js = d.createElement(s); js.id = id;
				js.src = "//connect.facebook.net/en_US/sdk.js";
				fjs.parentNode.insertBefore(js, fjs);
			}(document, 'script', 'facebook-jssdk'));
		</script>

### Android

Reference:

	https://developers.facebook.com/docs/android/getting-started/
	https://developers.facebook.com/docs/sharing/android

1. Copy 'wyn_fb' folder into your kha project 'Libraries' folder
2. In your android project's 'AndroidManifest.xml', add:

		<uses-permission android:name="android.permission.INTERNET"/>

3. In the app-level 'build.gradle', add (should be inside 'model.android'):

		repositories {
			mavenCentral()
		}

		dependencies {
			compile 'com.facebook.android:facebook-android-sdk:4.+'
		}

4. Add in 'strings.xml', usually located in 'app/src/main/res/values':

		<string name="facebook_app_id">123456781234567</string>

5. Add in 'AndroidManifest.xml', in <application> scope:

		<meta-data android:name="com.facebook.sdk.ApplicationId" android:value="@string/facebook_app_id"/>

		<activity android:name="com.facebook.FacebookActivity"
			android:configChanges="keyboard|keyboardHidden|screenLayout|screenSize|orientation"
			android:theme="@android:style/Theme.Translucent.NoTitleBar"
			android:label="@string/app_name" />

		<provider android:authorities="com.facebook.app.FacebookContentProvider1234"
			android:name="com.facebook.FacebookContentProvider"
			android:exported="true" />

6. Replace the "1234" value with your actual facebook_app_id, e.g. if your app id is "123456781234567" then it would look like this:

		<provider android:authorities="com.facebook.app.FacebookContentProvider123456781234567"
			android:name="com.facebook.FacebookContentProvider"
			android:exported="true" />

7. (optional #1) Add in KoreActivity.onCreate(), e.g.:

		FacebookSdk.sdkInitialize(this);

8. (optional #2) Add resume/pause tracking (requires optional #1) , e.g.:

		@Override
		protected void onResume() {
			super.onResume();

			if (FacebookSdk.isInitialized()) {
				// Logs 'install' and 'app activate' App Events.
				String facebookAppId = "123456781234567";
				AppEventsLogger.activateApp(this, facebookAppId);
				Log.d("WynKoreActivity", "onResume");
			}
		}

		@Override
		protected void onPause() {
			super.onPause();

			if (FacebookSdk.isInitialized()) {
				// Logs 'app deactivate' App Event.
				String facebookAppId = "123456781234567";
				AppEventsLogger.deactivateApp(this, facebookAppId);
				Log.d("WynKoreActivity", "onPause");
			}
		}

### iOS

- none yet

## Usage

1. If you did not do optional step #1, then remember to init via haxe:

		wyn.WynFB.init("123456781234567");

2. Simple, straightforward usage in your haxe code:

		wyn.WynFB.shareFeed(title, desc, caption);
		// example
		wyn.WynFB.shareFeed("My Game Name", "My Game Description", "http://www.example.com");
