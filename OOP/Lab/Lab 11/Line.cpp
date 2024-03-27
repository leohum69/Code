/*
 * Line.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#include "Line.h"

Line::Line():Point_1(4,6),Point_2(2,4) {

}
Line::Line(int x1, int y1, int x2, int y2):Point_1(x1,y1),Point_2(x2,y2){

}
Line::Line(const Point &p1, const Point &p2):Point_1(p1),Point_2(p2){

}
float Line::findSlope(){
	float slope=0;
	slope = static_cast<float>(this->Point_2.getY_Coordinate()) - static_cast<float>(this->Point_1.getY_Coordinate());
	slope = slope / (static_cast<float>(this->Point_2.getX_Coordinate()) - static_cast<float>(this->Point_1.getX_Coordinate()));
	return slope;
}
float Line::findLength(){
	float length=0;
	float xcc = this->Point_2.getX_Coordinate() - this->Point_1.getX_Coordinate();
	xcc = xcc * xcc;
	float ycc = this->Point_2.getY_Coordinate() - this->Point_1.getY_Coordinate();
	ycc = ycc * ycc;
	length = sqrt(xcc + ycc);
	return length;
}
Point Line::findMidPoint(){
	float x = this->Point_1.getX_Coordinate() + this->Point_2.getX_Coordinate();
	x = x/2;
	float y = this->Point_1.getY_Coordinate() + this->Point_2.getY_Coordinate();
	y = y/2;
	Point temp(x,y);
	return temp;
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

