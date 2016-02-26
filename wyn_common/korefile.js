var project = new Project('wyn_common');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_common_kore/**');
	// project.addIncludeDir('ios/wyn_common_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_common_kore/**');
	project.addIncludeDir('android/wyn_common_kore');
	// project.addJavaDir('android/java');
}

return project;
