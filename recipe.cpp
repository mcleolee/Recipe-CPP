//
// Created by Ravin on 2022/10/31.
//
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>     //man 3 socket / man 7 ip
#include <netinet/in.h>
#include <netinet/ip.h>     /* superset of previous */
#include <sys/socket.h>     // man  3 inet_addr
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include "tcp.h"
#include <iostream>

using namespace std;
int tcp_server_init(char *ip, int port, int backlog)
{
    int listenFd_init;
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //         创建套接字
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // socket(int domain, int type, int protocol);
    // PF_INET          Internet version 4 protocols,
    // SOCK_STREAM      TCP协议 流式套接字
    // 0                0
    listenFd_init = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == listenFd_init)
    {
        perror("socket");
        return -1;
    }
    cout << "socket " << listenFd_init << " is ready\n";
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //    填充ip,端口,协议等信息
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    struct sockaddr_in server_address;  // 用于保存服务器的 info
    /*
    所以 sockaddr_in 是在头文件里定义好了的
    #include <netinet/in.h>

    如下
    // * Socket address, internet style.

    struct sockaddr_in {
        __uint8_t       sin_len;
        sa_family_t     sin_family;
        in_port_t       sin_port;
        struct  in_addr sin_addr;
        char            sin_zero[8];
    };
    */
    memset(&server_address, 0, sizeof(server_address));
    // IPV4
    // socket.h
    // #define PF_INET         AF_INET
    server_address.sin_family   =   PF_INET;
    // _endian.h
    // #define htons(x)        __DARWIN_OSSwapInt16(x)
    // 端口号 1024-49151
    server_address.sin_port     =   htons(port);
    // #include <netinet/in.h>
    /*
    * Internet address (a structure for historical reasons)

    struct in_addr {
        in_addr_t s_addr;
    };
    */
    // 转化 ip
    server_address.sin_addr.s_addr = inet_addr(ip);

    // Optimize: 设置套接字重用
    int opt = 1;
    int m   = setsockopt(listenFd_init, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(-1 == m)
    {
        perror("setsockopt");
        return -1;
    }
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //     绑定 IP 和端口等信息
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // int     bind(int, const struct sockaddr *, socklen_t) __DARWIN_ALIAS(bind);
    int ret = ::bind(listenFd_init, (struct sockaddr*)&server_address, sizeof(server_address));
    if(-1 == ret)
    {
        perror("bind");
        return -1;
    }
    cout << "bind is OK" << endl;
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    //           建立监听
    // -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    // int     listen(int, int) __DARWIN_ALIAS(listen);
    ret = listen(listenFd_init, 8);
    if(-1 == ret)
    {
        perror("listen");
        return -1;
    }
    cout << "Waiting for the client to connect..." << endl;
    return listenFd_init;
}

int tcp_server_communication(int connectFd)
{
    while(1)
    {

    }

}
