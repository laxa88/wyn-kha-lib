(function() {

	// http://www.html5gamedevs.com/topic/6970-phaser-js-share-score-on-twitter/

	var canvas = document.getElementById("khanvas");

	window.wyn_tw = {

		tweet : function (message) {

			var onUpFunc = function () {

				canvas.removeEventListener("mouseup", onUpFunc);
				canvas.removeEventListener("touchend", onUpFunc);
				canvas.removeEventListener("pointerup", onUpFunc);
				canvas.removeEventListener("click", onUpFunc);

				// share score on twitter
				var tweetbegin = 'http://twitter.com/home?status=';
				var tweettxt = message;
				var finaltweet = tweetbegin + encodeURIComponent(tweettxt);
				window.open(finaltweet, '_blank');

			}

			// Circumvents trustedSource issue
			canvas.addEventListener("mouseup", onUpFunc);
			canvas.addEventListener("touchend", onUpFunc);
			canvas.addEventListener("pointerup", onUpFunc);
			canvas.addEventListener("click", onUpFunc);
		}

	};

})();