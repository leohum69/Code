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

void rev(char *msg, char *buf)
{
    int i = 0;
    for (; buf[i] != '\0'; i++)
    {
    }
    int x = 0;
    for (int j = i - 1; j >= 0; j--, x++)
    {
        msg[x] = buf[j];
    }
    msg[x] = '\0';
}
int main()
{

    char server_message[256] = "Hi, Yes you have reached the server!";
    char buf[256];
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
    listen(server_socket, 5);
    int client_socket[2];
    client_socket[0] = accept(server_socket, NULL, NULL);
    client_socket[1] = accept(server_socket, NULL, NULL);
    bool pp = true;
    for (int i = 0; i < 2; i++)
    {
        while (1)
        {
            recv(client_socket[i], &buf, sizeof(buf), 0);
            cout << "Client Sent " << i << " : ";
            printf("\n %s \n", buf);
            // rev(server_message,buf);
            if (strcmp(buf, "exit") == 0)
            {
                break;
            }
            cout << "Enter Response " << i << " : ";
            cin.getline(server_message, 256);
            // cin>>server_message;
            send(client_socket[i], server_message, sizeof(server_message), 0);
            clear(server_message);
            clear(buf);
        }
    }

    // close the socket
    close(server_socket);

    return 0;
}