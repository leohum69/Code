/*
 * point.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#include "point.h"

point::point() {
	// TODO Auto-generated constructor stub

}
point::point(int a,int b){
	x=a;
	y=b;
}
void point::setX(int a){
	x=a;
}
void point::setY(int b){
	y=b;
}
int point::getX(){
	return x;
}
int point::getY(){
	return y;
}
string point::check(){
	if(x==0 && y==0)
		return "Origin";
	else if(x>0 && y>0)
		return "Q1";
	else if(x<0 && y>0)
		return "Q2";
	else if(x<0 && y<0)
		return "Q3";
	else
		return "Q4";
}

point::~point() {
	// TODO Auto-generated destructor stub
}

