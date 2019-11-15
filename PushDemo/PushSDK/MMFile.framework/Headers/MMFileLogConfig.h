//
//  MMFileLogConfig.h
//  MMFile
//
//  Created by Dai Dongpeng on 2018/10/20.
//

#import <Foundation/Foundation.h>

@interface MMFileLogConfig : NSObject

@property (nonatomic, copy) NSString *logDir;
@property (nonatomic, copy) NSString *cacheDir;
@property (nonatomic, copy) NSString *filePrefix;
@property (nonatomic, assign) NSUInteger fileMaxLength;
//@property (nonatomic, assign) NSUInteger cacheBufferSize;
@property (nonatomic, assign, getter=isCrypt) BOOL crypt;
@property (nonatomic, assign, getter=isCompress) BOOL compress;
@property (nonatomic, assign, getter=isPrintTipLog) BOOL printTipLog;


@end
