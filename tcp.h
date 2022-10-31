//
// Created by Ravin on 2022/10/31.
//

#ifndef RECIPE_TCP_H
#define RECIPE_TCP_H

#define SERVER_IP   "127.0.0.1"     // INADDR_ANY
#define SERVER_PORT 6666

#define SIZE        1024

class connection
{
public:
    int tcp_server_init(char *ip, int port, int backlog);
    int tcp_server_communication(int connectFd);
};

#endif //RECIPE_TCP_H
