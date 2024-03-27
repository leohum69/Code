#include<iostream>
using namespace std;

int main(){

	char first,second;

	cout<<"Enter first character : ";
	cin>>first;
	cout<<"Enter second character : ";
	cin>>second;

	cout<<"First Character : "<< first <<endl;
	cout<<"Second Character : "<< second <<endl;

	char temp;

	temp = first;
	first = second;
	second = temp;

	cout<<"After Swap"<<endl<<endl;

 	cout<<"First Character : "<< first <<endl;
	cout<<"Second Character : "<< second <<endl;










return 0;
}
