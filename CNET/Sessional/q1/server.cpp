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

    char server_message[256] = "Hi, Yes you have reached the server!";
    char inp[1];
    char buf1[256];
    char buf2[256];
    char buf3[256];
    char buf4[256];
    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    pid_t pid;
    listen(server_socket, 5);
    int client_socket1[2];
    int client_socket2[2];
    client_socket1[0] = accept(server_socket, NULL, NULL);
    client_socket1[1] = accept(server_socket, NULL, NULL);
    pid = fork();
    if (pid == 0)
    {
        bool br = true;
        while (br)
        {
            recv(client_socket1[0], buf1, sizeof(buf1), 0);
            if (strcmp(buf1, "exit") == 0)
            {
                br = false;
                break;
            }
            recv(client_socket1[1], buf2, sizeof(buf1), 0);
            if (strcmp(buf2, "exit") == 0)
            {
                br = false;
                break;
            }
            send(client_socket1[1], buf1, sizeof(buf1), 0);
            send(client_socket1[0], buf2, sizeof(buf2), 0);
            clear(buf1);
            clear(buf2);
        }
        exit(0);
    }
    else
    {
        client_socket2[0] = accept(server_socket, NULL, NULL);
        client_socket2[1] = accept(server_socket, NULL, NULL);

        bool cr = true;
        while (cr)
        {
            recv(client_socket2[0], buf3, sizeof(buf3), 0);
            if (strcmp(buf3, "exit") == 0)
            {
                cr = false;
                break;
            }
            recv(client_socket2[1], buf4, sizeof(buf4), 0);
            if (strcmp(buf2, "exit") == 0)
            {
                cr = false;
                break;
            }
            send(client_socket2[1], buf3, sizeof(buf3), 0);

            send(client_socket2[0], buf4, sizeof(buf4), 0);
            clear(buf3);
            clear(buf4);
        }
    }

    // close the socket
    close(server_socket);

    return 0;
}