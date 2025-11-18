#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* myThread(void *arg) {
    printf("Thread running...\n");
    return NULL;
}

int main() {
    pthread_t t;
    pthread_attr_t attr;

    // 1️⃣ Initialize attributes
    pthread_attr_init(&attr);

    // 2️⃣ Set detach state
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    // use PTHREAD_CREATE_DETACHED for detached thread

    // 3️⃣ Set stack size (example: 1 MB)
    pthread_attr_setstacksize(&attr, 1024 * 1024);

    // 4️⃣ Set guard size (extra memory block)
    pthread_attr_setguardsize(&attr, 4096);

    // 5️⃣ Scheduling policy
    pthread_attr_setschedpolicy(&attr, SCHED_OTHER);
    // SCHED_FIFO and SCHED_RR need root permission

    // 6️⃣ Priority (schedparam struct)
    struct sched_param param;
    param.sched_priority = 0;  // 0 for normal threads
    pthread_attr_setschedparam(&attr, &param);

    // 7️⃣ Create thread with attributes
    pthread_create(&t, &attr, myThread, NULL);

    // 8️⃣ Wait (only if joinable)
    pthread_join(t, NULL);

    // 9️⃣ Destroy attribute object
    pthread_attr_destroy(&attr);

    printf("Main finished\n");
    return 0;
}

