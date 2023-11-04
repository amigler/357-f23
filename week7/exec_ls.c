#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

    printf("before\n");
    
    char *my_argv[] = { "ls", "-l", (char*) 0 };
    if (execv("/bin/ls", my_argv) < 0) {
        printf("execlp error");
    }
    // process never reaches this line (unless exec fails)
    printf("after\n");
}

