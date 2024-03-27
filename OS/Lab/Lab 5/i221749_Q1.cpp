#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    int pipefd1[2];
    if (pipe(pipefd1) == -1)
        cout << "error in pipe \n";

    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 == 0)
    {
        int var = d * a;
        close(pipefd1[0]);
        write(pipefd1[1], &var, sizeof(var));
        close(pipefd1[1]);
    }
    else
    {
        int x = 0;
        close(pipefd1[1]);
        ssize_t size_byte = read(pipefd1[0], &x, sizeof(x));
        if (size_byte <= 0)
            cout << "error in reading" << endl;
        cout << "recieved :" << x <<" hehe" << "\n";
        int pipefd2[2];
        if (pipe(pipefd2) == -1)
            cout << "error in pipe \n";
        pid2 = fork();
        if (pid2 == 0)
        {
            int pipefd3[2];
            if (pipe(pipefd3) == -1)
                cout << "error in pipe \n";
            pid_t pid3;
            pid3 = fork();
            if (pid3 == 0)
            {
                int var2 = c - a;
                close(pipefd3[0]);
                write(pipefd3[1], &var2, sizeof(var2));
                close(pipefd3[1]);
            }
            else
            {
                close(pipefd3[1]);
                int z;
                ssize_t size_byte = read(pipefd3[0], &z, sizeof(z));
                if (size_byte <= 0)
                    cout << "error in reading" << endl;

                z = z + (a + b);
                // cout<<"z"<<z<<endl;
                close(pipefd2[0]);
                write(pipefd2[1], &z, sizeof(z));
                close(pipefd2[1]);
            }
        }
        else
        {
            close(pipefd2[1]);
            int y;
            ssize_t size_byte = read(pipefd2[0], &y, sizeof(y));
            if (size_byte <= 0)
                cout << "error in reading" << endl;
            cout << "Result : " << x * y << endl;
        }
    }

    return 0;
}