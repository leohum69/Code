/*
 * Employee.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
using namespace std;

class Employee {
	string name;
	int empID;
public:
	Employee(string = "\0",int = 1234);
	virtual ~Employee();
};

#endif /* EMPLOYEE_H_ */
