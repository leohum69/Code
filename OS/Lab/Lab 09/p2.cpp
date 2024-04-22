#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <cstring>
using namespace std;

int main()
{
    char buf1[256], buf2[256];

    int p1 = open("fifo1", O_RDONLY);
    int p2 = open("fifo2", O_WRONLY);
    // cout << "idr??" << endl;
    while (1)
    {
        read(p1, buf2, 256);
        cout << "Output : " << buf2 << endl;
        if (strcmp(buf2, "exit") == 0)
        {
            break;
        }
        cout << "Enter Input : ";
        cin.getline(buf1, 256);
        write(p2, buf1, 256);
        if (strcmp(buf1, "exit") == 0)
        {
            break;
        }
    }
}