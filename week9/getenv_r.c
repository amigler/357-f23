// Advanced Programming in UNIX Figure 12.12 A reentrant (thread-safe) version of getenv

#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

extern char **environ;  // extern tells the compiler that this variable is defined elsewhere (no space set aside in this program)
pthread_mutex_t env_mutex;
static pthread_once_t init_done = PTHREAD_ONCE_INIT;  //  static sets scope of this variable to this .c file

static void thread_init(void) {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);  // allow a thread to "relock" without first unlocking
    pthread_mutex_init(&env_mutex, &attr);
    pthread_mutexattr_destroy(&attr);
}

// caller must provide its own buffer
int getenv_r(const char *name, char *buf, int buflen) {

    // ensure that the thread_init function is called only once per process,
    // regardless of how many threads might race to call getenv_r at the same time
    pthread_once(&init_done, thread_init);
    
    len = strlen(name);
    pthread_mutex_lock(&env_lock);
    for (int i = 0; envrion[i] != NULL; i++) {
        if (strncmp(name, environ[i], len) == 0 &&
            environ[i][len] == '=') {
            int olen = strlen(&environ[i][len + 1]);
            if (olen >= buflen) {
                pthread_mutex_unlock(&env_lock);
                return ENOSPC;  // no space
            }
            strcpy(buf, &environ[i][len + 1]);
            pthread_mutex_unlock(&env_mutex);
            return 0;
        }
    }
    
    pthread_mutex_unlock(&env_lock);
    return ENOENT;  // no entry
}
