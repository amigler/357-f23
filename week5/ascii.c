#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // convert to lower case
    char *p = "ABCDEFGH";
    while(*p) {
        printf("%c", *p | 0x20);  // 0x20 = ' '
        p++;
    }

    printf("\n");

    // upper()
    char *p_lower = "abcdefgh";
    while(*p_lower){
        printf("%c", *p_lower & 0x5f); // 0x5f = '_'
        p_lower++;
    }

    printf("\n");

    // toggle case
    char *p3 = "ToGgLE";
    while(*p3) {
        printf("%c", *p3 ^ 0x20);
        p3++;
    }

    printf("\n");
    
    return EXIT_SUCCESS;
}
