//
//  TXDefaultTool.h
//  NewEquery
//
//  Created by Jayden on 2017/9/12.
//  Copyright © 2017年 benning. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TXDefaultTool : NSObject

/**
 *  保存数据到userdefault
 */
+ (void)setDefaultsValue:(id)value for:(NSString *)key;

/**
 *  从userdefault中获取数据
 */
+ (id)getValueForKey:(NSString *)key;

/**
 *  删除userdefault中数据
 */

+ (void)removeValueForKey:(NSString *)key;

/**
 *  删除数据
 */
+ (void)removeAll;


@end
