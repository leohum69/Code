/*
 * Holiday.cpp
 *
 *  Created on: Mar 8, 2023
 *      Author: lab
 */

#include "Holiday.h"

Holiday::Holiday() {
	this->name='\0';
	this->date=0;
	this->month='\0';

}
Holiday::Holiday(string n, int d, string m):name(n),date(d),month(m){

}
Holiday::Holiday(Holiday & copy){
	this->name = copy.name;
	this->date = copy.date;
	this->month = copy.month;
}

int Holiday::getDate() const {
	return date;
}

void Holiday::setDate(int d) {
	if(d<1 || d>31){
		cout<<"error"<<endl;
	}
	else
		this->date=d;

}

const string& Holiday::getMonth() const {
	return month;
}

void Holiday::setMonth(const string &m) {
	int i=0;
	while(m[i]!='\0'){
		i++;
	}
	if(i>10){
		cout<<"error"<<endl;
	}else
		this->month = m;
}

const string& Holiday::getName() const {
	return name;
}

void Holiday::setName(const string &n) {
	int i=0;
	while(n[i]!='\0'){
		i++;
	}
	if(i>50){
			cout<<"error"<<endl;
		}else
			this->month = n;
}

Holiday::~Holiday() {
	// TODO Auto-generated destructor stub
}

