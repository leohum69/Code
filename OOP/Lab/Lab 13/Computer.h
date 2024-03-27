/*
 * Computer.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_
#include <string>
#include <iostream>
using namespace std;
class Computer {
	string companyName;
	int price;
public:
	Computer(string ="\0",int=35000);
	virtual void show();
	virtual ~Computer();
};

#endif /* COMPUTER_H_ */
