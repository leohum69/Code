#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <sys/wait.h>
using namespace std;

int main()
{
    srand(time(0));
    cout << "Enter the number of Processes you wanna create : ";
    int n = 0;
    cin >> n;

    int *arr = new int[n];

    pid_t pid;
    int pipefd[2];
    for (int i = 0; i < n; i++)
    {

        if (pipe(pipefd) == -1)
            cout << "error in pipe \n";

        pid = fork();
        srand(time(0) + getpid());
        if (pid == 0)
        {
            int x = rand() % 3 + 1;

            close(pipefd[0]);
            write(pipefd[1], &x, sizeof(x));
            close(pipefd[1]);
            exit(0);
        }
        else
        {
            int x = 0;
            close(pipefd[1]);
            ssize_t size_byte = read(pipefd[0], &x, sizeof(x));
            if (size_byte <= 0)
                cout << "error in reading" << endl;
            cout << "recieved :" << x << "\n";
            arr[i] = x;
            close(pipefd[0]);
            wait(NULL);
        }
    }
    int a = 0, b = 0, c = 0;
    int max = 0;
    int e;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            a++;
        }
        else if (arr[i] == 2)
        {
            b++;
        }
        else
        {
            c++;
        }
    }

    cout << "Nawaz Shareef Got " << a << " Votes." << endl;
    cout << "Imran Khan Got " << b << " Votes." << endl;
    cout << "Bilawal Bhutto Got " << c << " Votes." << endl;

    if (a >= b && a >= c)
    {
        cout << "Nawaz Shareef is the highest number guessed by " << a << " Voters." << endl;
    }
    else if (b >= a && b >= c)
    {
        cout << "Imran Khan is the highest number guessed by " << b << " Voters." << endl;
    }
    else if (c >= a && c >= b)
    {
        cout << "Bilawal Bhutto is the highest number guessed by " << c << " Voters." << endl;
    }

    // if (e == 1)
    //     cout << "Nawaz Shareef is the highest number guessed by " << max << " Voters." << endl;
    // else if (e == 2)
    //     cout << "Imran Khan is the highest number guessed by " << max << " Voters." << endl;
    // else if (e == 3)
    //     cout << "Bilawal Bhutto is the highest number guessed by " << max << " Voters." << endl;

    // cout<<n

    // wait(NULL);
}