#include <dirent.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

#define ERROR 1

extern int errno;

void printAll(ino_t inod, char *path) {
    DIR *dirp = opendir(path);
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (dp->d_ino == inod) {
            printf("%s ", dp->d_name);
        }
    } 
    printf("\nDone for %llu\n", inod);
    closedir(dirp);
}

int main(int argc, char **argv) {
    DIR *dirp = opendir("tmp");
    struct dirent *dp;
    if (dirp == NULL) {
        return (ERROR);
    }
    struct stat *buf = malloc(sizeof(struct stat));
    while ((dp = readdir(dirp)) != NULL) {
        char *p = malloc(100);
        strcat(p, "tmp/");
        strcat(p, dp->d_name);
        stat(p, buf);
        printf("%d %llu %s\n", buf->st_nlink, buf->st_ino, dp->d_name);
        if (buf->st_nlink >= 2 && strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            ino_t inod = buf->st_ino;
            printf("Print all files with the same pointer:\n");
            printAll(inod, "tmp/");
        }
    }
    closedir(dirp);
    return 0;

}