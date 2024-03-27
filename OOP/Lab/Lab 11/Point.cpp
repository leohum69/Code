/*
 * Point.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#include "Point.h"

Point::Point() {
	this->X_Coordinate = 0;
	this->Y_Cooridnate = 0;
}
Point::Point(int x, int y){
	this->X_Coordinate = x;
	this->Y_Cooridnate = y;
}
Point::Point(const Point &p){
	this->X_Coordinate = p.X_Coordinate;
	this->Y_Cooridnate = p.Y_Cooridnate;
}
int Point::getX_Coordinate() const{
	return X_Coordinate;
}
int Point::getY_Coordinate() const{
	return Y_Cooridnate;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

