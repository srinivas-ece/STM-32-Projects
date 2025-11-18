#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>

sem_t lock;
int a=0;
void *fun(void *arg){
	printf("enter into thread 1\n");
	printf("lock for thread1\n");
	sem_wait(&lock);
	printf("%d\n",a);

}

void *fun1(void *arg){
	printf("present in thread 2\n");
	 a=3442;
	sem_post(&lock);
	printf("success transper a value\n");
}
int main(){
	pthread_t t1,t2;
	sem_init(&lock,0,0);
	pthread_create(&t1,NULL,fun,NULL);
	pthread_create(&t2,NULL,fun1,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	sem_destroy(&lock);
	printf("main is end \n");
	return 0;
}



