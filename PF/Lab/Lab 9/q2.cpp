#include <iostream>

using namespace std;

int main(){

	int x=0;
	int count=0;
	cout<<"Enter Value: ";
	cin>>x;
	while(x%2==0)
	{
		cout<<"Invalid Input"<<endl;
		cout<<"Enter Value again: ";
		cin>>x;

	
	}
	
	
	
	for(int i = 1 ; i<=(x+1)/2 ; i++,count++)
	{
		for(int k=1;k<=((x+1)/2)-count;k++){
			cout<<" ";
		}
		
		for(int j=1;j<=i+count;j++){
			cout<<"*";
		}
		cout<<endl;
	}	
	count=0;
	
	for(int i=x;i>=1;i--,count++)
	{
		for(int k=1;k<=1+count;k++){
			cout<<" ";
		}
	
		for(int j=0;j<=i-count;j++){
			cout<<"*";
	}
		cout<<endl;
		}
		
	
		







	return 0;
}
