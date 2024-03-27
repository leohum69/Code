//============================================================================
// Name        : Lab07.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Block.h"
#include "Complex.h"
#include "Holiday.h"
using namespace std;
bool inSameMonth(Holiday h1,Holiday h2){
	if(h1.getMonth() == h2.getMonth())
		return true;
	else
		return false;
}
double avgDate(Holiday arr[], int size){
	double sum=0;
	for(int i=0;i<size;i++){
		sum += arr[i].getDate();
	}
	sum = sum / size;
	return sum;
}
int main() {
	//Q1
	/*Block B1;
	Block B2(5,6,7,"yellow","pew");
	B1.print();
	B2.print();
	cout<< B1.countofBlocks;*/
	//Q2
	/*Complex C1(5,6);
	Complex C2(C1);
	C1=C1.mulComplex(5);
	cout<<C1.getReal()<<endl;
	cout<<C1.getComp()<<endl;
	*/
	//Q3
	/*Holiday h1("chutti",5,"April");
	Holiday h2(h1);
	Holiday h3;
	cout<<inSameMonth(h1,h3);
	h1.setMonth("ASDFGHJKLOU");*/




	return 0;
}
