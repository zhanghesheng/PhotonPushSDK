//
//  MDAPIOperatorItem.h
//  
//
//  Created by Allen on 11/27/15.
//
//

#import <Foundation/Foundation.h>

@interface MDAPIOperatorItem : NSObject<NSCoding>

@property (nonatomic, copy) NSString                    *sharedSecret;
@property (nonatomic, copy) NSString                    *secretKey;

//这个只在内存中使用
@property (nonatomic, copy) NSString                    *TDKey;

- (instancetype)initWithSharedSecret:(NSString *)secret secretKey:(NSString *)key;

@end
