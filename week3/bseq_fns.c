#include "bseq.h"

void read_ints(FILE *fp) {
    int oc = 0, i = 0;
    while ((oc = fread(&i, sizeof(int), 1, fp)) == 1) {
        printf("%d\n", i);
    }

    //char c = ' ';
    //fread(&c, sizeof(char), 32, fp);  // read 32 bytes/chars into the variable c
}
