#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

typedef struct netstat_s
{

} netstat;

netstat startserv(void)
{
    int sockfd, connfd, len; 
    struct sockaddr_in server = {0}, cli = {0};  

    server.sin_addr.s_addr = htonl(0);
    server.sin_family = AF_INET; 
    server.sin_port = htons(27884);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) { fputs(strerror(errno), stderr); fputs("\n", stderr);exit(1); };
    if(bind(sockfd, (struct sockaddr*)&server, sizeof(server)) == -1) { fputs(strerror(errno), stderr); fputs("\n", stderr);exit(1); }
    if(listen(sockfd, 5) != 0) { fputs(strerror(errno), stderr); fputs("\n", stderr);exit(1); };
    connfd = accept(sockfd, (struct sockaddr*)&cli, (socklen_t*)&len); 
    if (connfd == -1) { fputs(strerror(errno), stderr); fputs("\n", stderr);exit(1); };

    char buff[128];

    memset(buff, 0, 128);
    read(connfd, buff, 128);
    printf("data: %s\n", buff);
    
    close(sockfd);
}