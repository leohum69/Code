/*
 * point.h
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#ifndef POINT_H_
#define POINT_H_
#include <string>
using namespace std;
class point {
	int x;
	int y;
public:
	point();
	point(int a,int b);
	void setX(int a);
	void setY(int b);
	int getX();
	int getY();
	string check();
	virtual ~point();
};

#endif /* POINT_H_ */
