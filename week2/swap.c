#include <stdio.h>
#include <stdlib.h>

void swap_flop(int x, int y);
void swap(int *px, int *py);

int main(int argc, char *argv[]) {

    int a = 357;
    int b = 430;
    
    printf("Initially, a = %d, b = %d\n", a, b);
    
    swap_flop(a, b);
    printf("After swap_flop(), a = %d, b = %d\n", a, b);

    swap(&a, &b);
    printf("After swap(), a = %d, b = %d\n", a, b);    
    
    return EXIT_SUCCESS;
}


// recall: call by value
void swap_flop(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}
