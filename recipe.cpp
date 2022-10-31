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
    
}
