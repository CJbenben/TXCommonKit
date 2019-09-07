//
//  SPHKGlobalDefine.h
//  Autoyol
//
//  Created by chenxiaojie on 18/11/14.
//  Copyright (c) 2018年 chenxiaojie. All rights reserved.
//
#import <Foundation/Foundation.h>

#ifndef Autoyol_AtzucheGlobalDefine_h
#define Autoyol_AtzucheGlobalDefine_h


#pragma mark - Block functions Block 相关

///block 声明
#ifdef NS_BLOCKS_AVAILABLE
typedef void (^AtzucheBasicBlock)(void);
typedef void (^AtzucheOperationCallBackBlock)(BOOL isSuccess, NSString *errorMsg);
typedef void (^AtzucheCallBackBlockWithResult)(BOOL isSuccess, NSString *errorCode,NSString *errorMsg,id result);
typedef void (^AtzucheArrayBlock)(NSArray *list);

typedef void (^AtzucheStrBlock)(NSString *str);
typedef void (^AtzucheIntBlock)(NSInteger count);
typedef void (^AtzucheDictBlock)(NSDictionary *dic);

typedef void (^AtzucheCallBackFailed)(NSString *errorCode,NSString *errorMsg);


#endif

#pragma mark - Extern and Inline  functions 内联函数  外联函数

/*／Atzuche_EXTERN 外联函数*/
#if !defined(SPHK_EXTERN)
#  if defined(__cplusplus)
#   define SPHK_EXTERN extern "C"
#  else
#   define SPHK_EXTERN extern
#  endif
#endif


/*Atzuche_INLINE 内联函数*/
#if !defined(Atzuche_INLINE)
# if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#  define Atzuche_INLINE static inline
# elif defined(__cplusplus)
#  define Atzuche_INLINE static inline
# elif defined(__GNUC__)
#  define Atzuche_INLINE static __inline__
# else
#  define Atzuche_INLINE static
# endif
#endif
//----------------------------------------------------------------------------------------------
#pragma mark - Nil or NULL 为空判断
//是否为空或是[NSNull null]

#define NotNilAndNull(_ref)  (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))

//字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""])||([(_ref)isEqualToString:@"<null>"])||([(_ref)isEqualToString:@"(null)"])||([(_ref)isEqualToString:@"null"]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))

//----------------------------------------------------------------------------------------------


SPHK_EXTERN id           safeObjectTxAtIndex(NSArray *arr, NSInteger index);
SPHK_EXTERN NSString     * EncodeStringFromDic(NSDictionary *dic, NSString *key);
SPHK_EXTERN NSArray      * EncodeArrayFromDic(NSDictionary *dic, NSString *key);
SPHK_EXTERN NSDictionary * EncodeDicFromDic(NSDictionary *dic, NSString *key);
SPHK_EXTERN void EncodeUnEmptyStrObjctToDic(NSMutableDictionary *dic,NSString *object, NSString *key);
SPHK_EXTERN void EncodeUnEmptyObjctToDic(NSMutableDictionary *dic,id object, NSString *key);

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

#endif
