#include <stdio.h>
#include <stdlib.h>  // for EXIT_SUCCESS

int main(int argc, char* argv[]) {

    int a[] = { 10, 20, 30, 40, 50 };
    int *p1 = &a[3]; // 4th element in array a
    int *p2 = &a[0]; // 1st element in array a
    int *p3 = a;     // 1st element in array a
    *p1 = 100;
    *p2 = 200;
    p1[2] = 300;
    p2[1] = 400;
    p3[2] = 500;

    printf("a = %p\n", a);
    
    printf("{ %d, %d, %d, %d, %d }\n", a[0], a[1], a[2], a[3], a[4]);
    
    return EXIT_SUCCESS;
}

