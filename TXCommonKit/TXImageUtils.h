//
//  TXImageUtils.h
//  Demo
//
//  Created by chenxiaojie on 2022/3/3.
//  Copyright © 2022 ChenJie. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TXImageUtils : NSObject

/**
 @brief pdf 转 image 并保存系统相册
 @param pdfPath     pdf本地路径
 @param completion  保存后回调
 */
- (void)getAndSaveUIImageFromPdfFilePath:(NSString * __nonnull)pdfPath completion:(void (^ __nullable)(BOOL isSuccess))completion;

@end

NS_ASSUME_NONNULL_END
