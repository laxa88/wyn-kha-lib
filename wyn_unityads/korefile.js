var project = new Project('wyn_unityads');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_unityads/**');
	// project.addIncludeDir('ios/wyn_unityads');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_unityads/**');
	project.addIncludeDir('android/wyn_unityads');
	project.addJavaDir('android/java');
}

return project;
