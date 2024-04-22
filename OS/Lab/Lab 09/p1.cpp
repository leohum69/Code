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
    if(mkfifo("fifo1", 0666) == -1)
    {
        cout << "Error in creating fifo1" << endl;
        return 1;
    }
    if(mkfifo("fifo2", 0666) == -1)
    {
        cout << "Error in creating fifo2" << endl;
        return 1;
    }
    // cout<<"idr??"<<endl;
    int p1 = open("fifo1", O_WRONLY);
    // cout<<p1;
    int p2 = open("fifo2", O_RDONLY);

    while (1)
    {
        cout<<"Enter Input : ";
        cin.getline(buf1, 256);
        write(p1, buf1, 256);
        if(strcmp(buf1, "exit") == 0)
        {
            break;
        }
        read(p2, buf2, 256);
        cout << "Output : " << buf2 << endl;
        if(strcmp(buf2, "exit") == 0)
        {
            break;
        }
    }
    

    return 0;
}