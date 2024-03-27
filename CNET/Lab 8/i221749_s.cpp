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

void concat(char *msg1, char *msg2, char *ser)
{
    int i = 0;
    for (; msg1[i] != '\0'; i++)
    {
        ser[i] = msg1[i];
    }
    for (int j = 0; msg2[j] != '\0'; j++, i++)
    {
        ser[i] = msg2[j];
    }
    ser[i] = '\0';
}
void comp(char *msg1, char *msg2, char *ser){
    if(strcmp(msg1,msg2)==0)
        strcpy(ser,"TRUE");
    else
        strcpy(ser,"FALSE");
}
int main()
{

    char server_message[256] = "Hi, Yes you have reached the server!";
    char server_menu[256] = "Welcome to the server\n1 - Concatinate Stirng\n2 - Compare Strings\nInput : ";
    char inp[1];
    char buf1[256];
    char buf2[256];
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
    while (1)
    {
        listen(server_socket, 5);
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        pid = fork();
        if (pid == 0)
        {
            send(client_socket, server_menu, sizeof(server_menu), 0);
            recv(client_socket, inp, sizeof(inp), 0);
            cout<<inp<<endl;
            recv(client_socket, &buf1, sizeof(buf1), 0);
            cout << "Client Sent"
                 << " : ";
            printf("\n %s \n", buf1);
            recv(client_socket, &buf2, sizeof(buf2), 0);
            cout << "Client Sent"
                 << " : ";
            printf("\n %s \n", buf2);
            if(inp[0]=='1')
                concat(buf1, buf2, server_message);
            else
                comp(buf1,buf2,server_message);

            // cin>>server_message;
            send(client_socket, server_message, sizeof(server_message), 0);
            clear(server_message);
            clear(buf1);
        }
    }

    // close the socket
    close(server_socket);

    return 0;
}