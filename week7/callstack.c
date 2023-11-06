#include<stdio.h>

int f2(int *i) {
    int j;
    j = *i;
    return j;
}

int f1(int x, int y) {
    int a;
    int b;
    b = f2(&x);
    return b;
}

int main()
{
    int c = f1(10, 30);

    printf("c = %d\n", c);
    
}
