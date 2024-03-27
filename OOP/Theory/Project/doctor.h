/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef DOCTOR_H
#define DOCTOR_H
#include<iostream>
#include<cstring>
using namespace std;

class doctor{
    int ID;
    char name[30];
    char pass[30];
    int age;
    char special[30];
    char gender;
    int reqinc[10];
public:
    doctor(int=0,char[] = "\0",char[] = "lalaleo123",int = 69,char[] = "veila xD", char = 'm');
    virtual ~doctor();
    void display();
    char* getname();
    char* getpass();
    char* getspec();
    int* senreqdoc();
    int getid();
    void operator=(doctor& other);




};
#endif // DOCTOR_H
