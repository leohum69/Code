/*
 * Rectangle.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: lab
 */

#include "Rectangle.h"
Rectangle::Rectangle() {

}
Rectangle::Rectangle(int a,int b){
	length=a;
	width=b;
	ar = a*b;
}
int Rectangle::scaleUp(int a,int b){
	length++;
	width++;
	ar = length * width;
	return length + width;
}
int Rectangle::area(int a,int b){
	ar=length*width;
	return ar;
}
void Rectangle::setLength(int a){
	length=a;
}
void Rectangle::setWidth(int b){
	width=b;
}
int Rectangle::GetLength(){
	return length;
}
int Rectangle::GetWidth(){
	return width;
}
int Rectangle::GetArea(){
	return ar;
}
void Rectangle::print(){
	cout<<"Length: "<<length<<endl;
	cout<<"Width: "<<width<<endl;
	cout<<"Area: "<<ar<<endl;
}



Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

