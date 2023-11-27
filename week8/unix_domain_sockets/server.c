#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// server that reads integers from client over a UNIX domain socket
// server adds 5 then sends the integer back to the client

int main(int argc, char *argv[])
{
    int socket_fd;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;
    int bytes_received, bytes_sent;
    int integer_buffer;
    socklen_t address_length = sizeof(struct sockaddr_un);

    if (argc != 2) {
        fprintf(stderr, "usage: %s <server-sock-name>\n", argv[0]);
        exit(1);
    }
    
    char *server_sock_name = argv[1];
    
    if((socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        perror("server: socket");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, server_sock_name);

    unlink(server_sock_name);
    if(bind(socket_fd, (const struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        close(socket_fd);
        perror("server: bind");
        return 1;
    }

    for(;;) {
        bytes_received = recvfrom(socket_fd, (void *) &integer_buffer, sizeof(int), 0,
                                  (struct sockaddr *) &(client_address),
                                  &address_length);

        if(bytes_received != sizeof(int)) {
            printf("did not read an int from client\n");
        } else {
            printf("received from client: %d\n", integer_buffer);
            
            integer_buffer += 5;

            bytes_sent = sendto(socket_fd, (void *) &integer_buffer, sizeof(int), 0,
                                (struct sockaddr *) &(client_address),
                                address_length);

            printf("sent to client: %d (%d bytes)\n", integer_buffer, bytes_sent);

        }
    }

    unlink(server_sock_name);
    close(socket_fd);

    return 0;
}
