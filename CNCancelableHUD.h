//
//  CNCancelableHUD.h
// 
//  Created by Ravel Antunes on 10/30/12.
//  
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

enum {
    CNCancelableHUDMaskTypeNone = 1, // allow user interactions while HUD is displayed
    CNCancelableHUDMaskTypeClear, // don't allow
    CNCancelableHUDMaskTypeBlack, // don't allow and dim the UI in the back of the HUD
    CNCancelableHUDMaskTypeGradient // don't allow and dim the UI with a a-la-alert-view bg gradient
};

typedef NSUInteger CNCancelableHUDMaskType;

@interface CNCancelableHUD : UIView

+ (void)show;
+ (void)showWithCancelBlock:(void (^)(void))block;
+ (void)showWithMaskType:(CNCancelableHUDMaskType)maskType;
+ (void)showWithMaskType:(CNCancelableHUDMaskType)maskType cancelBlock:(void (^)(void))block;

+ (void)showWithStatus:(NSString*)status;
+ (void)showWithStatus:(NSString*)status cancelBlock:(void (^)(void))block;
+ (void)showWithStatus:(NSString*)status maskType:(CNCancelableHUDMaskType)maskType;
+ (void)showWithStatus:(NSString*)status maskType:(CNCancelableHUDMaskType)maskType cancelBlock:(void (^)(void))block;

+ (void)showCancelingRequestsOnTap:(BOOL)cancelRequests;
+ (void)showWithStatus:(NSString*)status cancelingRequestsOnTap:(BOOL)cancelRequests;
+ (void)showWithStatus:(NSString*)status maskType:(CNCancelableHUDMaskType)maskType cancelingRequestsOnTap:(BOOL)cancelRequests;

+ (void)setStatus:(NSString*)string; // change the HUD loading status while it's showing

// stops the activity indicator, shows a glyph + status, and dismisses HUD 1s later
+ (void)showSuccessWithStatus:(NSString*)string;
+ (void)showErrorWithStatus:(NSString *)string;
+ (void)showImage:(UIImage*)image status:(NSString*)status; // use 28x28 white pngs

+ (void)dismiss;

+ (BOOL)isVisible;


// deprecated June 9th; custom durations encourages uncessarily long status strings (inappropriate, use UIAlertView instead)
+ (void)showSuccessWithStatus:(NSString *)string duration:(NSTimeInterval)duration;
+ (void)showErrorWithStatus:(NSString *)string duration:(NSTimeInterval)duration;

// deprecated June 9th; use the showWithSuccess/Error methods instead
+ (void)dismissWithSuccess:(NSString*)successString;
+ (void)dismissWithSuccess:(NSString*)successString afterDelay:(NSTimeInterval)seconds;
+ (void)dismissWithError:(NSString*)errorString;
+ (void)dismissWithError:(NSString*)errorString afterDelay:(NSTimeInterval)seconds;


@end
