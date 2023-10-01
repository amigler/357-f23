#include <stdio.h>

int power(int base, int n);

int main(int argc, char *argv[]) {
    printf("power(2, 5) is: %d\n", power(2, 5));
    return 0; // success
}

// function definition
// power: raise base to n-th power; n >= 0
int power(int base, int n) {
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}
