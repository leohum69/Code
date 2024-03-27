#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
using namespace std;

void clear(char *msg)
{
    for (int i = 0; i < 256; i++)
    {
        msg[i] = 0;
    }
}

int main()
{

    char request1[256];
    char request2[256];
    char buf[256];
    char inp[1];

    // create the socket
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // setup an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(3001);

    connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    bool br = true;
    while (br)
    {
        recv(sock, &buf, sizeof(buf), 0);
        cout << buf;
        if(strcmp(buf,"exit")==0){
            br = false;
            break;
        }
        clear(buf);
        cout << "enter Message : ";
        cin.getline(request1, 256);
        send(sock, request1, sizeof(request1), 0);
        if(strcmp(request1,"exit")==0){
            br = false;
            break;
        }
        clear(request1);
        clear(buf);
    }

    close(sock);

    return 0;
}