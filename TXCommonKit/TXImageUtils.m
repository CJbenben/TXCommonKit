//
//  TXImageUtils.m
//  Demo
//
//  Created by chenxiaojie on 2022/3/3.
//  Copyright © 2022 ChenJie. All rights reserved.
//

#import "TXImageUtils.h"
#import <UIKit/UIKit.h>

@interface TXImageUtils ()

@property (copy, nonatomic) void (^ saveCompletion)(BOOL isSuccess);

@end

@implementation TXImageUtils

/**
 @brief pdf 转 image 并保存系统相册
 @param pdfPath     pdf本地路径
 @param completion  保存后回调
 */
- (void)getAndSaveUIImageFromPdfFilePath:(NSString * __nonnull)pdfPath completion:(void (^ __nullable)(BOOL isSuccess))completion {
    if (pdfPath.length == 0) return;
    if (completion == nil) return;
    self.saveCompletion = completion;
    NSURL *filePath = [NSURL fileURLWithPath: pdfPath];
    // 读取PDF原文件的大小
    CGPDFDocumentRef doc = CGPDFDocumentCreateWithURL((__bridge CFURLRef)filePath);
    // 获取pdf页数
    NSInteger pageCount = CGPDFDocumentGetNumberOfPages(doc);
    for (NSInteger index = 1; index<=pageCount; index++) {
        CGPDFPageRef page =CGPDFDocumentGetPage(doc, index);
        CGRect pageRect = CGPDFPageGetBoxRect(page, kCGPDFMediaBox);
        pageRect.origin = CGPointZero;
        pageRect.size.height = pageRect.size.height*2;
        pageRect.size.width = pageRect.size.width*2;
        //开启图片绘制 上下文
        UIGraphicsBeginImageContext(pageRect.size);
        CGContextRef context = UIGraphicsGetCurrentContext();
        // 设置白色背景
        CGContextSetRGBFillColor(context,1.0,1.0,1.0,1.0);
        CGContextFillRect(context,pageRect);
        CGContextSaveGState(context);
        // 进行翻转
        CGContextTranslateCTM(context, -pageRect.size.width/2, pageRect.size.height*1.5);
        CGContextScaleCTM(context,2, -2);
        CGContextSetInterpolationQuality(context, kCGInterpolationHigh);
        CGContextSetRenderingIntent(context, kCGRenderingIntentDefault);
        CGContextConcatCTM(context, CGPDFPageGetDrawingTransform(page, kCGPDFMediaBox, pageRect,0,true));
        CGContextDrawPDFPage(context,page);
        CGContextRestoreGState(context);
        UIImage *pdfImage = UIGraphicsGetImageFromCurrentImageContext();
        UIGraphicsEndImageContext();
        [self saveImage:pdfImage];
    }
}
 
- (void)saveImage:(UIImage*)image {
    UIImageWriteToSavedPhotosAlbum(image,self,@selector(image:didFinishSavingWithError:contextInfo:), (__bridge void*)self);
}
 
- (void)image:(UIImage*)image didFinishSavingWithError:(NSError*)error contextInfo:(void*)contextInfo {
    if (self.saveCompletion) {
        self.saveCompletion(!error);
    }
}

@end
