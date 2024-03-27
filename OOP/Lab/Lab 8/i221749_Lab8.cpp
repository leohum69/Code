//============================================================================
// Name        : Lab8.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "IntegerList.h"
#include "FaceBook.h"
#include "Complex.h"
using namespace std;

int* GenderCount(FaceBook *arr, int size){
	int *p = new int[2]{0,0};

	for(int i=0;i<size;i++){
		if(arr[i].getGender() == 'M' || arr[i].getGender() == 'm')
			p[0]++;
		else if(arr[i].getGender() == 'F' || arr[i].getGender() == 'f')
			p[1]++;
	}
	return p;
}
int main() {
	//cout<<"ez";

	/*IntegerList a1(5);
	a1.setElement(0, 5);
	//cout<<a1.getElement(88); // code exit
	cout<<a1.getElement(0);




	FaceBook arr[5];
	for(int i=0;i<5;i++){
		if(i%2==0)
			arr[i].setGender('M');
		else
			arr[i].setGender('F');
	}
	int* x= GenderCount(arr,5);
	cout<<"Males: "<< x[0] << endl;
	cout<<"Females: "<< x[1] << endl;
	delete []x;
	//delete[]arr;

	Complex c1(5,2);
	Complex c2(c1);
	Complex c3(0,0);
	c3 = mulComplex(c1,c2);
	cout<<c3.getReal()<<" "<<c3.getComp();*/



	return 0;
}
