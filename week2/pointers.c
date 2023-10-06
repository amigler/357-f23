#include <stdio.h>
#include <stdlib.h>  // for EXIT_SUCCESS

int main(int argc, char* argv[]) {
    char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

    char *v = &vowels[0];

    printf("Pointer: %p, value: %c\n", v, *v);
    printf("Pointer: %p, value: %c\n", v+1, *(v+1));    
}
