#include <stdio.h>
#include <stdlib.h>



int main() {
    char command[20];
    while (1) {
        printf("> ");
        scanf("%s", command);
        system(command);
    }
    return 0;
}
