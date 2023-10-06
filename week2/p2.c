#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int a = 357;
    int b = 453;
    
    int *ip = &a;
    int *ip2 = &b;
    
    int **ipp = &ip;

    ip = &b;
    ip = ip2;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    printf("ip = %p\n", ip);
    printf("*ip = %d\n", *ip);

    printf("ipp = %p\n", ipp);
    printf("*ipp = %p\n", *ipp);
    printf("**ipp = %d\n", **ipp);
    
    return EXIT_SUCCESS;
}
