//
//  CJPhotoAlbumAuthorizationTool.h
//  Autoyol
//
//  Created by chenxioajie on 2017/7/17.
//  Copyright © 2017年 Autoyol. All rights reserved.
//

#import <Foundation/Foundation.h>

/** @brief 摄像头和相册相关的公共类 */
@interface CJPhotoAlbumAuthorizationTool : NSObject

// 相机权限判断
+ (BOOL)isPhotoAuthorization;
//相册权限判断
+ (BOOL)isAlbumAuthorization;


// 判断设备是否有摄像头
+ (BOOL) isCameraAvailable;

// 前面的摄像头是否可用
+ (BOOL) isFrontCameraAvailable;

// 后面的摄像头是否可用
+ (BOOL) isRearCameraAvailable;

@end
