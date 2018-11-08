#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char **argv) {
    FILE *file = fopen("/dev/random", "r");
    FILE *out = fopen("ex1.txt", "w");
    char myRandomData[20];
    int readed = 0;
    while (readed < 20) {
        ssize_t result = fread(myRandomData + readed, sizeof(char), 1, file);
        if (result < 0) {
            printf("Error");
        }
        readed++;
    }
    printf("%s", myRandomData);
    fprintf(out, "%s", myRandomData);

    return 0;
}
