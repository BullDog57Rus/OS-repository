#include <stdlib.h>
#include <stdio.h>

int main() {
    char r;
    int i = 0;
    char *string = malloc(sizeof(char));
    printf("Please, input a string: ");
    while ((r = (char) getchar()) != '\n') {
        string[i] = r;
        ++i;
        string = realloc(string, (i + 1) * sizeof(char));
    }
    string[i] = '\0';
    char *reversed = malloc(sizeof(char) * i);
    --i;
    for (int j = 0; i >= 0; ++j, --i) {
        reversed[j] = string[i];
    }
    free(string);
    printf("Here is you reversed string: %s\n", reversed);
    free(reversed);
    return 0;
}
