/*
 * HourlyEmployee.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef HOURLYEMPLOYEE_H_
#define HOURLYEMPLOYEE_H_

#include "Employee.h"

class HourlyEmployee: public Employee {
	int hourlyIncome;
public:
	HourlyEmployee(string = "\0",int = 1234);
	int calculate_the_hourly_income(int);
	virtual ~HourlyEmployee();
};

#endif /* HOURLYEMPLOYEE_H_ */
