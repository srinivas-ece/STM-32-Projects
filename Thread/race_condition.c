#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *threadFunc() {
    for(int i = 0; i < 1000000; i++)
        counter++; // not safe
}

int main() {
    pthread_t t1, t2 ,t3;
    pthread_create(&t1, NULL, threadFunc, NULL);
    pthread_create(&t2, NULL, threadFunc, NULL);
	pthread_create(&t3, NULL, threadFunc, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
	pthread_join(t3, NULL);
    printf("Final Counter = %d\n", counter);
    return 0;
}

