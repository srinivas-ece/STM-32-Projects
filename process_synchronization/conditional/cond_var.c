#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
int x,y,a;
//*char name[20];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *fun(void* arg){
	printf("entering into thread 1\n");
	pthread_mutex_lock(&lock);
//	pthread_cond_wait(&cond, &lock);

	sleep(2);
	while(x >= y){
		printf("its check x :%d and y :%d\n",x,y);
		pthread_cond_wait(&cond, &lock);
		printf("after sent signel a: %d\n",a);
		pthread_mutex_unlock(&lock);
	}
//	printf("after sent signel a: %d",a);
//	printf("after sent signel name: %s",name);
	pthread_mutex_unlock(&lock);
	return NULL;
}

void *fun1(void* arg){
	printf("entereing into thread 2\n");
	sleep(1);
	pthread_mutex_lock(&lock);
	printf("fun1: Preparing data...\n");
	x=5;
	y=10;
	a=20;
	pthread_cond_signal(&cond);
	printf("fun1: Data ready, signal sent!\n");
	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(){
   	 pthread_t t1, t2;

   	 pthread_create(&t1, NULL, fun, NULL);
   	 pthread_create(&t2, NULL, fun1, NULL);

    	 pthread_join(t1, NULL);
   	 pthread_join(t2, NULL);

	  pthread_mutex_destroy(&lock);
 	  pthread_cond_destroy(&cond);

    	  return 0;
}



