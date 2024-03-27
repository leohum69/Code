#ifndef PAIRS_H_
#define PAIRS_H_
#include "Location.h"
using namespace std;
class pairs
{
public:
    location first;
    int second;
    pairs()
    {
        second = -1;
    }
    pairs(location s1, int n)
    {
        first = s1;
        second = n;
    }
    pairs(const pairs &p1)
    {
        first = p1.first;
        second = p1.second;
    }
    void print()
    {
        cout << "First : " << first << endl;
        cout << "Second : " << second << endl;
    }
    bool operator==(const pairs &p1)
    {
        if (first == p1.first && second == p1.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream &operator<<(ostream &out, pairs &p)
{
    p.print();
    return out;
}

class pairstring
{
public:
    string first;
    int second;
    pairstring()
    {
        second = -1;
    }
    pairstring(string s1, int n)
    {
        first = s1;
        second = n;
    }
    pairstring(const pairstring &p1)
    {
        first = p1.first;
        second = p1.second;
    }
    void print()
    {
        cout << "First : " << first << endl;
        cout << "Second : " << second << endl;
    }
    bool operator==(const pairstring &p1)
    {
        if ((first == p1.first) && (second == p1.second))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream &operator<<(ostream &out, pairstring &p)
{
    p.print();
    return out;
}

class pairbool
{
public:
    string first;
    bool second;
    pairbool()
    {
        second = -1;
    }
    pairbool(string s1, bool n)
    {
        first = s1;
        second = n;
    }
    pairbool(const pairbool &p1)
    {
        first = p1.first;
        second = p1.second;
    }
    void print()
    {
        cout << "First : " << first << endl;
        cout << "Second : " << second << endl;
    }
    bool operator==(const pairbool &p1)
    {
        if ((first == p1.first) && (second == p1.second))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream &operator<<(ostream &out, pairbool &p)
{
    p.print();
    return out;
}
void swappair(pairstring &p1, pairstring &p2)
{
    pairstring p3;
    p3 = p1;
    p1 = p2;
    p2 = p3;
}
#endif /* PAIRS_H_ */