/*
 * System.h
 *
 *  Created on: Apr 26, 2023
 *      Author: lab
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <iostream>
#include "Flight.h"
using namespace std;

class System {
	Flight *arr;
public:
	System();
	void checker(string,string,string,string,string);
	virtual ~System();
};

#endif /* SYSTEM_H_ */
