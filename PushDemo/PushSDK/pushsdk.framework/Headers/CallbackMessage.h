//
//  CallbackMessage.h
//  pushsdk-ios
//
//  Created by wangduanqing on 2018/12/6.
//  Copyright © 2018年 momo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CallbackMessage : NSObject

/**
 注册等请求命令的编号
 */
@property (nonatomic,assign) int command;
/**
 注册等请求响应码，
 */
@property (nonatomic,assign) int resultCode;
/**
 注册等请求命令名称 比如 reg
 */
@property (nonatomic, copy) NSString *commandName;
/**
 注册等请求命令响应的内容，比如token
 */
@property (nonatomic,copy) NSString * message;

@end

NS_ASSUME_NONNULL_END
