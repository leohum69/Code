/*
Name : Mirza Humayun Masood
Roll No : i22-1749
Class : CY(A)
*/
#include "doctor.h"

doctor::doctor(int id,char na[],char pas[],int ag,char spec[],char gen){
    this->ID = id;
    strcpy(this->name,na);
    strcpy(this->pass,pas);
    this->age = ag;
    strcpy(this->special,spec);
    this->gender = gen;
    for(int  i=0 ; i < 10; i++){
        this->reqinc[i]=0;
    }
}
doctor::~doctor(){
}
void doctor::display(){
    cout<<"Doc name"<<this->name<<endl;
    cout<<"Doc pass"<<this->pass<<endl;
    cout<<"Doc age"<<this->age<<endl;
    cout<<"Doc special"<<this->special<<endl;
    cout<<"Doc gender"<<this->gender<<endl;
}
char* doctor::getname(){
    return this->name;
}
char* doctor::getspec(){
    return this->special;
}
int* doctor::senreqdoc(){
    return this->reqinc;
}
int doctor::getid(){
    return this->ID;
}
char* doctor::getpass(){
    return this->pass;
}
void doctor::operator=(doctor& other){
    this->ID = other.ID;
    strcpy(this->name, other.name);
    strcpy(this->pass, other.pass);
    this->age = other.age;
    strcpy(this->special, other.special);
    this->gender = other.gender;
    for(int i=0 ; i<10 ; i++){
        this->reqinc[i] = other.reqinc[i];
    }
}
