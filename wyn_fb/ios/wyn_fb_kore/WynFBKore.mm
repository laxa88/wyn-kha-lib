#include <WynFBKore.h>
#import <Foundation/Foundation.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKShareKit/FBSDKShareKit.h>

namespace WynFBKore
{
	void init ()
	{
		NSLog(@"WynFBKore init");

		[FBSDKAppEvents activateApp];
	}

	void shareFeed (const char* title, const char* desc, const char* websiteUrl, const char* pictureUrl)
	{
		// https://developers.facebook.com/docs/sharing/overview
		NSLog(@"WynFBKore shareFeed : %s , %s , %s , %s", title, desc, websiteUrl, pictureUrl);

		FBSDKShareLinkContent *content = [[FBSDKShareLinkContent alloc] init];
		content.contentTitle = [NSString stringWithUTF8String:title];
		content.contentDescription = [NSString stringWithUTF8String:desc];
		content.contentURL = [NSURL URLWithString:[NSString stringWithUTF8String:websiteUrl]];
		content.imageURL = [NSURL URLWithString:[NSString stringWithUTF8String:pictureUrl]];

		UIWindow* window = [UIApplication sharedApplication].keyWindow;
		FBSDKShareDialog *dialog = [[FBSDKShareDialog alloc] init];
		dialog.shareContent = content;
		dialog.fromViewController = window.rootViewController;

		// https://github.com/facebook/facebook-ios-sdk/blob/master/FBSDKShareKit/FBSDKShareKit/FBSDKShareDialogMode.h
		// Use the native FB app to show the dialog; otherwise use the web browser popup
		// WARNING: using other mode than Native won't pause the game! So, be sure
		// to only allow this when the player is idling at a gameover screen or something.
		// TODO: add delegates (callback handling)
		dialog.mode = FBSDKShareDialogModeNative;
		if (!dialog.canShow) dialog.mode = FBSDKShareDialogModeFeedWeb;

		[dialog show];
	}
}
