#include <arpa/inet.h>
#include <getopt.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MESG "Hello, TCP Server.\n"
#define MAXLEN 1000

int main(int argc, char *argv[]) {
    int port, len;
    int sock_fd;
    struct sockaddr_in sa;
    struct hostent *hostent;
    const char *hostname;
    char buff[MAXLEN+1];
    port = 10000;
    hostname = "localhost";
    
    hostent = gethostbyname(hostname);
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port); /* use our port */
    sa.sin_addr.s_addr = *(uint32_t *) hostent->h_addr_list[0];
    connect(sock_fd, (struct sockaddr *) &sa, sizeof(sa));
    
    len = send(sock_fd, MESG, strlen(MESG), 0);
    len = recv(sock_fd, buff, sizeof(buff), 0);
    write(STDOUT_FILENO, buff, len);
    
    shutdown(sock_fd, SHUT_RDWR);
    return 0;
}
