#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// send an integer to server via UNIX domain socket, read new value

int main(int argc, char *argv[])
{
    int socket_fd;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;
    int bytes_received, bytes_sent, integer_buffer;
    socklen_t address_length;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <server-sock-name> <int value>\n", argv[0]);
        exit(1);
    }

    int the_int = atoi(argv[2]);
    
    char *server_sock_name = argv[1];
    char *client_sock_name = "tmp";  // should be specific to this process (ie include PID)
    
    if((socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        perror("client: socket");
        return 1;
    }
    
    memset(&client_address, 0, sizeof(struct sockaddr_un));
    client_address.sun_family = AF_UNIX;
    strcpy(client_address.sun_path, client_sock_name);


    // bind client socket to name (server will discover this name via recvfrom)
    unlink(client_sock_name);
    if(bind(socket_fd, (const struct sockaddr *) &client_address,
            sizeof(struct sockaddr_un)) < 0) {
        perror("client: bind");
        return 1;
    }

    memset(&server_address, 0, sizeof(struct sockaddr_un));
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, server_sock_name);
    
    integer_buffer = the_int;
    
    bytes_sent = sendto(socket_fd, (char *) &integer_buffer, sizeof(int), 0,
                        (struct sockaddr *) &server_address,
                        sizeof(struct sockaddr_un));
    if(bytes_sent != sizeof(int)) {
        printf("incorrect size\n");
        return 1;
    }


    sleep(60);

    
    address_length = sizeof(struct sockaddr_un);
    bytes_received = recvfrom(socket_fd, (char *) &integer_buffer, sizeof(int), 0,
                              (struct sockaddr *) &server_address,
                              &address_length);

    close(socket_fd);

    if(bytes_received != sizeof(int)) {
        printf("incorrect size\n");
        return 1;
    }

    printf("%d\n", integer_buffer);

    unlink(client_sock_name);
    
    return 0;
}
