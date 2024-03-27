#include <iostream>

using namespace std;

int main(){

	int a,b,c;
	cout<<"Enter First Number: ";
	cin>>a;
	cout<<"Enter Second Number: ";
	cin>>b;
	cout<<"Enter Third Number: ";
	cin>>c;
	
	if(a>b){
		if(a>c){
			cout<<a<<" is the largest."<<endl;
		}
		else{
			cout<<c<<" is the largest."<<endl;
		}
	}
	else if(b>c){
		cout<<b<<" is the largest."<<endl;
	}
	else{
		cout<<c<<" is the largest."<<endl;
	}
	
	






return 0;
}
