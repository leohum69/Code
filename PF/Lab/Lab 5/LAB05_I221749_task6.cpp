#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float a, b, c;

	cout<<"Enter a : ";
	cin>>a;
	cout<<"Enter b : ";
	cin>>b;
	cout<<"Enter c : ";
	cin>>c;

	cout<<"First Root: "<< (-b + (sqrt((b*b) - (4 *a*c))))/(2*a)<<endl;

	cout<<"Second Root: "<< (-b - (sqrt((b*b) - (4 *a*c))))/(2*a)<<endl;





return 0;
}
