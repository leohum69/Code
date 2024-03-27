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
#define PORT 8080
#define MAXLINE 1024
int main()
{

    char server_message[256] = "Hi, Yes you have reached the server!";
    char buffer[MAXLINE];
    char buf1[256];
    // create the server socket
    struct sockaddr_in servaddr, cliaddr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    int len, n;

    len = sizeof(cliaddr);

    // bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    pid_t pid;
    while (1)
    {
        listen(server_socket, 5);
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        pid = fork();
        if (pid == 0)
        {
            
            int j;
            int p = recvfrom(sockfd, &j, MAXLINE, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
            j=j+5;
            sendto(sockfd, &j, sizeof(int), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
            recv(server_socket, buf1, sizeof(buf1), 0);
            cout<<int(buf1[0])<<endl<<endl;
            buf1[0]+=5;
            send(server_socket, buf1, sizeof(buf1), 0);
            cout<<"sent ?";
        }
    }

    // close the socket
    close(server_socket);

    return 0;
}