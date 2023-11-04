#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void charatatime(char*);

int main(int argc, char* argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0)  {
        charatatime("output from child\n");
    } else {
        charatatime("output from parent\n");
    }
    exit(0);
}

void charatatime(char* str)
{
    char* ptr;
    
    setbuf(stdout, NULL);  /* set stdout to be unbuffered */
    for (ptr = str; *ptr != 0; ++ptr) {
        putc(*ptr, stdout);
        usleep((rand() % 100) * .001);
    }
}
