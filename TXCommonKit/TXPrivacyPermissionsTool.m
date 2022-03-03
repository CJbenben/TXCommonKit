//
//  TXPrivacyPermissionsTool.m
//  Autoyol
//
//  Created by chenxiaojie on 2017/7/17.
//  Copyright © 2017年 Autoyol. All rights reserved.
//

#import "TXPrivacyPermissionsTool.h"
#import <Photos/Photos.h>
#import <CoreLocation/CLLocationManager.h>
#import <Contacts/Contacts.h>
#import <ContactsUI/ContactsUI.h>

@implementation TXPrivacyPermissionsTool

#define kCameraTitle        @"相机权限未开启"
#define kCameraMessage      @"相机权限未开启，请进入系统【设置】>【隐私】>【相机】中打开开关，开启相机功能"
#define kAlbumTitle         @"照片权限未开启"
#define kAlbumMessage       @"照片权限未开启，请进入系统【设置】>【隐私】>【照片】中打开开关，开启照片功能"
#define kLocationTitle      @"定位权限未开启"
#define kLocationMessage    @"定位权限未开启，请进入系统【设置】>【隐私】>【定位】中打开开关，开启定位功能"
#define kAudioTitle         @"麦克风权限未开启"
#define kAudioMessage       @"麦克风权限未开启，请进入系统【设置】>【隐私】>【麦克风】中打开开关，开启麦克风功能"
#define kContactTitle       @"通讯录权限未开启"
#define kContactMessage     @"通讯录权限未开启，请进入系统【设置】>【隐私】>【通讯录】中打开开关，开启通讯录功能"

/**
 @brief 相机权限判断
 @return 是否开启
 */
+ (BOOL)isCameraAuthorization {
    AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    if (authStatus == AVAuthorizationStatusDenied || authStatus == AVAuthorizationStatusRestricted) {
        return NO;
    }
    return YES;
}

/**
 @brief 相机权限判断，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isCameraAuthorizationAndPopupAlert {
    if ([self isCameraAuthorization]) {
        return YES;
    }
    // 没有权限。弹出alertView
    [self showPrivacyPermissionsAlertWithTitle:kCameraTitle message:kCameraMessage];
    return NO;
}

/**
 @brief 相册权限判断
 @return 是否开启
 */
+ (BOOL)isAlbumAuthorization {
    PHAuthorizationStatus status = [PHPhotoLibrary authorizationStatus];
    if (status == PHAuthorizationStatusDenied || status == PHAuthorizationStatusRestricted) {
        return NO;
    }
    return YES;
}

/**
 @brief 相册权限判断，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isAlbumAuthorizationAndPopupAlert {
    if ([self isAlbumAuthorization]) {
        return YES;
    }
    [self showPrivacyPermissionsAlertWithTitle:kAlbumTitle message:kAlbumMessage];
    return NO;
}

/**
 @brief 判断设备是否有摄像头
 @return 是否有
 */
+ (BOOL)isCameraAvailable {
    return [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
}

/**
 @brief 前面的摄像头是否可用
 @return 是否可用
 */
+ (BOOL)isFrontCameraAvailable {
    return [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceFront];
}

/**
 @brief 后面的摄像头是否可用
 @return 是否可用
 */
+ (BOOL)isRearCameraAvailable {
    return [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceRear];
}

/**
 @brief 定位权限是否开启
 @return 是否开启
 */
+ (BOOL)isLocationAuthorization {
    if ([CLLocationManager locationServicesEnabled] && ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusAuthorizedWhenInUse || [CLLocationManager authorizationStatus] == kCLAuthorizationStatusNotDetermined)) {
        return YES;
    } else if ([CLLocationManager authorizationStatus] ==kCLAuthorizationStatusDenied) {
        //定位不能用
    }
    return NO;
}

/**
 @brief 定位权限是否开启，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isLocationAuthorizationAndPopupAlert {
    if ([self isLocationAuthorization]) {
        return YES;
    }
    [self showPrivacyPermissionsAlertWithTitle:kLocationTitle message:kLocationMessage];
    return NO;
}

/**
 @brief 麦克风权限是否开启
 @return 是否开启
 */
+ (BOOL)isAudioAuthorization {
    AVAuthorizationStatus microPhoneStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeAudio];
    if (microPhoneStatus == AVAuthorizationStatusAuthorized ) {
        return YES;
    }
    return NO;
}

/**
 @brief 麦克风权限是否开启，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isAudioAuthorizationAndPopupAlert {
    if ([self isAudioAuthorization]) {
        return YES;
    }
    [self showPrivacyPermissionsAlertWithTitle:kAudioTitle message:kAudioMessage];
    return NO;
}

/**
 @brief 通讯录权限是否开启
 @return 是否开启
 */
+ (BOOL)isContactAuthhorization {
    CNAuthorizationStatus status = [CNContactStore authorizationStatusForEntityType:CNEntityTypeContacts];
    if (status == CNAuthorizationStatusAuthorized) {
        return YES;
    }
    return NO;
    // 第一次弹框
//    if (status == CNAuthorizationStatusNotDetermined) {
//        CNContactStore *store = [[CNContactStore alloc] init];
//        [store requestAccessForEntityType:CNEntityTypeContacts completionHandler:^(BOOL granted, NSError*  _Nullable error) {
//            if (error) {
//                NSLog(@"授权失败");
//            }else {
//                NSLog(@"成功授权");
//            }
//        }];
//    }
}



+ (void)showPrivacyPermissionsAlertWithTitle:(NSString *)title message:(NSString *)message {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"立即开启" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString] options:@{} completionHandler:nil];
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:okAction];
    [[self atzucheCurrentViewController] presentViewController:alertController animated:YES completion:nil];
}

+ (UIViewController*)atzucheCurrentViewController {
    //获得当前活动窗口的根视图
    UIViewController* vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (1) {
        //根据不同的页面切换方式，逐步取得最上层的viewController
        if ([vc isKindOfClass:[UITabBarController class]]) {
            vc = ((UITabBarController*)vc).selectedViewController;
        }
        if ([vc isKindOfClass:[UINavigationController class]]) {
            vc = ((UINavigationController*)vc).visibleViewController;
        }
        if (vc.presentedViewController) {
            vc = vc.presentedViewController;
        } else{
            break;
        }
    }
    return vc;
}

@end
