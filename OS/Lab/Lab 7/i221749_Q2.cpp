#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

void *plusz(void *arg)
{
    int sum = 0;
    for (int i = 0; i < 30; i++)
    {
        sum += arr[i];
    }
    pthread_exit((void *)sum);
}
void *mul(void *arg)
{
    int mum = 1;
    for (int i = 0; i < 30; i++)
    {
        mum *= arr[i];
    }
    pthread_exit((void *)mum);
}
int main()
{
    int n = 0;

    pthread_t t1,t2;

    pthread_create(&t1, NULL, plusz, NULL);
    pthread_create(&t2, NULL, mul, NULL);

    void * status1;
    void * status2;
    pthread_join(t1, &status1);
    pthread_join(t2, &status2);
    
    printf("In main Sum is %ld \n",status1);
    printf("In main Product is %ld \n",status2);

    return 0;
}