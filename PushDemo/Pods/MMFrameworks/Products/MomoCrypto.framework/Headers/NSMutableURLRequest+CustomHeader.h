//
//  NSMutableURLRequest+CustomHeader.h
//  
//
//  Created by Allen on 11/13/15.
//
//

#import <Foundation/Foundation.h>
#import "MDApiBaseParam.h"

@interface NSMutableURLRequest (CustomHeader)

- (void)injectParaToHeader:(MDApiBaseParam *)para;

@end
