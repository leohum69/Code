/*
 * Flight.cpp
 *
 *  Created on: Apr 26, 2023
 *      Author: lab
 */

#include "Flight.h"
#include <string>
using namespace std;

Flight::Flight(int fn, string org, string des,string da, string dept, string arrt, int ava):flight_num(fn),origin(org),dest(des),date(da),deptime(dept),arrtime(arrt),availseats(ava)
{

}



const string& Flight::getDest() const {
	return dest;
}

void Flight::setDest(const string &dest) {
	this->dest = dest;
}

int Flight::getFlightNum() const {
	return flight_num;
}

void Flight::setFlightNum(int flightNum) {
	flight_num = flightNum;
}

const string& Flight::getOrigin() const {
	return origin;
}

void Flight::setOrigin(const string &origin) {
	this->origin = origin;
}
int Flight::getAvailseats() const {
	return availseats;
}

const string& Flight::getArrtime() const {
	return arrtime;
}

void Flight::setArrtime(const string &arrtime) {
	this->arrtime = arrtime;
}

const string& Flight::getDate() const {
	return date;
}

void Flight::setDate(const string &date) {
	this->date = date;
}

const string& Flight::getDeptime() const {
	return deptime;
}

void Flight::setDeptime(const string &deptime) {
	this->deptime = deptime;
}

void Flight::setAvailseats(int availseats) {
	this->availseats = availseats;
}

Flight::~Flight() {
	// TODO Auto-generated destructor stub
}


