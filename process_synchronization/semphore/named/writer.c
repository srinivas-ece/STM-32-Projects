#include <stdio.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>
int a,b;
int main() {
    sem_t *sem;

    // Create a named semaphore with initial value 0
    sem = sem_open("/mysem", O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    printf("Writer: Doing some work...\n");
    sleep(3);
    	b=20;
	printf("%d\n",a);
    printf("Writer: Work done! Signaling reader.\n");
    sem_post(sem);  // Signal the semaphore

    sem_close(sem);
    return 0;
}

