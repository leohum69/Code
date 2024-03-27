/*
 * Money.cpp
 *
 *  Created on: Mar 29, 2023
 *      Author: lab
 */

#include "Money.h"

Money::Money() {
	this->dollar = 0;
	this->cents = 0;

}
Money::Money(int dollar, int cents){
	this->dollar = dollar;
	this->cents = cents;
	while(this->cents >=100){
		this->dollar++;
		this->cents-=100;
	}
}
Money Money::operator+(const Money &obj){
	Money temp;
	temp.dollar = this->dollar + obj.dollar;
	temp.cents = this->cents + obj.cents;
	while(temp.cents >=100){
		temp.dollar++;
		temp.cents-=100;
	}
	return temp;
}
Money Money::operator-(const Money &obj){
	Money temp;
	temp.dollar = this->dollar - obj.dollar;
	temp.cents = this->cents - obj.cents;
	if(temp.cents < 0){
		if(temp.dollar >=1 ){
			temp.cents = 100 + temp.cents;
			temp.dollar--;
		}else{
			temp.cents=0;
		}
	}
	if(temp.dollar < 0){
		temp.dollar = 0;
	}
	return temp;
}
const Money Money::operator=(const Money &obj){
	this->dollar = obj.dollar;
	this->cents = obj.cents;
	return *this;
}
void Money::operator++ (){
	this->dollar++;
	this->cents++;
	if(this->cents == 100){
		this->cents = 0;
		this->dollar++;
	}
}
void Money::operator++ (int x){
	this->dollar++;
	this->cents++;
	if(this->cents == 100){
		this->cents = 0;
		this->dollar++;
	}
}
void Money::operator-- (){
	this->dollar--;
	this->cents--;
	if(this->cents < 0){
			if(this->dollar >=1 ){
				this->cents = 100 + this->cents;
				this->dollar--;
			}else{
				this->cents=0;
			}
		}
		if(this->dollar < 0){
			this->dollar = 0;
		}
}
void Money::operator-- (int x){
	this->dollar--;
	this->cents--;
	if(this->cents < 0){
			if(this->dollar >=1 ){
				this->cents = 100 + this->cents;
				this->dollar--;
			}else{
				this->cents=0;
			}
		}
		if(this->dollar < 0){
			this->dollar = 0;
		}
}
void Money::operator*= (const Money& right){
	this->dollar *= right.dollar;
	this->cents *= right.dollar;
	while(this->cents >=100){
		this->dollar++;
		this->cents-=100;
	}
}
bool Money::operator!= (const Money& right){
	if((this->dollar == right.dollar) && (this->cents == right.cents))
		return false;
	else
		return true;
}
bool Money::operator > (const Money& right){
	if(this->dollar > right.dollar){
		return true;
	}else{
		if(this->dollar == right.dollar){
			if(this->cents > right.cents){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}
}
ostream& operator<< (ostream &os,Money& right){
	os<<"Dollar: "<< right.dollar << endl;
	os<<"Cents: "<< right.cents << endl;
	return os;
}
istream& operator>> (istream & in,Money& right){
	cout<<"Enter Dollars: ";
	in>>right.dollar;
	while(right.dollar < 0){
		cout<<"Enter Positive Money: ";
		in>>right.dollar;
	}
	in>>right.cents;
	while(right.cents < 0){
		cout<<"Enter Positive Money: ";
		in>>right.cents;
	}
	return in;
}

Money::~Money() {
	// TODO Auto-generated destructor stub
}

