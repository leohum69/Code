//============================================================================
// Name        : Lab04.cpp
// Author      : Mirza Humayun Masood
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

int Factorial(int n);
int fib(int x);
void printfib(int x);
int findGCD(int num1,int num2);
bool elfish(char a[],char b[],int index);
bool LinearSearch(int array[10],int find, int size);
int main() {
	//p1
	//cout<<Factorial(8);

	//p2
/*
	for(int i=0;i<10;i++){
		cout<<fib(i)<<" ";
	}

*/
	//p3
	//cout<<findGCD(25,35);
	//p4
	/*char a[]="shlf";
	char b[]="elf";
	cout<<boolalpha<<elfish(a,b,0);*/
	//p5
	/*
	int a[10]={1,11,22,33,44,55,66,77,88,99};
	cout<<boolalpha<<LinearSearch(a,0,10);
	*/
	return 0;
}
int Factorial(int n){
	if(n<1){
		return 1;
	}

	return n*Factorial(n-1);
}
int fib(int x){
	if(x==1||x==0){
		return x;
	}
	return fib(x-1)+fib(x-2);
}
int findGCD(int num1,int num2){
	if(num1==0){
		return 0;
	}
	else if(num2==0){
		return 0;
	}else if(num1==num2){
		return num1;
	}
	else if(num1>num2){
		return findGCD(num1-num2,num2);
	}else if(num2>num1){
		return findGCD(num1,num2-num1);
	}
}
bool elfish(char a[],char b[],int index){
	if(index==4){
		return true;
	}
	if(strchr(a,b[index])!=NULL)
		return true;
	else
		return false;


	return true && elfish(a,b,index+1);

}
bool LinearSearch(int array[10],int find, int size){
	if(array[size-1]==find){
		return true;
	}
	if(size==0){
			return false;
	}
	return false || LinearSearch(array,find,size-1);
}
