#include <iostream>
using namespace std;


void fun2(char &a){
	if(static_cast<int>(a)>=65 && static_cast<int>(a)<=90){
		cout<<"Enter Charater is Uppercased"<<endl;
	}else if(static_cast<int>(a)>=97 && static_cast<int>(a)<=122){
		cout<<"Enter Charater is Lowercased"<<endl;
	}

}
void fun1(char &a){
	if(static_cast<int>(a)>=48 && static_cast<int>(a)<=57){
		cout<<"Character is Number"<<endl;

	}else if(static_cast<int>(a)>=65 && static_cast<int>(a)<=122){
			fun2(a);
		}
	

}


int main(){
	char a;
	cout<<"Enter Character: ";
	cin>>a;
	
	fun1(a);



return 0;
}
