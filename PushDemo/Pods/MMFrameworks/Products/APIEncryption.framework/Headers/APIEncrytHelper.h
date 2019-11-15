//
//  APIEncrytHelper.h
//  APIEncryption
//
//  Created by Bruce on 2018/3/28.
//

#import <Foundation/Foundation.h>

@interface NSArray (APIEncJSONHelper)
- (NSString *)aPIEncJSON2String;
- (NSString *)aPIEncJSON2StringNilOptions;
@end

@interface NSDictionary (APIEncJSONHelper)
- (NSString *)aPIEncJSON2String;
- (NSString *)aPIEncJSON2StringNilOptions;
@end

@interface NSString (APIEncJSONHelper)
- (id)aPIEncObjectFromJSONString;
@end

@interface NSData (APIEncryption)
- (NSData *)aPIEncGunzippedData;
@end

@interface APIEncrytHelper : NSObject
@property (nonatomic, readonly) NSMutableDictionary   *commonHeaders;


+ (APIEncrytHelper *)defaultHelper;

- (void)setValue:(id)value forKey:(NSString *)key;
@end
