#include <iostream>
using namespace std;

bool multiple ( int, int );

int main(){

	int a,b;
	cout<<"Enter First interger: ";
	cin>>a;
	cout<<"Enter Second interger: ";
	cin>>b;
	
	bool chk= multiple(a,b);
	
	if(chk==1){
		cout<<b<<" is a multiple of "<<a<<endl;
	}else{
		cout<<b<<" is not a multiple of "<<a<<endl;
	}


return 0;
}

bool multiple ( int a, int b){
	return (b%a==0);
}
