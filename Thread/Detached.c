#include<stdio.h>
#include<pthread.h>
void *callfun(void *arg){
	printf("your in Detached fun");
	return NULL;
}
			
int main(){
	pthread_t t;
	pthread_create(&t,NULL,callfun,NULL);
	pthread_detach(t);
	printf("Main done, not waiting for thread.\n");
	sleep(2);
	return 0;   
}


