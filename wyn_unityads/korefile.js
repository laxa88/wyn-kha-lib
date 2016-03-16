var project = new Project('wyn_unityads');

if (platform === Platform.iOS)
{
	project.addFile('ios/wyn_unityads_kore/**');
	project.addIncludeDir('ios/wyn_unityads_kore');
	project.addLib('AdSupport');
	project.addLib('AVFoundation');
	project.addLib('CFNetwork');
	project.addLib('CoreFoundation');
	project.addLib('CoreMedia');
	project.addLib('CoreTelephony');
	project.addLib('StoreKit');
	project.addLib('SystemConfiguration');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_unityads_kore/**');
	project.addIncludeDir('android/wyn_unityads_kore');
	project.addJavaDir('android/java');
}

return project;
