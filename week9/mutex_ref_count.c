#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

struct foo {
    int f_count;
    pthread_mutex_t f_lock;
    int f_id;
    // additional struct members
};

// allocate the object 
struct foo *foo_alloc(int id) {
    struct foo *fp;
    
    if ((fp = malloc(sizeof(struct foo))) != NULL) {
        fp->f_count = 1;
        fp->f_id = id;
        if (pthread_mutex_init(&fp->f_lock, NULL) != 0) {
            free(fp);
            return(NULL);
        }

        // initialize structure        
    }
    return fp;
}

// add a reference to the object 
void foo_incr(struct foo *fp) {
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

// release a reference to the object 
void foo_decr(struct foo *fp) {
    pthread_mutex_lock(&fp->f_lock);
    if (--fp->f_count == 0) { // last reference, deallocate object
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        printf("ref count is 0, freeing object\n");
        free(fp);
    } else {
        pthread_mutex_unlock(&fp->f_lock);
    }
}


int main(void) {

    struct foo *f = foo_alloc(1234);


    foo_incr(f);
    printf("count: %d\n", f->f_count);
    
    foo_incr(f);
    printf("count: %d\n", f->f_count);
    
    foo_incr(f);
    printf("count: %d\n", f->f_count);

    foo_decr(f);
    printf("count: %d\n", f->f_count);
    
    foo_decr(f);
    printf("count: %d\n", f->f_count);
    
    foo_decr(f);
    printf("count: %d\n", f->f_count);

    foo_decr(f);
    printf("count: %d\n", f->f_count);  // invalid reference to free'd heap memory
    
    return 0;
}

