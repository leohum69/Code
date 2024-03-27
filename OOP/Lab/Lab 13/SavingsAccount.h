/*
 * SavingsAccount.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "BankAccount.h"

class SavingsAccount: public BankAccount {
public:
	SavingsAccount(int=1234,int=0);
	void amountWithdrawn(int x);
	void amountDeposit(int x);
	virtual ~SavingsAccount();
};

#endif /* SAVINGSACCOUNT_H_ */
