/*
 * CurrentAccount.h
 *
 *  Created on: May 3, 2023
 *      Author: lab
 */

#ifndef CURRENTACCOUNT_H_
#define CURRENTACCOUNT_H_


#include "BankAccount.h"

class CurrentAccount: public BankAccount {
public:
	CurrentAccount(int=1234,int=0);
	void amountWithdrawn(int x);
	void amountDeposit(int x);
	virtual ~CurrentAccount();
};

#endif /* CURRENTACCOUNT_H_ */
