/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef IOTS_H
#define IOTS_H
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;
class IOTS{
    char name[30];
    float tempreture;
    float sugar;
    int pulse;
    float BMI;
    int oxy_sat;
    int BP[2];
public:
    IOTS(char[] = "\0" ,float=37,float=100,int = 60,float = 20,int = 96, int = 128,int = 80);
    virtual ~IOTS();
    void Update();
    IOTS& Update2();
    void operator=(IOTS& is);
    void readiot(char[]);
    void setname(char[]);
    float gettemp();
    float getsug();
    int getpul();
    float getbmi();
    int getos();
    int getubp();
    int getlbp();
    void print();

};
#endif // IOTS_H
