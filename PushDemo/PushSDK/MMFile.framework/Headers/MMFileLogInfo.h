//
//  MMFileLogInfo.h
//  MMFile
//
//  Created by Dai Dongpeng on 2018/10/20.
//

#import <Foundation/Foundation.h>

@interface MMFileLogInfo : NSObject

@property (nonatomic, strong, readonly) NSArray <NSString *> *heads;
@property (nonatomic, strong, readonly) NSString *body;

- (instancetype)initWithHeads:(NSArray *)heads andBody:(NSString *)body;

- (void)pushHead:(NSString *)head;
- (void)setBody:(NSString *)body;

@end
