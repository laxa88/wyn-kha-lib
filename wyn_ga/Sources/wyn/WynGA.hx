package wyn;

// For reference of API usage:
// https://developers.google.com/analytics/devguides/collection/analyticsjs/command-queue-reference

#if js

// Note: extern class means this WynGA doesn't exist in
// the code -- it tries to link directly to the native class,
// e.g. window.wyn_ga.sendEvent(...); and assumes it exists.
@:native('wyn_ga')
extern class WynGA
{
	public static function init (id:String) : Void;
	public static function sendEvent (category:String, ?action:String, ?label:String, ?value:String) : Void;
	public static function sendSocial (network:String, ?action:String, ?target:String) : Void;
	public static function sendTiming (category:String, ?variable:String, ?value:String, ?label:String) : Void;
}

#elseif (sys_ios || sys_android_native)

@:headerCode('
#include <WynGAKore.h>
')

class WynGA
{
	@:functionCode('WynGAKore::init(id);')
	public static function init (id:String) : Void {}

	@:functionCode('WynGAKore::sendEvent(category, action, label, value);')
	public static function sendEvent (category:String, ?action:String, ?label:String, ?value:String) : Void {}

	@:functionCode('WynGAKore::sendSocial(network, action, target);')
	public static function sendSocial (network:String, ?action:String, ?target:String) : Void {}

	@:functionCode('WynGAKore::sendTiming(category, variable, value, label);')
	public static function sendTiming (category:String, ?variable:String, ?value:String, ?label:String) : Void {}
}

#else

class WynGA
{
	public static function init (id:String) : Void {}
	public static function sendEvent (category:String, ?action:String, ?label:String, ?value:String) : Void {}
	public static function sendSocial (network:String, ?action:String, ?target:String) : Void {}
	public static function sendTiming (category:String, ?variable:String, ?value:String, ?label:String) : Void {}
}

#end
