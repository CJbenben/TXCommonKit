//
//  ZSHAppInfo.h
//  DP
//
//  Created by 笨笨编程 on 2017/7/5.
//  Copyright © 2017年 cxj. All rights reserved.
//

#ifndef ZSHAppInfo_h
#define ZSHAppInfo_h


#endif /* ZSHAppInfo_h */

/** APP版本号 */
#define AppVersion              [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
/** APP BUILD 版本号 */
#define AppBuildVersion         [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]
/** APP名字 */
#define AppDisplayName          [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]
/** 当前语言 */
#define APPLocalLanguage        [[NSLocale currentLocale] objectForKey:NSLocaleLanguageCode]
/** 当前国家 */
#define APPLocalCountry         [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode]


///** APP信息 */
//#define kZSH_APP_NAME                   @"易捷海购"
//
//#define kZSH_HEADER_IMG                 [UIImage imageNamed:@"headerImg"]
//
///** APPicon_本地 */
//#define kYSMobile_APPICON_LOCAL         @"AppIcon80px"
///** 客服电话 */
//#define kYSMobile_SERVES                @"400-728-8016"
//
///** 在iTunes上的网页 */
//#define kZSH_ITUNES_WEBURL              @"https://itunes.apple.com/cn/app/易捷海购/id1176411709?mt=8"
//
///** APP下载链接 */
//#define kZSH_AppStore_Url               @"https://itunes.apple.com/us/app/%E6%98%93%E6%8D%B7%E6%B5%B7%E8%B4%AD/id1176411709?mt=8&uo=4"
