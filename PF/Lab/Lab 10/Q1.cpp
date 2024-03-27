#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int n;
	
	cout<<"Enter Number: ";
	cin>>n;
	while (n<3){
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Again : ";
		cin>>n;
	}
	
	cout<<"+"<<setw(n-1)<<setfill('-')<<"+"<<endl;
	
	for(int i=1;i<(n-1);i++){
		cout<<"|"<<setw(n-1)<<setfill('-')<<"|"<<endl;
	}
	cout<<"+"<<setw(n-1)<<setfill('-')<<"+"<<endl;
	
	



	return 0; 
}
