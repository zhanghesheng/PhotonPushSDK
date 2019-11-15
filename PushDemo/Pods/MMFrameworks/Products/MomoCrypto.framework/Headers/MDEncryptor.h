//
//  RNEncryptor
//
//  Copyright (c) 2012 Rob Napier
//
//  This code is licensed under the MIT License:
//
//  Permission is hereby granted, free of charge, to any person obtaining a 
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//  
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import "MDCryptor.h"

@interface MDEncryptor : MDCryptor
- (MDEncryptor *)initWithSettings:(MDCryptorSettings)settings
                    encryptionKey:(NSData *)encryptionKey
                          HMACKey:(NSData *)HMACKey
                          handler:(MDCryptorHandler)handler;


- (MDEncryptor *)initWithSettings:(MDCryptorSettings)settings
                         password:(NSString *)password
                          handler:(MDCryptorHandler)handler;

// This form with manual IV is generally only used for testing
- (MDEncryptor *)initWithSettings:(MDCryptorSettings)theSettings
                    encryptionKey:(NSData *)anEncryptionKey
                          HMACKey:(NSData *)anHMACKey
                               IV:(NSData *)anIV
                          handler:(MDCryptorHandler)aHandler;

// This form with manual IV and salts is generally only used for testing
- (MDEncryptor *)initWithSettings:(MDCryptorSettings)settings
                         password:(NSString *)password
                               IV:(NSData *)anIV
                   encryptionSalt:(NSData *)anEncryptionSalt
                         HMACSalt:(NSData *)anHMACSalt
                          handler:(MDCryptorHandler)handler;


+ (NSData *)encryptData:(NSData *)data withSettings:(MDCryptorSettings)settings password:(NSString *)password error:(NSError **)error;
+ (NSData *)encryptData:(NSData *)data withSettings:(MDCryptorSettings)settings encryptionKey:(NSData *)encryptionKey HMACKey:(NSData *)HMACKey error:(NSError **)error;

// This form with manual IV is generally only used for testing
+ (NSData *)encryptData:(NSData *)thePlaintext
           withSettings:(MDCryptorSettings)theSettings
          encryptionKey:(NSData *)anEncryptionKey
                HMACKey:(NSData *)anHMACKey
                     IV:(NSData *)anIV
                  error:(NSError **)anError;

// This form with manual IV and salts is generally only used for testing
+ (NSData *)encryptData:(NSData *)data
           withSettings:(MDCryptorSettings)settings
               password:(NSString *)password
                     IV:(NSData *)anIV
         encryptionSalt:(NSData *)anEncryptionSalt
               HMACSalt:(NSData *)anHMACSalt
                  error:(NSError **)error;

@end
