#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
int a,b;
int main() {
    sem_t *sem;

    // Open the same named semaphore
    sem = sem_open("/mysem", 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    printf("Reader: Waiting for writer to signal...\n");
    sem_wait(sem);  // Wait for signal
	printf("%d\n",b);
	a=10;
    printf("Reader: Got the signal! Proceeding.\n");

    sem_close(sem);
    sem_unlink("/mysem"); // Remove the named semaphore
    return 0;
}

