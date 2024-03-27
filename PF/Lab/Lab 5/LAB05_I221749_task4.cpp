#include <iostream>

using namespace std;

int main(){

	const int WEEKLY_WAGE = 1000;
	const int OVERTIME = 1500;
	int hours,h;
	bool check;
	int a,b, ez;

	cout<<"Enter hours: ";
	cin>>hours;

	check= !(hours<=40);

	h= (hours*check) - (check*40);

	a = (hours-(check*h))*WEEKLY_WAGE;
	b= h*OVERTIME;
	cout<<"Total Pay: "<<a+b<<endl;
	

	





return 0;
}
