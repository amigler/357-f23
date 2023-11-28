#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_t ntid;

void printids(const char *s) {
    pid_t pid; pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu, ntid %lu \n", s, (unsigned long)pid,
           (unsigned long)tid, (unsigned long)ntid);
}

void * thr_fn(void *arg) {
    printids("new thread: ");
    return((void *)0);
}

int main(void) {
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    printf("ntid: %lu \n", ntid);    
    if (err != 0) {
        printf("Error: %d, can’t create thread", err);
    }

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    printf("ntid: %lu \n", ntid);
    
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    printf("ntid: %lu \n", ntid);
    
    printids("main thread:");
    
    sleep(1);
    exit(0);
}
