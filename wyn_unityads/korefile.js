var project = new Project('wyn_unityads');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_unityads_kore/**');
	// project.addIncludeDir('ios/wyn_unityads_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_unityads_kore/**');
	project.addIncludeDir('android/wyn_unityads_kore');
	project.addJavaDir('android/java');
}

return project;
