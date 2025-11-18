#include <pthread.h> // Required for pthreads functions
#include <stdio.h>   // Required for printf

// Function that the new thread will execute
void* myThreadFunction(void* arg) {
    printf("Hello from the newly created thread!\n");
    return NULL; // Threads typically return NULL or a void* pointer
}

int main() {
    pthread_t newThread; // Declare a pthread_t variable to hold the thread ID

    // Create the new thread
    // pthread_create(thread_id, attributes, start_routine, argument)
    // - &newThread: Pointer to the pthread_t variable to store the new thread's ID
    // - NULL: Thread attributes (using default attributes here)
    // - myThreadFunction: The function the new thread will execute
    // - NULL: Argument to pass to the thread function (no argument in this case)
    if (pthread_create(&newThread, NULL, myThreadFunction, NULL) != 0) {
        perror("Error creating thread");
        return 1; // Indicate an error
    }

    printf("Hello from the main thread!\n");

    // Wait for the new thread to finish
    // pthread_join(thread_id, return_value_ptr)
    // - newThread: The ID of the thread to wait for
    // - NULL: Pointer to store the return value of the joined thread (not used here)
    if (pthread_join(newThread, NULL) != 0) {
        perror("Error joining thread");
        return 1; // Indicate an error
    }

    printf("Main thread finished after joining the new thread.\n");

    return 0; // Indicate successful execution
}
