//
// Created by Ravin on 2022/10/31.
//

#ifndef RECIPE_TCP_H
#define RECIPE_TCP_H

#define SERVER_IP   "127.0.0.1"     // INADDR_ANY
#define SERVER_PORT 6666

#define SIZE        1024
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                        SERVER
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int tcp_server_init(char *ip, int port, int backlog);
int tcp_server_communication(int connectFd);
int sign_in(char *receiveBuf);
int print(char *s);

//class connection
//{
//public:
//    int tcp_server_init(char *ip, int port, int backlog);
//    int tcp_server_communication(int connectFd);
//    int sign_in(char *receiveBuf);
//};

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                        CLIENT
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int tcp_client_init(char *ip, short port);
int tcp_client_communication(int connectFd, char buf[]);
#endif //RECIPE_TCP_H
