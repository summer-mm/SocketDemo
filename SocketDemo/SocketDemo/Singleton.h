//
//  Singleton.h
//  SocketDemo
//
//  Created by iMac on 16/6/3.
//  Copyright © 2016年 carlos_mm. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncSocket.h"



enum{
    SocketOfflineByServer,// 服务器掉线，默认为0
    SocketOfflineByUser,  // 用户主动cut
};

#define DEFINE_SHARED_INSTANCE_USING_BLOCK(block) \
static dispatch_once_t onceToken = 0; \
__strong static id sharedInstance = nil; \
dispatch_once(&onceToken, ^{ \
sharedInstance = block(); \
}); \
return sharedInstance; \

@interface Singleton : NSObject<AsyncSocketDelegate>
@property (nonatomic, strong) AsyncSocket    *socket;       // socket
@property (nonatomic, copy  ) NSString       *socketHost;   // socket的Host
@property (nonatomic, assign) UInt16         socketPort;    // socket的prot



//心跳通过计时器来实现 在singleton.h中声明一个定时器
@property (nonatomic, retain) NSTimer        *connectTimer; // 计时器


-(void)cutOffSocket; // 断开socket连接


+ (Singleton *)sharedInstance;



-(void)socketConnectHost;// socket连接
@end
