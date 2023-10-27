#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// print the binary representation of an integer
void print_bits(FILE *out, uint16_t n) {
    if (n>>1) {
        print_bits(out, n>>1);
    }
    fprintf(out, "%d", n & 0x1u);
}


int main(int argc, char *argv[]) {

    // bitwise AND
    uint8_t a = 0x0Au, b = 0x0Bu;  // 00001010 / 00001011
    printf("a & b = 0x%x\n", a & b);    // Expected output: 0xa

    // ints only (this will not compile)
    //double d = 0.0;
    //printf("%x", d & 1);

    // bitwise OR
    a = 0xAAu, b=0x03u;
    printf("a | b = 0x%x\n", a | b);  // Expected: 0xab

    // bitwise XOR
    // if a==b then a^b==0
    a = 0xAFu, b=0xAFu;
    printf("a == b is %s\n", (a==b) ? "True" : "False");
    printf("a ^ b = 0x%x\n", a^b);

    // bitwise NOT
    uint16_t a16 = 0xAAAAu; // a = 1010 1010 1010 1010 == 0xAAAA
    uint16_t b16 = ~a16;     // b = 0101 0101 0101 0101 == 0x5555
    printf("a16 = 0x%x\n", a16);
    printf("b16 = 0x%x\n", b16);


    a = 0x02u;   // 0000 0010 = 0x02
    printf("a << 3 = 0x%x\n", a << 3);

    a = 0xAAu;   // 1010 1010 = 0xAA
    printf("a >> 3 = 0x%x\n", a >> 3);

    print_bits(stdout, a);
    printf("\n");

    printf("chars: \n");
    

    char a1 = 'A';
    unsigned char mask = ' ';
    printf("A = ");
    print_bits(stdout, a1);
    printf("\n");
    print_bits(stdout, mask);
    printf("\n");

    printf("space = ");
    print_bits(stdout, ' ');
    printf("\n");

    printf("a = ");
    print_bits(stdout, 'a');
    printf("\n");

    
    return EXIT_SUCCESS;
}
