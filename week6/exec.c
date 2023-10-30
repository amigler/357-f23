#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int main(void) {
    int a = 4;
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) { /* specify pathname, specify environment */
        if (execle("/home/ubuntu/357/357-f23/week6/echoall",
                   "echoall", "arg1", "MY ARG2", (char *)0,  // becomes argv[]
                   env_init) < 0) {
            printf("execle error");
        }
        printf("...");
        // would not run
    }

    // wait for child
    if (waitpid(pid, NULL, 0) < 0) {
        printf("wait error");
    }
        
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) { /* specify filename, inherit environment */
        char *my_argv[] = { "echoall", "just 1 arg", (char*) 0 };
        if (execv("./echoall", my_argv) < 0) {
            printf("execlp error");
        }
    }
    
    exit(0);
}
