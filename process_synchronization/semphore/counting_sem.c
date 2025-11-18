#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

#define COUNT_MAX 6
sem_t sem;
void* fun(void* arg){
	int id=*(int*)arg;
	printf("Thread %d: waiting for resource..1.\n", id);
 	sem_wait(&sem);  // Decrease semaphore count
    	printf("Thread %d: got resource 2✅\n", id);

    	sleep(2); // Simulate work using resource

    	printf("Thread %d: releasing resource 3🌀\n", id);
    	sem_post(&sem);  // Increase semaphore count
    	return NULL;
}

 
int main(){
	pthread_t thread[6];
	int ids[6];
	sem_init(&sem,0,COUNT_MAX);
	
	for(int i=0;i<6;i++){
		ids[i]=i+1;
		pthread_create(&thread[i],NULL, fun,&ids[i]);
	}

	for(int i=0;i<6;i++){
		pthread_join(thread[i],NULL);
	}

	sem_destroy(&sem);
    return 0;
}

