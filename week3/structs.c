#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct s {
        char c, c2;
    };

    printf("sizeof(int) = %lu\n", sizeof(int));
    printf("sizeof(char) = %lu\n", sizeof(char));
    printf("sizeof(struct s) = %lu\n", sizeof(struct s));


    union int_float_or_string_or_long {
        int ival;
        float fval;
        char *sval;
        long long ll;
        char c;
    };

    typedef union int_float_or_string_or_long var;
    
    var a,b,c;

    var vars[200];

    printf("sizeof(var) = %lu\n", sizeof(var));
    printf("sizeof(vars) = %lu\n", sizeof(vars));

    
    return EXIT_SUCCESS;
}
