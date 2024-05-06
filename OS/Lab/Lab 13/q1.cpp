#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t sem1;


void* thread1(void* arg) {
    int *i = (int*)arg;
    sem_wait(&sem1);
    printf("Trying to Eat on table by person %d \n", *i);
    sleep(1);
    printf("Now Person %d is Eating in the Restaurant\n", *i);
    sleep(1);
    printf("Person %d has eaten the Food\n", *i);
    sem_post(&sem1);
    return NULL;
}

int main() {
    sem_init(&sem1, 0, 10);

    pthread_t t[20];
    int *arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = new int(i+1);
        pthread_create(&t[i], NULL, thread1, (void*)arr[i]);
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(t[i], NULL);
    }

    sem_destroy(&sem1);

    return 0;
}