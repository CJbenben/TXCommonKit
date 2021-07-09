//
//  CJConst.h
//  Demo
//
//  Created by chenxiaojie on 2020/11/23.
//  Copyright © 2020 ChenJie. All rights reserved.
//

#ifndef CJConst_h
#define CJConst_h


#endif /* CJConst_h */

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

#define kAPPDelegate ((AppDelegate*)[[UIApplication sharedApplication] delegate])


#pragma mark - Block functions Block 相关

///block 声明
#ifdef NS_BLOCKS_AVAILABLE
typedef void (^AtzucheBasicBlock)(void);
typedef void (^AtzucheOperationCallBackBlock)(BOOL isSuccess, NSString *errorMsg);
typedef void (^AtzucheCallBackBlockWithResult)(BOOL isSuccess, NSString *errorCode, NSString *errorMsg, id result);
typedef void (^AtzucheArrayBlock)(NSArray *list);

typedef void (^AtzucheStrBlock)(NSString *str);
typedef void (^AtzucheIntBlock)(NSInteger count);
typedef void (^AtzucheFloatBlock)(CGFloat value);
typedef void (^AtzucheDictBlock)(NSDictionary *dic);

typedef void (^AtzucheCallBackFailed)(NSString *errorCode,NSString *errorMsg);


#endif


#define IOS14_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 14.0)
#define IOS13_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 13.0)
#define IOS12_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 12.0)
#define IOS11_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0)
#define IOS10_OR_LATER  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define IOS9_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define IOS8_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define IOS7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)
#define IOS6_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0)
#define IOS5_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 5.0)
#define IOS4_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 4.0)
#define IOS3_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 3.0)

#define IS_IPAD         ((UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad))
#define IS_IPADz         ([(UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad) intValue])

#define IS_IPHONE_11 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_XS_MAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6_PLUS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6_PLUS_ZOOM ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

