#include <iostream>

using namespace std;

int main(){

	int a,b,counter=1,highest=0;
	cout<<"Input the first number: ";
	cin>>a;
	cout<<"Input the second number:";
	cin>>b;
	
	
	if(a>b){
	
		while(counter<=a){
			if(a%counter==0 && b%counter==0){
				highest=counter;
			}
			
			counter++;
		
		
		
		}
	}else{
		while(counter<=b){
			if(a%counter==0 && b%counter==0){
				highest=counter;
			}
			
			counter++;
		
		
		
		}
	}


	cout<<"The Greatest Common Divisor is: "<<highest<<endl;



	return 0;
}
