//
//  SPHKGlobalDefine.m
//  Autoyol
//
//  Created by chenxiaojie on 18/11/14.
//  Copyright (c) 2018年 chenxiaojie. All rights reserved.
//

#import "CJGlobalDefine.h"

SPHK_EXTERN id safeObjectTxAtIndex(NSArray *arr, NSInteger index)
{
    if (IsArrEmpty(arr)) {
        //        AtzucheAssert(!IsArrEmpty(arr));
        return nil;
    }
    
    if ([arr count]-1<index) {
        //        AtzucheAssert([arr count]-1<index);
        return nil;
    }
    
    return [arr objectAtIndex:index];
}

SPHK_EXTERN NSString* EncodeStringFromDic(NSDictionary *dic, NSString *key)
{
    id temp = [dic objectForKey:key];
    if ([temp isKindOfClass:[NSString class]])
    {
        return temp;
    }
    else if ([temp isKindOfClass:[NSNumber class]])
    {
        return [temp stringValue];
    }
    return nil;
}

SPHK_EXTERN NSArray      *EncodeArrayFromDic(NSDictionary *dic, NSString *key)
{
    id temp = [dic objectForKey:key];
    if ([temp isKindOfClass:[NSArray class]])
    {
        return temp;
    }
    return nil;
}

SPHK_EXTERN NSDictionary *EncodeDicFromDic(NSDictionary *dic, NSString *key)
{
    id temp = [dic objectForKey:key];
    if ([temp isKindOfClass:[NSDictionary class]])
    {
        return temp;
    }
    return nil;
}

SPHK_EXTERN void EncodeUnEmptyStrObjctToDic(NSMutableDictionary *dic,NSString *object, NSString *key)
{
    if (IsNilOrNull(dic))
    {
        return;
    }
    
    if (IsStrEmpty(object))
    {
        return;
    }
    
    if (IsStrEmpty(key))
    {
        return;
    }
    
    [dic setObject:object forKey:key];
}

SPHK_EXTERN void EncodeUnEmptyObjctToDic(NSMutableDictionary *dic,id object, NSString *key)
{
    if (IsNilOrNull(dic))
    {
        return;
    }
    if (IsNilOrNull(object))
    {
        return;
    }
    if (IsStrEmpty(key))
    {
        return;
    }
    
    [dic setObject:object forKey:key];
}

