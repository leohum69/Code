/*
 * Laptop.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef LAPTOP_H_
#define LAPTOP_H_

#include "Computer.h"

class Laptop: public Computer {
	string color;
	int size;
	int weight;
	string processor;
public:
	Laptop(string ="\0",int=35000,string = "black",int = 19,int = 3 ,string = "i5");
	void show();
	virtual ~Laptop();
};

#endif /* LAPTOP_H_ */
