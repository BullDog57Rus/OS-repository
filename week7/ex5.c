#include <stdio.h>

int main() {
    // Add malloc
    char **s = malloc(1);
    char foo[] = "Hello World";
    *s = foo;
    // Add * to print a string, not a pointer to it
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);
    return(0);
}
