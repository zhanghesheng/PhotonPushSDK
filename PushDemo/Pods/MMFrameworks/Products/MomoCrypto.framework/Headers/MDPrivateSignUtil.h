//
//  MDPrivateSignUtil.h
//  MomoCrypto
//
//  Created by Allen on 2017/7/19.
//  Copyright © 2017年 Allen. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, MDCryptoSourceType) {
    MDCryptoSourceTypeAPI       = 1,
    MDCryptoSourceTypeIMJ       = 2,
    MDCryptoSourceTypeLiveIM    = 3
};

/**
 使用预埋的服务器公钥验证服务器使用对应私钥做的签名（私钥只有服务器才有）
 **/
@interface MDPrivateSignUtil : NSObject

/**
 @param singStr stander base64 encoded string
 **/
+ (BOOL)verifySignWithMessage:(NSString *)msgStr base64EncodedSign:(NSString *)signStr sourceType:(MDCryptoSourceType)type keyVersion:(NSUInteger)version;

@end
