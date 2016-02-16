var project = new Project('wyn_fb');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_fb_kore/**');
	// project.addIncludeDir('ios/wyn_fb_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_fb_kore/**');
	project.addIncludeDir('android/wyn_fb_kore');
	project.addJavaDir('android/java');
}

return project;
