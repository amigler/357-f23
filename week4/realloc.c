#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b) {
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );
    return (int_a > int_b) - (int_a < int_b);
}

int main() {

    int count = 0, n = 0;
    int *array = NULL;

    printf("Enter one integer per line, q to quit.\n");
    
    while (scanf("%i", &n)) {
        void *tmp = realloc(array, (count + 1) * sizeof(int));
        printf("realloc() returned %p, size: %lu\n", tmp, (count + 1) * sizeof(int));
        if (tmp == NULL) {
            // realloc failed
            printf("realloc() failed()\n");
        } else if (tmp == array) {
            // realloc returned same space, array pointer can remain unchanged
            array[count++] = n;
        } else {
            // realloc returned different block of memory
            array = tmp;
            array[count++] = n;
        }
    }

    // sort the array using qsort() function
    qsort(array, count, sizeof(int), compare_int);

    printf("Your integers (sorted): ");
    
    for (int i = 0; i < count; i++) {
        printf("%i  ", array[i]);
    }
    printf("\n");
    
    free(array);

    return EXIT_SUCCESS;

}
