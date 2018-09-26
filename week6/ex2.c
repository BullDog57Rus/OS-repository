#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

int main() {
    int ch[2];
    pipe(ch);
    pid_t pid = fork();

    if (pid == 0) {
        char str2[BUF_SIZE];
        close(ch[1]);
        read(ch[0], str2, BUF_SIZE);
        close(ch[0]);
        printf("Here is your string from child: %s\n", str2);
    } else {
        char str1[BUF_SIZE];
        printf("Enter your string to parent: ");
        scanf("%s", str1);
        close(ch[0]);
        write(ch[1], str1, BUF_SIZE);
        close(ch[1]);
    }
}
