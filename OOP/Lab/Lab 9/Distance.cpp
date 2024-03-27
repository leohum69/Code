/*
 * Distance.cpp
 *
 *  Created on: Mar 22, 2023
 *      Author: lab
 */

#include "Distance.h"

Distance::Distance(int f, int i) {
	this->feet = f;
	this->inches = i;
	while(this->inches >= 12){
		this->feet++;
		this->inches = this->inches - 12;
	}
}
bool Distance::setFeet(int f){
	if(f>=0){
		this->feet = f;
		return true;
	}else{
		return false;
	}
}
int Distance::getFeet()const{
	return feet;
}
bool Distance::setInches(int i){
	bool s = false;
	if(i>=0){
		this->inches = i;
		s = true;
	}else{
		s = false;
	}
	while(this->inches >= 12){
		this->feet++;
		this->inches = this->inches - 12;
	}
	return s;
}
int Distance::getInches()const{
	return this->inches;
}
Distance Distance::operator+(const Distance &obj){
	Distance temp;
	temp.feet = this-> feet + obj.feet;
	temp.inches = this->inches + obj.inches;
	while(temp.inches>=12){
		temp.feet++;
		temp.inches = temp.inches - 12;
	}
	return temp;
}
Distance Distance::operator-(const Distance &obj){
	Distance temp;
	temp.feet = this-> feet - obj.feet;
	temp.inches = this->inches - obj.inches;
	return temp;

}
const Distance Distance::operator=(const Distance &obj){
	this->feet = obj.feet;
	this->inches = obj.inches;
	return *this;
}

Distance::~Distance() {
	// TODO Auto-generated destructor stub
}

