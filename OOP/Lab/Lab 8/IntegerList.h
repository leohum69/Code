/*
 * IntegerList.h
 *
 *  Created on: Mar 15, 2023
 *      Author: lab
 */

#ifndef INTEGERLIST_H_
#define INTEGERLIST_H_
#include <iostream>
#include <cstdlib>
using namespace std;
class IntegerList {
	int *list;
	int numElements;
	int size;

public:
	IntegerList(int);
	IntegerList(IntegerList &copy);
	bool isValid(int);
	void setElement(int, int);
	int getElement(int);
	virtual ~IntegerList();
};

#endif /* INTEGERLIST_H_ */
