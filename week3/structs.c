#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct s {
        int i;
        char c;
    };

    printf("sizeof(struct s) = %lu\n", sizeof(struct s));


    /*
    union int_float_or_string {
        int ival;
        float fval;
        char *sval;
        long long ll;
    };

    typedef union int_float_or_string var;
    
    var a,b,c;

    var vars[200];

    printf("sizeof(var) = %lu\n", sizeof(var));
    printf("sizeof(vars) = %lu\n", sizeof(vars));
    */
    
    return EXIT_SUCCESS;
}
