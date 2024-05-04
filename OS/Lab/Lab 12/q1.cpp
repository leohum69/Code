#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t sem1;


void* thread1(void* arg) {
    int *i = (int*)arg;
    sem_wait(&sem1);
    printf("Trying to Cross the Bridge by Car %d \n", *i);
    sleep(1);
    printf("Now Car %d is crossing the bridge\n", *i);
    sleep(1);
    printf("Car %d has crossed the bridge\n", *i);
    sem_post(&sem1);
    return NULL;
}

int main() {
    sem_init(&sem1, 0, 3);

    pthread_t t[15];
    int *arr[15];
    for (int i = 0; i < 15; i++) {
        arr[i] = new int(i+1);
        pthread_create(&t[i], NULL, thread1, (void*)arr[i]);
    }

    for (int i = 0; i < 15; i++) {
        pthread_join(t[i], NULL);
    }

    sem_destroy(&sem1);

    return 0;
}