(function() {

	var canvas = document.getElementById("khanvas");
	var fbAppId = '';

	window.wyn_fb = {

		init : function (appId) {

			// NOTE
			// - actual init using appId is done in "facebook.js"
			// - this method is used by other targets.

			// We're only saving the appId here in case FB API is not loaded.
			// (e.g. caused by popup blockers, etc.)
			console.log("init FB app Id : " + appId);
			fbAppId = appId;

		},

		shareFeed : function (title, desc, caption, websiteUrl, pictureUrl) {

			// NOTE: caption must be the URL for the link to work.

			// NOTE: if popup doesn't appear / is blocked, make sure
			// this function is called within the event that triggers it

			var onUpFunc = function () {

				canvas.removeEventListener("mouseup", onUpFunc);
				canvas.removeEventListener("touchend", onUpFunc);
				canvas.removeEventListener("pointerup", onUpFunc);
				canvas.removeEventListener("click", onUpFunc);

				if (typeof FB === 'undefined')
				{
					console.log("using FB redirection");

					// We're using URL redirection method in case FB
					// API isn't loaded (due to popup blockers, etc.)

					var url = "https://www.facebook.com/dialog/feed?"
						+ "app_id=" + fbAppId
						+ "&display=popup"
						+ "&name=" + encodeURIComponent(title)
						+ "&description=" + encodeURIComponent(desc)
						+ "&caption=" + encodeURIComponent(caption)
						+ "&picture=" + encodeURIComponent(pictureUrl);
						+ "&link=" + encodeURIComponent(websiteUrl)
						+ "&redirect_uri=" + websiteUrl;

					console.log(url);

					// reference:
					// https://developers.facebook.com/docs/sharing/reference/feed-dialog/v2.2
					// var url = "https://www.facebook.com/dialog/feed?"
					//   + "app_id=145634995501895"
					//   + "&display=popup&caption=An%20example%20caption "
					//   + "&link=https%3A%2F%2Fdevelopers.facebook.com%2Fdocs%2F"
					//   + "&redirect_uri=https://developers.facebook.com/tools/explorer";

					window.open(url, '_blank');
				}
				else
				{
					console.log("using FB API");

					// share score on facebook
					var opts = {
						method: 'feed',
						link: websiteUrl,
						picture: pictureUrl,
						display: "popup"
					};

					if (title != null && title != "") opts.name = title; // defaults to HTML page <title>
					if (desc != null && desc != "") opts.description = desc; // defaults empty
					if (caption != null && caption != "") opts.caption = caption; // defaults to the website domain, e.g. coinflipstudios.com

					FB.ui(opts, function (response) {
						// console.log("done sharing");
					});
				}

			}

			// Circumvents trustedSource issue
			canvas.addEventListener("mouseup", onUpFunc);
			canvas.addEventListener("touchend", onUpFunc);
			canvas.addEventListener("pointerup", onUpFunc);
			canvas.addEventListener("click", onUpFunc);

		}
	};

})();

