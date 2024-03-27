/*
 * Holiday.h
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#ifndef HOLIDAY_H_
#define HOLIDAY_H_
#include <iostream>
#include <string>
using namespace std;
class Holiday {
	string name;
	int date;
	string month;
public:
	Holiday();
	Holiday(string n, int d, string m);
	Holiday(Holiday & copy);

	virtual ~Holiday();
	int getDate() const;
	void setDate(int d);
	const string& getMonth() const;
	void setMonth(const string &m);
	const string& getName() const;
	void setName(const string &n);
};

#endif /* HOLIDAY_H_ */
