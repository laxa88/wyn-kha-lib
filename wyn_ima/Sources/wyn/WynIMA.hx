package wyn;

#if js

@:native('wyn_ima')
extern class WynIMA
{
	public static function init () : Bool;
	public static function show () : Bool;
}

#elseif (sys_ios || sys_android_native)

@:headerCode('
#include <WynIMAKore.h>
')

class WynIMA
{
	@:functionCode('WynIMAKore::init();')
	public static function init () : Void {}

	@:functionCode('WynIMAKore::show();')
	public static function show () : Void {}
}

#else

class WynIMA
{
	public static function init () : Bool {}
	public static function show () : Bool {}
}

#end