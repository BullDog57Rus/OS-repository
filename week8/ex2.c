#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    char *memory;
    for (int i = 0; i < 10; ++i) {
        memory = calloc(sizeof(char), 10 * 1024 * 1024);
        memset(memory, 0, 10 * 1024 * 1024);
        printf("Allocated %dth time\n", i);
        sleep(1);
    }
}
