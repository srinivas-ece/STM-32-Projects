#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t barrier;

void* task1(void* arg) {
    printf("Thread-1 reached barrier\n");
    pthread_barrier_wait(&barrier);

    sleep(2);
    printf("Thread-1 continued after barrier\n");
    return NULL;
}

void* task2(void* arg) {
    printf("Thread-2 reached barrier\n");
    pthread_barrier_wait(&barrier);

    sleep(4);
    printf("Thread-2 continued after barrier\n");
    return NULL;
}

void* task3(void* arg) {
    printf("Thread-3 reached barrier\n");
    pthread_barrier_wait(&barrier);

    printf("Thread-3 continued after barrier\n");
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    // Initialize barrier for 3 threads
    pthread_barrier_init(&barrier, NULL,333 );

    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, task3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_barrier_destroy(&barrier);

    return 0;
}

