/*
File: two_thread_signal.c
Compile: gcc -pthread two_thread_signal.c -o two_thread_signal
Run: ./two_thread_signal
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;   // Semaphore for signaling

// 🧵 Thread 1: Does some work and then signals Thread 2
void* thread1_func(void* arg) {
    printf("Thread 1: Doing some work...\n");
    sleep(2);
    printf("Thread 1: Work done! Sending signal to Thread 2...\n");
    sem_post(&sem);  // Signal Thread 2
    return NULL;
}

// 🧵 Thread 2: Waits for signal from Thread 1
void* thread2_func(void* arg) {
    printf("Thread 2: Waiting for signal from Thread 1...\n");
    sem_wait(&sem);  // Wait for signal
    printf("Thread 2: Received signal! Now continuing work...\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize semaphore with 0 → means Thread 2 must wait
    sem_init(&sem, 0, 0);

    // Create both threads
    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy semaphore
    sem_destroy(&sem);

    printf("Main: Both threads have finished.\n");
    return 0;
}

