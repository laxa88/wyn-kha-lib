# Wyn Google Analytics
Simple Google Analytics library for Kha

## Installation

1. Copy the 'wyn_ga' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_ga');

### HTML5 (additional steps)

1. Include the code in your html5 page, typically after including 'kha.js':

		<script type="text/javascript" src="wyn_ga.js"></script>

2. Manually copy 'wyn_ga.js' from 'wyn_ga/html5' into your 'builds/html5' folder
3. Note: The Google Analytics init code (below) is already included in 'wyn_ga.js'. Remove the snippet if you already have it somewhere else in the html:

		// Initialise google analytics
		(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
		(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
		m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
		})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

### Android (Android Studio additional steps)

1. In your android project's 'AndroidManifest.xml', add:

		<uses-permission android:name="android.permission.INTERNET"/>
		<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>

2. In the app-level 'build.gradle', add (should be inside 'model.android') the dependency:

		dependencies {
			compile 'com.google.android.gms:play-services-analytics:8.4.0'
		}

3. Add in 'AndroidManifest.xml' (usually right before your <application> tag):

		<uses-permission android:name="android.permission.INTERNET"/>
		<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>

4. Add the dependency in your project-level 'build.gradle':

		dependencies {
			classpath 'com.google.gms:google-services:2.0.0-alpha6'
		}

5. Apply the dependency in your app-level 'build.grade' (usually just prepend at the first line):

		apply plugin: 'com.google.gms.google-services'

6. Add the dependency in your app-level 'build.gradle':

		// If this section doesn't exist, you can add it in right after 'defaultConfig.with{ ... }'
		dependencies {
			compile 'com.google.android.gms:play-services-analytics:8.4.0'
		}

7. Get the configuration ('google-services.json') file. The Google Analytics ID is set via the config file. Refer here for instructions to get the config file:

		https://developers.google.com/analytics/devguides/collection/android/v4/

8. Paste the config file into your app-level folder, e.g.:

		/path/to/game-project/build/android-native-build/game-project/app

### iOS

- none yet

## Usage

1. Initialise at the beginning of your code, example:

		wyn.WynGA.init('XX-XXXXXXXX-X');

2. Now you can use google analytics methods, example:

		wyn.WynGA.sendEvent('advertisement', 'video', 'start');
		wyn.WynGA.sendSocial('facebook', 'feed', currentUrl);
		wyn.WynGA.sendTiming('gameplay', 'session', milisecond);


