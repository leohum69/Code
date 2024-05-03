#include <iostream>
#include <pthread.h>
#include <queue>
#include <mutex>
#include <ctime>
using namespace std;

pthread_mutex_t m;
class documents
{
public:
    int pages;
    documents()
    {
        pages = rand() % 40 + 10;
    }
};
class printer
{
public:
    queue<documents> q1;
    int pages;
    int id;
    printer(int x)
    {
        id = x;        
        pages = 0;
    }
};

queue<documents> q;

void *printerwork(void *arg)
{
    printer *p = (printer *)arg;
    while (true)
    {
        pthread_mutex_lock(&m);
        if (q.empty())
        {   
            pthread_mutex_unlock(&m);
            return NULL;
        }
        p->q1.push(q.front());
        q.pop();
        pthread_mutex_unlock(&m);
        while(p->q1.front().pages > p->pages)
        {
            printf("Printer %d is waiting for pages\n", p->id);
        }
        p->q1.pop();
        printf("Printer %d is printing\n", p->id);
    }
}
void *labor(void *arg)
{
    printer *p = (printer *)arg;
    while (1)
    {
        pthread_mutex_lock(&m);
        if(!p[0].q1.empty())
        {
            p[0].pages += 5;
            // printf("Added pages to printer 1 \n");
        }
        pthread_mutex_unlock(&m);
        pthread_mutex_lock(&m);
        if(!p[1].q1.empty())
        {
            p[1].pages += 5;
            // printf("Added pages to printer 2 \n");
        }
        pthread_mutex_unlock(&m);

        if(p[0].q1.empty() && p[1].q1.empty())
        {
            return NULL;
        }
    }
    
}

int main()
{
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        q.push(documents());
    }
    pthread_mutex_init(&m, NULL);
    pthread_t p1,p2;
    pthread_t l;

    printer p[2] = {printer(1), printer(2)};
    pthread_create(&p1, NULL, printerwork, &p[0]);
    pthread_create(&p2, NULL, printerwork, &p[1]);
    pthread_create(&l, NULL, labor, p);


    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(l, NULL);

    pthread_mutex_destroy(&m);

    return 0;
}
