//
//  APIEncryption.h
//  CocoaLumberjack
//
//  Created by Bruce on 2018/3/26.
//



#import <Foundation/Foundation.h>
#import "APIEncryptionConfiguration.h"
#import "APIEncyptionItem.h"
#import "APIEncrytHelper.h"
#import "APIEncryptionProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, APIStatus) {
    APIStatusNormal       = 0,
    APIStatusBlock        = 1,
};

typedef NS_ENUM(NSUInteger, APIRequestStatus) {
    APIRequestStatusNormal,
    APIRequestStatusEarlyTermination
};

typedef NS_ENUM(NSUInteger,APISecKeyType) {
    APISecKeyTypeMomoKey = 0,
    APISecKeyTypeSayKey,
    APISecKeyTypeWowoKey
};

@interface APIEncryption : NSObject

@property (nonatomic, strong) id<MMAPIEncryptionRequest>    proxyRequest;

+(instancetype)shareInstance;

+ (void)saveBindItem:(APIEncyptionItem *)item andKey:(NSString *)key;

+ (APIEncyptionItem *)bindItemWithKey:(NSString *)key;

+ (void)removeItemWithKey:(NSString *)key;

// 获取request header所需参数
+ (NSDictionary *)getItemToHeader:(APIEncyptionItem *)item;

- (void)doClearWorkWhileLogout;

- (void)registerAPIKeyType:(APISecKeyType)keyType kVersion:(NSInteger)version;
// 注册代理类，解决依赖性 加密参数配置
+(void)registeredProxyObjectWithClass:(Class)proxyClass andConfigureInfo:(APIEncryptionConfiguration *)configInfo;

+ (void)configureAPIEncryptionInfo:(APIEncryptionConfiguration *)configInfo;
// 对普通request请求参数进行加密
- (APIRequestStatus)encryptCommonRequestParamter:(APIEncyptionItem *)apiItem;

// 登入注册的request请求处理
- (APIRequestStatus)encryptRegORLoginRequestParamter:(APIEncyptionItem *)apiItem;

// 交换public key的接口
- (APIRequestStatus)encryptExchangePublicKeyRequestParamter:(APIEncyptionItem *)apiItem;

//针对普通request请求的response的处理
- (APIRequestStatus)dencryptCommonResponse:(APIEncyptionItem *)apiItem;

//针对注册登录request请求的response的处理
- (APIRequestStatus)dencryptRegORLoginResponse:(APIEncyptionItem *)apiItem andLoginType:(BOOL)isLoginType;

- (BOOL)exchangePKSuccessed:(nonnull APIEncyptionItem *)apiItem userInfo:(id)userInfo;

- (BOOL)exchangePKFailure:(nonnull APIEncyptionItem *)apiItem userInfo:(id)userInfo;



@end

@interface APIEncryption(Extension)
// 加密操作
+ (void)encrytReuqest:(nonnull id<MMAPIEncryptionRequest>)request
        callBackQueue:(nullable dispatch_queue_t)queue
           completion:(MMAPIEncryptionCompletion)completion;

//加密操作
+ (void)dencrytReuqest:(nonnull id<MMAPIEncryptionRequest>)request
         callBackQueue:(nullable dispatch_queue_t)queue
            completion:(MMAPIDecryptionCompletion)completion;

- (void)requestFailedResult:(NSSet *)failItemSet;

- (void)reEncrytRequest:(APIEncyptionItem *)apiItem;

- (NSString *)cacheKey:(nonnull id<MMAPIEncryptionRequest>)request;

@end


NS_ASSUME_NONNULL_END
