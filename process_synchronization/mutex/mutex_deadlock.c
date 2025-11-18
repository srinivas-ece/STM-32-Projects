#include <pthread.h>
#include <stdio.h>
#include <unistd.h> // For sleep

// Declare and initialize mutexes globally
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thread_one_func(void* arg) {
    // Step 1: Thread 1 acquires mutex 1
    pthread_mutex_lock(&mutex1);
    printf("Thread 1 acquired mutex 1\n");

    // Give Thread 2 a chance to run and acquire mutex 2
    sleep(1);
    pthread_mutex_unlock(&mutex1);

    // Step 2: Thread 1 tries to acquire mutex 2
    printf("Thread 1 trying to acquire mutex 2...\n");
    pthread_mutex_lock(&mutex2);
    printf("Thread 1 acquired mutex 2\n"); // This line will not be reached in a deadlock

    // Critical section (not reached in this case)
    printf("Thread 1 in critical section\n");

    // Release the locks (not reached in this case)
    pthread_mutex_unlock(&mutex2);
//    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void* thread_two_func(void* arg) {
    // Step 1: Thread 2 acquires mutex 2
    pthread_mutex_lock(&mutex2);
    printf("Thread 2 acquired mutex 2\n");

    // Give Thread 1 a chance to run and acquire mutex 1
    sleep(1);
    pthread_mutex_unlock(&mutex2);

    // Step 2: Thread 2 tries to acquire mutex 1
    printf("Thread 2 trying to acquire mutex 1...\n");
    pthread_mutex_lock(&mutex1);
    printf("Thread 2 acquired mutex 1\n"); // This line will not be reached in a deadlock

    // Critical section (not reached in this case)
    printf("Thread 2 in critical section\n");

    // Release the locks (not reached in this case)
    pthread_mutex_unlock(&mutex1);
   // pthread_mutex_unlock(&mutex2);

    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create threads
    pthread_create(&t1, NULL, thread_one_func, NULL);
    pthread_create(&t2, NULL, thread_two_func, NULL);

    // Wait for threads to finish (they won't due to deadlock)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutexes (not reached due to deadlock)
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    printf("Program finished\n"); // Not reached

    return 0;
}         
