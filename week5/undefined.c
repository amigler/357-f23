#include <stdio.h>
#include <stdlib.h>

char *create_string(char ch, int n) {
    char *new_str = malloc(sizeof(char) * (n+1));
    for (int i = 0; i < n; i++) {
        new_str[i] = ch;
    }
    new_str[n] = '\0';
    return new_str;
}

int main(int argc, char *argv[]) {
    char *str = create_string('A', 30);
    printf("%s\n", str);
    free(str);


    int *ip = (int *) str;
    ip[0] = 10;
    ip[2] = 20;
    printf("%d\n", ip[0]);
    

    /*
    str[0] = 'B';
    str[1] = 'B';
    str[2] = '\0';
    printf("%s\n", str);    
    free(str);
    */
    
    return 0;
}
