#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t mutexl;

int balance;

void *deposit(void *arg)
{
    int *tid = (int *)arg;

    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutexl);
        int readbalance = balance;
        printf("At time %d, the balance for withdrawal thread %d is %d  \n", i, *tid, balance);
        readbalance = readbalance + 11;
        // sleep(10);
        balance = readbalance;
        printf("At time %d, the balance after depositing thread %d is %d \n", i, tid, balance);
        pthread_mutex_unlock(&mutexl);
    }
    return NULL;
}
void *withdraw(void *arg)
{
    int *tid = (int *)arg;
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutexl);
        int readbalance = balance;
        if (readbalance < 10)
        {
            printf("Cant withdraw. \n");
            pthread_mutex_unlock(&mutexl);
            pthread_exit(NULL);
        }
        printf("At time %d, the balance for withdrawal thread %d is %d  \n", i, *tid, balance);
        readbalance = readbalance - 10;
        // sleep(10);
        balance = readbalance;
        printf("At time %d, the balance after depositing thread %d is %d \n", i, tid, balance);
        pthread_mutex_unlock(&mutexl);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutexl,NULL);
    pthread_t p[4];
    int *tids[4];
    for (int i = 0; i < 2; i++)
    {

        pthread_create(&p[i], NULL, &deposit, &tids[i]);
    }
    for (int i = 2; i < 4; i++)
    {
        tids[i] = new int(i);
        pthread_create(&p[i], NULL, &withdraw, &tids[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(p[i], NULL);
    }

    // cout << balance << endl;
    pthread_mutex_destroy(&mutexl);
}