#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t ships;
sem_t cars;
pthread_mutex_t m;
int bara = 0;
bool x = 0;

void *carthread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&m);
        if (bara == 0)
        {
            pthread_mutex_unlock(&m);
            break;
        }
        pthread_mutex_unlock(&m);
    }

    int *i = (int *)arg;
    sem_wait(&cars);
    sleep(1);
    printf("Now Car %d is crossing the bridge\n", *i);
    sleep(1);
    sem_post(&cars);
    return NULL;
}
void *newt(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&m);
        bara = 0;
        pthread_mutex_unlock(&m);
        sleep(3);
        pthread_mutex_lock(&m);
        bara = 1;
        pthread_mutex_unlock(&m);
        if (x == 1)
        {
            break;
        }
    }
    return NULL;
}
void *shipthread(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&m);
        if (bara == 0)
        {
            pthread_mutex_unlock(&m);
            break;
        }
        pthread_mutex_unlock(&m);
    }
    int *i = (int *)arg;
    sem_wait(&ships);
    sleep(1);
    printf("Now ship %d is crossing the bridge\n", *i);
    sleep(1);
    sem_post(&ships);
    return NULL;
}

int main()
{
    pthread_mutex_init(&m, NULL);
    sem_init(&ships, 0, 5);
    sem_init(&cars, 0, 4);

    pthread_t cart[20];

    int *arr1[20];
    pthread_t lol;
    pthread_create(&lol, NULL, newt, NULL);

    for (int i = 0; i < 20; i++)
    {
        arr1[i] = new int(i + 1);
        pthread_create(&cart[i], NULL, carthread, (void *)arr1[i]);
    }
    pthread_t shipt[15];
    int *arr2[15];
    for (int i = 0; i < 15; i++)
    {
        arr2[i] = new int(i + 1);
        pthread_create(&shipt[i], NULL, shipthread, (void *)arr2[i]);
    }

    for (int i = 0; i < 20; i++)
    {
        pthread_join(cart[i], NULL);
    }
    for (int i = 0; i < 15; i++)
    {
        pthread_join(shipt[i], NULL);
    }
    x = true;
    pthread_join(lol, NULL);

    sem_destroy(&ships);
    sem_destroy(&cars);
    pthread_mutex_destroy(&m);

    return 0;
}