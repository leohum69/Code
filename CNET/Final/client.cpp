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
    cout << "Please Choose Who you are: " << endl;
    cout << "1. UDP" << endl;
    cout << "2. TCP" << endl;
    cin >> choice;

    if (choice == 1)
    {
        int sockfd;
        string buffer;
        struct sockaddr_in servaddr;

        // Creating socket file descriptor
        if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }

        // memset(&servaddr, 0, sizeof(servaddr));

        // Filling server information
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(3001);
        servaddr.sin_addr.s_addr = INADDR_ANY;

        int n, len;
        len = sizeof(servaddr);
        cout << "Welcome to the server\n1 - Concatinate Stirng\n2-First occurance\n3 - Compare Strings\nInput : ";
        cin >> n;
        char c1[256], c2[256];
        cin.ignore();
        cout << "Enter first string : ";
        cin.getline(c1, 256);
        cout << "Enter Second string : ";
        cin.getline(c2, 256);

        sendto(sockfd, &n, sizeof(n), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        sendto(sockfd, &c1, sizeof(c1), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        sendto(sockfd, &c2, sizeof(c2), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

        cout << recvfrom(sockfd, (char *)buffer.c_str(), 256, 0, (struct sockaddr *)&servaddr, (socklen_t *)&len) << endl;
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

        cin.ignore();
        cin.getline(request, 256);
        // cout<<request<<endl;
        // cout<<"xd0";
        send(sock, &request, sizeof(request), 0);
        clear(buf);
        recv(sock, &buf, sizeof(buf), 0);
        cout << buf;
        close(sock);
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}