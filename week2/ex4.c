#include <stdio.h>

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}

int main() {
    int a, b;
    printf("Please, input a: ");
    scanf("%d", &a);
    printf("Please, input b: ");
    scanf("%d", &b);
    swap(&a, &b);
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}
