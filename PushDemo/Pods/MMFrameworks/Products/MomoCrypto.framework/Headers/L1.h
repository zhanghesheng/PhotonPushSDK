//
//  L1.h
//  MomoChat
//
//  Created by 晗晖 刘 on 12-9-16.
//  Copyright (c) 2012年 wemomo.com. All rights reserved.
//

#ifndef MomoChat_L1_h
#define MomoChat_L1_h

void L1Encrypt(const unsigned char *inData, unsigned int inLength ,unsigned long long int key, unsigned char *outData);

void L1Decrypt(const unsigned char *inData, unsigned int inLength ,unsigned long long int key, unsigned char *outData);

#endif
