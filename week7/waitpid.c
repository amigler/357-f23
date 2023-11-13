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
        printf("in child, before sleep(1)\n");
        sleep(1);
        printf("in child, before exit()\n");
        exit(7);
    }

    printf("in parent, child pid = %d\n", pid);


    printf("in parent, before wait()\n");
    // in parent process, wait for child and print status
    if (waitpid(-1, &status, 0) != pid) {   // equivalent to: if (wait(&status) != pid) {
        printf("wait error");
    }
    pr_exit(status);

    sleep(10);
    
    exit(0);
}
