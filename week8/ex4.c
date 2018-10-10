#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <string.h>

int main() {
    struct rusage usage;
    char *memory;
    for (int i = 0; i < 10; i++) {
        getrusage(RUSAGE_SELF, &usage);
        memory = calloc(sizeof(char), 10 * 1024 * 1024);
        memset(memory, 0, 10 * 1024 * 1024);
        sleep(1);
        fflush(stdout);
        printf("Maximum resident set size: %d\n", (int) usage.ru_maxrss);
    }
}
