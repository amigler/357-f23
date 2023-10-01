#include <stdio.h>

// function declaration
void filecopy(FILE *, FILE *);

// cat:  concatenate files
// From The C Programming Language, Section 7.5
int main(int argc, char *argv[])
{
    FILE *fp;
    if (argc == 1) { // no args; copy standard input
        filecopy(stdin, stdout);
    } else {
        for (int i = 1; i < argc; i++) {
            fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("cat: can't open %s\n", argv[i]);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    return 0;
}


// filecopy:  copy file ifp to file ofp using getc()
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    // while (c = getc(ifp) != EOF) { // invalid, evaluates to: c = (getc(ifp) != EOF)
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);

    }
}


// filecopy:  copy file ifp to file ofp using fgets()
void filecopy2(FILE *ifp, FILE *ofp)
{
    char str[513];
    char *p;
    while ((p = fgets(str, 512, ifp)) != NULL) {
        fputs(str, ofp);
    }
}
