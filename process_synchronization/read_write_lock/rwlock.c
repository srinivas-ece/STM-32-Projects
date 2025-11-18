#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_data = 0;
pthread_rwlock_t rwlock;

void* reader(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_rdlock(&rwlock);   // Acquire read lock
        printf("Reader %d: read shared_data = %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);   // Release read lock
        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);   // Acquire write lock
        shared_data++;
        printf("Writer %d: wrote shared_data = %d\n", id, shared_data);
        pthread_rwlock_unlock(&rwlock);   // Release write lock
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t r1, r2, w1;
    int id1 = 1, id2 = 2, wid = 1;

    pthread_rwlock_init(&rwlock, NULL);

    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w1, NULL, writer, &wid);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    pthread_rwlock_destroy(&rwlock);
    return 0;
}

