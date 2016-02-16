var project = new Project('wyn_admob_kore');

if (platform === Platform.iOS)
{
	// project.addFile('ios/wyn_admob_kore/**');
	// project.addIncludeDir('ios/wyn_admob_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_admob_kore/**');
	project.addIncludeDir('android/wyn_admob_kore');
	project.addJavaDir('android/java');
}

return project;
