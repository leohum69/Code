#include <cstdlib>
#include <iostream>
#include <ctime>
#include <limits>
#include <string>
#include <cstring>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

class player
{
public:
    string name;
    int score;
    int turn;

    player()
    {
        turn = -1;
        score = 0;
        name = "meow";
    }
    player(string n, int s, int t)
    {
        name = n;
        score = s;
        t = turn;
    }
};
sem_t sema[5];
pthread_mutex_t m;

player p[5];
bool win = false;
int turn = 0;

void *play(void *arg)
{
    int *ez = (int *)arg;

    while (!win)
    {
        while (1)
        {
            pthread_mutex_lock(&m);
            if (turn == p[*ez].turn)
            {
                pthread_mutex_unlock(&m);
                break;
            }
            pthread_mutex_unlock(&m);
            if(win){
                return NULL;
            }
        }
        if(win){
            return NULL;
        }
        int x = -1, y = -1;

        x = rand() % 6;
        y = rand() % 6;

        if (x == y && x == 6)
        {
            p[*ez].score--;
        }
        else if (x == y)
        {
            p[*ez].score = p[*ez].score + 2;
        }
        cout << p[*ez].name << " Have " << p[*ez].score << endl;
        if (p[*ez].score >= 20)
        {
            pthread_mutex_lock(&m);
            win = true;
            cout << p[*ez].name << " won the match " << endl;
            pthread_mutex_unlock(&m);
        }
        pthread_mutex_lock(&m);
        turn++;
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

void *mast(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&m);
        if (turn == 5)
        {
            turn = 0;
            cout << endl;
            pthread_mutex_unlock(&m);
        }
        pthread_mutex_unlock(&m);

        if (win)
        {
            break;
        }
    }
    return NULL;
}

int main()
{
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        sem_init(&sema[i], 0, 1);
    }

    cout << "Hello to the game :)" << endl;
    string x;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Your name player " << i + 1 << " : ";
        getline(cin, x);
        p[i].name = x;
    }
    int lol = -1;
    bool lolb = false;
    for (int i = 0; i < 5; i++)
    {
        while (1)
        {
            lol = rand() % 5;
            for (int j = 0; j < 5; j++)
            {
                if (j == i)
                {
                    continue;
                }

                if (lol == p[j].turn)
                {
                    lolb = true;
                    break;
                }
            }
            if (lolb == true)
            {
                lolb = false;
                continue;
            }
            else
            {
                p[i].turn = lol;
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << p[i].name << " " << p[i].turn << endl;
    }

    pthread_t master;
    pthread_create(&master, NULL, mast, NULL);

    pthread_t thr[5];
    int *arr[5];

    for (int i = 0; i < 5; i++)
    {
        arr[i] = new int(i);
        pthread_create(&thr[i], NULL, play, (void *)arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(thr[i], NULL);
    }

    pthread_join(master, NULL);

    return 0;
}