//
//  MDKeyGenerator.h
//  MDCryptor
//
//  Created by Allen on 9/17/15.
//  Copyright (c) 2015 Allen. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDApiBaseParam, MDAPIOperatorItem;
@interface MDPrivateKeyGenerator : NSObject

@property (nonatomic, strong, readonly) NSString  *base64SharedSecret;
@property (nonatomic, strong, readonly) NSString  *base64PublicKey;

@property (nonatomic, assign, readonly) NSUInteger pkVersion;


+ (instancetype)generatorWithServerPublicKey:(NSString *)spk version:(NSUInteger)version;

+ (NSString *)hashValueForData:(NSData *)data;

+ (NSString *)getAPIKeyWithVersion:(NSUInteger)version;

+ (NSString *)getWowoAPIKeyWithVersion:(NSUInteger)version;

+ (NSString *)getSayAPIKeyWithVersion:(NSUInteger)version;

#pragma mark- IMJ
+ (NSString *)getIMJKeyWithVersion:(NSUInteger)version;
+ (NSString *)getLiveIMKeyWithVersion:(NSUInteger)version;
+ (NSString *)getWowoIMKeyWithVersion:(NSUInteger)version;

#pragma mark- API
+ (NSString *)verifiedTokenWithVersion:(NSNumber *)version userID:(NSString *)uid;
+ (void)generator:(MDPrivateKeyGenerator *)generator injectPKToRequestPara:(MDApiBaseParam *)para;
+ (NSString *)generateSecretKeyForPK:(NSString *)pk;

+ (void)handleRegisterPara:(MDApiBaseParam *)para withGenerator:(MDPrivateKeyGenerator *)generator operatorItem:(MDAPIOperatorItem *)item userAgentData:(NSData *)uaData;

+ (void)handleCommonPara:(MDApiBaseParam *)para withOperatorItem:(MDAPIOperatorItem *)item userAgentData:(NSData *)uaData;

+ (NSString *)signStringForUserAgentData:(NSData *)data withTDKey:(NSString *)key;

@end
