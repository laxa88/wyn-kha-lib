var project = new Project('wyn_ima_kore');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_ima_kore/**');
	// project.addIncludeDir('ios/wyn_ima_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_ima_kore/**');
	project.addIncludeDir('android/wyn_ima_kore');
	project.addJavaDir('android/java');
}

return project;
