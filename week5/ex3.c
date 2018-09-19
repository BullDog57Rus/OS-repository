#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUF_SIZE 50

int count = 0;
int producerSleeping = 0;
int consumerSleeping = 1;
pthread_t producerId = 0;
pthread_t consumerId = 0;

void sleepThread(int *threadSleeping) {
    *threadSleeping = 1;
    while (*threadSleeping) {
        if (producerSleeping) {
            printf("Producer is sleeping, count = %d\n", count);
        }
        if (consumerSleeping) {
            printf("Consumer is sleeping, count = %d\n", count);
        }
    }
}

void wakeThread(int *threadSleeping) {
    *threadSleeping = 0;
}

void *producer() {
    while (1) {
        if (count == BUF_SIZE) sleepThread(&producerSleeping);
        if (!producerSleeping) {
            count++;
            printf("Inserted item\n");
            if (count == 1) {
                wakeThread(&consumerSleeping);
            }
        }
    }
}

void *consumer() {
    while (1) {
        if (count == 0) {
            sleepThread(&consumerSleeping);
        }
        if (!consumerSleeping) {
            count--;
            printf("Removed item\n");
            if (count == BUF_SIZE - 1) {
                wakeThread(&producerSleeping);
            }
        }
    }
}

int main() {
    pthread_create(&producerId, NULL, producer, NULL);
    pthread_create(&consumerId, NULL, consumer, NULL);
    pthread_exit(NULL);
}
