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
            int x = rand() % 10 + 1;

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

    int max = 0;
    int e;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > max)
        {
            max = count;
            e = arr[i];
        }
    }
    cout<<e<<" is the highest number guessed by "<<max<<" Childs."<<endl;
    
    


    // wait(NULL);
}