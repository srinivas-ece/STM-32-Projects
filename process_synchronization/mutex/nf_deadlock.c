#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock;

//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void nested_function() {
    printf("Inside nested_function: trying to lock again...\n");
  //  pthread_mutex_lock(&lock);   // 🔥 DEADLOCK: same thread trying to re-lock
    pthread_mutex_unlock(&lock); 
    printf("nested_function: unlocked again (won’t reach here)\n");
    pthread_mutex_lock(&lock);
    //pthread_mutex_unlock(&lock);
}

void *thread_func(void *arg) {
    printf("Thread: locking first time...\n");
    pthread_mutex_lock(&lock);
    printf("Thread: locked first time.\n");

    nested_function();  // calls function that tries to lock again

    pthread_mutex_unlock(&lock);
    printf("srinivas\n");
    return NULL;
}

int main() {
	pthread_mutex_init(&lock,NULL);
    pthread_t t;
    pthread_create(&t, NULL, thread_func, NULL);
    pthread_join(t, NULL);
    return 0;
}

