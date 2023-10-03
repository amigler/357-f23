#include <stdio.h>

// ac_standardio.c - count the number of 'a' characters in a file / stdin
// (notably, missing error handling)
int main(int argc, char *argv[]) {

    unsigned int count = 0;
    char c = 0;

    FILE *fp = fopen(argv[1], "r");

    /*
    while  ((c = fgetc(fp)) != EOF) {
        if (c == 'a') {
            count = count + 1;
        }
    }
    printf("a count: %d\n", count);
    */

    //char *s;  // pointer to a character (address in  memory)
    //char *s[100]; // 100 char * (100 x memory addresses)
    char s[100];  // 99 characters + NULL terminator
    while (fgets(s, 100, fp) != NULL) {
        printf("Read line: %s", s);
    }

    fclose(fp);
    
    return 0;
}
