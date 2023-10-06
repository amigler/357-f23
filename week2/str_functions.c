#include <stdio.h>
#include <stdlib.h>

void strcpy(char s[], char t[]);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);

int main(int argc, char *argv[]) {

    char str1[4] = "357";
    char str2[4] = "453";

    char *p1 = str1;
    char *p2 = str2;

    printf("Initially: str1 = %s, str2 = %s, p1 = %s, p2 = %s\n", str1, str2, p1, p2);
    printf("Initially, as pointers: str1 = %p, str2 = %p, p1 = %p, p2 = %p\n", str1, str2, p1, p2);

    // p1 = p2;  // not valid
    // str1 = str2; // not valid
    
    strcpy(str1, str2);  // ok
    strcpy(p1, p2);  // ok (same behavior)

    
    printf("After copy: str1 = %s, str2 = %s, p1 = %s, p2 = %s\n", str1, str2, p1, p2);
    printf("After copy, as pointers: str1 = %p, str2 = %p, p1 = %p, p2 = %p\n", str1, str2, p1, p2);
    
    return EXIT_SUCCESS;
}

// strlen:  return length of string s
// (from The C Programming Language, section 5.5)
int strlen(char *s) {
    char *p = s;
    while (*p != '\0') {
        p++;
    }
    return p - s;
}

// strcpy: copy t to s; array subscript version
// (from The C Programming Language, section 5.5)
// char s[] and char *s are equivalent in a function definition
void strcpy(char *s, char *t) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

// strcpy2:  copy t to s; pointer version
// (from The C Programming Language, section 5.5)
void strcpy2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

// strcpy:  copy t to s; pointer version 3
// (from The C Programming Language, section 5.5)
void strcpy3(char *s, char *t) {
    while (*s++ = *t++)  // equivalent to: while ((*s++ = *t++) != '\0')
        ;
}


