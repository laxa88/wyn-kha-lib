// Initialise google analytics
(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

// API for WynGA.hx extern
(function() {

	window.wyn_ga = {

		init : function (id, name, enableAdvertiserTracking) {

			// for 'enableAdvertiserTracking'
			// https://developers.google.com/analytics/devguides/collection/analyticsjs/display-features
			// used for demographic tracking in my case

			// https://developers.google.com/analytics/devguides/collection/analyticsjs/creating-trackers
			// e.g.
			// id = 'UA-XXXXX-Y'
			// name = 'myTracker'
			if (name != null && name != "")
			{
				ga('create', id, 'auto', name);
				if (enableAdvertiserTracking) ga(name+'.require', 'displayfeatures');
				ga(name+'.send', 'pageview'); // e.g. myTracker.send
			}
			else
			{
				ga('create', id, 'auto');
				if (enableAdvertiserTracking) ga('require', 'displayfeatures');

				// unused for now
				// ga('create', id, 'auto', {'allowLinker': true});
				// ga('require', 'linker');
				// ga('linker:autoLink', ['funfe.com'] );

				ga('send', 'pageview');
			}

			this.isInit = true;

		},
		
		sendEvent : function (name, category, action, label, value) {

			if (!this.isInit)
			{
				console.warn('sendEvent error: wyn_ga uninitialised');
				return;
			}

			// NOTE: category is required at least
			// example: sendEvent('', 'link', 'click', 'http://example.com');
			// example: sendEvent('', 'video', 'play', 'cats.mp4');

			var sendStr = "send";
			if (name != null && name != "")
				sendStr = name + ".send"; // e.g. myTracker.send

			console.log("sendEvent : " + sendStr + " , " + category + " , " + action + " , " + label + " , " + value);

			if (action != null) {
				if (label != null) {
					if (value != null) {
						ga(sendStr, 'event', category, action, label, value);
					}
					else {
						ga(sendStr, 'event', category, action, label);
					}
				}
				else {
					ga(sendStr, 'event', category, action);
				}
			}
			else {
				ga(sendStr, 'event', category);
			}

		},

		sendSocial : function (name, network, action, target) {

			if (!this.isInit)
			{
				console.warn('sendSocial error: wyn_ga uninitialised');
				return;
			}

			// NOTE: network is required at least

			var sendStr = "send";
			if (name != null && name != "")
				sendStr = name + ".send"; // e.g. myTracker.send

			console.log("sendSocial : " + sendStr + " , " + network + " , " + action + " , " + target);

			if (action != null) {
				if (target != null) {
					ga(sendStr, 'social', network, action, target);
				}
				else {
					ga(sendStr, 'social', network, action);
				}
			}
			else {
				ga(sendStr, 'social', network);
			}

		},

		sendTiming : function (name, category, variable, value, label) {

			if (!this.isInit)
			{
				console.warn('sendTiming error: wyn_ga uninitialised');
				return;
			}

			// NOTE: category is required at least

			var sendStr = "send";
			if (name != null && name != "")
				sendStr = name + ".send"; // e.g. myTracker.send

			console.log("sendTiming : " + sendStr + " , " + category + " , " + variable + " , " + value + " , " + label);

			if (variable != null) {
				if (value != null) {
					if (label != null) {
						ga(sendStr, 'timing', category, variable, value, label);
					}
					else {
						ga(sendStr, 'timing', category, variable, value);
					}
				}
				else {
					ga(sendStr, 'timing', category, variable);
				}
			}
			else {
				ga(sendStr, 'timing', category);
			}

		}

	};

})();

