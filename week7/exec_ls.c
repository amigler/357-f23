#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(void) {

    printf("before exec\n");

    char *my_argv[] = { "ls", "-l", (char*) 0 };
    char *my_env[] = { "PATH=.", "USER=me", (char*) 0 };

    if (execv("/bin/ls", my_argv) < 0) {
        printf("execv error");
    }

    /*
    int ls_fd = open("/bin/ls", O_RDONLY);
    if (fexecve(ls_fd, my_argv, my_env) < 0) {
        printf("fexecve error");
    }
    */
    
    // process never reaches this line (unless exec fails)
    printf("after exec\n");
}

