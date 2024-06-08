#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctime>
using namespace std;
int main()
{
    int n;

    cout << "enter n:";
    cin >> n;

    int fr = n;
    pid_t p1;
    int *rnf = new int[n];
    int *freq = new int[n];
    int pip[2];

    for (int i = 0; i < n; i++)
    {
        pipe(pip);
        p1 = fork();
        
        srand(time(NULL) + i);

        if (p1 == 0)
        {
            int randn = rand() % 10 + 1;
            cout<<randn<<endl;

            close(pip[0]);
            write(pip[1], &randn, sizeof(randn));
            close(pip[1]);
            exit(0);
        }
        else
        {
            int r = 0;
            close(pip[1]);
            read(pip[0], &r, sizeof(r));
            cout << i << ":r =" << r << endl;
            rnf[i] = r;
            close(pip[0]);
            wait(NULL);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int n1 = rnf[i];
        for (int j = 0; j < n; j++)
        {
            if (n1 == rnf[j])
            {
                freq[i]++;
            }
        }
    }

    cout << "random n:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << rnf[i];
    }

    int gr = 0;
    for (int i = 1; i < n; i++)
    {

        if (freq[i] > freq[gr])
        {
            gr = i;
        }
    }

    cout << "\nthe highest gessed number is: " << rnf[gr] << endl;
    delete[] rnf;
    return 1;
}