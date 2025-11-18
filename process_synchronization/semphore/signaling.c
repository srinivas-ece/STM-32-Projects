#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>
sem_t lock;

void *fun1(void *arg)
{
    sem_wait(&lock);
    printf("in thread 1\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

void *fun2(void *arg)
{
    sem_wait(&lock);
    printf("in thread 2\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

void *fun3(void *arg)
{
    sem_wait(&lock);
    printf("in thread 3\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

void *fun4(void *arg)
{
    sem_wait(&lock);
    printf("in thread 4\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

void *fun5(void *arg)
{
    sem_wait(&lock);
    printf("in thread 5\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

void *fun6(void *arg)
{
    sem_wait(&lock);
    printf("in thread 6\n");
    sem_post(&lock);
    sleep(1);
    return NULL;
}

int main()
{
    sem_init(&lock, 0, 2); // Semaphore initialized to 3
    pthread_t th1, th2, th3, th4, th5, th6;

    pthread_create(&th1, NULL, fun1, NULL);
    pthread_create(&th2, NULL, fun2, NULL);
    pthread_create(&th3, NULL, fun3, NULL);
    pthread_create(&th4, NULL, fun4, NULL);
    pthread_create(&th5, NULL, fun5, NULL);
    pthread_create(&th6, NULL, fun6, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    pthread_join(th3, NULL);
    pthread_join(th4, NULL);
    pthread_join(th5, NULL);
    pthread_join(th6, NULL);

    sem_destroy(&lock);
    return 0;
}

