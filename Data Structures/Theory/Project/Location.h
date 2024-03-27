#ifndef LOCATION_H_
#define LOCATION_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class location
{
public:
    string name;
    string sector;
    int isbin;
    int pfull;
    location()
    {
        name = "";
        sector = "";
        isbin = 0;
        pfull = -1;
    }
    location(string n, string s, int b, int al)
    {
        name = n;
        sector = s;
        isbin = b;
        pfull = al;
    }
    location(const location &l1)
    {
        name = l1.name;
        sector = l1.sector;
        isbin = l1.isbin;
        pfull = l1.pfull;
    }
    void setname(string n)
    {
        name = n;
    }
    void setsector(string s)
    {
        sector = s;
    }
    void setisbin(int x)
    {
        isbin = x;
    }
    void setpfull(int x)
    {
        pfull = x;
    }
    void print()
    {
        cout << "Street Name: " << name << endl;
        cout << "Secotor: " << sector << endl;
        cout << "Percent Full: " << pfull << endl;
        if (isbin == 0)
        {
            cout << "Its a Bin" << endl;
        }
        else if (isbin == 1)
        {
            cout << "Its a Departure point" << endl;
        }
        else if (isbin == 2)
        {
            cout << "Its a Dumping point" << endl;
        }
    }
    bool operator==(const location &l1)
    {
        if (name == name)
        {
            return true;
        }
        else
            return false;
    }
};
ostream &operator<<(ostream &out, location &l)
{
    l.print();
    return out;
}

#endif /* LOCATION_H_ */