# Wyn Native Utilities
Simple utility library for Kha

## Installation

1. Copy the 'wyn_native_util' folder to your Libraries folder
2. Add the following in your project's 'khafile.js':

		project.addLibrary('wyn_native_util');

### HTML5 (additional steps)

1. Include this code in your index.html, typically after including 'kha.js':

		<script type="text/javascript" src="wyn_native_util.js"></script>

2. Manually copy 'wyn_native_util.js' from 'wyn_native_util/html5' into your 'builds/html5' folder

### Android
- No additional steps.

### iOS
- none yet

## Usage

2. Simple, straightforward usage in your haxe code:

		wyn.WynNativeUtil.openUrl("http://google.com");
