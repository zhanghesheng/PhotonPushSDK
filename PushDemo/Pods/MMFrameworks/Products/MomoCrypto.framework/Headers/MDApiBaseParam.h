//
//  MDApiBaseParam.h
//  MomoCrypto
//
//  Created by Allen on 2017/9/7.
//  Copyright © 2017年 Allen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDApiBaseParam : NSObject

//当前API是否使用了最新的加密方式
@property (nonatomic, assign) BOOL                  compressed;

//当前API使用的加密密钥对应的key
@property (nonatomic, copy)   NSString              *licienceKey;

@property (nonatomic, strong) NSMutableDictionary   *paraDic;

@property (nonatomic, strong) NSDictionary          *backupDic;

@property (nonatomic, strong) NSString              *tokenString;

@property (nonatomic, assign) NSUInteger            currentLV;

@property (nonatomic, assign) NSUInteger            decodeFailedCount;

@property (nonatomic, strong) NSString              *signString;

//当前这个请求发出的时候是否处在登录状态下
@property (nonatomic, assign, getter=isLoggedIn) BOOL  loggedIn;

@end
