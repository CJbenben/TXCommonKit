//
//  TXTool.h
//  DP
//
//  Created by 笨笨编程 on 2017/7/5.
//  Copyright © 2017年 dp. All rights reserved.
//

#ifndef TXTool_h
#define TXTool_h

#endif /* TXTool_h */

/* 隐藏键盘 */
#define HidenKeybord {[[[UIApplication sharedApplication] keyWindow] endEditing:YES];}

/* 开启子线程 */
#define PERFORMSEL_BACK(block) dispatch_async(\
dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),\
block)

/* 主线程 */
#define PERFORMSEL_MAIN(block) dispatch_async(dispatch_get_main_queue(),\
block)

#pragma mark - Singleton Creation  functions单例创建，统一单例命名调用方式
//单例声明 .h中使用
#undef    AS_SINGLETON
#define AS_SINGLETON( __class ) \
+ (__class *)sharedInstance;
//单例实现创建 .m中使用
#undef    DEF_SINGLETON
#define DEF_SINGLETON( __class ) \
+ (__class *)sharedInstance \
{ \
static dispatch_once_t once; \
static __class * __singleton__; \
dispatch_once( &once, ^{ __singleton__ = [[__class alloc] init]; } ); \
return __singleton__; \
}

/* 设置圆角 */
#define kViewBorderRadius(View, Radius)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];

/* log */
#ifdef DEBUG
#define CJString [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
#define CJLog(...) printf("%s: %s 第%d行: %s\n\n",[[NSString lr_stringDate] UTF8String], [LRString UTF8String] ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String]);
#else
#define CJLog(...)
#endif

// 整数价格只显示整数，小数价格保留两位有效数字
#define RMB(priceStr) \
({NSString *price = priceStr;\
if (price.floatValue == price.intValue) {\
price = [NSString stringWithFormat:@"￥%.0f", price.floatValue];\
}\
else {\
price = [NSString stringWithFormat:@"￥%.2f", price.floatValue];\
}\
(price);})

