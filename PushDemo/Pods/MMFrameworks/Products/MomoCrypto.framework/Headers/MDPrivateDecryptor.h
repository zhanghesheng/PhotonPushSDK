//
//  MDDecryptor.h
//  MDCryptor
//
//  Created by Allen on 9/7/15.
//  Copyright (c) 2015 Allen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDPrivateDecryptor : NSObject

+ (NSString *)decryptString:(NSString *)string withPassword:(NSString *)password error:(NSError *__autoreleasing*)error;

+ (NSData *)decryptData:(NSData *)data withPassword:(NSString *)password error:(NSError *__autoreleasing*)error;

@end
