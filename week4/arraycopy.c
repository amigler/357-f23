#include <stdlib.h>
#include <stdio.h>

int *array_copy(int *a, int size) {
    int i, *a2;
    
    a2 = (int *) malloc(sizeof(int) * size);
    
    if (a2 == NULL) {
        return NULL;
    }
    
    for (i = 0; i < size; i++) {
        a2[i] = a[i];
    }
    
    return a2;
}

int main(int argc, char *argv[]) {
    int the_array[3] = { 3, 5, 7 };
    
    int *the_copy = array_copy(the_array, 3);

    printf("the_copy = %p\n", the_copy);
    
    // use the copied array

    free(the_copy);
    the_copy = NULL;
    
    int *new_mem = malloc(3 * sizeof(int));
    printf("new_mem = %p\n", new_mem);

    return EXIT_SUCCESS;
}
