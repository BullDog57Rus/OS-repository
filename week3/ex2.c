#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int s) {
    int temp = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int s;
    printf("Enter size of array: ");
    scanf("%d", &s);
    int *array = malloc(s * sizeof(int));
    printf("Enter your array in form of numbers separated with spaces: ");
    for (int i = 0; i < s; ++i) {
        scanf("%d", &array[i]);
    }
    bubble_sort(array, s);
    printf("Here is your sorted array: ");
    for (int i = 0; i < s; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}