#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctime>
using namespace std;
int main()
{
    pid_t lol;
    int a = 1, b = 2, c = 3, d = 4;
    int pipe1[2];
    pipe(pipe1);
    lol = fork();
    if (lol == 0)
    {
        int res = d * a;
        close(pipe1[0]);
        write(pipe1[1], &res, sizeof(res));
        close(pipe1[1]);
        exit(0);
    }
    else
    {
        wait(NULL);
        int lol = 0;
        close(pipe1[1]);
        read(pipe1[0], &lol, sizeof(lol));
        close(pipe1[0]);
        int pipe2[2];
        pipe(pipe2);
        pid_t lol2;
        lol2 = fork();
        if (lol2 == 0)
        {
            int res2 = a + b;
            pid_t lol3;
            int pipe3[2];
            pipe(pipe3);
            lol3 = fork();
            if (lol3 == 0)
            {
                int res3 = c - a;
                close(pipe3[0]);
                write(pipe3[1], &res3, sizeof(res3));
                close(pipe3[1]);
                exit(0);
            }
            else
            {
                wait(NULL);
                int nope;
                close(pipe3[1]);
                read(pipe3[0], &nope, sizeof(nope));
                close(pipe3[0]);
                res2 = res2 + nope;
                close(pipe2[0]);
                write(pipe2[1], &res2, sizeof(res2));
                close(pipe2[1]);
            }
            exit(0);
        }
        else
        {
            wait(NULL);
            int x;
            close(pipe2[1]);
            read(pipe2[0], &x, sizeof(x));
            close(pipe2[0]);

            lol = lol * x;
            cout << lol;
        }
    }

    return 0;
}