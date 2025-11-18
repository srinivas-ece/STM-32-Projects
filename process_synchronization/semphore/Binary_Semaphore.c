#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t bin_sem;

void* worker(void* arg) {
    printf("Worker: Waiting for main to signal...\n");
    sem_wait(&bin_sem);
    printf("Worker: Signal received, starting work...\n");
    sleep(1);
    sem_post(&bin_sem);
    printf("Worker: Work done!\n");
    return NULL;
}

int main(){
	pthread_t t;
	sem_init(&bin_sem, 0, 0);
	printf("i am in main\n");
	pthread_create(&t, NULL, worker, NULL);
	printf("Main: Doing some setup work...\n");
   	sleep(2);
	printf("Main: Sending signal to worker\n");
	sem_post(&bin_sem);
	pthread_join(t,NULL);
	sem_destroy(&bin_sem);
	return 0;
}

