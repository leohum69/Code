/*
 * Computer.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "Computer.h"

Computer::Computer(string cn,int pr) {
	this->companyName = cn;
	this->price = pr;
}
void Computer::show(){
	cout<<"Company Name : "<<this->companyName<<endl;
	cout<<"Price : "<<this->price<<endl;
}
Computer::~Computer() {
	// TODO Auto-generated destructor stub
}

