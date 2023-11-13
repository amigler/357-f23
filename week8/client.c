#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


    if (argc < 3) {
        printf("usage: ./client <fifo name> \"message to send\"\n");
        exit(-1);
    }
    
    int fifo_fd;
    char *server_fifo = argv[1];
    char *msg = argv[2];
    char buf[BUFSIZ];
    memset(buf, 0, sizeof(buf));
    
    fifo_fd = open(server_fifo, O_WRONLY);
    printf("fifo_fd: %d\n", fifo_fd);
    
    int n = write(fifo_fd, msg, strlen(msg));
    printf("write returned %d\n", n);
    
    close(fifo_fd);
    return 0;
}
