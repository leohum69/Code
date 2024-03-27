#include<iostream>

using namespace std;

int main(){
	int a;
	
	cout<<"Enter Number: ";
	cin>>a;
	
	bool b= (a%2==0);
	
	switch(a){
	
		case 0:
			cout<<"Number is zero and even"<<endl;
			break;
		default:
			switch(b){
				case 0:
					cout<<"The number is Non-zero and Odd"<<endl;
					break;
				case 1:
					cout<<"The number is Non-zero and Even"<<endl;
					break;
				}
		break;


}



return 0;
}
