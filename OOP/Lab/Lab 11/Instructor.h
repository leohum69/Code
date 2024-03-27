/*
 * Instructor.h
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#ifndef INSTRUCTOR_H_
#define INSTRUCTOR_H_
#include <iostream>
#include <string>
using namespace std;

class Instructor {
	string First;
	string Last;
	string Office;
	string Designation;
public:
	Instructor();
	Instructor(string,string,string,string);
	void Set();
	void Print();
	virtual ~Instructor();
};

#endif /* INSTRUCTOR_H_ */
