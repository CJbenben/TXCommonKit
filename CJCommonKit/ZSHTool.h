//
//  ZSHTool.h
//  DP
//
//  Created by 笨笨编程 on 2017/7/5.
//  Copyright © 2017年 dp. All rights reserved.
//

#ifndef ZSHTool_h
#define ZSHTool_h

 
#endif /* ZSHTool_h */

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

#define IS_IPHONE_X ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6_PLUS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6_PLUS_ZOOM ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPHONE_4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)



#define WeakSelf __weak typeof(self) weakSelf = self;

/* 隐藏键盘 */
#define HidenKeybord {[[[UIApplication sharedApplication] keyWindow] endEditing:YES];}


#ifdef DEBUG
#define CJString [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define CJLog(...) printf("%s: %s 第%d行: %s\n\n",[[NSString lr_stringDate] UTF8String], [LRString UTF8String] ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String]);
#else
#define CJLog(...)
#endif

//保留两位有效数字加￥符
#define RMB(priceStr)           [NSString stringWithFormat:@"￥%.2f", priceStr.floatValue]

