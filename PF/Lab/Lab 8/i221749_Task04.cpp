#include <iostream>

using namespace std;

int main(){
	int a;
	int i=1,product=1;
	
	cout<<"Enter Number: ";
	cin>>a;
	if(a<20){
	while(i<=a){
	
	product *= i;
	i++;
	}

	cout<<"Factorial of "<<a<<" is : "<<product<<endl;
}
else{
	cout<<"Invalid Input"<<endl;
}
	return 0;
}
