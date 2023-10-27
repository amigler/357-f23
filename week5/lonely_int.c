#include <stdio.h>
#include <stdlib.h>

int find_the_lonely_int(int *array, size_t array_size) {
    int result = 0;
    for(int i = 0; i < array_size; ++i) {
        result ^= array[i];  // result = result ^ array[i];
    }
    return result;
}

int main(int argc, char *argv[]) {

    int array[9] = { 9,1,2,3,3,8,2,1,9 };
    //int array[9] = { 1,1,2,2,3,3 }; // no solitary int
    printf("%d\n", find_the_lonely_int(array, 9));

    return EXIT_SUCCESS;
}
