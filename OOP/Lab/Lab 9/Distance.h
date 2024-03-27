/*
 * Distance.h
 *
 *  Created on: Mar 22, 2023
 *      Author: lab
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_

class Distance {
	int feet;
	int inches;

public:
	Distance(int =0,int =0);
	bool setFeet(int f);
	int getFeet()const;
	bool setInches(int i);
	int getInches()const;
	Distance operator+(const Distance &obj);
	Distance operator-(const Distance &obj);
	const Distance operator=(const Distance &obj);
	virtual ~Distance();
};

#endif /* DISTANCE_H_ */
