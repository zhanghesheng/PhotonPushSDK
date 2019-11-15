//
//  APIEncryptionConfiguration.h
//  APIEncryption
//
//  Created by Bruce on 2018/3/26.
//

#import <Foundation/Foundation.h>
#import <MomoCrypto/MomoCrypto.h>
@interface APIEncryptionConfiguration : MDApiBaseParam
// 一些信息需要和用户绑定
@property (nonatomic, copy)NSString     *userID;

@property (nonatomic)NSInteger          appVersion;

@property (nonatomic, assign) NSInteger  keyVersion;

@property (nonatomic, copy) NSString     *pkey;
@end
