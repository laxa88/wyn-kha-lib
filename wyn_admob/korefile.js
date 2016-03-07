var project = new Project('wyn_admob_kore');

if (platform === Platform.iOS)
{
	project.addFile('ios/wyn_admob_kore/**');
	project.addIncludeDir('ios/wyn_admob_kore');
	project.addLib('ios/GoogleMobileAds');
	project.addLib('AdSupport');
	project.addLib('AudioToolbox');
	project.addLib('AVFoundation');
	project.addLib('CoreGraphics');
	project.addLib('CoreMedia');
	project.addLib('CoreTelephony');
	project.addLib('EventKit');
	project.addLib('EventKitUI');
	project.addLib('MessageUI');
	project.addLib('StoreKit');
	project.addLib('SystemConfiguration');
	project.addLib('MediaPlayer');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_admob_kore/**');
	project.addIncludeDir('android/wyn_admob_kore');
	project.addJavaDir('android/java');
}

return project;
