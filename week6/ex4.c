#include <signal.h>
#include <printf.h>
#include <stdlib.h>

void killHandler(int signal) {
    printf("Signal %d (kill) received\n", signal);
    exit(1);
}

void stopHandler(int signal) {
    printf("Signal %d (stop) received\n", signal);
    exit(1);
}

void usr1Handler(int signal) {
    printf("Signal %d (usr1) received\n", signal);
    exit(1);
}

int main() {
    signal(SIGKILL, killHandler);
    signal(SIGSTOP, stopHandler);
    signal(SIGUSR1, usr1Handler);
    while (1) { }
}
