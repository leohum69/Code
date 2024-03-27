/*
 * Line.h
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#ifndef LINE_H_
#define LINE_H_
#include "Point.h"
#include <cmath>
class Line {
	Point Point_1;
	Point Point_2;
public:
	Line();
	Line(int x1, int y1, int x2, int y2);
	Line(const Point &p1, const Point &p2);
	float findSlope();
	float findLength();
	Point findMidPoint();
	virtual ~Line();
};

#endif /* LINE_H_ */
