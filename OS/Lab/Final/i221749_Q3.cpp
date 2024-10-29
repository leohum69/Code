#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t sem1;

pthread_mutex_t m[6];

void *eat(void *arg)
{
    int *ez = (int *)arg;
    // cout<<"hello";
    while (1)
    {
        sem_wait(&sem1);
        pthread_mutex_lock(&m[*ez + 1 % 6]);
        pthread_mutex_lock(&m[*ez]);
        sleep(1);
        cout << "Philosopher " << *ez+1 << " is eating" << endl;
        sleep(1);
        pthread_mutex_unlock(&m[*ez+1%6]);
        pthread_mutex_unlock(&m[*ez]);
        sem_post(&sem1);
        sleep(2);
    }
    return NULL;
}

int main()
{
    sem_init(&sem1, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        pthread_mutex_init(&m[i], NULL);
    }

    pthread_t phil[6];
    int *arr[6];
    for (int i = 0; i < 6; i++)
    {
        arr[i] = new int(i);
        pthread_create(&phil[i], NULL, eat, (void *)arr[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        pthread_join(phil[i],NULL);
    }
    

    return 0;
}