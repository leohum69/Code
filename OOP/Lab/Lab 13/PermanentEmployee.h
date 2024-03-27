/*
 * PermanentEmployee.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef PERMANENTEMPLOYEE_H_
#define PERMANENTEMPLOYEE_H_

#include "Employee.h"

class PermanentEmployee: public Employee {
	int hourlyIncome;
public:
	PermanentEmployee(string = "\0",int = 1234);
	int calculate_the_income();
	virtual ~PermanentEmployee();
};

#endif /* PERMANENTEMPLOYEE_H_ */
