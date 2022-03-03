//
//  TXColor.h
//  DP
//
//  Created by cxj on 17/07/05.
//  Copyright © 2015年 笨笨编程. All rights reserved.
//

#ifndef TXColor_h
#define TXColor_h

#endif /* TXColor_h */

/* rgb 颜色值 */
#define CJRGBCOLOR(R, G, B)               [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:1]
#define CJRGBACOLOR(R, G, B, A)           [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]

/* 十六进制 颜色值 */
#define CJHEXRGB(V)                       [UIColor colorWithRGBHex:V]
#define CJHEXRGBA(V, A)                   [UIColor colorWithRGBHex:V alpha:A]

/* 随机色 */
#define RandomColor                       CJRGBCOLOR(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))
