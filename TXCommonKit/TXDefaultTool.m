//
//  TXDefaultTool.m
//  NewEquery
//
//  Created by Jayden on 2017/9/12.
//  Copyright © 2017年 benning. All rights reserved.
//

#import "TXDefaultTool.h"

@implementation TXDefaultTool

+ (void)setDefaultsValue:(id)value for:(NSString *)key{
    [self removeValueForKey:key];
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:value forKey:key];
    [userDefaults synchronize];
}

+ (id)getValueForKey:(NSString *)key{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults] ;
    id value = [userDefaults objectForKey:key];
    return value;
}

+ (void)removeValueForKey:(NSString *)key{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults removeObjectForKey:key];
    [userDefaults synchronize];
}

+ (void)removeAll{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    NSDictionary *dict = [userDefaults dictionaryRepresentation];
    for (id key in dict) {
        [userDefaults removeObjectForKey:key];
    }
    [userDefaults synchronize];
}

@end
