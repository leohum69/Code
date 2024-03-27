#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid;
    for (int i = 0; i < 6; i++)
    {
        pid = fork();
    }
    cout << "Hello" << endl;

    if (pid > 0)
    {
        pid_t wpid;
        int status;
        while ((wpid = wait(&status)) > 0)
            ;
    }
    return 0;
}