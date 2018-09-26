#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 256

int main() {
    int ch[2];
    char str1[BUF_SIZE];
    char str2[BUF_SIZE];

    printf("Plese, enter the string: ");
    scanf("%s", str1);
    pipe(ch);

    write(ch[1], str1, BUF_SIZE);
    close(ch[1]);

    read(ch[0], str2, BUF_SIZE);
    close(ch[0]);

    printf("Here is your string: %s\n", str2);
}
