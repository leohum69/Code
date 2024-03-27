#include <iostream>

using namespace std;

int main(){

	int n;
	cout<<"Enter Number : ";
	cin>>n;
	int count =1;
	while(n<1 || n>26){
		cout<<"Invalid Input "<<endl;
		cout<<"Enter Number Again: ";
		cin>>n;
	}
	
	if(n>=1 && n<=26){
	
		for(int i=65;i<(n+65);i++,count++){
			for(int j=1;j<=count;j++){
				cout<<static_cast<char>(i);
			}
			cout<<endl;
			
		}
	
	
	}
	



	return 0; 
}
