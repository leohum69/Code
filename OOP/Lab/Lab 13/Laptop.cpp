/*
 * Laptop.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "Laptop.h"

Laptop::Laptop(string cn,int pr,string clr,int s,int w,string pt):Computer(cn,pr) {
	this->color = clr;
	this->size = s;
	this->weight = w;
	this->processor = pt;
}
void Laptop::show(){
	Computer::show();
	cout<<"Color : "<<this->color<<endl;
	cout<<"Size : "<<this->size<<endl;
	cout<<"Weight : "<<this->weight<<endl;
	cout<<"Processor Type : "<<this->processor<<endl;
}
Laptop::~Laptop() {
	// TODO Auto-generated destructor stub
}

