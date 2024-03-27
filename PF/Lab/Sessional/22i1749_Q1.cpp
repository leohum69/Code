#include <iostream>
using namespace std;

int main(){

	float x;
	int y;
	cout<<"Enter starting Time: ";
	cin>>x;
	cout<<"Enter Number of minutes: ";
	cin>>y;
	int time;
	int pp,dd;
	float ll;
	double price;
	pp=static_cast<int>(x);
	ll=x-static_cast<float>(pp);
	dd=ll*100;
	if(pp>23 || pp<0){
		cout<<"Invalid Input"<<endl;
	}else if(dd>59 || dd<0){
		cout<<"Invalid Input"<<endl;	
	}else{
		time = y;
		if(pp<7){
			price=(static_cast<double>(time)*0.12);
		}else if(pp>=7 && pp<=13){
			price=(static_cast<double>(time)*0.55);
		}else if(pp>13 && pp<20){
			price=(static_cast<double>(time)*0.45);
		}else if(pp>=20){
			price=(static_cast<double>(time)*0.35);
		}
		
		cout<<"Your Total Price is: "<<price<<endl;
	}
	





return 0;
}
