/*
 * BankAccount.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
#include <iostream>
using namespace std;
class BankAccount {
	int accountID;
	int balance;
public:
	BankAccount(int=1234,int=0);
	int balanceInquiry();
	virtual ~BankAccount();
	int getAccountId() const;
	void setAccountId(int accountId);
	int getBalance() const;
	void setBalance(int balance);
};

#endif /* BANKACCOUNT_H_ */
