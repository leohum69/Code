#include <iostream>
#include "getch.h"
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{
    int choice = 0;

    while (choice != 7)
    {
        cout << "Choose from the Following: " << endl;
        cout << "1-List Files in the Folder" << endl;
        cout << "2-Cat A File" << endl;
        cout << "3-Make a Folder" << endl;
        cout << "4-Echo A String" << endl;
        cout << "5-Print Date" << endl;
        cout << "6-Execute The Program" << endl;
        cout << "7-Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;

        while (choice < 1 && choice > 8)
        {
            cout << "Enter Choice Again : ";
            cin >> choice;
        }
        pid_t pid = fork();

        if (pid == 0)
        {
            if (choice == 1)
            {
                system("clear");
                char * args[] = {"ls","-l",NULL};
                execvp("ls", args);
            }
            else if (choice == 2)
            {
                system("clear");
                execl("/bin/cat", "cat", "lol.txt", NULL);
            }
            else if (choice == 3)
            {
                system("clear");
                cout << "Enter Name of the Folder : ";
                char s[256];
                cin.ignore();
                cin.getline(s, 256);
                execl("/bin/mkdir", "mkdir", s, NULL);
            }
            else if (choice == 4)
            {
                system("clear");
                cout << "Enter The String: ";
                char t[256];
                cin.ignore();
                cin.getline(t, 256);
                execl("/bin/echo", "echo", t, NULL);
            }
            else if (choice == 5)
            {
                system("clear");
                execv("/bin/date", NULL);
            }
            else if (choice == 6)
            {
                system("clear");
                execlp("./pew", "pew", NULL);
            }
        }
        else
        {
            wait(NULL);
            cin.ignore();
            getch();
            system("clear");
        }
    }

    return 0;
}