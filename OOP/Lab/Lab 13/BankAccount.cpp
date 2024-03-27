/*
 * BankAccount.cpp
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#include "BankAccount.h"

BankAccount::BankAccount(int ID,int bal) {
	this->accountID = ID;
	this->balance = bal;

}
int BankAccount::balanceInquiry(){
	return this->balance;
}

BankAccount::~BankAccount() {
	// TODO Auto-generated destructor stub
}

int BankAccount::getAccountId() const {
	return accountID;
}

void BankAccount::setAccountId(int accountId) {
	accountID = accountId;
}

int BankAccount::getBalance() const {
	return balance;
}

void BankAccount::setBalance(int balance) {
	this->balance = balance;
}
