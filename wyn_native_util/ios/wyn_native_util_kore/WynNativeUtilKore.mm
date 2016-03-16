#include <WynNativeUtilKore.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

namespace WynNativeUtilKore
{
	void openUrl (const char* url)
	{
		NSLog(@"WynNativeUtilKore openUrl : %s", url);
		NSString *sUrl = [NSString stringWithUTF8String:url];
		[[UIApplication sharedApplication] openURL:[NSURL URLWithString:sUrl]];
	}
}
