#include <unistd.h>
#include <stdio.h>

int main() {
    int n = 1337;
    if ((n = fork()) == 0) {
        printf("Hello from child %d\n", getpid());
    } else {
        printf("Hello from parent %d\n", getpid());
    }
    return 0;
}
