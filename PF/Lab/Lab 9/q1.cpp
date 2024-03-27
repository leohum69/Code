#include <iostream>
#include <iomanip>
using namespace std;

int main(){


	int x=0;
	cout<<"Enter Value: ";
	cin>>x;
	while(x%2==0)
	{
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Value again: ";
		cin>>x;

	
	}
/*
		for(int i=1;i<=((x+1)/2);i++){
			cout<<setw(i)<<setfill('*')<<'*'<<endl;
		}
		for(int j=(((x+1)/2)-1);j>=1;j--){
			cout<<setw(j)<<setfill('*')<<'*'<<endl;
		}
		
*/
	
	for(int i = 1 ; i<=(x+1)/2 ; i++)
	{
		for(int j=1;j<=i;j++){
			cout<<"*";
		}
		cout<<endl;
	}	
	for(int i=((x+1)/2)-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++){
			cout<<"*";
	}
		cout<<endl;
		}
		
		
	
	
	

	
	
	


	return 0;
}
