/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef PATEINT_H
#define PATIENT_H
#include<iostream>
#include<cstring>
#include"doctor.h"
#include"iots.h"
#include "EHR.h"
using namespace std;

class patient{
private:
    int ID;
    char name[30];
    char pass[30];
    char filepass[40];
    char ehpass[40];
    int age;
    char gender;
    int docnum;
    IOTS wear;
    ehr *ehh;
    int docidx[5];
    doctor **docarr;
    int reqsen[5];


public:
    patient(int=-1,char[] = "\0",char[]= "lalaleo123",char[] = "\0",char[] = "\0",int = 69,char = 'f',int = 2,int[] = NULL);
    virtual ~patient();
    void prints();
    void setdocs(doctor *point);
    void adddoc(int idx,doctor *point);
    void remdoc(int idx,doctor *point);
    IOTS& getiot();
    char* getname();
    char* getpass();
    ehr* getehr();
    int getnumberofdocs();
    void setapt();
    int getid();
    doctor** getdocarr();
    void addnewdocplz(doctor *point);
    void viewehr();
    void chkreqs(doctor *point);
    int* getrewaliarr();
    void call();
    int getage();
    void operator=(patient& other);
    char* getehrpath();
    void encrypt();
    void decrypt();



};
#endif // PATIENT_H
void sorting(int *arr){
    int temp;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

