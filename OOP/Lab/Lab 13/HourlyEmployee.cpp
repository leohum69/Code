/*
 * HourlyEmployee.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(string n,int x):Employee(n,x) {
	this->hourlyIncome = 150;
}
int HourlyEmployee::calculate_the_hourly_income(int x){
	return this->hourlyIncome * x;
}
HourlyEmployee::~HourlyEmployee() {
	// TODO Auto-generated destructor stub
}

