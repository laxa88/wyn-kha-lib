# Wyn Interactive Media Ads (IMA)
Simple Google IMA library for Kha

## TODO

- Android-Native version

## Installation

1. Copy the 'wyn_ima' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_ima');

### HTML5 (additional steps)

1. Include this code in your index.html, typically after including 'kha.js':

		<script type="text/javascript" src="wyn_ima.js"></script>

2. Manually copy 'wyn_ima.js' from 'wyn_ima/html5' into your 'builds/html5' folder

3. Include the Google 'ima.js' code, before including 'wyn_ima.js':

		// refer to: https://developers.google.com/interactive-media-ads/docs/sdks/html5/quickstart
		<script type="text/javascript" src="//imasdk.googleapis.com/js/sdkloader/ima3.js"></script>

4. Additional manual step (TODO - I need to remove this part later); Find the code below in 'wyn_ima.js', and replace it with your own javascript callback code for when the ad is finished showing:

        // Resume game here
		WynGame.onAdComplete();

### Android (Android Studio additional steps)

- none yet

### iOS

- none yet

## Usage

1. Simple, straightforward usage in your haxe code:

        if (!wyn.WynIMA.init()) {
			trace("WynIMA not loaded");
		}
		
		if (!wyn.WynIMA.show()) {
			trace("WynIMA not shown");
		}
