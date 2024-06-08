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

int main()
{
	pid_t pid = fork();
	if (pid == 0)
	{
		cout << "Welcome to The FAST GRADING SYSTEM" << endl;
		cout << "Welcome Admin." << endl;
		cout << "Please Enter Your Password: ";
		string password;
		cin >> password;
		while (password != "password")
		{
			cout << "Invalid Password!" << endl;
			cout << "Please Enter Your Password: ";
			cin >> password;
		}

		cout << "Welcome Admin!" << endl;
		cout << "Please Enter What you want to do" << endl;
		int choice;
		cout << "1 - Add a New Teacher" << endl;
		cout << "2 - Add a New Student" << endl;
		cout << "3 - View All Teachers" << endl;
		cout << "4 - View All Students" << endl;
		cout << "5 - Delete a Teacher" << endl;
		cout << "6 - Delete a Student" << endl;
		cout << "Enter Command: ";
		cin >> choice;
		if (choice == 1)
		{
			string name;
			cout << "Enter Teacher Name: ";
			cin >> name;
			ofstream file;
			file.open("teachers.txt", ios::app);
			file << name << endl;
			file.close();
		}
		else if (choice == 2)
		{
			string roll;
			cout << "Enter Student Roll Number: ";
			cin >> roll;
			ofstream file;
			file.open("students.txt", ios::app);
			file << roll << endl;
			file.close();
		}
		else if (choice == 3)
		{
			ifstream file;
			file.open("teachers.txt");
			string name;
			while (file >> name)
			{
				cout << name << endl;
			}
			file.close();
		}
		else if (choice == 4)
		{
			ifstream file;
			file.open("students.txt");
			string roll;
			while (file >> roll)
			{
				cout << roll << endl;
			}
			file.close();
		}
		else if (choice == 5)
		{
			string name;
			cout << "Enter Teacher Name: ";
			cin >> name;
			ifstream file;
			file.open("teachers.txt");
			ofstream temp;
			temp.open("temp.txt");
			string line;
			while (file >> line)
			{
				if (line != name)
				{
					temp << line << endl;
				}
			}
			file.close();
			temp.close();
			remove("teachers.txt");
			rename("temp.txt", "teachers.txt");
		}
		else if (choice == 6)
		{
			string roll;
			cout << "Enter Student Roll Number: ";
			cin >> roll;
			ifstream file;
			file.open("students.txt");
			ofstream temp;
			temp.open("temp.txt");
			string line;
			while (file >> line)
			{
				if (line != roll)
				{
					temp << line << endl;
				}
			}
			file.close();
			temp.close();
			remove("students.txt");
			rename("temp.txt", "students.txt");
		}
		else
		{
			cout << "Invalid Command!" << endl;
		}
	}
	else
	{
		pid_t pid1 = fork();
		if (pid1 == 0)
		{
			char server_message[256] = "Welcome Student!\nPlease Enter Your Roll Number: ";
			char tarue[256] = "Yes You are found in our data base, now you can see Your Records.";
			char falsee[256] = "False";
			char roll[256];

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
			pid_t pid2;
			while (1)
			{
				listen(server_socket, 5);
				int client_socket;
				client_socket = accept(server_socket, NULL, NULL);
				pid2 = fork();
				if (pid2 == 0)
				{
					bool lol = false;
					ifstream file;
					file.open("students.txt");
					int num;
					file>>num;
					file.ignore();
					clear(buf);
					send(client_socket, &server_message, sizeof(server_message), 0);
					recv(client_socket, &buf, sizeof(buf), 0);
					// cout << buf << endl;
					int i=0;
					for (;i<num;i++)
					{
						file.getline(roll, 256);
						cout << roll << endl;
						if (strcmp(roll, buf) == 0)
						{
							send(client_socket, &tarue, sizeof(tarue), 0);
							lol = true;
							break;
						}
					}
					if (lol == false)
						send(client_socket, &falsee, sizeof(falsee), 0);
					else{
						int j=i;
						for(;i<num;i++){
							file.getline(roll, 256);
						}
						for (int l = 0; l < j; l++)
						{
							file.getline(roll, 256);
						}
						
						send(client_socket, &roll, sizeof(roll), 0);
					}
					close(client_socket);
				}
			}
		}
		else
		{
			char server_message[256] = "Welcome Teacher!\nPlease Enter Your Name: ";
			char tarue[256] = "Teacher found in our data base, Here you can view yout data.";
			char falsee[256] = "Teacher Not found Do you want to Add this Teacher?";
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
				client_socket = accept(server_socket, NULL, NULL);
				pid2 = fork();
				if (pid2 == 0)
				{
					bool lol = false;
					ifstream file2;
					file2.open("teachers.txt");
					int num;
					file2>>num;
					file2.ignore();
					clear(buf);
					send(client_socket, &server_message, sizeof(server_message), 0);
					recv(client_socket, &buf, sizeof(buf), 0);
					// cout << buf << endl;
					for(int i=0;i<num;i++)
					{
						file2.getline(name, 256);
						cout << name << endl;
						if (strcmp(name, buf) == 0)
						{
							send(client_socket, &tarue, sizeof(tarue), 0);
							lol = true;
							break;
						}
					}
					if (lol == false){
						send(client_socket, &falsee, sizeof(falsee), 0);
						recv(client_socket, &buf, sizeof(buf), 0);
						if(buf == "yes"){
							ofstream file;
							file.open("teachers.txt", ios::app);
							file<<buf<<endl;
							file.close();
						}
					close(client_socket);
				}
			}
		}
	}
	return 0;
}