#include <unistd.h>

/* copy input to output */
int main(int argc, char* argv[])
{
    char buf[10];
    int n;
    while ((n = read(0, buf, 10)) > 0) {
        write(1, buf, n);
    }
    return 0;
}
