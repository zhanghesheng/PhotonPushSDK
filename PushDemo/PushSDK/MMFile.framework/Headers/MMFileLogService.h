//
//  MMFileLogManager.h
//  Expecta
//
//  Created by Dai Dongpeng on 2018/10/20.
//

#import <Foundation/Foundation.h>

@class MMFileLogInfo, MMFileLogConfig;

@interface MMFileLogService : NSObject

@property (nonatomic, strong, readonly) MMFileLogConfig *config;
@property (nonatomic, strong, readonly) MMFileLogInfo *commonInfo;

- (instancetype)initWithConfig:(MMFileLogConfig *)config commonInfo:(MMFileLogInfo *)info;
- (void)updateCommoninfo:(MMFileLogInfo *)info;

- (void)start;
- (void)writeLog:(MMFileLogInfo *)info;
- (void)flush;
- (void)close;

@end
