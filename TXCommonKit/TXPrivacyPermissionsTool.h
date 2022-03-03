//
//  TXPrivacyPermissionsTool.h
//  Autoyol
//
//  Created by chenxioajie on 2017/7/17.
//  Copyright © 2017年 Autoyol. All rights reserved.
//

#import <Foundation/Foundation.h>

/** @brief 判断权限是否开启的相关公共类 */
@interface TXPrivacyPermissionsTool : NSObject

//************************************************** 相机、相册 **************************************************//
/**
 @brief 相机权限判断
 @return 是否开启
 */
+ (BOOL)isCameraAuthorization;

/**
 @brief 相机权限判断，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isCameraAuthorizationAndPopupAlert;


/**
 @brief 相册权限判断
 @return 是否开启
 */
+ (BOOL)isAlbumAuthorization;

/**
 @brief 相册权限判断，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isAlbumAuthorizationAndPopupAlert;

/**
 @brief 判断设备是否有摄像头
 @return 是否有
 */
+ (BOOL)isCameraAvailable;

/**
 @brief 前面的摄像头是否可用
 @return 是否可用
 */
+ (BOOL)isFrontCameraAvailable;

/**
 @brief 后面的摄像头是否可用
 @return 是否可用
 */
+ (BOOL)isRearCameraAvailable;

//************************************************** 定位 **************************************************//

/**
 @brief 定位权限是否开启
 @return 是否开启
 */
+ (BOOL)isLocationAuthorization;

/**
 @brief 定位权限是否开启，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isLocationAuthorizationAndPopupAlert;

//************************************************** 麦克风 **************************************************//

/**
 @brief 麦克风权限是否开启
 @return 是否开启
 */
+ (BOOL)isAudioAuthorization;

/**
 @brief 麦克风权限是否开启，未开启时并弹出授权弹框
 @return 是否开启
 */
+ (BOOL)isAudioAuthorizationAndPopupAlert;

/**
 @brief 通讯录权限是否开启
 @return 是否开启
 */
+ (BOOL)isContactAuthhorization;

@end
