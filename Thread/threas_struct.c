#include<stdio.h>
#include<string.h>
#include<pthread.h>
struct threadarg{
	int num;
	float flo;
	char name[20];
};
void *mythread(void *arg){
	struct threadarg* args = (struct threadarg*)arg;
	printf("%d\n",args->num);
	printf("%.2f",args->flo);
	printf("%s",args->name);
	return NULL;
}

int main(){
	pthread_t t;
	struct threadarg arg;
	arg.num=20;
	arg.flo=34.556;
	
	strcpy(arg.name,"srinivas");
	
	pthread_create(&t,NULL,mythread,&arg);
	pthread_join(t,NULL);
	return 0;
}


