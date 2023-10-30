#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// print a description of a process exit status
void pr_exit(int status) {
    if (WIFEXITED(status)) {
        printf("normal termination, exit status = %d\n",
               WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),

#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
        "");
#endif
               
    } else if (WIFSTOPPED(status)) {
        printf("child stopped, signal number = %d\n", WSTOPSIG(status));
    }
}

// Demonstrate various exit statuses
int main(void) {
    pid_t pid;
    int status;
    
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) {  /* child */
        exit(7);
    }

    // in parent process, wait for child and print status
    if (wait(&status) != pid) {
        printf("wait error");
    }
    pr_exit(status);
    
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) {  // child 
        abort();  // generates SIGABRT
    }

    // wait for child and print status
    if (wait(&status) != pid) {
        printf("wait error");
    }
    pr_exit(status);
    
    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) { // child 
        status /= 0;  // divide by 0 generates SIGFPE
    }

    // wait for child and print status
    if (wait(&status) != pid) {
        printf("wait error");
    }
    pr_exit(status);
    
    exit(0);
}
