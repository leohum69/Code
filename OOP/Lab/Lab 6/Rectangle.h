/*
 * Rectangle.h
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
using namespace std;

class Rectangle {
	int length;
	int width;
	int ar;
public:
	Rectangle();
	Rectangle(int a,int b);
	int area(int a,int b);
	int scaleUp(int a,int b);
	void setLength(int a);
	void setWidth(int b);
	int GetLength();
	int GetWidth();
	int GetArea();
	void print();
	virtual ~Rectangle();
};

#endif /* RECTANGLE_H_ */
