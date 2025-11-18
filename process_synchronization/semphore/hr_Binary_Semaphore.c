#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
pthread_t t1,t2;
sem_t lock;
int count=0;

void* function_1(){
        while(1){
                sem_wait(&lock);
                count++;
                printf("i am thread=%ld: count=%d\n",pthread_self(),count);
                sem_post(&lock);
                usleep(1000);
        }

}

void* function_2(){
        while(1){
                sem_wait(&lock);
                count--;
                printf("i am thread=%ld: count=%d\n",pthread_self(),count);
                sem_post(&lock);
                usleep(1000);
        }
}

int main(){
        sem_init(&lock,0,1);
        pthread_create(&t1,NULL,function_1,NULL);
        pthread_create(&t2,NULL,function_2,NULL);

        pthread_join(t1,NULL);
        pthread_join(t2,NULL);

        sem_destroy(&lock);
        return 0;
}
