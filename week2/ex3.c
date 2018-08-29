#include <stdlib.h>
#include <stdio.h>

void print_line(int n_spaces, int n_stars) {
    for (int i = 0; i < n_spaces; ++i) {
        printf("%c", ' ');
    }
    for (int i = 0; i < n_stars; ++i) {
        printf("%c", '*');
    }
    for (int i = 0; i < n_spaces; ++i) {
        printf("%c", ' ');
    }
}

int main(int argc, char *argv[]) {
    int height = atoi(argv[1]);
    int star = 1;
    for (int i = height - 1; i >= 0; --i) {
        print_line(i, (2 * star++) - 1);
        printf("\n");
    }
    return 0;
}