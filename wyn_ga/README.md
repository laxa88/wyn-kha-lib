# Wyn Google Analytics
Simple Google Analytics library for Kha

## Installation

Add the following in your project's 'khafile.js':

  project.addLibrary('wyn_ga');

### HTML5

- Include the code in your html5 page, e.g.:

  <script type="text/javascript" src="wyn_fb.js"></script>

- Copy 'wyn_fb.js' into your 'builds/html5' folder

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


