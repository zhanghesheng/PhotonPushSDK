//
//  MDAPICustomRequest.m
//  PushDemo
//
//  Created by Bruce on 2019/5/13.
//  Copyright © 2019年 Bruce. All rights reserved.
//

#import "MDAPICustomRequest.h"

@implementation MDAPICustomRequest
/*
 是否登录状态
 */
- (BOOL)isLogin{
    return YES;
}
/*
 接口请求是否被加密,YES 加密 ，NO 不加密
 */
- (BOOL)isEncrypted{
    return YES;
}
/*
 用户id
 */
- (nullable NSString *)userid{
    return @"user_id";
}

/*
 版本号，和user-agent保持一致
 */
- (NSInteger)appVersion{
    return 101;
}

/*
 是否是登录的请求
 */
- (BOOL)isLoginRequest{
     return YES;
}
/*
 是否是交换秘钥的请求
 */
- (BOOL)isExchangePKRequest{
    return YES;
}

/*
 是否是注册的请求
 */
- (BOOL)isRegisterRequest{
    return YES;
}

/*
 user-agent,类型string or data
 */
- (nullable id)userAgent{
    return @"";
}

/*
 请求的域名
 */
- (nullable NSString *)requestHost{
    return @"api.immomo.com";
}

/*
 请求的原始url
 */
- (nullable NSString *)urlString{
     return @"api.immomo.com";
}

/*
 请求的原始参数
 */
- (nullable NSDictionary<NSString *,id> *)originParameters{
    return @{};
}


/*
 请响应的header
 */
- (nullable NSDictionary<NSString *,id> *)responseHeader{
     return @{};
}

/*
 请响应的数据
 */
- (nullable NSData*)responseData{
    return nil;
}

- (void)exchangePublicKey:(void(^)(id<MMAPIEncryptionRequest> request))success failure:(void(^)(id<MMAPIEncryptionRequest> request))failure{
    MDAPICustomRequest *request = [[MDAPICustomRequest alloc] init];
    [APIEncryption encrytReuqest:request callBackQueue:dispatch_get_main_queue() completion:^(NSDictionary<NSString *,id> * _Nullable header, NSDictionary * _Nullable paramters, NSError * _Nullable error) {
        // 真实的发出请求
    }];
    
    // 请求结束后封装custom request
    MDAPICustomRequest *request;
    APIEncryption dencrytReuqest:request callBackQueue:dispatch_get_main_queue() completion:^(NSData * _Nullable responseData, NSError * _Nullable error) {
        
    }];
    
}

- (void)resendRequest:(id<MMAPIEncryptionRequest>)request{
    
}


- (nullable NSDictionary *)userInfo{
    return @{};
}
@end
