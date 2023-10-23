#include <stdio.h>
#include <stdlib.h>

char *create_string(char ch, int n) {
    char *new_str = malloc(sizeof(char) * (n));
    for (int i = 0; i < n; i++) {
        new_str[i] = ch;
    }
    new_str[n] = '\0';
    return new_str;
}

int main(int argc, char *argv[]) {
    char *str = create_string('A', 3);
    printf("%s\n", str);
    free(str);

    str[0] = 'B';
    str[1] = '\0';
    printf("%s\n", str);    
    
    return 0;
}
