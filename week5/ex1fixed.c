#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <zconf.h>

void printHello(int i) {
    printf("\nHello from thread number %d, created in iteration %d", (int) pthread_self(), i);
    pthread_exit(NULL);
}

int main() {
    int n = 0;
    printf("Input the number of threads: ");
    scanf("%d", &n);
    pthread_t *threadId = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        pthread_create(&threadId[i], NULL, printHello, i);
        pthread_join(threadId[i], NULL);
        printf("\nCreated thread number %d, iteration %d", (int) threadId[i], i);

        /*
         * pthread_create(&threadId[i], NULL, printHello, i);
         * printf("\nCreated thread number %d, iteration %d", (int) threadId[i], i);
         * pthread_join(threadId[i], NULL);
         *
         * If we try to print main function, then join and thread function, the processor can after creation of thread
         * execute this thread, so we will get printed
         * Hello from thread number %d, created in iteration %d
         * Created thread number %d, iteration %d
         */

    }
    pthread_exit(NULL);
}
