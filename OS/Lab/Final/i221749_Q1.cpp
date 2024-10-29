#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <sys/wait.h>
using namespace std;

int main()
{

    srand(time(0));
    int arr[4] = {0};

    pid_t pid;
    int pipe1[2];

    for (int i = 0; i < 500; i++)
    {
        pipe(pipe1);
        pid = fork();
        srand(time(0) + getpid());
        if (pid == 0)
        {
            int vote = -1;
            while (1)
            {
                vote = rand() % 4;
                if (vote == 0)
                {
                    int lol = rand() % 10;
                    if (lol != 1)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (vote == 1)
                {
                    int lol = rand() % 10;
                    if (lol != 1 && lol != 2 && lol != 3)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (vote == 2)
                {
                    int lol = rand() % 10;
                    if (lol != 1 && lol != 2 && lol != 3 && lol != 4)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (vote == 3)
                {
                    int lol = rand() % 10;
                    if (lol != 1 && lol != 2)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            close(pipe1[0]);
            write(pipe1[1], &vote, sizeof(vote));
            close(pipe1[1]);
            exit(0);
        }
        else
        {
            wait(NULL);
            int realvote = 0;
            close(pipe1[1]);
            read(pipe1[0], &realvote, sizeof(realvote));
            arr[realvote]++;
            close(pipe1[0]);
        }
    }
    cout << "Candidate A got " << arr[0] << " votes." << endl;
    cout << "Candidate B got " << arr[1] << " votes." << endl;
    cout << "Candidate C got " << arr[2] << " votes." << endl;
    cout << "Candidate D got " << arr[3] << " votes." << endl;
    return 0;
}