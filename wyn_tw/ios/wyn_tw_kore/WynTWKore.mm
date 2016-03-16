#include <WynTWKore.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

namespace WynTWKore
{
	void tweet (const char* msg)
	{
		NSString *sUrl = [NSString stringWithUTF8String:msg];

        // http://stackoverflow.com/questions/8088473/how-do-i-url-encode-a-string
        // http://stackoverflow.com/questions/6725558/cast-of-objective-c-pointer-type-nsstring-to-c-pointer-type-cfstringref-a
        sUrl = (__bridge NSString *)CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)sUrl, NULL, (CFStringRef)@"!*'();:@&=+$,/?%#[]", kCFStringEncodingUTF8);
        sUrl = [@"https://twitter.com/intent/tweet?text=" stringByAppendingString:sUrl];

        // http://stackoverflow.com/questions/5428325/issue-with-code-format-string-is-not-a-string-literal
        NSLog(@"%@", sUrl);
        
		[[UIApplication sharedApplication] openURL:[NSURL URLWithString:sUrl]];
	}
}
