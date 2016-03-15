# Wyn Facebook
Simple Facebook library for Kha

## Installation

1. Copy the 'wyn_fb' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_fb');

### HTML5 (additional steps)

1. Include this code in your index.html, typically after including 'kha.js':

		<script type="text/javascript" src="wyn_fb.js"></script>

2. Manually copy 'wyn_fb.js' from 'wyn_fb/html5' into your 'builds/html5' folder

3. Don't forget to include the SDK code (directly after the opening <body>):

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

### Android (Android Studio additional steps)

Reference:

	https://developers.facebook.com/docs/android/getting-started/
	https://developers.facebook.com/docs/sharing/android

1. In your android project's 'AndroidManifest.xml', add:

		<uses-permission android:name="android.permission.INTERNET"/>

2. In the app-level 'build.gradle', add (should be inside 'model.android'):

		repositories {
			mavenCentral()
		}

		dependencies {
			compile 'com.facebook.android:facebook-android-sdk:4.+'
		}

3. Add in 'strings.xml', usually located in 'app/src/main/res/values':

		<string name="facebook_app_id">123456781234567</string>

4. Add in 'AndroidManifest.xml', in <application> scope:

		<meta-data android:name="com.facebook.sdk.ApplicationId" android:value="@string/facebook_app_id"/>

		<activity android:name="com.facebook.FacebookActivity"
			android:configChanges="keyboard|keyboardHidden|screenLayout|screenSize|orientation"
			android:theme="@android:style/Theme.Translucent.NoTitleBar"
			android:label="@string/app_name" />

		<provider android:authorities="com.facebook.app.FacebookContentProvider1234"
			android:name="com.facebook.FacebookContentProvider"
			android:exported="true" />

5. Replace the "1234" value with your actual facebook_app_id, e.g. if your app id is "123456781234567" then it would look like this:

		<provider android:authorities="com.facebook.app.FacebookContentProvider123456781234567"
			android:name="com.facebook.FacebookContentProvider"
			android:exported="true" />

6. (optional #1) Add in KoreActivity.onCreate(), e.g.:

		FacebookSdk.sdkInitialize(this);

7. (optional #2) Add resume/pause tracking (requires optional #1) , e.g.:

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

Reference:

	https://developers.facebook.com/docs/ios/getting-started
	https://developers.facebook.com/docs/sharing/ios

1. Download the Facebook SDK for iOS

		https://developers.facebook.com/docs/ios

2. Drag-and-drop the following files into your XCode project's "Frameworks" folder. Note: I tried using "Link Binary With Libraries" to add the frameworks, but it didn't work, hence I had to drag-and-drop.

		FBSDKCoreKit.Framework
		FBSDKLoginKit.Framework
		FBSDKShareKit.Framework

3. Navigate to your FB app's setup page and add the necessary info to your plist file:

		// replace "app-id" with your app number, e.g. 123456789012345
		https://developers.facebook.com/quickstarts/app-id/?platform=ios

4. If you don't know where your plist file is, go to "Build Settings" tab in your XCode project, and look for "Info.plist File" line, note where the plist file is (for kha's case, it's called "ios.plist"), and navigate to the path accordingly.

5. Here is the example of info appended in my ios.plist for my project:

		<key>CFBundleURLTypes</key>
		<array>
			<dict>
			<key>CFBundleURLSchemes</key>
			<array>
				<string>fb123456789012345</string>
			</array>
			</dict>
		</array>
		<key>FacebookAppID</key>
		<string>123456789012345</string>
		<key>FacebookDisplayName</key>
		<string>Wy-Game</string>

6. The following needs to be appended to ios.plist because we are using Facebook Dialogs for the link sharing. Otherwise, your game will crash when attempting to use the Share Dialog feature.

		<key>LSApplicationQueriesSchemes</key>
		<array>
			<string>fbapi</string>
			<string>fb-messenger-api</string>
			<string>fbauth2</string>
			<string>fbshareextension</string>
		</array>

## Usage

1. If you did not do optional step #1, then remember to init via haxe:

		// Note: The FB app id is only used in HTML5 in case the FB API
		// is not loaded. The app id is normally initialised outside the code.
		// For HTML5, it's in your FB.init() code
		// For Android, it's in your Manifest and strings.xml
		// For iOS, it's in your plist file

		wyn.WynFB.init("123456781234567");

2. Simple, straightforward usage in your haxe code:

		wyn.WynFB.shareFeed("My Game Name", "My Game Description", "http://example.com", "http://example.com/mypreviewimage.png");
