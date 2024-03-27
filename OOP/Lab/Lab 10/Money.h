/*
 * Money.h
 *
 *  Created on: Mar 29, 2023
 *      Author: lab
 */

#ifndef MONEY_H_
#define MONEY_H_
#include <iostream>
using namespace std;


class Money {
	int dollar;
	int cents;
public:
	Money();
	Money(int dollar, int cents);
	Money operator+(const Money &obj);
	Money operator-(const Money &obj);
	const Money operator=(const Money &obj);
	void operator++ ();
	void operator++ (int x);
	void operator-- ();
	void operator-- (int x);
	void operator*= (const Money& right);
	bool operator!= (const Money& right);
	bool operator > (const Money& right);
	friend ostream& operator<< (ostream &os,Money& right);
	friend istream& operator>> (istream & in,Money& right);
	virtual ~Money();
};

#endif /* MONEY_H_ */
