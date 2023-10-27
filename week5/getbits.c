#include <stdio.h>

// get the nth bit of a number n
int getbit(int num, int n) {
    return (num >> n) & 0x1u;
}

// getbits:  get n bits starting at position p 
int getbits(int x, int p, int n) {
    // x >> (p+1-n) moves the desired field to the right end of the word.
    // ~0 is all 1-bits;
    //   shifting it left n positions with ~0<<n places zeros in the rightmost n bits;
    //   complementing that with ~ makes a mask with ones in the rightmost n bits.
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main(int argc, char *argv[]) {
    
}
