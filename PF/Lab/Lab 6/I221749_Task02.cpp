#include <iostream>
#include <string>

using namespace std;

int main(){

	string var;
	
	cout<<"Enter your Grade: ";
	cin>>var;
	
	if( var== "A+"){
		cout<<"GPA = 4.00"<<endl;
	}
	else if(var == "A"){
		cout<<"GPA = 4.00"<<endl;
	}
	else if(var == "A-"){
		cout<<"GPA = 3.67"<<endl;
	}
	else if(var == "B+"){
		cout<<"GPA = 3.33"<<endl;
	}
	else if(var == "B"){
		cout<<"GPA = 3.00"<<endl;
	}
	else if(var== "B-"){
		cout<<"GPA = 2.67"<<endl;
	}
	else if(var == "C+"){
		cout<<"GPA = 2.33"<<endl;
	}
	else if(var == "C"){
		cout<<"GPA = 2.00"<<endl;
	}
	else if(var== "C-"){
		cout<<"GPA = 1.67"<<endl;
	}
	else if(var == "D+"){
		cout<<"GPA = 1.33"<<endl;
	}
	else if(var== "D"){
		cout<<"GPA = 1.00"<<endl;
	}
	else if(var == "D-"){
		cout<<"GPA = 0.67"<<endl;
	}
	else if(var=="F"){
		cout<<"GPA = 0.00"<<endl;
	}
	else{
		cout<<"Invalid Input"<<endl;
	}








return 0;
}
