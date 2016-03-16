var project = new Project('wyn_ga');

if (platform === Platform.iOS)
{
	project.addFile('ios/wyn_ga_kore/**');
	project.addIncludeDir('ios/wyn_ga_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_ga_kore/**');
	project.addIncludeDir('android/wyn_ga_kore');
	project.addJavaDir('android/java');
}

return project;
