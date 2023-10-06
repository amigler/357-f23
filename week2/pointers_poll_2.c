#include <stdio.h>
#include <stdlib.h>  // for EXIT_SUCCESS

int main(int argc, char *argv[]) {

    char *c = "t";
    
    int arr[3] = { 2, 3, 4 };
    int *p = &arr[1];
    //int *p = arr;
    //*p += 1;  // arr[0] = arr[0] + 1;

    int **dp = &p; // pointer to a pointer

        
    *(*dp) += 1;
    p += 1;
    *(*dp) += 1;

    // What values does arr hold at this point?
    // Poll:
    // A. {2, 3, 4}
    // B. {3, 4, 5}
    // C. {2, 6, 4}
    // D. {2, 4, 5}
    // E. Not sure

    printf("{ %d, %d, %d }\n", arr[0], arr[1], arr[2]);

    return EXIT_SUCCESS;
}
