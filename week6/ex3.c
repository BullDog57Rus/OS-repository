#include <signal.h>
#include <stdlib.h>
#include <printf.h>

void handle(int signal) {
    printf("Signal %d received\n", signal);
    exit(1);
}

int main() {
    signal(SIGINT, handle);
    while (1) { }
}
