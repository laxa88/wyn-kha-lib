var project = new Project('wyn_native_util');

if (platform === Platform.iOS)
{
	project.addFile('ios/wyn_native_util_kore/**');
	project.addIncludeDir('ios/wyn_native_util_kore');
}
else if (platform === Platform.Android)
{
	project.addFile('android/wyn_native_util_kore/**');
	project.addIncludeDir('android/wyn_native_util_kore');
	project.addJavaDir('android/java');
}

return project;
