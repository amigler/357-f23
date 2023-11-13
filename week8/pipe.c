#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 1024

int main(void) {
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    
    if (pipe(fd) < 0) {
        printf("pipe error");
    }
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid > 0) {  /* parent */
        close(fd[0]); 
        write(fd[1], "hello from parent\n", 18);
        sleep(1);
    } else {              /* child */
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    exit(0);
}
