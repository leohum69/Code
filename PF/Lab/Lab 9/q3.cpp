#include <iostream>

using namespace std;

int main(){

	
	int x,y,count=1,gcd=0;
	cout<<"Enter First Number: ";
	cin>>x;
	cout<<"Enter Second Number: ";
	cin>>y;
	
	if(x>=y){
		while(count<=y){
			if((x%count==0)&&(y%count == 0)){
				gcd=count;
			}
		count++;
		}
	}
	if(x<y){
		while(count<=x){
			if((x%count==0)&&(y%count == 0)){
				gcd=count;
			}
		count++;
		}
	}


	cout<<"GCD is: "<<gcd<<endl;



	return 0;
}
