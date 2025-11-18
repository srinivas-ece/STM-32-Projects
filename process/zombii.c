#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
	    printf("hii in start");
        sleep(10);  // parent sleeps
        printf("Parent: Done.\n");
    }
    else if (pid == 0) {
        printf("Child: Exiting.%d\n",getppid());
    }
    return 0;
}

