#include <iostream>
#include <cmath>

using namespace std;

int main(){

	float x,y=0,sum=0;
	cout<<"Enter Number: ";
	cin>>x;
	
	for(int i=1;i<=x;i++){
		y= (static_cast<float>(1))/(pow(i,i));
		cout<<"1/"<<"i"<<"^"<<i<<" = "<<y<<endl;
		sum=sum+y;
		cout<<pow(i,i);	
	}
	cout<<"The sum of the above series is: "<<sum<<endl;






	return 0;
}
