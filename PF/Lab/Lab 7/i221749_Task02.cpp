#include<iostream>

using namespace std;

int main(){

	cout<<"Grade Calculator"<<endl;
	cout<<"______________________"<<endl;
	float a;
	
	cout<<"Enter Your score = ";
	cin>>a;
	
	if(a>=90){
		cout<<"Your Grade is A+"<<endl;
	}else if(a>=80 && a<90){
		cout<<"Your Grade is A"<<endl;
	}else if(a>=70 && a<80){
		cout<<"Your Grade is B"<<endl;
	}else if(a>=60 && a<70){
		cout<<"Your Grade is C"<<endl;
	}else if(a>=50 && a<60){
		cout<<"Your Grade is D"<<endl;
	}else if(a<50){
		cout<<"Your Grade is F"<<endl;
	}






return 0;
}
