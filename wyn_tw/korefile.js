var project = new Project('wyn_tw');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_tw_kore/**');
	// project.addIncludeDir('ios/wyn_tw_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_tw_kore/**');
	project.addIncludeDir('android/wyn_tw_kore');
	project.addJavaDir('android/java');
}

return project;
