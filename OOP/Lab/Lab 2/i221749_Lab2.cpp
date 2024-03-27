//============================================================================
// Name        : lab2.cpp
// Author      : i221749_Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void getAddress(int &num);
void swap(int* n1, int* n2);
int countPrime(int arr[], int size,int count);
int* duplicate(int* ptr2, int arr2[], int length);
char* toCapital(char *p);

int main(){
	//Question 5 case 2
	char str[12]="environment";
	   char *p=str;
	   char *expec=toCapital(p);// expect a return
	   char res[12]="ENVIRONMENT";

	   for(int i=0;i<12;i++){
		   cout<<*(expec+i);
	   }










}

void getAddress(int &num){
	cout<<"Number Value: "<<num<<endl;
	cout<<"Number Address: "<<&num<<endl;
	int* p=&num;
	*p=rand();//value changed
	cout<<num;

}
void swap(int* n1, int* n2){
	int temporary=*n1;
	*n1=*n2;
	*n2=temporary;

}
int* duplicate(int* ptr2, int arr2[], int length){
	for(int i=0;i<length;i++){
		*(arr2+i)= *(ptr2+i);
	}
	return arr2;
}
int countPrime(int arr[], int size,int count){
	int c=0;
	int c2=0;
	for(int i=0;i<size;i++){
		for(int j=1;j<=*(arr+i);j++){
			if(*(arr+i)%j==0){
				c2++;
			}
		}
		if(c2==2){
			c++;
		}
		c2=0;
	}

	return c;
}
char* toCapital(char *p){
	int i=0;
	int c=0;
	while(*(p+i)!='\0'){
		c++;
		i++;
	}
	for(i=0;i<c;i++){
		*(p+i)=*(p+i)-32;
	}

	return p;

}
