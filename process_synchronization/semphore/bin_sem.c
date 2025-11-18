#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t sem;
int count = 0;

void* fun1(void*arg){
	while(1){
		sem_wait(&sem);
		count++;
		printf("inc :%d\n",count);
		sem_post(&sem);
	}sleep(1);
	pthread_exit(NULL);
}

void* fun2(void*arg){
	while(1){
		sem_wait(&sem);
		count--;
		printf("dec :%d\n",count);
                sem_post(&sem);
        }sleep(1);
        pthread_exit(NULL);
}

int main(){
	pthread_t t1,t2;
	printf("i am in main");
	
	sem_init(&sem,0,1);
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	sem_destroy(&sem);
	sleep(5);
	return 0;
}
