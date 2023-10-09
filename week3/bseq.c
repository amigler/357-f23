#include <stdio.h>
#include <stdlib.h>


void read_ints(FILE *fp);

// read/write a sequence of integers from/to a file in binary format
// command line arguments: integer max, file name
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: bseq <integer> <file> OR bseq <file>\n");
        return EXIT_FAILURE;
    }

    if (argc == 2) {
        // read integers from file
        FILE *fp = fopen(argv[1], "rb");
        if (fp == NULL) {
            printf("Unable to open file, %s\n", argv[2]);
            return EXIT_FAILURE;
        }        
        read_ints(fp);
        fclose(fp);
    } else {
        // write integers 0..max to file
        int max = atoi(argv[1]);    
        FILE *fp = fopen(argv[2], "wb");
        if (fp == NULL) {
            printf("Unable to open file, %s\n", argv[2]);
            return EXIT_FAILURE;
        }
        for (int i = 0; i < max; i++) {
            int oc = fwrite(&i, sizeof(int), 1, fp);
            printf("i = %d, wrote %lu bytes\n", i, oc * sizeof(int));
        }
        fclose(fp);
    }
        
    return EXIT_SUCCESS;
}

void read_ints(FILE *fp) {
    int oc = 0, i = 0;
    while ((oc = fread(&i, sizeof(int), 1, fp)) == 1) {
        printf("%d\n", i);
    }

    //char c = ' ';
    //fread(&c, sizeof(char), 32, fp);  // read 32 bytes/chars into the variable c
}


