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
    // create the socket
    int sock;
    char buf[256];
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // setup an address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8001);

    connect(sock, (struct sockaddr *)&server_address, sizeof(server_address));
    int n;
    cout << "Enter Number: ";
    cin >> n;
    buf[0] = {char(n)};
    cout<<int(buf[0])<<endl;
    send(sock, buf, sizeof(buf), 0);
    clear(buf);
    recv(sock, &buf, sizeof(buf), 0);
    cout<<"out put : "<<int(buf[0])<<endl;

    close(sock);

    return 0;
}
