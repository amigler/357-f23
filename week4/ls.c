#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    
    DIR *dp = opendir(".");
    struct dirent *de = NULL;
    struct stat fstat;
    
    while ((de = readdir(dp)) != NULL) {
        stat(de->d_name, &fstat);
        
        printf("inode: %lu, st_size: %lu, name: %s\n", de->d_ino, fstat.st_size, de->d_name);
    }

    closedir(dp);
    
    return EXIT_SUCCESS;
}
