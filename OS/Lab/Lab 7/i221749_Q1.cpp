#include <iostream>
// #include <unistd.h>
#include <pthread.h>

using namespace std;

void *print(void *arg)
{
    printf("thread id returned by self is : %ld \n ", pthread_self());
    return 0;
}
int main()
{
    int n = 0;
    cout << "Enter The Number of Threads : ";
    cin >> n;
    pthread_t *id = new pthread_t[n];
    for (int i = 0; i < n; ++i)
    {
        pthread_create(&id[i], NULL, print, NULL);
    }

    for (int i = 0; i < n; ++i)
    {
        pthread_join(id[i], NULL);
    }
    return 0;
}