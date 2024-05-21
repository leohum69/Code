#include <iostream>
#include <unistd.h>
using namespace std;

int i=0;

int main()
{
    printf("%d\n",i);
    fork();
    i = i+1;
    printf("%d\n",i);
    fork();
    i = i+1;
    printf("%d\n",i);
    
    return 0;
}