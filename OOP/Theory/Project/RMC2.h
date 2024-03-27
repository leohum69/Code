/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#ifndef RMC2_H
#define RMC2_H
#include"doctor.h"

class rmc2{
    doctor *docs;
    patient *pats;

public:
    rmc2(doctor* = NULL,patient* = NULL);
    virtual ~rmc2();
    void apointchk(int docidx);
    doctor* getdoc();
    void chkcnslthist(int docidx);
    void randomdata(int docidx);
    void Requestfordata(int docidx);
    void editehr(int docidx);
    void chkiot(int docidx);





};
#endif // RMC2_H
