#include <iostream>
#include <cmath>
using namespace std;

double hypotenuse(double,double);

int main(){

	double a,b;
	
	for(int i=1;i<=3;i++){
	cout<<"Enter 2 sides of "<<i<<"st Right Triangle: ";
	cin>>a>>b;
	cout<<"Hypotenuse: "<<hypotenuse(a,b)<<endl;
	}
	
return 0;
}

double hypotenuse(double a,double b){
	return (sqrt(pow(a,2) + pow (b,2)));
}
