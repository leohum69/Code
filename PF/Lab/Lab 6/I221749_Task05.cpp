#include <iostream>

using namespace std;

int main(){

	int num,cost,updated_cost;
	cout<<"Enter number of units: ";
	cin>>num;
	
	if(num<100){
		cost = 9 * num;
	}
	else if(num>100 && num< 200){
		cost = 11 * num;
	}
	else if(num>200 && num<300){
		cost = 19 * num;
	}
	
	if(cost<750){
		updated_cost= cost + (5*cost)/100;
	}
	else if(cost > 750){
		updated_cost= cost + ((7*cost)/100); 
	}
	
	cout<<"Your Electercity bill is: "<<updated_cost<<endl;








return 0;
}
