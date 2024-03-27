#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <string>
using namespace std;
class truckdriver
{
    string name;
    string username;
    string password;
    int sec;

public:
    truckdriver()
    {
        name = "";
        username = "";
        password = "";
        sec = -1;
    }
    truckdriver(string name, string usrname, string pass, int sector)
    {
        this->name = name;
        username = usrname;
        password = pass;
        sec = sector;
    }
    void setname(string n)
    {
        name = n;
    }
    void setusrname(string usr)
    {
        username = usr;
    }
    void setpass(string pass)
    {
        password = pass;
    }
    void setsec(int x)
    {
        sec = x;
    }
    string getname()
    {
        return name;
    }
    string getusrname()
    {
        return username;
    }
    string getpass()
    {
        return password;
    }
    int getsector()
    {
        return sec;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Sector val: " << sec << endl;
    }
};
class controller
{
    string name;
    string username;
    string password;

public:
    controller()
    {
        name = "";
        username = "";
        password = "";
    }
    controller(string name, string usrname, string pass)
    {
        this->name = name;
        username = usrname;
        password = pass;
    }
    void setname(string n)
    {
        name = n;
    }
    void setusrname(string usr)
    {
        username = usr;
    }
    void setpass(string pass)
    {
        password = pass;
    }
    string getname()
    {
        return name;
    }
    string getusrname()
    {
        return username;
    }
    string getpass()
    {
        return password;
    }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }
};
#endif