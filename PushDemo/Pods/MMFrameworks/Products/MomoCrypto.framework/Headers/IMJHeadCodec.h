//
//  IMJHeadCodec.h
//  MomoChat
//
//  Created by Allen on 27/1/15.
//  Copyright (c) 2015 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * ============================================
 * 根据定义好的协议生成IMJ的head
 * ============================================
 */
@protocol IMJHeadCodec <NSObject>

/**
 对普通消息的head编码
 */
- (NSData *)messageHeadDataWithBodyLength:(NSUInteger)length;

@optional

- (NSData *)sauthHeadDataWithBodyLength:(NSInteger)length keyLength:(NSInteger)kLen;

/**
 pingpong的head
 */
- (NSData *)pingpongHeadData;

@end
