#include <iostream>

using namespace std;

int main(){

	int a,b,counter=1;
	cout<<"Enter Number: ";
	cin>>a;
	cout<<"Enter Limit: ";
	cin>>b;
	if(a>0 && b>0){	


		while(counter<=b){
	
			cout<<a<<" * "<<counter<<" = "<<a*counter<<endl;
			counter++;
	
			}
	}else{
			cout<<"Invalid Input"<<endl;
			}
	




	return 0;
}
