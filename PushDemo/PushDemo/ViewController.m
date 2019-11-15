//
//  ViewController.m
//  push-ios
//
//  Created by wangduanqing on 2018/12/4.
//  Copyright © 2018年 momo. All rights reserved.
//

#import "ViewController.h"
#import <pushsdk/MoPushManager.h>
@interface ViewController ()<UITextFieldDelegate>
@property(nonatomic, strong)UITextField *textFiled;
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    UITextField *textFiled = [[UITextField alloc] initWithFrame:CGRectMake(10, 30, 350, 40)];
    textFiled.backgroundColor = [UIColor grayColor];
    textFiled.delegate = self;
    _textFiled = textFiled;
    [_textFiled setText:@"123456"];
    textFiled.textColor = [UIColor redColor];
    [self.view addSubview:textFiled];
    
    UIButton *aliasRegisterBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 90, 350, 40)];
    [aliasRegisterBtn setTitle:@"别名注册" forState:UIControlStateNormal];
    aliasRegisterBtn.backgroundColor = [UIColor darkGrayColor];
    [aliasRegisterBtn addTarget:self action:@selector(regiseterWithAlias:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:aliasRegisterBtn];
    
    UIButton *registerBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 150, 350, 40)];
    [registerBtn setTitle:@"注册" forState:UIControlStateNormal];
    registerBtn.backgroundColor = [UIColor darkGrayColor];
    [registerBtn addTarget:self action:@selector(regiseter:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:registerBtn];
    
    
    UIButton *unRegisterBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 210, 350, 40)];
    [unRegisterBtn setTitle:@"注销" forState:UIControlStateNormal];
    unRegisterBtn.backgroundColor = [UIColor darkGrayColor];
    [unRegisterBtn addTarget:self action:@selector(unRegiseter:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:unRegisterBtn];
    
    
    UIButton *setVendorToken = [[UIButton alloc] initWithFrame:CGRectMake(10, 270, 350, 40)];
    [setVendorToken setTitle:@"设置厂商token" forState:UIControlStateNormal];
    setVendorToken.backgroundColor = [UIColor darkGrayColor];
    [setVendorToken addTarget:self action:@selector(setVendorToken:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:setVendorToken];
    
    UIButton *aliasBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 330, 350, 40)];
    [aliasBtn setTitle:@"设置别名" forState:UIControlStateNormal];
    aliasBtn.backgroundColor = [UIColor darkGrayColor];
    [aliasBtn addTarget:self action:@selector(alias:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:aliasBtn];
    
    UIButton *unAliasBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 390, 350, 40)];
    [unAliasBtn setTitle:@"取消别名设置" forState:UIControlStateNormal];
    unAliasBtn.backgroundColor = [UIColor darkGrayColor];
    [unAliasBtn addTarget:self action:@selector(unAlias:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:unAliasBtn];
    
    UIButton *uploadBtn = [[UIButton alloc] initWithFrame:CGRectMake(10, 390, 450, 40)];
    [uploadBtn setTitle:@"上传log" forState:UIControlStateNormal];
    uploadBtn.backgroundColor = [UIColor darkGrayColor];
    [uploadBtn addTarget:self action:@selector(uploadLog:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:uploadBtn];
    
    
    
}

- (void)regiseterWithAlias:(id)sender {
    if (_textFiled.text.length) {
        [MoPushManager registerWithAlias:_textFiled.text];
    } else {
        [self alert:@"你得先输入别名啊哥"];
    }
}

- (void) alert:(NSString *)msg {
    UIAlertView *alertView = [[UIAlertView alloc]
                              initWithTitle:msg
                              message:nil
                              delegate:nil
                              cancelButtonTitle:@"确认"
                              otherButtonTitles:nil];
    [alertView show];
}

- (void)regiseter:(id)sender {
    [MoPushManager  registerToken];
}

- (void)unRegiseter:(id)sender {
    [MoPushManager logout:nil];
}

- (void)alias:(id)sender {
    [MoPushManager setAlias:nil alias:@"123456"];
}

- (void)unAlias:(id)sender {
    [MoPushManager unAlias:nil alias:@"123456"];
}

- (void)uploadLog:(id)sender{
    [MoPushManager uploadLog];
}
- (void)setVendorToken:(id)sender {
//    [[MoPushManager shareInstance] regVendor:@"T-6af871013c324e949eaf3cc67f5a9876-0527-0" vendorToken:@"a187b15e c19cd523 0fec0326 084cfcfa a574b4ab 1503e4b3 49bfb11d b8ddc192"];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    return [textField resignFirstResponder];
}
@end
