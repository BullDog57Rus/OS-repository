#include <signal.h>
#include <printf.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        while (1) {
            printf("I am alive\n");
            sleep(1);
        }
    } else {
        sleep(10);
        kill(pid, SIGTERM);
    }
    return 0;
}
