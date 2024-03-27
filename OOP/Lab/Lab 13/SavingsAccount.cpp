/*
 * SavingsAccount.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int ID,int bal):BankAccount(ID,bal) {
	// TODO Auto-generated constructor stub

}
void SavingsAccount::amountWithdrawn(int x){
	if((this->getBalance() - x)<10000){
		cout<<"Error The Balance can't be lower than 10000."<<endl;
	}else{
		this->setBalance(this->getBalance()-x);
	}
}
void SavingsAccount::amountDeposit(int x){
	if(x<0){
		cout<<"Error, deposited amount can't be negative"<<endl;
	}else{
		this->setBalance(this->getBalance()+x);
	}
}
SavingsAccount::~SavingsAccount() {
	// TODO Auto-generated destructor stub
}

