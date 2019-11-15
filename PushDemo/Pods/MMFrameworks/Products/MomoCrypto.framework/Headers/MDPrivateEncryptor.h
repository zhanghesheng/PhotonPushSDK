//
//  MDEncryptor.h
//  MDCryptor
//
//  Created by Allen on 9/7/15.
//  Copyright (c) 2015 Allen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDPrivateEncryptor : NSObject

+ (NSData *)encryptString:(NSString *)string withPassword:(NSString *)password error:(NSError *__autoreleasing*)error;

+ (NSData *)encryptData:(NSData *)data withPassword:(NSString *)password error:(NSError *__autoreleasing*)error;

@end
