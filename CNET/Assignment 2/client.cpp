#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string>
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

    int choice;
    cout << "Welcome to The FAST GRADING SYSTEM" << endl;
    cout << "Please Choose Who you are: " << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;
    cin >> choice;

    if (choice == 1)
    {
        char request[256];
        char buf[256];

        // create the socket
        int sock;
        sock = socket(AF_INET, SOCK_STREAM, 0);

        // setup an address
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(3001);

        connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
        // cout<<"xd";
        recv(sock, &buf, sizeof(buf), 0);
        // cout<<"xd";
        cout << buf;
        // cout<<"xd"; 
        cin.ignore();
        cin.getline(request,256);
        send(sock, &request,sizeof(request), 0);
        clear(buf);
        recv(sock, &buf, sizeof(buf), 0);
        cout << buf;
        close(sock);
    }
    else if (choice == 2)
    {
        char request[256];
        char buf[256];

        // create the socket
        int sock;
        sock = socket(AF_INET, SOCK_STREAM, 0);

        // setup an address
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr.s_addr = INADDR_ANY;
        server_address.sin_port = htons(3002);

        connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));

        recv(sock, &buf, sizeof(buf), 0);
        cout << buf;
        cin.ignore();
        cin.getline(request, 256);
        // cout<<request<<endl;
        // cout<<"xd0";
        send(sock, &request, sizeof(request), 0);
        clear(buf);
        recv(sock, &buf, sizeof(buf), 0);
        cout << buf;
        cout<<"teacher close";
        close(sock);
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}