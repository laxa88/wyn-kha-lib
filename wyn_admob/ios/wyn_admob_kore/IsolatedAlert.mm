// #import "IsolatedAlert.h"

// iOsType* staticPointer;

// @implementation IsolatedAlert

// -(void)showAlert:(iOsType*)callback
// {
//     staticPointer = callback;

//     UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Title?"
//                                                     message:@"Message?"
//                                                    delegate:self
//                                           cancelButtonTitle:@"Cancel"
//                                           otherButtonTitles:@"OK", nil];
//     [alert show];
//     //[alert release];
// }

// -(void)alertView:(UIAlertView *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
// {
//     staticPointer->callback(buttonIndex);
// }

// @end