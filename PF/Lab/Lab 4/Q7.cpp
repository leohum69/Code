#include <iostream>
using namespace std;

int main(){

	int seconds;
	cout<<"Enter Seconds: ";
	cin>>seconds;

	int hours,minutes,s;
	hours = seconds/3600;
	minutes= (seconds-(3600*hours))/60;
	s= (seconds-(3600*hours)-(minutes*60));


	cout<<hours<<" hours : "<<minutes<<" minutes : "<<s<<" seconds"<<endl;



return 0;
}
