/*
 * Desktop.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef DESKTOP_H_
#define DESKTOP_H_

#include "Computer.h"

class Desktop: public Computer {
	string color;
	int monitor_size;
	string processor;
public:
	Desktop(string ="\0",int=35000,string = "black",int = 19, string = "i5");
	void show();
	virtual ~Desktop();
};

#endif /* DESKTOP_H_ */
