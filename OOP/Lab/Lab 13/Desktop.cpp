/*
 * Desktop.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "Desktop.h"

Desktop::Desktop(string cn,int pr,string clr,int ms,string pt):Computer(cn,pr) {
	this->color = clr;
	this->monitor_size = ms;
	this->processor = pt;
}
void Desktop::show(){
	Computer::show();
	cout<<"Color : "<<this->color<<endl;
	cout<<"Monitor Size : "<<this->monitor_size<<endl;
	cout<<"Processor Type : "<<this->processor<<endl;
}

Desktop::~Desktop() {
	// TODO Auto-generated destructor stub
}

