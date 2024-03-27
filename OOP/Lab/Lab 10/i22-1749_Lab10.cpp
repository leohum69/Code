//============================================================================
// Name        : Lab10.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Money.h"
using namespace std;

int main() {
	Money M1(7,5);
	Money M2(6,6);
	Money M3;
	cout<<M1;
	cout<<M2;
	cout<<M3;
	M3 = M1+M2;
	cout<<M3;
	M3 = M1-M2;
	cout<<M3;
	M3 *= M1;
	cout<<M3;
	cout<<"M1 "<<M1;
	M1++;
	cout<<"updated M1 "<<M1;
	++M1;
	cout<<"updated M1 "<<M1;
	--M2;
	cout<<"M2 "<<M2;
	cout<< (M1>M2) <<endl;
	cout<<(M1 != M2)<<endl;
	M3 = M1-M2;
	cout<<M3;
	Money M4(3,0);
	M4--;
	cout<<M4;
	M4--;
	cout<<M4;


	return 0;
}
