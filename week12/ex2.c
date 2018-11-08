#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char **argv) {
    int flag;
    if (argc == 3 && strcmp(argv[1], "-a") == 0) {
        flag = TRUE;
    } else if (argc == 2) {
        flag = FALSE;
    } else {
        printf("Wrong arguments");
        return 0;
    }
    int wr;
    if (flag) {
        wr = 2;
    } else {
        wr = 1;
    }
    FILE *fwr;
    if (flag) {
        fwr = fopen(argv[wr], "a");
    } else {
        fwr = fopen(argv[wr], "w");
    }
    char sym;
    while (read(0, &sym, 1) > 0) {
        printf("%c", sym);
        fprintf(fwr, "%c", sym);
    }
    
    return 0;
}
