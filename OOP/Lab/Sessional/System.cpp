/*
 * System.cpp
 *
 *  Created on: Apr 26, 2023
 *      Author: lab
 */

#include "System.h"
#include "Flight.h"
using namespace std;

System::System() {
	this->arr = new Flight(5);
	this->arr[0].setFlightNum(0000);
	this->arr[0].setOrigin("Rawalpindi");
	this->arr[0].setDest("Islamabad");
	this->arr[0].setDate("2003-10-7");
	this->arr[0].setArrtime("12:00");
	this->arr[0].setDeptime("14:00");
	this->arr[0].setAvailseats(500);

	this->arr[1].setFlightNum(6969);
	this->arr[1].setOrigin("New York");
	this->arr[1].setDest("Los Angeles");
	this->arr[1].setDate("2023-05-15");
	this->arr[1].setArrtime("9:00");
	this->arr[1].setDeptime("13:00");
	this->arr[1].setAvailseats(500);

	this->arr[2].setFlightNum(420);
	this->arr[2].setOrigin("Karachi");
	this->arr[2].setDest("Islamabad");
	this->arr[2].setDate("2023-4-26");
	this->arr[2].setArrtime("9:00");
	this->arr[2].setDeptime("11:00");
	this->arr[2].setAvailseats(455);

	this->arr[3].setFlightNum(988);
	this->arr[3].setOrigin("Rawalpindi");
	this->arr[3].setDest("Islamabad");
	this->arr[3].setDate("2003-10-7");
	this->arr[3].setArrtime("15:00");
	this->arr[3].setDeptime("17:00");
	this->arr[3].setAvailseats(115);

	this->arr[4].setFlightNum(4648);
	this->arr[4].setOrigin("Rawalpindi");
	this->arr[4].setDest("Islamabad");
	this->arr[4].setDate("2003-10-7");
	this->arr[4].setArrtime("12:00");
	this->arr[4].setDeptime("18:00");
	this->arr[4].setAvailseats(1);



}
void System::checker(string org,string des,string dat,string dep,string arr){
	int num = 1;
	for(int i=0;i<5;i++){
		if((this->arr[i].getOrigin() == org) && (this->arr[i].getDest() == des) && (this->arr[i].getDate()== dat)){
			cout<<"Flight "<<num<<": "<<endl;
			cout<<"Departure : "<<this->arr[i].getOrigin()<<" at "<< this->arr[i].getDeptime()<<" on "<< this->arr[i].getDate() << endl;
			cout<<"Departure : "<<this->arr[i].getDest()<<" at "<< this->arr[i].getArrtime()<<" on "<< this->arr[i].getDate() << endl;
			num++;
		}
	}


}
System::~System() {
	// TODO Auto-generated destructor stub
}

