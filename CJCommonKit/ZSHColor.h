//
//  ZSHColor.h
//  DP
//
//  Created by cxj on 17/07/05.
//  Copyright © 2015年 笨笨编程. All rights reserved.
//

#ifndef ZSHColor_h
#define ZSHColor_h


#endif /* ZSHColor_h */

/* rgb 颜色值 */
#define RGBCOLOR(R, G, B)               [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:1]
#define RGBACOLOR(R, G, B, A)           [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

/* 十六进制 颜色值 */
#define HEX_RGB(V)                      [UIColor colorWithRGBHex:V]
#define HEX_RGBA(V, A)                  [UIColor colorWithRGBHex:V alpha:A]

/* 随机色 */
#define RandomColor                     RGBCOLOR(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
