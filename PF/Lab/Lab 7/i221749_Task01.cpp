#include<iostream>

using namespace std;

int main(){
	
	char oper;
	float a,b;
	
	cout<<"Enter First Number: ";
	cin>>a;
	cout<<"Enter Second Number:";
	cin>>b;
	cout<<"Enter the operator:";
	cin>>oper;
	
	switch(oper){
		case '+':
			cout<<"Addition is: "<<a+b<<endl;
			break;
		case '-':
			cout<<"Substraction is:"<<a-b<<endl;
			break;
		case '*':
			cout<<"Multiplication is:"<<a*b<<endl;
			break;
		case '/':
			if(b==0){
				cout<<"Cannot Divide with zero"<<endl;
			}else{
				cout<<"Division is:"<<a/b<<endl;
			}
			break;
		default:
			cout<<"Invalid Input."<<endl;
	}







return 0;
}
