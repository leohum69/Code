#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void clear(char *msg)
{
	for (int i = 0; i < 256; i++)
	{
		msg[i] = 0;
	}
	return;
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
void comp(char *msg1, char *msg2, char *ser)
{
	if (strcmp(msg1, msg2) == 0)
		strcpy(ser, "TRUE");
	else
		strcpy(ser, "FALSE");
}

int main()
{

	pid_t pid1 = fork();
	if (pid1 == 0)
	{
		int sockfd;
		string buffer;
		struct sockaddr_in servaddr, cliaddr;

		// Creating socket file descriptor
		if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		{
			perror("socket creation failed");
			exit(EXIT_FAILURE);
		}

		// memset(&servaddr, 0, sizeof(servaddr));
		// memset(&cliaddr, 0, sizeof(cliaddr));

		// Filling server information
		servaddr.sin_family = AF_INET; // IPv4
		servaddr.sin_addr.s_addr = INADDR_ANY;
		servaddr.sin_port = htons(3001);

		// Bind the socket with the server address

		int len;

		len = sizeof(cliaddr); // len is value/resuslt
		pid_t pid2;
		while (1)
		{
			if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
			{
				perror("bind failed");
				exit(EXIT_FAILURE);
			}
			pid2 = fork();
			if (pid2 == 0)
			{
				int n;
				char op1[256], op2[256];
				char lol[256];
				recvfrom(sockfd, &n, 4, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
				recvfrom(sockfd, &op1, 256, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
				recvfrom(sockfd, &op2, 256, 0, (struct sockaddr *)&cliaddr, (socklen_t *)&len);
				if (n == 1)
				{
					concat(op1, op2, lol);
					sendto(sockfd, &lol, sizeof(lol), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
				}
				else if (n == 2)
				{
					comp(op1, op2, lol);
					sendto(sockfd, &lol, sizeof(lol), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
				}
			}
		}
	}
	else
	{
		char name[256];
		char buf[256];
		// create the server socket
		int server_socket;
		server_socket = socket(AF_INET, SOCK_STREAM, 0);

		// define the server address
		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(3002);
		server_address.sin_addr.s_addr = INADDR_ANY;

		// bind the socket to our specified IP and port
		bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
		pid_t pid2;
		while (1)
		{
			listen(server_socket, 5);
			int client_socket;
			char lol[256]='\0';
			client_socket = accept(server_socket, NULL, NULL);
			pid2 = fork();
			if (pid2 == 0)
			{
				if(lol[0] =='\0' )
				recv(client_socket, &buf, sizeof(buf), 0);
				send(client_socket,&lol,sizeof(lol),0);
				close(client_socket);
			}
		}
	}
	return 0;
}