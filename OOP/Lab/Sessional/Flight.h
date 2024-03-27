/*
 * Flight.h
 *
 *  Created on: Apr 26, 2023
 *      Author: lab
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <string>
using namespace std;

class Flight {
	int flight_num;
	string origin;
	string dest;
	string date;
	string deptime;
	string arrtime;
	int availseats;
public:
	Flight(int = 1749, string = "Rawalpindi", string = "Islamabad",string = "2003-10-7", string = "12:00", string = "13:00", int = 500);
	virtual ~Flight();
	const string& getDest() const;
	void setDest(const string &dest);
	int getFlightNum() const;
	void setFlightNum(int flightNum);
	const string& getOrigin() const;
	void setOrigin(const string &origin);
	int getAvailseats() const;
	void setAvailseats(int availseats);
	const string& getArrtime() const;
	void setArrtime(const string &arrtime);
	const string& getDate() const;
	void setDate(const string &date);
	const string& getDeptime() const;
	void setDeptime(const string &deptime);
};

#endif /* FLIGHT_H_ */
