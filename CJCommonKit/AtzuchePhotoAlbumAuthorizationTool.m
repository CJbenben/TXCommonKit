//
//  AtzuchePhotoAlbumAuthorizationTool.m
//  Autoyol
//
//  Created by fanxiao on 2017/7/17.
//  Copyright © 2017年 Autoyol. All rights reserved.
//

#import "AtzuchePhotoAlbumAuthorizationTool.h"
#import <Photos/Photos.h>
//#import <AssetsLibrary/AssetsLibrary.h>

@implementation AtzuchePhotoAlbumAuthorizationTool

// 相机权限判断
+ (BOOL)isPhotoAuthorization
{
    AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
    if (authStatus == AVAuthorizationStatusDenied || authStatus == AVAuthorizationStatusRestricted) {
        // 没有权限。弹出alertView
        [AtzuchePhotoAlbumAuthorizationTool showPhotoAlert];
        return NO;
    }else{
        //获取了权限，直接调用相机接口
        return YES;
    }
    
}

//相册权限判断
+ (BOOL)isAlbumAuthorization
{
//    // <AssetsLibrary/AssetsLibrary.h>
//    if ([[[UIDevice currentDevice] systemVersion] floatValue] > 8.0) {
//        ALAuthorizationStatus authStatus = [ALAssetsLibrary authorizationStatus];
//        if (authStatus == ALAuthorizationStatusDenied || authStatus == ALAuthorizationStatusRestricted) {
//            [AtzuchePhotoAlbumAuthorizationTool showAlbumAlert];
//            return NO;
//        } return YES;
//    }
//    // <Photos/Photos.h>
//    else {
        PHAuthorizationStatus status = [PHPhotoLibrary authorizationStatus];
        if (status == PHAuthorizationStatusDenied || status == PHAuthorizationStatusRestricted) {
            [AtzuchePhotoAlbumAuthorizationTool showAlbumAlert];
            return NO;
        } return YES;
//    }
}

+ (BOOL) isCameraAvailable{
    return [UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera];
}

// 前面的摄像头是否可用
+ (BOOL) isFrontCameraAvailable{
    return [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceFront];
}

// 后面的摄像头是否可用
+ (BOOL) isRearCameraAvailable{
    return [UIImagePickerController isCameraDeviceAvailable:UIImagePickerControllerCameraDeviceRear];
}

+ (void)showPhotoAlert
{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"相机权限未开启" message:@"相机权限未开启，请进入系统【设置】>【隐私】>【相机】中打开开关,开启相机功能" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"立即开启" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:okAction];
    [[self atzucheCurrentViewController] presentViewController:alertController animated:YES completion:nil];

//    [OHAlertView showAlertWithTitle:@"相机权限未开启" message:@"相机权限未开启，请进入系统【设置】>【隐私】>【相机】中打开开关,开启相机功能" cancelButton:@"取消" okButton:@"立即开启" buttonHandler:^(OHAlertView *alert, NSInteger buttonIndex) {
//        if (buttonIndex == 1) {
//#ifdef __IPHONE_8_0
//            //跳入当前App设置界面,
//            [[UIApplication sharedApplication]openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
//#else
//            //适配iOS7 ,跳入系统设置界面
//            [[UIApplication sharedApplication]openURL:[NSURL URLWithString:@"prefs:General&path=Reset"]];
//#endif
//        }
//    }];
}

+ (void)showAlbumAlert
{
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"照片权限未开启" message:@"照片权限未开启，请进入系统【设置】>【隐私】>【照片】中打开开关,开启照片功能" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:nil];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"立即开启" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
    }];
    [alertController addAction:cancelAction];
    [alertController addAction:okAction];
    [[self atzucheCurrentViewController] presentViewController:alertController animated:YES completion:nil];

    
//    [OHAlertView showAlertWithTitle:@"照片权限未开启" message:@"照片权限未开启，请进入系统【设置】>【隐私】>【照片】中打开开关,开启照片功能" cancelButton:@"取消" okButton:@"立即开启" buttonHandler:^(OHAlertView *alert, NSInteger buttonIndex) {
//        if (buttonIndex == 1) {
//#ifdef __IPHONE_8_0
//            //跳入当前App设置界面,
//            [[UIApplication sharedApplication]openURL:[NSURL URLWithString:UIApplicationOpenSettingsURLString]];
//#else
//            //适配iOS7 ,跳入系统设置界面
//            [[UIApplication sharedApplication]openURL:[NSURL URLWithString:@"prefs:General&path=Reset"]];
//#endif
//        }
//    }];
}

+ (UIViewController*)atzucheCurrentViewController {
    //获得当前活动窗口的根视图
    UIViewController* vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (1)
    {
        //根据不同的页面切换方式，逐步取得最上层的viewController
        if ([vc isKindOfClass:[UITabBarController class]]) {
            vc = ((UITabBarController*)vc).selectedViewController;
        }
        if ([vc isKindOfClass:[UINavigationController class]]) {
            vc = ((UINavigationController*)vc).visibleViewController;
        }
        if (vc.presentedViewController) {
            vc = vc.presentedViewController;
        }else{
            break;
        }
    }
    return vc;
}

@end
