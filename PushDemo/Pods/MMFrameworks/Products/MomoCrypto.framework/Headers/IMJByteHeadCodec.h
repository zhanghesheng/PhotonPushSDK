//
//  IMJByteHeadCodec.h
//  MomoChat
//
//  Created by Allen on 27/1/15.
//  Copyright (c) 2015 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IMJHeadCodec.h"

@interface IMJByteHeadCodec : NSObject<IMJHeadCodec>

/**
 使用Lua脚本初始化一个实例
 */
- (instancetype)initWithVersion:(NSInteger)version pkVersion:(NSInteger)pkVersion;

+ (instancetype)codecWithVersion:(NSInteger)version pkVersion:(NSInteger)pkVersion;

/**
 对普通消息的head编码
 */
- (NSData *)messageHeadDataWithBodyLength:(NSUInteger)length;


- (NSData *)sauthHeadDataWithBodyLength:(NSInteger)length keyLength:(NSInteger)kLen;

/**
 pingpong的head
 */
- (NSData *)pingpongHeadData;

@end
