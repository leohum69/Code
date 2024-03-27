//============================================================================
// Name        : i221749_Sessional.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Flight.h"
#include "System.h"
using namespace std;

int main() {
	string org,des,date,dep,arr;
	System x;
	int p;

	cout<<"Welcome to XYZ Airlines Reservation System!"<<endl;
	bool cont=1;
	while(cont){
		cout<<"Please Enter you Departure City: ";
		getline(cin,org);
		cout<<"Please Enter you arrival City: ";
		getline(cin,des);
		cout<<"Please enter your departure date: ";
		getline(cin,date);
		cout<<"Please Enter Your preferred departure time: ";
		getline(cin,dep);
		cout<<"Please Enter Your preferred Arrival time: ";
		getline(cin,arr);

		x.checker(org,des,date,dep,arr);

		cout<<"Select one flight: ";
		cin>>p;

	}



	return 0;
}
