#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int global = 2;
int main()
{

    int a,b,c,d;
    cout << "Enter Numbers: ";
    cin>>a>>b>>c>>d;

    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        int x = a+b;
        pid_t cid = fork();
        if(cid == 0){
            int l = c-a;
            exit(l);
        }
        int status = 0;
        waitpid(cid, &status, 0);

        int res = WEXITSTATUS(status);
        x = x + res;
        exit(x);
    }

    else
    {
        int ans = d * a;
        int status = 0;
        waitpid(pid, &status, 0);

        int res = WEXITSTATUS(status);
        ans = ans * res;

        cout <<"Answer of Expression : "<< ans <<endl;
    }

    return 0;
}