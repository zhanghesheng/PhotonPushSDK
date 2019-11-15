//
//  NSData+L1.h
//  MomoChat
//
//  Created by 晗晖 刘 on 12-9-16.
//  Copyright (c) 2012年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData(L1)

- (NSData *) L1Encrypt:(int)aKey;

- (NSData *) L1Decrypt:(int)aKey;

@end
