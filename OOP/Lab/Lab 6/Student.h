/*
 * Student.h
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
	string name;
	string roll;
	int age;
	double cgpa;


public:
	Student();
	Student(string n,int a);
	void SetName(string n);
	string GetName();
	void SetRoll(string b);
	string GetRoll();
	void SetAge(int a);
	int GetAge();
	void SetCgpa(double x);
	double GetCgpa();
	void print();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
