#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IOLBF, 0);
    for (int i = 0; i < 5; ++i) {
        printf("H");
        sleep(1);
        printf("e");
        sleep(1);
        printf("l");
        sleep(1);
        printf("l");
        sleep(1);
        printf("o\n");
        sleep(1);
    }

    return 0;
}
