#import "iOSHelper.h"
// #import "IsolatedAlert.h"
#include "hxcpp.h"

// void iOSHelper::ShowAlert(void(*callback)(int index))
// {
//     this->callback = callback;

//     IsolatedAlert* instance = [IsolatedAlert new];
//     [instance showAlert: this];
// }

Dynamic iOSHelper::adViewDidReceiveAdCB;

void iOSHelper::setCallbacks (Dynamic a, Dynamic b, Dynamic c, Dynamic d, Dynamic e, Dynamic f)
{
	this->adViewDidReceiveAdCB = a;
	this->didFailToReceiveAdWithErrorCB = b;
	this->adViewWillPresentScreenCB = c;
	this->adViewWillDismissScreenCB = d;
	this->adViewDidDismissScreenCB = e;
	this->adViewWillLeaveApplicationCB = f;

	// IsolatedAlert* instance = [IsolatedAlert new];
	// [instance showAlert: this];
}