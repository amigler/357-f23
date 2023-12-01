#include <arpa/inet.h>
#include <getopt.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MESG "Hello from client\n"
#define MAXLEN 1000

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in sa;
    struct hostent *hostent;
    char buff[MAXLEN+1];
    int len, mlen;
    socklen_t slen;
    int port = 10000;
    char *hostname = "localhost";
    
    hostent = gethostbyname(hostname);
    
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = *(uint32_t*) hostent->h_addr_list[0];
    mlen = strlen(MESG);
    len = sendto(sock_fd, MESG, mlen, 0, (struct sockaddr *) &sa, sizeof(sa));
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    slen = sizeof(sa);
    
    len = recvfrom(sock_fd, buff, sizeof(buff), 0, (struct sockaddr *) &sa, &slen);
    write(STDOUT_FILENO, buff, len);
    
    shutdown(sock_fd, SHUT_RDWR);
    
    return 0;
}
