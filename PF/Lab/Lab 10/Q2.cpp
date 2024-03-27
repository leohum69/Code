#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	int n;
	cout<<"Enter Number: ";
	cin>>n;
	while(n<0 || n>20){
		cout<<"Invalid Input "<<endl;
		cout<<"Enter Number Again: ";
		cin>>n;
	}
	int p=1;
	int pew=n;
	if(n>=0 && n<=20){
		cout<<setw(n+1)<<'|'<<endl;
		
		for(int k=1;k<=n && p<=n;k++,p++,pew--){
			cout<<setw(pew);
			for(int i=1;i<=p;i++){
				cout<<"*";
			}
			cout<<"|";
			for(int j=1;j<=p;j++){
				cout<<"*";
			}
			cout<<endl;
		}
	
	}
	


	return 0; 
}
