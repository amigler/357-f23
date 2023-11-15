#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char buf[BUFSIZ];
    int fifo_fd, n;
    memset(buf, 0, sizeof(buf));
    
    if (argc < 2) {
        printf("usage: ./server <fifo name>");
        exit(-1);
    }
    
    char *server_fifo = argv[1];

    printf("creating fifo at: %s\n", server_fifo);
    mkfifo(server_fifo, 0666);

    fifo_fd = open(server_fifo, O_RDWR);
    while((n = read(fifo_fd, buf, BUFSIZ)) != EOF && n > 0) {
        printf("read %d, %s\n", n, buf);
        memset(buf, 0, sizeof(buf));
    }

    printf("read EOF, closing fifo: %s\n", server_fifo);
    
    close(fifo_fd);    
    unlink(server_fifo);
    return 0;
}
