#pragma once
// #include "hxcpp.h"

class iOSHelper
{
public:

    void(*callback)(int index);
    iOSHelper () { }
    void ShowAlert (void(*callback)(int));
    
	// Dynamic adViewDidReceiveAdCB;
	// Dynamic didFailToReceiveAdWithErrorCB;
	// Dynamic adViewWillPresentScreenCB;
	// Dynamic adViewWillDismissScreenCB;
	// Dynamic adViewDidDismissScreenCB;
	// Dynamic adViewWillLeaveApplicationCB;
};