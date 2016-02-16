(function() {

	var canvas = document.getElementById("khanvas");

	if (typeof google === 'undefined')
		google = null;



	var khanvas = document.getElementById('khanvas');
	var mainAdContainer = document.getElementById('mainAdContainer');
	var adContainer = document.getElementById('adContainer');
	var adDisplayContainer = null;
	var adsManager = null;
	var adsLoader = null;
	var adsRequest = null;

	if (google)
	{
		adDisplayContainer = new google.ima.AdDisplayContainer(adContainer, khanvas);
		adsManager = null;

		// Re-use this AdsLoader instance for the entire lifecycle of your page.
		adsLoader = new google.ima.AdsLoader(adDisplayContainer);

		// Add event listeners
		adsLoader.addEventListener(google.ima.AdsManagerLoadedEvent.Type.ADS_MANAGER_LOADED, onAdsManagerLoaded, false);
		adsLoader.addEventListener(google.ima.AdErrorEvent.Type.AD_ERROR, onAdError, false);

		// NOTE: game has no post-roll state, so ignore any tutorials
		// that deal with handling post-roll ads via videoContent.onended

		// Request video ads.
		adsRequest = new google.ima.AdsRequest();
		// adsRequest.adTagUrl = 'https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dlinear&correlator=';
		adsRequest.adTagUrl = 'http://googleads.g.doubleclick.net/pagead/ads?ad_type=video&client=ca-games-pub-4968145218643279&videoad_start_delay=0&description_url=http%3A%2F%2Fwww.google.com&max_ad_duration=40000&adtest=on';
		// adsRequest.adTagUrl = 'http://googleads.g.doubleclick.net/pagead/ads?ad_type=video_image_flash_text&client=ca-video-pub-4968145218643279&videoad_start_delay=0&description_url=http%3A%2F%2Fwww.google.com&max_ad_duration=40000';
		// adsRequest.adTagUrl = 'http://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/ad_rule_samples&ciu_szs=300x250&ad_rule=1&impl=s&gdfp_req=1&env=vp&output=xml_vmap1&unviewed_position_start=1&cust_params=sample_ar%3Dpremidpostpod%26deployment%3Dgmf-js&cmsid=496&vid=short_onecue&correlator=';

		// Specify the linear and nonlinear slot sizes. This helps the SDK to
		// select the correct creative if multiple are returned.
		adsRequest.linearAdSlotWidth = 640;
		adsRequest.linearAdSlotHeight = 400;
		adsRequest.nonLinearAdSlotWidth = 640;
		adsRequest.nonLinearAdSlotHeight = 150;
	}
	else
	{
		console.warn("google API not initialised; is it blocked?");
	}



	function onAdError(adErrorEvent) {

		if (!google)
			return;

		// resume game
		onContentResumeRequested();
	}

	function onAdsManagerLoaded(adsManagerLoadedEvent) {

		if (!google)
			return;

		// See API reference for contentPlayback
		adsManager = adsManagerLoadedEvent.getAdsManager(khanvas); 

		var skippable = adsManager.getAdSkippableState();
		// console.log("skippable : " + skippable);
		// TODO
		// if true, show and enable the skip button
		// if false, hide and disable the skip button

		adsManager.addEventListener(google.ima.AdErrorEvent.Type.AD_ERROR, onAdError);
		adsManager.addEventListener(google.ima.AdEvent.Type.CONTENT_PAUSE_REQUESTED, onContentPauseRequested);
		adsManager.addEventListener(google.ima.AdEvent.Type.CONTENT_RESUME_REQUESTED, onContentResumeRequested);

		try
		{
			// console.log("init adsManager");
			// Initialize the ads manager. Ad rules playlist will start at this time.
			adsManager.init(320, 180, google.ima.ViewMode.NORMAL);
			
			// Call start to show ads. Single video and overlay ads will
			// start at this time; this call will be ignored for ad rules, as ad rules
			// ads start when the adsManager is initialized.
			adsManager.start();

		}
		catch (adError)
		{
			// An error may be thrown if there was a problem with the VAST response.
			console.log(adError);
		}
	}

	function onContentPauseRequested(event) {

		// This is called before the ad is played. Do the game-pausing
		// and other stuff here to prepare for the ad before it shows up.

		if (!google)
			return;

		mainAdContainer.style.backgroundColor = "#000000";

		window.addEventListener("resize", updateAdSize);

		updateAdSize();
	}

	function onContentResumeRequested() {

		// The ad is done playing, so do the game resuming stuff here.

		if (!google)
			return;

		window.removeEventListener("resize", updateAdSize);

		// Reset ad to original size
		mainAdContainer.style.backgroundColor = "";
		adContainer.parentNode.style.width = "320px";
		adContainer.parentNode.style.height = "180px";

		// because the ad container is on top of khanvas and blocks
		// user actions, hide ad container when ad is done.
		mainAdContainer.style.display = "none";

		// Resume game here
		WynGame.onAdComplete();

		// Handle the error logging and destroy the AdsManager
		adsLoader.contentComplete();

		// handle for times when adsManager did not
		// load (slow internet, popup blocker...)
		if (adsManager != null)
		{
			adsManager.resize(320, 180, google.ima.ViewMode.NORMAL);
			adsManager.destroy();
		}
	}




	function updateAdSize () {

		// Makes sure the ad always fits to the screen
		// especially when on mobile device, after screen rotation.

		if (!google)
			return;

		var windowW = window.innerWidth;
		var ratio = 320 / windowW;

		if (ratio < 0.5)
			ratio = 0.5;

		var finalW = 320 / ratio;
		var finalH = 180 / ratio;

		adContainer.parentNode.style.width = finalW+"px";
		adContainer.parentNode.style.height = finalH+"px";
		adsManager.resize(finalW, finalH, google.ima.ViewMode.NORMAL);
	}



	window.wyn_ima = {

		init : function () {

			console.log("wyn_ima init");

			if (!google)
				return false;

			adDisplayContainer.initialize();

			// Hide the ad so it doesn't block game input
			mainAdContainer.style.display = "none";

			return true;

		},

		show : function () {

			console.log("wyn_ima show");

			if (!google)
				return false;

			// Show the ad container, which will also block input
			mainAdContainer.style.display = "";

			// In case init() wasn't called, this will confirm it
			adDisplayContainer.initialize();

			adsLoader.requestAds(adsRequest);

			return true;

		}
	};

})();

