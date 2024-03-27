//============================================================================
// Name        : Lab13.cpp
// Author      : MIrza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "HourlyEmployee.h"
#include "PermanentEmployee.h"
#include "Computer.h"
#include "Desktop.h"
#include "Laptop.h"
using namespace std;

int main() {
	//Q1
	/*SavingsAccount S1(420,50000);
	cout<<"The Balance of Saving account :"<<S1.balanceInquiry()<<endl;
	S1.amountWithdrawn(5000);
	cout<<"The Balance of Saving account after withdrawing :"<<S1.balanceInquiry()<<endl;
	//S1.amountWithdrawn(35000);
	//S1.amountWithdrawn(35001);
	S1.amountDeposit(50);
	cout<<"The Balance of Saving account after Deposit :"<<S1.balanceInquiry()<<endl;
	CurrentAccount C1(420,50000);
	cout<<"The Balance of Current account :"<<C1.balanceInquiry()<<endl;
	C1.amountWithdrawn(10000);
	cout<<"The Balance of Current account after withdrawing :"<<C1.balanceInquiry()<<endl;
	//C1.amountWithdrawn(35000);
	//C1.amountWithdrawn(35001);
	C1.amountDeposit(50);
	cout<<"The Balance of Current account after Deposit :"<<C1.balanceInquiry()<<endl;*/
	//Q2
	/*HourlyEmployee H1("Ali",1234);
	cout<<"The income of hourly employee for 25 hours : "<<H1.calculate_the_hourly_income(25)<<endl;
	PermanentEmployee P1("Ahmed",4321);
	cout<<"The income of Permanent employee : "<<P1.calculate_the_income()<<endl;*/
	//Q3
	/*Computer **c1;
	c1 = new Computer*[2];
	c1[0] = new Desktop("acer",15000,"white",19,"i3");
	c1[1] = new Laptop("Hp",50000,"Black",15,3,"i5");
	for(int i = 0; i < 2 ; i++){
		c1[i]->show();
	}
	delete []c1;*/




	return 0;
}
