#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// emulate behavior of program 2>&1 > error.txt using dup2

int main(void) {

    
    int out_fd = open("error.txt", O_WRONLY | O_CREAT);

    printf("out_fd = %d\n", out_fd);

    perror("open");
    
    dup2(out_fd, 1);
    
    dup2(1, 2);
    
    close(out_fd);
    
    fprintf(stdout, "standard output\n");
    fprintf(stderr, "standard error\n");
    
    fflush(stdout);

    sleep(100); // see file descriptors in /proc/pid/fd 

    close(out_fd);
    
    return 0;
}
