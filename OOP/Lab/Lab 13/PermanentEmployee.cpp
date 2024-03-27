/*
 * PermanentEmployee.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "PermanentEmployee.h"

PermanentEmployee::PermanentEmployee(string n,int x):Employee(n,x) {
	this->hourlyIncome = 150;

}
int PermanentEmployee::calculate_the_income(){
	return this->hourlyIncome * 240;
}

PermanentEmployee::~PermanentEmployee() {
	// TODO Auto-generated destructor stub
}

