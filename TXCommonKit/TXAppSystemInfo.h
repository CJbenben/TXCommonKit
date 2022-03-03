//
//  TXAppSystemInfo.h
//  AFNetworking
//
//  Created by chenxiaojie on 2019/8/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/** App 系统相关信息 */
@interface TXAppSystemInfo : NSObject

/**
 @brief 获取当前设备手机型号
 @return    手机型号
 */
+ (NSString *)getCurrentDeviceModel;

/*
 @brief 获取设备当前网络IP地址
 @return    ip 地址
 */
+ (NSString *)getNetworkIPAddress;

@end

NS_ASSUME_NONNULL_END
