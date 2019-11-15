//
//  APIEncryptionProtocol.h
//  APIEncryption
//
//  Created by Bruce on 2018/3/28.
//

#import <Foundation/Foundation.h>
#import "APIEncyptionItem.h"
NS_ASSUME_NONNULL_BEGIN

@protocol MMAPIEncryptionRequest<NSObject>
/*
 是否登录状态
 */
- (BOOL)isLogin;
/*
 接口请求是否被加密,YES 加密 ，NO 不加密
 */
- (BOOL)isEncrypted;
/*
 用户id
 */
- (nullable NSString *)userid;

/*
 版本号，和user-agent保持一致
 */
- (NSInteger)appVersion;

/*
 是否是登录的请求
 */
- (BOOL)isLoginRequest;
/*
 是否是交换秘钥的请求
 */
- (BOOL)isExchangePKRequest;

/*
 是否是注册的请求
 */
- (BOOL)isRegisterRequest;

/*
 user-agent,类型string or data
 */
- (nullable id)userAgent;

/*
 请求的域名
 */
- (nullable NSString *)requestHost;

/*
 请求的原始url
 */
- (nullable NSString *)urlString;

/*
 请求的原始参数
 */
- (nullable NSDictionary<NSString *,id> *)originParameters;


/*
 请响应的header
 */
- (nullable NSDictionary<NSString *,id> *)responseHeader;

/*
 请响应的数据
 */
- (nullable NSData*)responseData;

- (void)exchangePublicKey:(void(^)(id<MMAPIEncryptionRequest> request))success failure:(void(^)(id<MMAPIEncryptionRequest> request))failure;

- (void)resendRequest:(id<MMAPIEncryptionRequest>)request;

@optional
- (nullable NSDictionary *)userInfo;



@end


@protocol APIEncryptionProtocol<NSObject>
@optional
@property (nonatomic, strong) NSMutableSet<APIEncyptionItem *>               *cacheFailedResendRequestItems;
- (void)beginExchangePKWithKey:(id)obj success:(BOOL(^)(APIEncyptionItem *apiItem))success failure:(BOOL(^)(APIEncyptionItem *apiItem))failure;
- (void)resendFailedRequest:(APIEncyptionItem *)apiItem;

// 获取userId
- (NSString *)userId;
// 判断用户是否在线
- (BOOL)isOnline;
// 设置的wowo publickey version
- (NSInteger)wowoAPIKeyVersion;
// 设置的Say publickey version
- (NSInteger)sayAPIKeyVersion;





@end
NS_ASSUME_NONNULL_END
