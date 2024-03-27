/*
 * CurrentAccount.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(int ID,int bal):BankAccount(ID,bal){
	// TODO Auto-generated constructor stub

}
void CurrentAccount::amountWithdrawn(int x){
	if((this->getBalance() - x)<5000){
			cout<<"Error The Balance can't be lower than 5000."<<endl;
		}else{
			this->setBalance(this->getBalance()-x);
		}
}
void CurrentAccount::amountDeposit(int x){
	if(x<0){
		cout<<"Error, deposited amount can't be negative"<<endl;
	}else{
		this->setBalance(this->getBalance()+x);
	}
}
CurrentAccount::~CurrentAccount() {
	// TODO Auto-generated destructor stub
}

