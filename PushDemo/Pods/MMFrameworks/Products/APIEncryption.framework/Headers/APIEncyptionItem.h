//
//  APIEncyptionItem.h
//  APIEncryption
//
//  Created by Bruce on 2018/3/26.
//

#import <Foundation/Foundation.h>
#import <MomoCrypto/MomoCrypto.h>
NS_ASSUME_NONNULL_BEGIN
typedef void(^MMAPIExchangePublicKeyCompletion)(NSData *_Nullable responseData,
                                                NSError *_Nullable error);

typedef void(^MMAPIEncryptionCompletion)(NSDictionary<NSString*,id> *_Nullable header,
                                         NSDictionary *_Nullable paramters,
                                         NSError *_Nullable error);

typedef void(^MMAPIDecryptionCompletion)(NSData *_Nullable responseData,
                                         NSError *_Nullable error);
@interface APIEncyptionItem : MDApiBaseParam
// 一些信息需要和用户绑定
@property (nonatomic, copy)NSString             *userID;

@property (nonatomic, copy)NSString             *requestHost;

@property (nonatomic, copy)NSString             *urlString;

@property (nonatomic, strong)NSData             *userAgentData;

@property (nonatomic, strong)NSHTTPURLResponse  *response;

//如果response存在，可以直接获取allHeaderFields，此处allHeaderFields可为nil。
@property (nonatomic, strong)NSDictionary       *allHeaderFields;

@property (nonatomic, strong)NSData             *responseData;

/**
 *存储回调（成功，失败）等信息
 *如果是Block形式，存储样式如:@[@"success":successBlock,@"failure":failureBlock]
 *如果是Delegate样式，存储样式如:
 @[@"delegate":delegateObj,@"successSelector":successMethodName,
 @"failureSelector":failedMethodName,@"errorSelector":errorMethodName]
 **/
@property (nonatomic, strong)NSMutableDictionary  *userInfo;

// 加密是失败或是响应请求失败下的网络重试
@property (nonatomic, strong)id                     resendParam;

//
@property (nonatomic, strong) dispatch_queue_t queue;

@property (nonatomic, assign) BOOL  isEncryption;

@property (nonatomic, copy)   MMAPIEncryptionCompletion  encryptionCompletion;
@property (nonatomic, copy)   MMAPIDecryptionCompletion  dencryptionCompletion;
@end
NS_ASSUME_NONNULL_END
