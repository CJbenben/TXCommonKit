//
//  CJFont.h
//  DP
//
//  Created by cxj on 17/07/05.
//  Copyright © 2015年 笨笨编程. All rights reserved.
//

#ifndef CJFont_h
#define CJFont_h


#endif /* CJFont_h */

#define FONTSTYLE_PingFangSC_Light ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0 ? @"PingFangSC-Light" : @"Helvetica-Light")
#define FONTSTYLE_PingFangSC_Medium ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0 ? @"PingFangSC-Medium" : @"Helvetica-Bold")
#define FONTSTYLE_PingFangSC_Regular ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0 ? @"PingFangSC-Regular" : @"Helvetica")

#define COMMON_FONT(F) [UIFont systemFontOfSize:F]

#define FONT9  COMMON_FONT(9)
#define FONT10 COMMON_FONT(10)
#define FONT11 COMMON_FONT(11)
#define FONT12 COMMON_FONT(12)
#define FONT13 COMMON_FONT(13)
#define FONT14 COMMON_FONT(14)
#define FONT15 COMMON_FONT(15)
#define FONT16 COMMON_FONT(16)
#define FONT17 COMMON_FONT(17)
#define FONT18 COMMON_FONT(18)
#define FONT19 COMMON_FONT(19)
#define FONT20 COMMON_FONT(20)
#define FONT21 COMMON_FONT(21)
#define FONT22 COMMON_FONT(22)
