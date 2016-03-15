package wyn;

#if js

@:native("wyn_tw")
extern class WynTW
{
    public static function tweet (msg:String) : Void;
}

#elseif (sys_ios || sys_android_native)

@:headerCode('
#include <WynTWKore.h>
')

class WynTW
{
	@:functionCode('WynTWKore::tweet(msg);')
	public static function tweet (msg:String) : Void {}
}

#else

class WynTW
{
    public static function tweet (msg:String) : Void {}
}

#end