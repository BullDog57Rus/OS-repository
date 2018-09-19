#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void printHello(int i) {
    printf("\nHello from thread number %d, created in iteration %d", (int) pthread_self(), i);
    pthread_exit(NULL);
}

int main() {
    int n = 0;
    printf("Input the number of threads: ");
    scanf("%d", &n);
    int *threadId = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        pthread_create(&threadId[i], NULL, printHello, i);
        printf("\nCreated thread number %d, iteration %d", threadId[i], i);
    }
    pthread_exit(NULL);
}
