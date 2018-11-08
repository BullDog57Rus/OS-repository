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
    ssize_t result = fread(myRandomData, sizeof(char), 20, file);
    if (result < 0) {
        printf("Smth wrong");
        return 1;
    }
    printf("%s", myRandomData);
    fprintf(out, "%s", myRandomData);

    return 0;
}
