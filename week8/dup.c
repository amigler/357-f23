#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int f1(void);

// demonstrate dup() functions, redirect stdout to a file
int main(void) {
    int    fd;

    printf("starting dup() example\n");

    fflush(stdout);

    // create a copy of stdout file descriptor (to restore later)
    fd = dup(STDOUT_FILENO);

    // open file "dup.log" and associate it with stdout stream
    // cause anything to be written to stdout to be sent to file "dup.log"
    freopen("dup.log", "w", stdout);

    printf("calling f1()\n");
    f1();

    fflush(stdout);

    // restore stdout, clean up temporary copy
    dup2(fd, STDOUT_FILENO);
    close(fd);

    printf("process complete\n");
    exit(0);
}

int f1(void) {
    printf("message from function f1()\n");
    return 0;
}
