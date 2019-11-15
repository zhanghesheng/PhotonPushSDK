//
//  AppDelegate.m
//  push-ios
//
//  Created by wangduanqing on 2018/12/4.
//  Copyright © 2018年 momo. All rights reserved.
//

#import "AppDelegate.h"
#import <objc/runtime.h>
#include <pushsdk/MoPushManager.h>
//#import "NSData+MoPushBase64.h"
//#import "NSString+MoPushBase64.h"

#import <APIEncryption/APIEncryption.h>
#define APP_ID @"26e61d33cefc4e2cab629715b6aa260f"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    // 初始化
    [[APIEncryption shareInstance] registerAPIKeyType:APISecKeyTypeWowoKey  kVersion:2];
    
    [MoPushManager initSDK: APP_ID];
    [MoPushManager setBuildStat:MOBuildStat_RELEASE];
    NSLog(@"RELEASE");
#ifdef DEBUG
    [MoPushManager setBuildStat:MOBuildStat_DEBUG];
    NSLog(@"DEBUG");
#elif INHOUSE
    [MoPushManager setBuildStat:MOBuildStat_INHOUSE];
    NSLog(@"INHOUSE");
#endif
    
    [MoPushManager addCommandListener:@selector(onCommand:) target:self];
    
    [self registerRemoteNotification];
    return YES;
}

- (void) onCommand:(CallbackMessage*) message  {
    NSLog(@"AppDelegate callback ----->> cmd:%d,  code: %d, message:%@", [message command],[message resultCode], [message message]);
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alertView = [[UIAlertView alloc]
                                  initWithTitle:@"操作完成"
                                  message:[message message]
                                  delegate:nil
                                  cancelButtonTitle:@"确认"
                                  otherButtonTitles:nil];
        [alertView show];
    });
    

}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"注册失败 %@", error);
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    NSLog(@"接收到通知 %@", userInfo);
    NSDictionary *aps = [userInfo objectForKey:@"aps"];
    NSString *alert = [[aps objectForKey:@"alert"] objectForKey:@"body"];
    if(alert){
        [self alert:alert];
    }
    
}

- (void) alert:(NSString *)msg
{
    UIAlertView *alertView = [[UIAlertView alloc]
                              initWithTitle:msg
                              message:nil
                              delegate:nil
                              cancelButtonTitle:@"确认"
                              otherButtonTitles:nil];
    [alertView show];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void)registerRemoteNotification {
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0) {

        UIUserNotificationSettings *uns = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound) categories:nil];
        [[UIApplication sharedApplication] registerUserNotificationSettings:uns];
        [[UIApplication sharedApplication] registerForRemoteNotifications];

    }
    else {
        UIRemoteNotificationType apn_type = (UIRemoteNotificationType)(UIRemoteNotificationTypeAlert|UIRemoteNotificationTypeSound|UIRemoteNotificationTypeBadge);
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:apn_type];
    }
    
    //iOS 10
    if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0) {
        if (@available(iOS 10.0, *)) {
            UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
            center.delegate = self;
            [center requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert) completionHandler:^(BOOL granted, NSError * _Nullable error) {
                if (!error) {
                    NSLog(@"request authorization succeeded!");
                }
            }];
        } else {
            // Fallback on earlier versions
        }
    }
   

}

// IOS 10
- (void) userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler{
    // TO_DO
    
    // 收到推送请求
    UNNotificationRequest* request = notification.request;
    // 收到推送内容
    UNNotificationContent* content = request.content;
    // 收到推送声音
    UNNotificationSound* sound = content.sound;
    // 收到推送角标
    NSNumber* badge = content.badge;
    // 收到推送标题
    NSString* title = content.title;
    // 收到推送副标题
    NSString* subtitle = content.subtitle;
    // 收到推送消息body
    NSString* body = content.body;
    // 收到推送基本信息
    NSDictionary* userInfo = content.userInfo;
    // 判断推送通知类型
    if([notification.request.trigger isKindOfClass:[UNPushNotificationTrigger class]]){
        NSLog(@"IOS 10 前台-远程推送消息 userInfo: %@",userInfo);
    }else{
        NSLog(@"IOS 10 前台-本地推送消息 badge: %@ , title: %@ , subtitle: %@ , body: %@ , userInfo: %@ ",badge,title,subtitle,body,userInfo);
    }
    NSDictionary *aps = [userInfo objectForKey:@"aps"];
    NSString *alert = [[aps objectForKey:@"alert"] objectForKey:@"body"];
    if(alert){
        [self alert:alert];
    }
    
    // IOS 10 系统要求执行， 选择是否提醒用户
    completionHandler(UNNotificationPresentationOptionBadge|
                      UNNotificationPresentationOptionAlert|
                      UNNotificationPresentationOptionSound);
    
}
//
- (void) userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler{
    //TO_DO
    
    // 收到推送请求
    UNNotificationRequest* request = response.notification.request;
    // 收到推送内容
    UNNotificationContent* content = request.content;
    // 收到推送声音
    UNNotificationSound* sound = content.sound;
    // 收到推送角标
    NSNumber* badge = content.badge;
    // 收到推送标题
    NSString* title = content.title;
    // 收到推送副标题
    NSString* subtitle = content.subtitle;
    // 收到推送消息body
    NSString* body = content.body;
    // 收到推送基本信息
    NSDictionary* userInfo = content.userInfo;
    // 判断推送通知类型
    if([response.notification.request.trigger isKindOfClass:[UNPushNotificationTrigger class]]){
        NSLog(@"IOS 10 点击-远程推送消息 userInfo: %@",userInfo);
    }else{
        NSLog(@"IOS 10 点击-本地推送消息 badge: %@ , title: %@ , subtitle: %@ , body: %@ , userInfo: %@ ",badge,title,subtitle,body,userInfo);
    }
    NSDictionary *aps = [userInfo objectForKey:@"aps"];
    NSString *alert = [[aps objectForKey:@"alert"] objectForKey:@"body"];
    if(alert){
        [self alert:alert];
    }
    
    // IOS 10 系统要求执行
    completionHandler();
}
@end
