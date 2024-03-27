/*
 * Course.cpp
 *
 *  Created on: Apr 5, 2023
 *      Author: lab
 */

#include "Course.h"

Course::Course() {
	// TODO Auto-generated constructor stub

}
void Course::setter(){
	this->Ins.Set();
	this->Tex.Set();
}
void Course::Print(){
	this->Ins.Print();
	this->Tex.Print();
}
Course::~Course() {
	// TODO Auto-generated destructor stub
}

