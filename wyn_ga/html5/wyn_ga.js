// Initialise google analytics
(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
})(window,document,'script','//www.google-analytics.com/analytics.js','ga');

// API for WynGA.hx extern
(function() {

	window.wyn_ga = {

		init : function (id, enableAdvertiserTracking) {

			ga('create', id, 'auto'); // Coinflip studios GA id
			if (enableAdvertiserTracking) ga('require', 'displayfeatures');
			ga('send', 'pageview');
			this.isInit = true;

		},
		
		sendEvent : function (category, action, label, value) {

			if (!this.isInit)
			{
				console.warn('sendEvent error: wyn_ga uninitialised');
				return;
			}

			// NOTE: category is required at least

			// example: sendEvent('link', 'click', 'http://example.com');
			// example: sendEvent('video', 'play', 'cats.mp4');

			console.log("sendEvent : " + category + " , " + action + " , " + label + " , " + value);

			if (action != null) {
				if (label != null) {
					if (value != null) {
						ga('send', 'event', category, action, label, value);
					}
					else {
						ga('send', 'event', category, action, label);
					}
				}
				else {
					ga('send', 'event', category, action);
				}
			}
			else {
				ga('send', 'event', category);
			}

		},

		sendSocial : function (network, action, target) {

			if (!this.isInit)
			{
				console.warn('sendSocial error: wyn_ga uninitialised');
				return;
			}

			// NOTE: network is required at least

			console.log("sendSocial : " + network + " , " + action + " , " + target);

			if (action != null) {
				if (target != null) {
					ga('send', 'social', network, action, target);
				}
				else {
					ga('send', 'social', network, action);
				}
			}
			else {
				ga('send', 'social', network);
			}

		},

		sendTiming : function (category, variable, value, label) {

			if (!this.isInit)
			{
				console.warn('sendTiming error: wyn_ga uninitialised');
				return;
			}

			// NOTE: category is required at least

			console.log("sendTiming : " + category + " , " + variable + " , " + value + " , " + label);

			if (variable != null) {
				if (value != null) {
					if (label != null) {
						ga('send', 'timing', category, variable, value, label);
					}
					else {
						ga('send', 'timing', category, variable, value);
					}
				}
				else {
					ga('send', 'timing', category, variable);
				}
			}
			else {
				ga('send', 'timing', category);
			}

		}

	};

})();

