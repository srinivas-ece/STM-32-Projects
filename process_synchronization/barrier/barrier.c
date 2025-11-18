#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t barrier1;
pthread_t t1, t2, t3;

void* function_1() {
    pthread_barrier_wait(&barrier1);
//    sleep(2);
    printf("I am thread-1\n");
    return NULL;
}

void* function_2() {
    pthread_barrier_wait(&barrier1);
  //  sleep(5);
    printf("I am thread-2\n");
    return NULL;
}

void* function_3() {
    pthread_barrier_wait(&barrier1);
    printf("I am thread-3\n");
    return NULL;
}

int main() {
    pthread_barrier_init(&barrier1, NULL, 3);

    pthread_create(&t1, NULL, function_1, NULL);
    pthread_create(&t2, NULL, function_2, NULL);
    pthread_create(&t3, NULL, function_3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_barrier_destroy(&barrier1);

    return 0;
}

