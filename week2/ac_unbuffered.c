#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// ac_unbuffered.c count all 'a' characters from a text file (using unbuffered / UNIX I/O)
// (notably, error handling is absent)

int main(int argc, char *argv[]) {

    int count;

    char c2[1]; // an array of one character
    
    int fd;
    fd = open(argv[1], O_RDONLY);
    
    while (read(fd, c2, 1) == 1) {
        if (c2[0] == 'a') {
            count = count + 1;
        }
    }

    printf("%d\n", count);

    return 0;
}
