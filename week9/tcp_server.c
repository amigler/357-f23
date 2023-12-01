#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define DEFAULT_BACKLOG 100
#define MESG "Hello, TCP Client.\n"
#define MAXLEN 1000

int main(int argc, char *argv[]) {
    int mlen, sock_fd, newsock, port = 10000;
    struct sockaddr_in sa, newsockinfo, peerinfo;
    socklen_t len;
    
    char localaddr[INET_ADDRSTRLEN], peeraddr[INET_ADDRSTRLEN], buff[MAXLEN+1];
    
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(sock_fd, (struct sockaddr *) &sa, sizeof(sa));
    
    listen(sock_fd, DEFAULT_BACKLOG);
    
    len = sizeof(newsockinfo); 
    newsock = accept(sock_fd, (struct sockaddr *) &peerinfo, &len);
    
    len = sizeof(newsockinfo);
    getsockname(newsock, (struct sockaddr *) &newsockinfo, &len);
    
    inet_ntop(AF_INET, &newsockinfo.sin_addr.s_addr, localaddr, sizeof(localaddr));
    inet_ntop(AF_INET, &peerinfo.sin_addr.s_addr, peeraddr, sizeof(peeraddr));
    
    printf("New Connection: %s:%d->%s:%d\n", peeraddr, ntohs(peerinfo.sin_port), localaddr, ntohs(newsockinfo.sin_port));
    

    mlen = recv(newsock, buff, sizeof(buff), 0);
    write(STDOUT_FILENO,buff,mlen);
    mlen = send(newsock, MESG, strlen(MESG), 0);
    
    shutdown(sock_fd, SHUT_RDWR);
    shutdown(newsock, SHUT_RDWR);
    
    return 0;
}
