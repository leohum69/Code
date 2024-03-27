#include<iostream>

using namespace std;

int main(){

	int a,b;
	cout<<"Enter First number: ";
	cin>>a;
	cout<<"Enter Second number: ";
	cin>>b;
	
	string ez = (a^b)?"Not Equal":"Equal";
	
	cout<<ez<<endl;






return 0;
}
