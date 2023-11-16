#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

static void error_exit(const char *m) { perror(m); exit(1); }

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "usage: %s <domain-sock-name> <num-chars>\n", argv[0]);
        exit(1);
    }

    const char *name = argv[1];
    int num_to_recv = atoi(argv[2]);

    struct sockaddr_un  un;

    if (strlen(name) >= sizeof(un.sun_path)) {
        errno = ENAMETOOLONG;
        error_exit("name too long");
    }

    int fd, len;

    // create a UNIX domain datagram socket
    if ((fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        error_exit("socket failed");
    }

    // remove the socket file if exists already
    unlink(name);

    // fill in the socket address structure
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, name);
    len = offsetof(struct sockaddr_un, sun_path) + strlen(name);

    // bind the name to the descriptor
    if (bind(fd, (struct sockaddr *)&un, len) < 0) {
        error_exit("bind failed");
    }

    char buf[num_to_recv + 1];

    for (;;) { // forever
        memset(buf, 0, sizeof(buf));
        int n = recv(fd, buf, num_to_recv, 0);
        if (n < 0) {
            error_exit("recv failed");
        } else {
            printf("%d bytes received: \"%s\"\n", n, buf);
        }
    }

    close(fd);
    unlink(name);
    return 0;
}
