#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/param.h>

#define NZERO 20;

unsigned long long count;
struct timeval end;

void checktime(char* str)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    if (tv.tv_sec >= end.tv_sec && tv.tv_usec >= end.tv_usec)
        {
            printf("%s count = %lld\n", str, count);
            exit(0);
        }
}

int main(int argc, char* argv[])
{
    pid_t pid;
    char* s;
    int nzero;
    int ret;
    int adj = 0;

    //setbuf(stdout, NULL);  // disable buffering on stdout
    nzero = NZERO;
    printf("NZERO = %d\n", nzero);
    if (argc == 2) {
            adj = strtol(argv[1], NULL, 10);
    }
    gettimeofday(&end, NULL);
    end.tv_sec += 10;  // run for 10 seconds 

    if ((pid = fork()) < 0) {
        printf("fork failed");
    } else if (pid == 0) {  // child
        s = "child";
        printf("current nice value in child is %d, adjusting by %d\n", nice(0) + nzero, adj);
        errno = 0;
        if ((ret = nice(adj)) == -1 && errno != 0) {
            printf("child set scheduling priority");
        }
        printf("now child nice value is %d\n", ret + nzero);
    } else {  // parent 
        s = "parent";
        printf("current nice value in parent is %d\n", nice(0) + nzero);
    }
    
    while (1) {
        if (++count == 0) {
            printf("%s counter wrap", s);
            exit(0);
        }
        checktime(s);
    }
}
