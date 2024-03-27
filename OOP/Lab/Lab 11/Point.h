/*
 * Point.h
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
	int X_Coordinate;
	int Y_Cooridnate;
public:
	Point();
	Point(int , int);
	Point(const Point &p);
	int getX_Coordinate() const;
	int getY_Coordinate() const;
	virtual ~Point();
};

#endif /* POINT_H_ */
