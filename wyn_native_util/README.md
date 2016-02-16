# Wyn Google Analytics
Simple Google Analytics library for Kha

## Installation

### HTML5
- Copy 'wyn_ga.js' from 'wyn_ga/html5' to 'build/html5'
- Write some code (refer to Usage section below) and build your project
- In 'build/html5/index.html', add this inside <head>:

    <script type="text/javascript" src="wyn_ga.js"></script>

### Android
- Copy 'wyn_ga' folder into your kha project 'Libraries' folder
- Write some code (refer to Usage section below) and build your project
- In your android project's 'AndroidManifest.xml', add:

   <uses-permission android:name="android.permission.INTERNET"/>
   <uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>

- In the app-level 'build.gradle', add (should be inside 'model.android'):

    dependencies {
        compile 'com.google.android.gms:play-services-analytics:8.4.0'
    }

- Sync gradle project

### iOS
- none yet

## Usage

- Initialise at the beginning of your code, example:

	// HTML5, set the GA ID
    wyn.WynGA.init('XX-XXXXXXXX-X');

- Note: For android, the GA ID is set via 'google-services.json'. Refer here for instructions to get the configuration file and installation: https://developers.google.com/analytics/devguides/collection/android/v4/
- Now you can use google analytics methods, example:

	wyn.WynGA.sendEvent('advertisement', 'video', 'start');
    wyn.WynGA.sendSocial('facebook', 'feed', currentUrl);
    wyn.WynGA.sendTiming('gameplay', 'session', milisecond);