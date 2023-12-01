#include <arpa/inet.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MESG "Message from server\n"
#define MAXLEN 1000

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in sa;
    socklen_t len;
    
    char localaddr[INET_ADDRSTRLEN];
    char buff[MAXLEN+1];
    int port = 10000;
    
    socklen_t slen;
    
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port); // use designated port
    
    sa.sin_addr.s_addr = htonl(INADDR_ANY); // any local interfaces
    bind(sock_fd, (struct sockaddr *) &sa, sizeof(sa));  
    
    slen = sizeof(sa);
    int n = recvfrom(sock_fd, buff, sizeof(buff),0, (struct sockaddr *) &sa, &slen);

    inet_ntop(AF_INET, &sa.sin_addr.s_addr, localaddr, sizeof(localaddr));
    
    printf("Message from <%s:%d>: ", localaddr, ntohs(sa.sin_port));
    fflush(stdout);
    
    write(STDOUT_FILENO, buff, strlen(MESG));
    len = sendto(sock_fd, MESG, strlen(MESG), 0, (struct sockaddr *) &sa, sizeof(sa));
    
    shutdown(sock_fd, SHUT_RDWR);
    
    return 0;
}
