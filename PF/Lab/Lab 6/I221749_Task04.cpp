#include <iostream>

using namespace std;

int main(){

	int x,y,z,intermediate,large, sort;
	cout<<"Enter First Number: ";
	cin>>x;
	cout<<"Enter Second Number: ";
	cin>>y;
	cout<<"Enter Third Number: ";
	cin>>z;
	
	
	
	if( x>y && x>z){
		large=x;
	}
	else if(y>x && y>z){
		large=y;
	}
	else if(z>x && z>y){
		large=z;
	}

	
	if(x<y && x<z){
		sort=x;
	}
	else if(y<x && y<z){
		sort=y;
	}
	else if(z<x && z<y){
		sort = z;
	}
	

	
	if(x!=sort && x!= large){
		intermediate=x;
	}
	else if(y!=sort && y!= large){
		intermediate=y;
	}
	else if(z!=sort && z!= large){
		intermediate=z;
	}
	
	

	cout<<"Intermediate value: "<<intermediate<<endl;






return 0;
}
