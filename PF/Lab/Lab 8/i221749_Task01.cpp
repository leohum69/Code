#include <iostream>

using namespace std;

int main(){

	int a,b,i=0,even=0,odd=0;
	cout<<"Enter Start: ";
	cin>>a;
	cout<<"Enter End: ";
	cin>>b;
	
	while(a<=b){
		if(a%2==0){
			even++;
		}else if(a%2 != 0){
			odd++;
		}
		a++;
	}
	

	cout<<"Even Number were: "<<even<<endl;
	cout<<"Odd Number were: "<<odd<<endl;


	return 0;
}
