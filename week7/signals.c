#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void sig_handler(int);

// to send SIGUSR1 to a process: kill -USR1 <pid>

// register signal handlers for this process
int main(void) {
    if (signal(SIGUSR1, sig_handler) == SIG_ERR) {
        printf("unable to register handler for SIGUSR1");
    }
    if (signal(SIGTSTP, sig_handler) == SIG_ERR) {
        printf("unable to register handler for SIGTSTP");
    }
    if (signal(SIGUSR2, sig_handler) == SIG_ERR) {
        printf("unable to register handler for SIGUSR2");
    }
    
    for ( ; ; )
        pause();
}

void sig_handler(int signo) {

    // strsignal() returns a string description of a signal
    printf("received signal %d (%s)\n", signo, strsignal(signo));
    
    if (signo == SIGTSTP) {
        printf("received SIGTSTP (%d)\n", signo);
        signal(SIGTSTP, SIG_DFL);  // switch to default signal handler
        kill(getpid(), SIGTSTP);  // re-send SIGSTP signal to this process
    }
}
