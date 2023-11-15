#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

void child(int socket) {
    const char hello[] = "hello from the child";
    write(socket, hello, sizeof(hello)); /* sizeof(char[]) includes null terminator */
}

void parent(int socket) {
    /* read child's message */
    char buf[1024];
    int n = read(socket, buf, sizeof(buf));
    printf("parent received '%.*s'\n", n, buf);
}

int main() {
    int fd[2];
    const int parentsocket = 0;
    const int childsocket = 1;
    pid_t pid;

    socketpair(PF_LOCAL, SOCK_STREAM, 0, fd);

    pid = fork();
    if (pid == 0) { /* child */
        close(fd[parentsocket]);
        child(fd[childsocket]);
    } else { /*  parent */
        close(fd[childsocket]);
        parent(fd[parentsocket]);
    }
    exit(0); 
}
