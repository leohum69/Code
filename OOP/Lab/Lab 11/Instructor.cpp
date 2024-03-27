/*
 * Instructor.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#include "Instructor.h"

Instructor::Instructor() {
	cout<<"Inside Instructor Constuctor"<<endl;
	this->First = "\0";
	this->Last = "\0";
	this->Office = "\0";
	this->Designation = "\0";
}
Instructor::Instructor(string a,string b,string c,string d):First(a),Last(b),Office(c),Designation(d){

}
void Instructor::Set(){
	cout<<"Enter First Name: ";
	getline(cin,this->First);
	//cin.ignore();
	cout<<"Enter Last name: ";
	getline(cin,this->Last);
	//cin.ignore();
	cout<<"Enter Office number: ";
	getline(cin,this->Office);
	//cin.ignore();
	cout<<"Enter Designation: ";
	getline(cin,this->Designation);
	//cin.ignore();
}
void Instructor::Print(){
	cout<<"First Name : "<<this->First<<endl;
	cout<<"Last name : "<<this->Last<<endl;
	cout<<"Office number : "<<this->Office<<endl;
	cout<<"Designation : "<<this->Designation<<endl;
}
Instructor::~Instructor() {
	// TODO Auto-generated destructor stub
}

